/*******************************************************************
*
*  DESCRIPTION: Atomic Model Dragon Decision
*
*  AUTHOR: Meagan Leflar
*
*  EMAIL: meagan_leflar@carleton.ca
*
*  DATE: 15/10/2012
*
*******************************************************************/

#ifndef __DDECISION_H
#define __DDECISION_H

#include "atomic.h"     // class Atomic

class Ddecision : public Atomic
{
public:
	Ddecision( const string &name = "Ddecision" );					//Default constructor
	~Ddecision();
	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &in;
	Port &out;
	int packet;
	int index;
	int dist;
	int hp;

};	// class Ddecision

// ** inline ** // 
inline
string Ddecision::className() const
{
	return "Ddecision" ;
}

#endif   //__DDECISION_H
