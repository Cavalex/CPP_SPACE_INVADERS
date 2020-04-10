#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <conio.h>

#include "GlobalSettings.cpp"

#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

class Player : public Entity {
	public:
		Player(int, int, int, int, char, string, int, bool);
		Player();
		bool moveAction();
		void shoot(int, int, char, int);
		bool isAlive();
		
	private: 
		int score;
		string name;
		bool alive;
		
};

#endif
