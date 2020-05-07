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
		
		if(i <= numEnemies/2 - 1) enemies[i] = Enemy(4 + spaceBtEnemies*i, enemyYInit, 1, 1, 'X', 10, 0, true);
		else enemies[i] = Enemy(4 + spaceBtEnemies*(i - numEnemies/2), enemyYInit + enemyYDifference, 1, 1, 'X', 10, 0, true);
		i++;
		
		/*
		enemies1[i] = Enemy(4 + (spaceBtEnemies - 1)*i, enemyYInit, 0, 0, 'X', 10, 0, true);
		enemies2[i] = Enemy(4 + (spaceBtEnemies - 1)*i, enemyYInit + enemyYDifference, 0, 0, 'X', 10, 0, true);
		enemies3[i] = Enemy(4 + (spaceBtEnemies - 1)*i, enemyYInit + 2 * enemyYDifference, 0, 0, 'X', 10, 0, true);
		i++;
		*/
		
		/*
		int size = 9;
		char draw[9] = {' ', 219, ' ',
						219, 219, 219,
						' ', '|', ' '};
		*/
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
	
	// preencher shots[]
	for(int i = 0; i < numTotalShots; i++){
		shots[i] = Shot(-50, -50, 0, 0, ' ', 0, false, 0);
	}
	
	// game loop
	while(true){
    	
    	updatePlayerShots();
    	updateEnemyShots();
    	updateShots();
    	updateEnemies();
    	updatePlayers();
    	updateBarriers();
    	checkCols();
    	
    	// TESTE
    	int a = 0;
    	for(int i = 0; i < numTotalShots; i++){
			if(shots[i].isAlive()){
				a++;
			}
		}
		SetCursorPosition(0, 0);
		cout << "Alive Shots: " << a << " ";
		cout << "|| Can Enemy Shoot?: " << canShoot;
		if(!canShoot){ cout << " || UPDATED";}
		else{ cout << " ";}
		
		// O usleep() estava a causar erros no movimento, decidimos usar o sleep() portanto
		sleep(0.01);
    }
}

void Game::checkCols(){
	for(int i = 0; i < numEnemies; i++){
		for(int s = 0; s < 100; s++){
			// Estes dois fors s�o para dar loop a cada "bloco" do inimigo
			for(int ye = -enemies[i].getSizeY(); ye <= enemies[i].getSizeY(); ye++){
				for(int xe = -enemies[i].getSizeX(); xe <= enemies[i].getSizeX(); xe++){
					// Colis�essssssss
					if( ( ((enemies[i].getX() + xe) == (shots[s].getX() + shots[s].getSizeX() ))
					&&  ((enemies[i].getY() + ye) == (shots[s].getY() + shots[s].getSizeY() )) )
					&& (enemies[i].isAlive() && shots[s].isAlive()) ){
						//TESTE
						//SetCursorPosition(enemies[i].x, enemies[i].y);
						//cout << "MOR";
						// Mat�-los e apag�-los
						shots[s].setLife(false);
						enemies[i].setLife(false);
						shots[s].clearEntity();
						enemies[i].clearEntity();
					}
				}
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
		checkCols();
	}
}

void Game::updateBarriers(){
	for(int i = 0; i < numBarriers; i++){
		barriers[i].checkCol();
	}
}

void Game::updateEnemyShots(){
	int a = 1;
}

void Game::updatePlayerShots(){
	
	// Se algu�m disparar, criar o tiro no array
	for(int i = 0; i < numTotalShots; i++){
	//for(int i = 0; i < numShotsPP * numPlayers; i++){
		if(!(shots[i].isAlive())){
			for(int n = 0; n < numPlayers; n++){
				if(playerShot[n] == true && playerShotCD[n] <= 0){
					//shots[i] = Shot(playerShotX[n], playerShotY[n], 0, 0, '|', 1, true, 1);
					shots[i] = Shot(players[n].x, players[n].y, 0, 0, '|', 1, true, 1);
					playerShot[n] = false;
					playerShotCD[n] += shotCD;
				}
				else playerShot[n] = false;
			}
		}
	//}
	}
}

void Game::updateShots(){
	
	// Temos que atualizar aqui os tiros, se o fizermos na classe Shot arriscamo-nos
	// a ter um problema de recurs�o novamente, porque para atualizarmos o array
	// precisavamos de um "game", e o resto j� se sabe
	// Se calhar podemos resolver assim o problema do player
	
	// Mesma estrutura que o updateEnemies(), t�m que se mover todos ao mesmo tempo
	if (t2.getTimePassed()>=1/(shotVelocity)){
		
		// Tiros dos inimigos
		for(int i = 0; i < numEnemies; i++){
			for(int s = 0; s < numEnemies; s++){
				// Se o inimigo n�o tiver ningu�m em baixo dele:
				if(enemies[i].isAlive()){
					if(enemies[s].isAlive()){
						if (enemies[s].x == enemies[i].x){
							if(!(enemies[s].y > enemies[i].y)){
								canShoot = true;
							}
							else{
								canShoot = false;
								// TESTE
								/*
								SetCursorPosition(enemies[i].x, enemies[i].y);
								cout << "CANT";
								*/
								break;
							}
						}
					}
				}
				else{
					canShoot = false;
				}
			}
			if(canShoot){
				//int r = getRandomNumber(1, shotChance);
				// TESTE
				int r = 1;
				//SetCursorPosition(0, 1);
				//cout << "r: " << r << " ";
				if(r == 10){
					// TESTE
					/*
					SetCursorPosition(enemies[i].x, enemies[i].y);
					cout << "SHOT";
					*/
					for(int t = 0; t < numTotalShots; t++){
						if(!(shots[t].isAlive())){
							shots[t] = Shot(enemies[i].x + enemies[i].getSizeX(), enemies[i].y + enemies[i].getSizeY() + 1, 0, 0, '0', 1, true, -1);
							break;
						}
					}
				}
			}
			canShoot = true;
		}
		
		for(int i = 0; i < numPlayers; i++) if(!(playerShotCD[i]) <= 0) playerShotCD[i] -= 1;
		
		//TESTE
		SetCursorPosition(0, 1);
		cout << "P1 CD: " << playerShotCD[0] << " ";
		SetCursorPosition(j, 2);
		if(playerShot[0]){
			cout << "Shot!";
			j += 7;
		}
	
		// Update do movimento dos tiros
		for(int i = 0; i < numTotalShots; i++){
			if(shots[i].isAlive()){
				shots[i].move();
			}
		}
		
		// Ver colis�es
		for(int i = 0; i < numTotalShots; i++){
			if(shots[i].isAlive()){
				shots[i].checkCol();
			}
		}
		checkCols();
		t2.restart();
	}
}

