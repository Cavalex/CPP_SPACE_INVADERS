#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <conio.h>
#include <unistd.h>
#include <ctime>
#include <vector>

#include "GlobalSettings.cpp"

#include "Carr_Guar.h"
#include "Enemy.h"
#include "Player.h"
#include "Shot.h"
#include "Timer.cpp"
#include "Barrier.cpp"

#ifndef GAME_H
#define GAME_H

class Game {
	public:
		Game();
		Game(int, int, bool);
		friend class Carr_Guar;
		void updatePlayers();
		void updateEnemies();
		void updateShots();
		void updatePlayerShots();
		void updateUI();
		void start();
		void menu();
		
		void resetMostValues();
		void resetVelocities();
		void checkCols();
		void checkGameOver();
		bool checkPlayersLives();
		
		bool playerLost;
		bool gameOver;
		int numEnemies;
		int numDeadEnemies;
		int numPlayers;
		bool hasBoss;
		
		// Têm que ser públicas para evitar usar gets de arrays que podem complicar muito o código e
		// não poupam linhas, assim tbm fica mais fácil de ler
		Enemy enemies[50];
		Player players[4];
		//Shot shots[numShotsPP * numPlayers];
		Shot shots[200];
		vector<Barrier> barriers;
		
	// não funcionam com protected, públicas it is
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
