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
	for(int i = 0; i < numEnemies; i++){
		if(i <= numEnemies/2 - 1) enemies[i] = Enemy(4 + spaceBtEnemies*i, 5, 1, 1, 'X', 10, 0, true);
		else enemies[i] = Enemy(4 + spaceBtEnemies*(i - numEnemies/2), 9, 1, 1, 'X', 10, 0, true);
	}
	
	// preencher players[]
	for(int i = 1; i <= numPlayers; i++){
		players[i-1] = Player(WIDTH / 2, HEIGHT - 2 - 2 * i, 1, 0, 'O', playersN[i], 0, true, i);
		players[i-1].drawEntity(); // S� para n�o ficarem invisiveis no in�cio
	}
	
	// preencher barriers[]
	for(int i = 0; i < numBarriers; i++){
		barriers[i] = Barrier(5 + 9*i, HEIGHT - 8, 1, 1, (char)barrierCharInt, true);
		barriers[i].drawEntity(); // S� para n�o ficarem invisiveis no in�cio
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
		
		// O usleep() estava a causar erros no movimento, decidimos usar o sleep() portanto
		sleep(0.01);
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
			// Para ver se algum inimigo colidiu com a parede antes de mov�-los
			// Da� o numEnemies*2, para fazer tudo no mesmo for
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
		// Se algum deles colidir com a barreira ent�o descem todos ao mesmo tempo
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

void Game::updateBarriers(){
	for(int i = 0; i < numBarriers; i++){
		barriers[i].checkCol();
	}
}

void Game::updateShots(){
	
	// Se algu�m disparar, criar o tiro no array
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
	// a ter um problema de recurs�o novamente, porque para atualizarmos o array
	// precisavamos de um "game", e o resto j� se sabe
	// Se calhar podemos resolver assim o problema do player
	
	// Mesma estrutura que o updateEnemies(), t�m que se mover todos ao mesmo tempo
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
		t2.restart();
	}
}

