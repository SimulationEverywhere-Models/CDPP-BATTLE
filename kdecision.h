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

#ifndef __KDECISION_H
#define __KDECISION_H

#include "atomic.h"     // class Atomic

class Kdecision : public Atomic
{
public:
	Kdecision( const string &name = "Kdecision" );					//Default constructor
	~Kdecision();
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

};	// class Kdecision

// ** inline ** // 
inline
string Kdecision::className() const
{
	return "Kdecision" ;
}

#endif   //__KDECISION_H
