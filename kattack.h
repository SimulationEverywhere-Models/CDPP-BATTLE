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

#ifndef __KATTACK_H
#define __KATTACK_H

//#include <list>
#include "atomic.h"     // class Atomic

class Kattack : public Atomic
{
public:
	Kattack( const string &name = "Kattack" );					//Default constructor

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
	int bow_damage;
	int sword_damage;
	int sword_range;
	Time preparationTime;
//	typedef list<Value> ElementList ;
//	ElementList elements ;

//	Time timeLeft;

};	// class Kattack

// ** inline ** // 
inline
string Kattack::className() const
{
	return "Kattack" ;
}

#endif   //__KATTACK_H
