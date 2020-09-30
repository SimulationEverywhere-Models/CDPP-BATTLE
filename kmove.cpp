/*******************************************************************
*
*  DESCRIPTION: Atomic Model Knight Movement
*
*  AUTHOR: Meagan Leflar
*
*  EMAIL: meagan_leflar@carleton.ca
*
*  DATE: 15/10/2012
*
*******************************************************************/

/** include files **/
#include "kmove.h"      // class Kmove
#include "message.h"    // class ExternalMessage, InternalMessage
#include "distri.h"        // class Distribution
#include "mainsimu.h"      // class MainSimulator
#include "strutil.h"       // str2float( ... )
#include <stdlib.h>
 
/** public functions **/

/*******************************************************************
* Function Name: Kmove
* Description: 
********************************************************************/
Kmove::Kmove( const string &name )
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
Model &Kmove::initFunction()
{
	this-> passivate();
	step = 4; //feet
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description: 
********************************************************************/
Model &Kmove::externalFunction( const ExternalMessage &msg )
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
Model &Kmove::internalFunction( const InternalMessage & )
{
	passivate();
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description: 
********************************************************************/
Model &Kmove::outputFunction( const InternalMessage &msg )
{
	//move
	if(dist > 50)
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

	sendOutput( msg.time(), out, dist );
	return *this ;
}

Kmove::~Kmove()
{
	//delete dist;
	//delete index;
	//delete step;
}
