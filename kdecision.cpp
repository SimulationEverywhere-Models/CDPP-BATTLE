/*******************************************************************
*
*  DESCRIPTION: Atomic Model Knight Decision
*
*  AUTHOR: Meagan Leflar
*
*  EMAIL: meagan_leflar@carleton.ca
*
*  DATE: 15/10/2012
*
*******************************************************************/

/** include files **/
#include "kdecision.h"      // class Kdecision
#include "message.h"    // class ExternalMessage, InternalMessage
#include "distri.h"        // class Distribution
#include "mainsimu.h"      // class MainSimulator
#include "strutil.h"       // str2float( ... )
#include <stdlib.h>
 
/** public functions **/

/*******************************************************************
* Function Name: Kdecision
* Description: 
********************************************************************/
Kdecision::Kdecision( const string &name )
: Atomic( name )
, in( addInputPort( "in" ) )
, out( addOutputPort( "out" ) )
//, preparationTime( 0, 0, 3, 0 )
{
	index = 1;
}

/*******************************************************************
* Function Name: initFunction
* Description: Initialize model, set to passive
********************************************************************/
Model &Kdecision::initFunction()
{
	this-> passivate();
	hp = 100;
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description: 
********************************************************************/
Model &Kdecision::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == in ) //if incoming message
	{
		index ++; // why do we have the index?

		//receive input
		packet = static_cast < int > (msg.value());

		//how long it takes to do this action.**
			//holdIn is the time advance function
		holdIn( active, Time::Zero);
	}

	return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description: 
********************************************************************/
Model &Kdecision::internalFunction( const InternalMessage & )
{
	passivate();
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description: 
********************************************************************/
Model &Kdecision::outputFunction( const InternalMessage &msg )
{
	//update relevant variables
	if(packet > 0) //other character moved
	{
		dist = packet;
	}
	else if (packet < 0) //other character attacked
	{
		int damage = packet;
		hp+=damage;
		if(hp <= 0) //if character is now dead, end simulation
		{
			packet = 0;
		}
	}

	//testing
	//sendOutput(msg.time(), out, hp);

	//if randomly generated percentage is less than 95%
	//if ((double)rand() / (double) RAND_MAX  < 0.95)
	//	sendOutput( msg.time(), out, packet ) ;

	//60% chance of attacking
	//but only attack if within range
	//and if not dead
	if(packet != 0)
	{
		if(dist < 50)
		{
			 if((double)rand() / (double) RAND_MAX < 0.80)
			 {
				 //attack
				 int d = dist * -1;
				 sendOutput(msg.time(), out, d);
			 }
			 else // maneuver
			 {
				 sendOutput(msg.time(), out, dist);
			 }
		}
		else
		{
			//maneuver
			sendOutput(msg.time(),out,dist);
		}
	}
	else
	{
		//you're dead
		sendOutput(msg.time(),out, packet);
	}

	return *this ;
}

Kdecision::~Kdecision()
{
	//delete dist;
	//delete packet;
	//delete index;
	//delete hp;
}
