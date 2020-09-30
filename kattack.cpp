/*******************************************************************
*
*  DESCRIPTION: Atomic Model Receiver
*
*  AUTHOR: Tao Zheng 
*
*  EMAIL: mailto://zhengtao@sce.carleton.ca
*
*  DATE: 15/10/2002
*
*******************************************************************/

/** include files **/
#include "kattack.h"      // class Queue
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: Kattack
* Description: 
********************************************************************/
Kattack::Kattack( const string &name )
: Atomic( name )
, in( addInputPort( "in" ) )
, out( addOutputPort( "out" ) )
, preparationTime( 0, 0, 10, 0 )
{
	/*string time( MainSimulator::Instance().getParameter( description(), "preparation" ) ) ;

	if( time != "" )
		preparationTime = time ;*/
}

/*******************************************************************
* Function Name: initFunction
* Description:
********************************************************************/
Model &Kattack::initFunction()
{
	this-> passivate();
	sword_damage = -10;
	bow_damage = -5;
	sword_range = 5; //feet
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description: 
********************************************************************/
Model &Kattack::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == in )
	{
		//get distance value input
		dist = static_cast < int > (msg.value());
		if(dist < 0) //otherwise, you're moving this round, not attacking
		{
			//activate cell for 10 seconds?? Time unit??
			dist = dist * -1; //make it positive
			holdIn( active, preparationTime);
		}
	}

	return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description: 
********************************************************************/
Model &Kattack::internalFunction( const InternalMessage & )
{
	passivate();
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description: 
********************************************************************/
Model &Kattack::outputFunction( const InternalMessage &msg )
{
	int damage = -1;
	//if within sword range
	if(dist <= sword_range)
		damage = sword_damage;
	else //use bow
		damage = bow_damage;

	//attack
	sendOutput( msg.time(), out, damage) ;
	return *this ;
}
