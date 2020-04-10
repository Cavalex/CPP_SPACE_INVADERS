#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <conio.h>

#include "GlobalSettings.cpp"
#include "Game.h"
#include "Timer.cpp"
#include "Enemy.h"

using namespace std;

Timer t;

Game::Game(int n, int p){
	this->numEnemies = n;
	this->numPlayers = p;
}

void Game::start(){
	
	// fill enemies[]
	for(int i = 0; i < numEnemies; i++){
		if(i <= numEnemies/2 - 1) enemies[i] = Enemy(4 + spaceBtEnemies*i, 5, 1, 1, 'X', 10, 0, true);
		else enemies[i] = Enemy(4 + spaceBtEnemies*(i - numEnemies/2), 9, 1, 1, 'X', 10, 0, true);
	}
	
	// fill players[]
	for(int i = 0; i < numPlayers; i++){
		players[i] = Player(WIDTH / 2, HEIGHT - 2 + 2 * i, 1, 0, 'O', "Cavalex", 0, true);
		players[i].drawEntity(); // Só para não ficar invisível no início
	}
	
	while(true){
    	
    	updateEnemies();
    	updatePlayers();
		
		usleep(5000);
    }
}

void Game::updatePlayers(){
	for(int i = 0; i < numPlayers; i++){
		if (players[i].isAlive() == true) players[i].moveAction();
	}
}


void Game::updateEnemies(){
	
	int checkedCol = false;
	
	if (t.getTimePassed()>=1/(globalVelocity)){
		for(int i = 0; i < numEnemies*2; i++){
			// Para ver se algum inimigo colidiu com a parede antes de movê-los
			// Daí o numEnemies*2, para fazer tudo no mesmo for
			if (!(checkedCol)){
				if(enemies[i].collidedWall()){
					allDrop = true;
					break;
				}
				if(i == numEnemies - 1){
					checkedCol = true;
					i = -1;
				}
			}
			else{
				if (enemies[i].isAlive() == true){
					enemies[i].moveHorizontally();
				}	
			}
		}
		if (allDrop){
			way = -way;
			for(int i = 0; i < numEnemies; i++){
				if (enemies[i].isAlive() == true){
				enemies[i].moveVertically();
				}	
			}
			allDrop = false;
		}
		t.restart();
	}
}

/*
void Game::updateBarriers(){
	for(int i = 0; i < numPlayers; i++){
		players[i].moveAction();
	}
}
*/
