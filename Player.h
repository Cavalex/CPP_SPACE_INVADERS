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
		Player(int, int, int, int, char, string, int, bool, int, int);
		Player();
		void action(); // o movimento e o disparo do jogador
		void shoot();
		bool isAlive();
		void gotHit();
		int getLives();
		string getName();
		void drawEntity();
		void drawOn(int, int, char);
		void moveTo(int, int);
		//int shootKey = playerControls[num-1][0];
		
	private: 
		int nave1[3] = { 62 ,206, 60};
		int drawing = 1;
		int lives;
		int num;
		int score;
		string name;
		bool alive;
		
		//const int shootKey = playerControls[num-1][0];
		
};

#endif
