#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <conio.h>
#include <algorithm>

#include "GlobalSettings.cpp"
#include "Game.h"
#include "Timer.cpp"
#include "Enemy.h"
#include "Shot.h"

using namespace std;

// O timer para o clock (o movimento dos inimigos)
Timer t;
Timer t2;
Timer scoreT;

Game::Game(int n, int p){
	this->numEnemies = n;
	this->numPlayers = p;
	this->numDeadEnemies = 0;
	this->gameOver = false;
	this->playerLost = false;
}

Game::Game(){
	this->numEnemies = 20;
	this->numPlayers = 1;
	this->numDeadEnemies = 0;
	this->gameOver = false;
	this->playerLost = false;
}

void Game::start(){
	
	scoreT;
	scoreT.restart();
	
	// preencher enemies[]
	int i = 0;
	while (i < numEnemies){
		
		gameState = 1;
		
		// Nome do jogador
		
		
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
		players[i-1] = Player(WIDTH / 2, HEIGHT - 2 - 2 * i, 1, 0, 'O', playersN[i-1], 0, true, i, playerLives);
		players[i-1].drawEntity(); // Só para não ficarem invisiveis no início
	}
	
	// preencher vetor barriers
	for(int i = 0; i < numBarriers; i++){
		for(int z2 = 0; z2 < 3; z2++){
			for(int z = 0; z < 3; z++){
				barriers.push_back(Barrier(6 + z + (9*i), barrierMaxHeight + z2, 0, 0, (char)barrierCharInt, true));
			}
		}
		
		// Barreiras antigas
		/*
		barriers[i] = Barrier(6 + 9*i, HEIGHT - 8, 1, 1, (char)barrierCharInt, true);
		barriers[i].drawEntity(); // Só para não ficarem invisiveis no início
		*/
	}
	
	// desenhar barriers
	for(int i = 0; i < barriers.size(); i++) barriers[i].drawEntity();

	
	// preencher shots[]
	for(int i = 0; i < numTotalShots; i++){
		shots[i] = Shot(-50, -50, 0, 0, ' ', 0, false, 0);
	}
	
	// game loop
	while(!gameOver){
    	
    	if(!gameOver) updatePlayerShots();
    	if(!gameOver) updateEnemyShots();
    	if(!gameOver) updateShots();
    	if(!gameOver) updateEnemies();
    	if(!gameOver) updatePlayers();
    	if(!gameOver) checkCols();
    	if(!gameOver) checkGameOver();
    	if(!gameOver) updateUI();
    	
    	//
		// TESTE
    	int a = 0;
    	for(int i = 0; i < numTotalShots; i++){
			if(shots[i].isAlive()){
				a++;
			}
		}
		SetCursorPosition(0, 0);
		cout << "Alive Shots: " << a << " ";
		cout << "|| Can Enemy Shoot?: " << canShoot << " ";
		cout << "|| Lives: " << players[0].getLives() << " ";
		
		// O usleep() estava a causar erros no movimento, portanto decidimos usar o sleep()
		sleep(0.01);
    }
    
    // Quando o jogo acabar:
    // Se todos os jogadores estão mortos:
    if(!checkPlayersLives() || playerLost){
    	//TESTE
		SetCursorPosition(WIDTH/2 - 7, HEIGHT/2 - 2);
    	cout << "PERDESTE";
    	
    	resetVelocities();
    	scoreT.restart();
    	velBonus = initialBonus;
    	shotChance = initialShotChance;
    	// Se perder, recomeçar o jogo
    	gameState = 0;
		// Reiniciar Score
		score = 0;
    	// Repetir jogo (todo)
	}
	else{ // Se acabou o jogo, mas há jogadores vivos:
		//TESTE
		SetCursorPosition(WIDTH/2 - 7, HEIGHT/2 - 2);
		cout << "GANHASTE";
		
		gameState += 1;
		resetVelocities();
		scoreT.restart();
		velBonus = initialBonus;
		shotChance = initialShotChance;
		// Score aumenta com o tempo
		// Tabela de score
		// Guardar o score, o nome e o estado (HS e comparaçoes dentro da funçao do Marco)
	}
}

