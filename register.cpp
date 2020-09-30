/*******************************************************************
*
*  Auto Generated File
*
*  DESCRIPTION: Simulator::registerNewAtomics()
*
*  This registration file is used to describe the atomic models that can be used to compose coupled models.
*
*
*******************************************************************/

#include "modeladm.h"
#include "mainsimu.h"
#include "queue.h"      // class Queue
#include "generat.h"    // class Generator
#include "cpu.h"        // class CPU
#include "transduc.h"   // class Transducer
#include "trafico.h"    // class Trafico
#include "kattack.h"
#include "kdecision.h"
#include "kmove.h"
#include "dattack.h"
#include "ddecision.h"
#include "dmove.h"



void MainSimulator::registerNewAtomics()
{
	// Register Built-in models
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Queue>() , "Queue" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Generator>() , "Generator" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<CPU>() , "CPU" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Transducer>() , "Transducer" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Trafico>() , "Trafico" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Kattack>() , "Kattack" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Kmove>() , "Kmove" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Kdecision>() , "Kdecision" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Dattack>() , "Dattack" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Dmove>() , "Dmove" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Ddecision>() , "Ddecision" ) ;
}
