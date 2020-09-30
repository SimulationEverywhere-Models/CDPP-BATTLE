/*******************************************************************
*
*  DESCRIPTION: Atomic Knight Attack Model
*
*  AUTHOR: Meagan Leflar
*
*  EMAIL: meagan_leflar@carleton.ca
*
*  DATE: 15/10/2012
*
*******************************************************************/

#ifndef __DATTACK_H
#define __DATTACK_H

//#include <list>
#include "atomic.h"     // class Atomic

class Dattack : public Atomic
{
public:
	Dattack( const string &name = "Dattack" );					//Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &in;
	Port &out;
	int dist;
	int fire_damage;
	int claw_damage;
	int claw_range;
	Time preparationTime;
//	typedef list<Value> ElementList ;
//	ElementList elements ;

//	Time timeLeft;

};	// class Dattack

// ** inline ** // 
inline
string Dattack::className() const
{
	return "Dattack" ;
}

#endif   //__DATTACK_H
