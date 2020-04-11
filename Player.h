#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <conio.h>

#include "GlobalSettings.cpp"
#include "Game.h"

#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

class Player : public Entity {
	public:
		Player(int, int, int, int, char, string, int, bool, int);
		Player();
		void action(Game&);
		//void shoot(int, int, char, int);
		bool isAlive();
		
	private: 
		int num;
		int score;
		string name;
		bool alive;
		
};

#endif
