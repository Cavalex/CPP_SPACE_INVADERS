#include <iostream>
#include <string>
#include <conio.h>
#include <vector>

#include "GlobalSettings.cpp"

#ifndef BARRIER_H
#define BARRIER_H

using namespace std;

class Barrier : public Entity {
	public:
		Barrier(int, int, int, int, char, bool);
		Barrier();
		bool isAlive();
		void setLife(bool);
		void setSize(int);
		int getSize();
		
	private: 
		bool alive;
		int size;
		
};

#endif
