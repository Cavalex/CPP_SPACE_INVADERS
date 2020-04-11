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
#include "Player.cpp"
#include "Shot.h"
#include "Timer.cpp"
#include "Barrier.cpp"

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
		void playerShoot();
		
		int numEnemies;
		int numPlayers;
		
		Enemy enemies[100];
		Player players[4];
		//Shot shots[numShotsPP * numPlayers];
		Shot shots[1000];
		Barrier barriers[100];
		
	/*
	protected:
		// É necessário um construtor vazio para preencher os arrays
		Enemy enemies[100];
		Player players[4];
		Shot shots[numShotsPP * numPlayers];
		Barrier barriers[100];
		
		int numEnemies;
		int numPlayers;
	*/
};

#endif
