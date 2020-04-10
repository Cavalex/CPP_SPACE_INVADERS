#include <iostream>
#include <string>
#include <conio.h>

#include "GlobalSettings.cpp"

#ifndef ENTITY_H
#define ENTITY_H

using namespace std;

class Barrier : public Entity {
	public:
		Player(int, int, int, int, char, bool);
		
	private: 
		bool isAlive;
		
};

#endif
