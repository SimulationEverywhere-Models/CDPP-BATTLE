/*******************************************************************
*
*  DESCRIPTION: Atomic Model Subnet
*
*  AUTHOR: Tao Zheng 
*
*  EMAIL: mailto://zhengtao@sce.carleton.ca
*
*  DATE: 15/10/2002
*
*******************************************************************/

#ifndef __KMOVE_H
#define __KMOVE_H

#include "atomic.h"     // class Atomic


/** forward declarations **/
//class Distribution ;

class Kmove : public Atomic
{
public:
	Kmove( const string &name = "Kmove" );					//Default constructor
	~Kmove();
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

};	// class Kmove

// ** inline ** // 
inline
string Kmove::className() const
{
	return "Kmove" ;
}

#endif   //__KMOVE_H
