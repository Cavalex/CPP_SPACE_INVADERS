#include <iostream>
#include <string>
#include <conio.h>

#include "GlobalSettings.cpp"

#ifndef BARRIER_H
#define BARRIER_H

using namespace std;

class Barrier : public Entity {
	public:
		Barrier(int, int, int, int, char, bool);
		Barrier();
		void checkCol();
		
	private: 
		bool alive;
		
};

#endif
