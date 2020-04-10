#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <conio.h>

#include "GlobalSettings.cpp"

#ifndef SHOT_H
#define SHOT_H

class Shot : public Entity {
	public:
		Shot(int, int, int, int, char, int);
		Shot();
		
	private: 
		int dmg;
};

#endif
