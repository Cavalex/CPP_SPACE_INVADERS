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
#include "Shot.h"

using namespace std;

// O timer para o clock (o movimento dos inimigos)
Timer t;
Timer t2;

Game::Game(int n, int p){
	this->numEnemies = n;
	this->numPlayers = p;
}

void Game::start(){
	
	//menu();
	
	// preencher enemies[]
	int i = 0;
	while (i < numEnemies){
		
		/*
		if(i <= numEnemies/2 - 1) enemies[i] = Enemy(4 + spaceBtEnemies*i, 5, 1, 1, 'X', 10, 0, true);
		else enemies[i] = Enemy(4 + spaceBtEnemies*(i - numEnemies/2), 9, 1, 1, 'X', 10, 0, true);
		i++;
		*/
		
		enemies[i] = Enemy(4 + (spaceBtEnemies - 1)*i, 5, 0, 0, 'X', 10, 0, true);
		i++;
		
		int size = 9;
		char draw[9] = {' ', 219, ' ',
						219, 219, 219,
						' ', '|', ' '};
		
		/*
		if(i <= numEnemies/2 - 1){
			// Queremos criar 10 inimigos 3x3, ou seja 90 inimigos
			for(int z = 0; z < size; z++){
				enemies[i] = Enemy((4 + (z%(size/3)) + spaceBtEnemies*((i/size))), 4 + size/3, 0, 0, draw[z], 10, 0, true);
				i++;
			}
		}
		
		else {
			// Aqui criamos os outros 10 inimigos, mais 90
			for(int z = 0; z < size; z++){
				enemies[i] = Enemy((4 + (z%(size/3)) + spaceBtEnemies*((i/size))), 9 + size/3, 0, 0, draw[z], 10, 0, true);
				i++;
			}
		}
		*/
		
		/*
		if(i <= numEnemies/2 - 1){
			// Inimigos 3x3
			for(int z = 0; z < size; z++){
				if(z < size/3) enemies[i] = Enemy(4 + spaceBtEnemies*i + ((z % 3) + 1), 5 + size/3, 0, 0, draw[z], 10, 0, true);
			}
		}
		else {
			// Inimigos 3x3
			for(int z = 0; z < size; z++){
				if(z < size/3) enemies[i] = Enemy(4 + spaceBtEnemies*(i - numEnemies/2) + ((z % 3) + 1), 9 + size/3, 0, 0, draw[z], 10, 0, true);
			}	
		}
		*/
	}
	
	// preencher players[]
	for(int i = 1; i <= numPlayers; i++){
		players[i-1] = Player(WIDTH / 2, HEIGHT - 2 - 2 * i, 1, 0, 'O', playersN[i], 0, true, i);
		players[i-1].drawEntity(); // Só para não ficarem invisiveis no início
	}
	
	// preencher barriers[]
	for(int i = 0; i < numBarriers; i++){
		barriers[i] = Barrier(5 + 9*i, HEIGHT - 8, 1, 1, (char)barrierCharInt, true);
		barriers[i].drawEntity(); // Só para não ficarem invisiveis no início
	}
	
	// game loop
	while(true){
    	
    	// Isto era para testar
    	//cout << players[0].x;
    	//sleep(100);
    	updateShots();
    	updateEnemies();
    	updatePlayers();
    	updateBarriers();
    	checkCols();
		
		// O usleep() estava a causar erros no movimento, decidimos usar o sleep() portanto
		sleep(0.01);
    }
}

void Game::checkCols(){
	for(int i = 0; i < numEnemies; i++){
		for(int s = 0; s < 100; s++){
			if( (((enemies[i].getX() + enemies[i].getSizeX()) == (shots[s].getX() + shots[s].getSizeX()))
			&&  ((enemies[i].getY() + enemies[i].getSizeY()) == (shots[s].getY() + shots[s].getSizeY())) )
			&& (enemies[i].isAlive() && shots[s].isALive())){
				shots[s].setLife(false);
				enemies[i].setLife(false);
				shots[s].clearEntity();
				enemies[i].clearEntity();
			}
		}
	}
}

void Game::updatePlayers(){
	for(int i = 0; i < numPlayers; i++){
		if (players[i].isAlive() == true) players[i].action();
	}
}

void Game::updateEnemies(){
	
	int checkedCol = false;
	
	if (t.getTimePassed()>=1/(enemyVelocity)){
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
				if (i == numEnemies) break;
			}
		}
		// Se algum deles colidir com a barreira então descem todos ao mesmo tempo
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
		checkCols();
	}
}

void Game::updateBarriers(){
	for(int i = 0; i < numBarriers; i++){
		barriers[i].checkCol();
	}
}

void Game::updateShots(){
	
	// Se alguém disparar, criar o tiro no array
	for(int i = 0; i < numTotalShots; i++){
	//for(int i = 0; i < numShotsPP * numPlayers; i++){
		if(!(shots[i].isALive())){
			for(int n = 0; n < numPlayers; n++){
				if(playerShot[n] == true && playerShotCD[n] <= 0){
					shots[i] = Shot(playerShotX[n], playerShotY[n], 0, 0, '|', 1, true, 1);
					playerShot[n] = false;
					playerShotCD[n] += shotCD;
				}
			}
		}
	//}
	}
	
	// Temos que atualizar aqui os tiros, se o fizermos na classe Shot arriscamo-nos
	// a ter um problema de recursão novamente, porque para atualizarmos o array
	// precisavamos de um "game", e o resto já se sabe
	// Se calhar podemos resolver assim o problema do player
	
	// Mesma estrutura que o updateEnemies(), têm que se mover todos ao mesmo tempo
	if (t2.getTimePassed()>=1/(shotVelocity)){
		
		for(int i = 0; i < numPlayers; i++) playerShotCD[i] -= 1;
		
		for(int i = 0; i < numTotalShots; i++){
			if(shots[i].isALive()){
				shots[i].move();
			}
		}

		for(int i = 0; i < numTotalShots; i++){
			if(shots[i].isALive()){
				shots[i].checkCol();
			}
		}
		checkCols();
		t2.restart();
	}
}

