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
		void updateEnemyShots();
		void updatePlayerShots();
		void start();
		void menu();
		
		void checkCols();
		
		int numEnemies;
		int numPlayers;
		
		// Têm que ser públicas para evitar usar gets de arrays que podem complicar muito o código e
		// não poupam linhas, assim tbm fica mais fácil de ler
		Enemy enemies[50];
		
		Player players[4];
		//Shot shots[numShotsPP * numPlayers];
		Shot shots[400];
		Barrier barriers[100];
		
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
