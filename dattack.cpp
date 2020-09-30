/*******************************************************************
*
*  DESCRIPTION: Atomic Model Dragon Attack
*
*  AUTHOR: Meagan Leflar
*
*  EMAIL: meagan_leflar@carleton.ca
*
*  DATE: 15/10/2012
*
*******************************************************************/

/** include files **/
#include "dattack.h"      // class Queue
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: Dattack
* Description: 
********************************************************************/
Dattack::Dattack( const string &name )
: Atomic( name )
, in( addInputPort( "in" ) )
, out( addOutputPort( "out" ) )
, preparationTime( 0, 0, 10, 0 ) //10 seconds
{
	/*string time( MainSimulator::Instance().getParameter( description(), "preparation" ) ) ;

	if( time != "" )
		preparationTime = time ;*/
}

/*******************************************************************
* Function Name: initFunction
* Description:
********************************************************************/
Model &Dattack::initFunction()
{
	this-> passivate();
	claw_damage = -15; //hit points
	fire_damage = -10; //hit points
	claw_range = 10; //feet
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description: 
********************************************************************/
Model &Dattack::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == in )
	{
		//get distance value input
		dist = static_cast < int > (msg.value());
		if(dist < 0) //otherwise, you're moving this round, not attacking
		{
			//activate cell for 10 seconds?? Time unit??
			dist = dist * -1; //make it positive for calculations
			holdIn( active, preparationTime);
		}
	}

	return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description: 
********************************************************************/
Model &Dattack::internalFunction( const InternalMessage & )
{
	passivate();
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description: 
********************************************************************/
Model &Dattack::outputFunction( const InternalMessage &msg )
{
	int damage = -1;
	//if within claw range
	if(dist <= claw_range)
		damage = claw_damage;
	else //use fire breath
		damage = fire_damage;

	//attack
	sendOutput( msg.time(), out, damage) ;
	return *this ;
}
