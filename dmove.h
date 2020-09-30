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

#ifndef __DMOVE_H
#define __DMOVE_H

#include "atomic.h"     // class Atomic


/** forward declarations **/
//class Distribution ;

class Dmove : public Atomic
{
public:
	Dmove( const string &name = "Dmove" );					//Default constructor
	~Dmove();
	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &in;
	Port &out;
	Time preparationTime;
	int dist;
	int index;
	int step;
	/*Distribution * dist;
	
	Distribution &distribution()
		{return *dist;}*/

};	// class Dmove

// ** inline ** // 
inline
string Dmove::className() const
{
	return "Dmove" ;
}

#endif   //__DMOVE_H
