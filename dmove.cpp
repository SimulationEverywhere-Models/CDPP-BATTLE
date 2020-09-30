/*******************************************************************
*
*  DESCRIPTION: Atomic Model Dragon Movement
*
*  AUTHOR: Meagan Leflar
*
*  EMAIL: meagan_leflar@carleton.ca
*
*  DATE: 15/10/2012
*
*******************************************************************/

/** include files **/
#include "dmove.h"      // class Dmove
#include "message.h"    // class ExternalMessage, InternalMessage
#include "distri.h"        // class Distribution
#include "mainsimu.h"      // class MainSimulator
#include "strutil.h"       // str2float( ... )
#include <stdlib.h>
 
/** public functions **/

/*******************************************************************
* Function Name: Dmove
* Description: 
********************************************************************/
Dmove::Dmove( const string &name )
: Atomic( name )
, in( addInputPort( "in" ) )
, out( addOutputPort( "out" ) )
, preparationTime( 0, 0, 5, 0 )
{	index = 1;
	/*try
	{
		dist = Distribution::create( MainSimulator::Instance().getParameter( description(), "distribution" ) );

		MASSERT( dist );

		for ( register int i = 0 ; i < dist->varCount() ; i++ )
		{
			string parameter( MainSimulator::Instance().getParameter( description(), dist->getVar(i) ) ) ;
			dist->setVar( i, str2float( parameter ) ) ;
		}
	} catch( InvalidDistribution &e )
	{
		e.addText( "The model " + description() + " has distribution problems!" ) ;
		e.print(cerr);
		MTHROW( e ) ;
	} catch( MException &e )
	{
		MTHROW( e ) ;
	}*/
}

/*******************************************************************
* Function Name: initFunction
* Description: Resetea la lista
* Precondition: El tiempo del proximo evento interno es Infinito
********************************************************************/
Model &Dmove::initFunction()
{
	this-> passivate();
	step = 8; //feet
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description: 
********************************************************************/
Model &Dmove::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == in )
	{	index ++;
		dist = static_cast < int > (msg.value());

		if(dist > 0)
		{
			//Time t(fabs(this->distribution().get()));
			//holdIn( active, Time( static_cast<float>( fabs( distribution().get() ) ) ) );
			holdIn(active, preparationTime);
		}
	}

	return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description: 
********************************************************************/
Model &Dmove::internalFunction( const InternalMessage & )
{
	passivate();
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description: 
********************************************************************/
Model &Dmove::outputFunction( const InternalMessage &msg )
{
	//dragon may just wait
	//only 60% chance of moving at all
	if((double)rand() / (double) RAND_MAX < 0.6)
	{
		//move
		if(dist > 80)
		{
			//move forward
			dist-=step;
		}
		else if(dist < (step+1))
		{
			//move away
			dist+=step;
		}
		else //randomly decide if moving forward or back
		{
			if ((double)rand() / (double) RAND_MAX  < 0.5)
			{
				dist+=step;
			}
			else
			{
				dist-=step;
			}
		}
	}
	else
	{
		dist+=0;
	}

	sendOutput( msg.time(), out, dist );
	return *this ;
}

Dmove::~Dmove()
{
	//delete dist;
	//delete index;
	//delete step;
}
