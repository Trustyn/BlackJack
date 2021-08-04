/************************************************************************
* Class: Random
*
* Constructors:	
*	Random()
*		seeds the random and returns rand() % n(whats passed in.)
*
* Mutators:
*
* Methods:
*
*************************************************************************/
#ifndef RANDOM_H
#define RANDOM_H
#include <cstdlib>
#include <ctime>

class Random
{ 
	public:  
		Random()
		{ 
			srand(static_cast<unsigned> (time(0)));
		}
		unsigned int GetRandom(int n) const 
		{ 
			return rand() % n; 
		}
};
#endif