void Game::updateUI(){
	// UI
	SetCursorPosition(6, 1);
	cout << "Name: " << players[0].getName() << " ";
	
	SetCursorPosition(WIDTH - 16, 1);
	cout << "Time: " << scoreT.getTimePassed() << " ";
}

void Game::resetVelocities(){
	enemyVelocity = initialEnemyVelocity;
	shotVelocity = initialShotVelocity;
}

void Game::checkGameOver(){
	if(numDeadEnemies >= numEnemies) gameOver = true;
	checkPlayersLives();
}

bool Game::checkPlayersLives(){
	bool allDead = true;
	for(int i = 0; i < numPlayers; i++){
		if(!(players[i].isAlive())) allDead = true;
		else{
			allDead = false;
			break;
		}
	}
	if(allDead){
		gameOver = true;
		playerLost = true;
		return false;
	}
	return true;
}

void Game::checkCols(){
	
	// Colisões Inimigos-Balas
	for(int i = 0; i < numEnemies; i++){
		for(int s = 0; s < numTotalShots; s++){ // /2 para não ter de calcular tantos tiros
			// Estes dois fors são para dar loop a cada "bloco" do inimigo
			for(int ye = -enemies[i].getSizeY(); ye <= enemies[i].getSizeY(); ye++){
				for(int xe = -enemies[i].getSizeX(); xe <= enemies[i].getSizeX(); xe++){
					// Colisõessssssss
					if( ( ((enemies[i].getX() + xe) == (shots[s].getX() + shots[s].getSizeX() ))
					&&  ((enemies[i].getY() + ye) == (shots[s].getY() + shots[s].getSizeY() )) )
					&& (enemies[i].isAlive() && shots[s].isAlive()) ){
						//TESTE
						//SetCursorPosition(enemies[i].x, enemies[i].y);
						//cout << "MOR";
						// Matá-los e apagá-los
						shots[s].setLife(false);
						enemies[i].setLife(false);
						shots[s].clearEntity();
						enemies[i].clearEntity();
						numDeadEnemies += 1;
					}
				}
			}
		}
	}
	
	// Colisões Jogador-Balas
	for(int i = 0; i < numPlayers; i++){
		for(int s = 0; s < numTotalShots; s++){
			// Estes dois fors são para dar loop a cada "bloco" do jogador
			for(int ye = -players[i].getSizeY(); ye <= players[i].getSizeY(); ye++){
				for(int xe = -players[i].getSizeX(); xe <= players[i].getSizeX(); xe++){
					// Colisõessssssss
					if( ( ((players[i].getX() + xe) == (shots[s].getX() + shots[s].getSizeX() ))
					&&  ((players[i].getY() + ye) == (shots[s].getY() + shots[s].getSizeY() )) )
					&& (players[i].isAlive() && shots[s].isAlive()) ){
						//TESTE
						//SetCursorPosition(enemies[i].x, enemies[i].y);
						//cout << "MOR";
						// Matá-los e apagá-los
						shots[s].setLife(false);
						players[i].gotHit();
						shots[s].clearEntity();
						players[i].drawEntity();
					}
				}
			}
		}
	}
	
	// (numBarriers * barrierAverageSize)
	// Colisões Barreiras-Balas;
	for(int i = 0; i < (numBarriers * barrierAverageSize); i++){
		for(int s = 0; s < numTotalShots; s++){ // /2 para não ter de calcular tantos tiros
			// Estes dois fors são para dar loop a cada "bloco" do inimigo
			for(int ye = -barriers[i].getSizeY(); ye <= barriers[i].getSizeY(); ye++){
				for(int xe = -barriers[i].getSizeX(); xe <= barriers[i].getSizeX(); xe++){
					// Colisõessssssss
					if( ( ((barriers[i].getX() + xe) == (shots[s].getX() + shots[s].getSizeX() ))
					&&  ((barriers[i].getY() + ye) == (shots[s].getY() + shots[s].getSizeY() )) )
					&& (barriers[i].isAlive() && shots[s].isAlive()) ){
						//TESTE
						//SetCursorPosition(enemies[i].x, enemies[i].y);
						//cout << "MOR";
						// Matá-los e apagá-los
						shots[s].setLife(false);
						barriers[i].setLife(false);
						shots[s].clearEntity();
						barriers[i].clearEntity();
					}
				}
			}
		}
	}
	
	// Colisões Balas-Balas
	for(int i = 0; i < numTotalShots; i++){
		for(int s = 0; s < numTotalShots; s++){
			if((shots[i].getX() == shots[s].getX()) &&
			(shots[i].getY() == shots[s].getY()) &&
			shots[i].isAlive() &&
			shots[s].isAlive() && s != i){
				shots[i].setLife(false);
				shots[s].setLife(false);
				shots[i].clearEntity();
			}
		}
	}
	
	// Colisões Inimigos-Barreiras
	for(int i = 0; i < numEnemies; i++){
		for(int s = 0; s < barriers.size(); s++){ // /2 para não ter de calcular tantos tiros
			// Estes dois fors são para dar loop a cada "bloco" do inimigo
			for(int ye = -enemies[i].getSizeY(); ye <= enemies[i].getSizeY(); ye++){
				for(int xe = -enemies[i].getSizeX(); xe <= enemies[i].getSizeX(); xe++){
					// Colisõessssssss
					if( ( ((enemies[i].getX() + xe) == (barriers[s].getX() + barriers[s].getSizeX() ))
					&&  ((enemies[i].getY() + ye) == (barriers[s].getY() + barriers[s].getSizeY() )) )
					&& (enemies[i].isAlive() && barriers[s].isAlive()) ){
						// Se colidirem o jogo acaba:
						gameOver = true;
						playerLost = true;
						barriers[s].setLife(false);
						enemies[i].setLife(false);
						barriers[s].clearEntity();
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
		// Resetar o wasAllDrop
		if(wasAllDrop == 2 || wasAllDrop == 1){
			wasAllDrop -= 1;
		}
		// Se algum deles colidir com a barreira então descem todos ao mesmo tempo
		if (allDrop && wasAllDrop == 0){
			way = -way;
			wasAllDrop = 2;
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
	
	// Aumento da velocidade dos inimigos
	if(numDeadEnemies == numEnemies - (numEnemies / 2) && velBonus == 1){
		enemyVelocity += 5;
		velBonus += 1;
	}
	if(numDeadEnemies == numEnemies - (numEnemies / 4) && velBonus == 2){
		enemyVelocity += 5;
		velBonus += 1;
	}
	if(numDeadEnemies == numEnemies - (numEnemies / 10) && velBonus == 3){
		enemyVelocity += 10;
		velBonus += 1;
	}
	if(numDeadEnemies == numEnemies - 1 && velBonus == 4){
		enemyVelocity += 30;
		velBonus += 1;
	}
}

void Game::updateEnemyShots(){
	int a = 1;
}

void Game::updatePlayerShots(){
	
	// Se alguém disparar, criar o tiro no array
	for(int i = 0; i < numTotalShots; i++){
		if(!(shots[i].isAlive())){
			for(int n = 0; n < numPlayers; n++){
				if(playerShot[n] == true && playerShotCD[n] <= 0){
					//shots[i] = Shot(playerShotX[n], playerShotY[n], 0, 0, '|', 1, true, 1);
					shots[i] = Shot(players[n].x, players[n].y - 1, 0, 0, '|', 1, true, 1);
					playerShot[n] = false;
					playerShotCD[n] += shotCD;
				}
				else playerShot[n] = false;
			}
		}
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
				int r = getRandomNumber(1, shotChance);
				// TESTE
				//int r = 1;
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
		
		// Ver colisões com as paredes
		for(int i = 0; i < numTotalShots; i++){
			if(shots[i].isAlive()){
				shots[i].checkCol();
			}
		}
		checkCols();
		t2.restart();
	}
}

