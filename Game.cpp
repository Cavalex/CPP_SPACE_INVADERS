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
		
		// 20 inimigos 
		
		/*
		enemies1[i] = Enemy(4 + (spaceBtEnemies - 1)*i, enemyYInit, 0, 0, 'X', 10, 0, true);
		enemies2[i] = Enemy(4 + (spaceBtEnemies - 1)*i, enemyYInit + enemyYDifference, 0, 0, 'X', 10, 0, true);
		enemies3[i] = Enemy(4 + (spaceBtEnemies - 1)*i, enemyYInit + 2 * enemyYDifference, 0, 0, 'X', 10, 0, true);
		i++;
		*/
		
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
	
	// preencher shots[]
	for(int i = 0; i < numTotalShots; i++){
		shots[i] = Shot(-50, -50, 0, 0, ' ', 0, false, 0);
	}
	
	// game loop
	while(true){
		srand(time(NULL));
    	
    	// Isto era para testar
    	//cout << players[0].x;
    	//sleep(100);
    	updatePlayerShots();
    	updateEnemyShots();
    	updateShots();
    	updateEnemies();
    	updatePlayers();
    	updateBarriers();
    	checkCols();
    	
    	
    	int a = 0;
    	for(int i = 0; i < numTotalShots; i++){
			if(shots[i].isAlive()){
				a++;
			}
		}
		SetCursorPosition(0, 0);
		cout << "Alive Shots: " << a;
		
		// O usleep() estava a causar erros no movimento, decidimos usar o sleep() portanto
		//sleep(0.01);
    }
}

void Game::checkCols(){
	for(int i = 0; i < numEnemies; i++){
		for(int s = 0; s < 100; s++){
			// Estes dois fors são para dar loop a cada "bloco" do inimigo
			for(int ye = -enemies[i].getSizeY(); ye <= enemies[i].getSizeY(); ye++){
				for(int xe = -enemies[i].getSizeX(); xe <= enemies[i].getSizeX(); xe++){
					// Colisõessssssss
					if( ( ((enemies[i].getX() + xe) == (shots[s].getX() + shots[s].getSizeX() ))
					&&  ((enemies[i].getY() + ye) == (shots[s].getY() + shots[s].getSizeY() )) )
					&& (enemies[i].isAlive() && shots[s].isAlive()) ){
						// Matá-los e apagá-los
						shots[s].setLife(false);
						enemies[i].setLife(false);
						shots[s].clearEntity();
						enemies[i].clearEntity();
					}
					
					// Colisões antigas
					/*
					if( ( ((enemies[i].getX() + enemies[i].getSizeX()) == (shots[s].getX() + shots[s].getSizeX() ))
					&&  ((enemies[i].getY() + enemies[i].getSizeY()) == (shots[s].getY() + shots[s].getSizeY() )) )
					&& (enemies[i].isAlive() && shots[s].isAlive()) ){
						shots[s].setLife(false);
						enemies[i].setLife(false);
						shots[s].clearEntity();
						enemies[i].clearEntity();
					}
					*/
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

void Game::updateEnemyShots(){
	int a = 1;
}

void Game::updatePlayerShots(){
	
	// Se alguém disparar, criar o tiro no array
	for(int i = 0; i < numTotalShots; i++){
	//for(int i = 0; i < numShotsPP * numPlayers; i++){
		if(!(shots[i].isAlive())){
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
}

void Game::updateShots(){
	
	// Temos que atualizar aqui os tiros, se o fizermos na classe Shot arriscamo-nos
	// a ter um problema de recursão novamente, porque para atualizarmos o array
	// precisavamos de um "game", e o resto já se sabe
	// Se calhar podemos resolver assim o problema do player
	
	// Mesma estrutura que o updateEnemies(), têm que se mover todos ao mesmo tempo
	if (t2.getTimePassed()>=1/(shotVelocity)){
		
		// Tiros dos inimigos
		
		for(int i = 0; i < numEnemies; i++){
			for(int s = 0; s < numEnemies; s++){
				// Se o inimigo não tiver ninguém em baixo dele:
				
				if ( canShoot && (!(enemies[i].x == enemies[s].x)) || (
				!(  (enemies[i].y == enemies[s].y + enemyYDifference)
				|| (enemies[i].y == enemies[s].y + 2*enemyYDifference)
				|| (enemies[i].y == enemies[s].y + 3*enemyYDifference)
				|| (enemies[i].y == enemies[s].y + 4*enemyYDifference) )
				) && enemies[s].isAlive() && enemies[i].isAlive())
					canShoot = true;
				else canShoot = false;
				/*
				if(enemies[s].isAlive() && enemies[i].isAlive())
				{
					canShoot = true;
				}
				else canShoot = false;
				*/
			}
			if(canShoot){
				int r = getRandomNumber(1, shotChance);
				//int r = 1;
				if(r == 1){
					for(int t = 0; (t < numTotalShots && canShoot); t++){
						if(!(shots[t].isAlive())){
							shots[t] = Shot(enemies[i].x + enemies[i].getSizeX(), enemies[i].y + enemies[i].getSizeY() + 1, 0, 0, '0', 1, true, -1);
							canShoot = false;
							break;
						}
					}
				}
			}
			canShoot = true;
		}
		
		for(int i = 0; i < numPlayers; i++) playerShotCD[i] -= 1;

		for(int i = 0; i < numTotalShots; i++){
			if(shots[i].isAlive()){
				shots[i].move();
			}
		}

		for(int i = 0; i < numTotalShots; i++){
			if(shots[i].isAlive()){
				shots[i].checkCol();
			}
		}
		checkCols();
		t2.restart();
	}
	
	/*
	if(r == 1){
		if(ignore5 == false){
			for(int i = 0; i < enemies5.size(); i++){
				if(!(enemies5[i].isAlive()) && continue5 == false){
					ignore5 = true;
				}
				else {
					ignore5 = false;
					continue5 = true;
				}
			}
			continue5 = false;
		}
		
		if(ignore4 == false){
			for(int i = 0; i < enemies4.size(), i++){
				if(!(enemies4[i].isAlive()) && continue4 == false){
					ignore4 = true;
				}
				else {
					ignore4 = false;
					continue4 = true;
				}
			}
			continue4 = false;
		}
	
		if(ignore3 == false){
			for(int i = 0; i < enemies3.size(), i++){
				if(!(enemies3[i].isAlive()) && continue3 == false){
					ignore3 = true;
				}
				else {
					ignore3 = false;
					continue3 = false;
				}
			}
			continue3 = false;
		}
		
		if(ignore2 == false){
			for(int i = 0; i < enemies2.size(), i++){
				if(!(enemies2[i].isAlive()) && continue2 == false){
					ignore2 = true;
				}
				else {
					ignore2 = false;
					continue2 = false;
				}
			}
			continue2 = false;
		}
	}
	*/
}









