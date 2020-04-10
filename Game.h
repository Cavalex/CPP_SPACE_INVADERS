#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <conio.h>
#include <unistd.h>
#include <ctime>

#include "GlobalSettings.cpp"

#include "Enemy.h"
#include "Player.h"
#include "Shot.h"
#include "Timer.cpp"

#ifndef GAME_H
#define GAME_H

class Game {
	public:
		Game(int, int);
		void updatePlayers();
		void updateEnemies();
		void updateShots();
		void updateBarriers();
		void start();
		void menu();
		
	private:
		Enemy enemies[100];
		Player players[4];
		Shot shots[5];
		
		int numEnemies;
		int numPlayers;
};

#endif
