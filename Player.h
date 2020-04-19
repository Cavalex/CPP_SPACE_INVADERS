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
		Player(int, int, int, int, char, string, int, bool, int);
		Player();
		void action(); // o movimento e o disparo do jogador
		void shoot();
		bool isAlive();
		//int shootKey = playerControls[num-1][0];
		
	private: 
		int num;
		int score;
		string name;
		bool alive;
		
		//const int shootKey = playerControls[num-1][0];
		
};

#endif
