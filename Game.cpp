#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <conio.h>
#include <algorithm>

#include "HS.h"
#include "GlobalSettings.cpp"
#include "Game.h"
#include "Timer.cpp"
#include "Enemy.h"
#include "Shot.h"
#include "story.h"

using namespace std;

// Para criarmos a história
Story story;

// Os timers para os movimentos dos inimigos e dos jogadores
Timer t;
Timer t2;

Game::Game(int n, int p, bool b = false){
	this->numEnemies = n;
	this->numPlayers = p;
	this->numDeadEnemies = 0;
	this->gameOver = false;
	this->playerLost = false;
	this->hasBoss = b;
}

Game::Game(){
	this->numEnemies = 20;
	this->numPlayers = 1;
	this->numDeadEnemies = 0;
	this->gameOver = false;
	this->playerLost = false;
	this->hasBoss = false;
}

void Game::start(){
	
	scoreT;
	scoreT.restart();
	
	// preencher enemies[]
	int i = 0;
	if(!hasBoss){
		while (i < numEnemies){
			
			if(numEnemies == 20){
				if(i <= 9) enemies[i] = Enemy(4 + spaceBtEnemies*i, enemyYInit, 1, 1, 'X', 10, 0, true, 1);
				else enemies[i] = Enemy(4 + spaceBtEnemies*(i - numEnemies/2), enemyYInit + enemyYDifference, 1, 1, 'X', 10, 0, true, 2);
				i++;
			}
			
			if(numEnemies == 30){
				if(i <= 9) enemies[i] = Enemy(4 + spaceBtEnemies*i, enemyYInit, 1, 1, 'X', 10, 0, true, 1);
				else if(i >= 10 && i <= 19) enemies[i] = Enemy(4 + spaceBtEnemies*(i - 10), enemyYInit + enemyYDifference, 1, 1, 'X', 10, 0, true, 2);
				else enemies[i] = Enemy(4 + spaceBtEnemies*(i - 20), enemyYInit + 2 * enemyYDifference, 1, 1, 'X', 10, 0, true, 3);
				i++;
			}
			
			if(numEnemies == 40){
				if(i <= 9) enemies[i] = Enemy(4 + spaceBtEnemies*i, enemyYInit, 1, 1, 'X', 10, 0, true, 1);
				else if(i >= 10 && i <= 19) enemies[i] = Enemy(4 + spaceBtEnemies*(i - 10), enemyYInit + enemyYDifference, 1, 1, 'X', 10, 0, true, 2);
				else if(i >= 20 && i <= 29) enemies[i] = Enemy(4 + spaceBtEnemies*(i - 20), enemyYInit + 2 * enemyYDifference, 1, 1, 'X', 10, 0, true, 3);
				else enemies[i] = Enemy(4 + spaceBtEnemies*(i - 30), enemyYInit + 3 * enemyYDifference, 1, 1, 'X', 10, 0, true, 4);
				i++;
			}
			
			/*
			enemies1[i] = Enemy(4 + (spaceBtEnemies - 1)*i, enemyYInit, 0, 0, 'X', 10, 0, true);
			enemies2[i] = Enemy(4 + (spaceBtEnemies - 1)*i, enemyYInit + enemyYDifference, 0, 0, 'X', 10, 0, true);
			enemies3[i] = Enemy(4 + (spaceBtEnemies - 1)*i, enemyYInit + 2 * enemyYDifference, 0, 0, 'X', 10, 0, true);
			i++;
			*/
		}
	}
	else{
		//enemies[i] = Boss(12, 10, 'X', 10, 0, true, 10);
		enemies[i] = Enemy(25, 7, 15, 3, 'X', 10, 0, true, 5);
		enemyVelocity = 6;
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
    	if(!gameOver) updateShots();
    	if(!gameOver) updateEnemies();
    	if(!gameOver) updatePlayers();
    	if(returned){ for(int i = 0; i < numBarriers * barrierAverageSize; i++) if(barriers[i].isAlive()) barriers[i].drawEntity(); returned = false; players[0].drawEntity(); } // Se continuar o jogo desenhar as barreiras
    	if(leftGame){ resetMostValues(); scoreT.restart(); break; } // Se o jogador sair do jogo
    	if(!gameOver) checkCols();
    	if(!gameOver) checkGameOver();
    	updateUI();
    	
    	if(hasBoss && bossHP <= 0){
    		enemies[0].setLife(false);
    		gameOver = true;
		}
    	
    	//
		// TESTE
		/*
    	int a = 0;
    	for(int i = 0; i < numTotalShots; i++){
			if(shots[i].isAlive()){
				a++;
			}
		}
		int b = 0;
		for(int i = 0; i < numEnemies; i++){
			if(enemies[i].isAlive()){
				b++;
			}
		}
		SetCursorPosition(0, 0);
		cout << "Alive Shots: " << a << " ";
		cout << "|| Lives: " << players[0].getLives() << " ";
		cout << "|| Enemies: " << b << " ";
		cout << "|| BossHP: " << bossHP << " ";
		cout << "|| Boss Alive: " << enemies[0].isAlive() << " ";
		cout << "|| PlayerLost: " << playerLost << " ";
		*/
		
		sleep(0.01);
    }
    
    // Quando o jogo acabar:
    HS scoreManager;
	if(!leftGame){
	    if((bossHP > 0 && hasBoss) || !checkPlayersLives() || playerLost){ // Se perdemos
	    	//TESTE
	    	/*
	    	SetCursorPosition(10, 10);
	    	cout << "PERDESTE";
			char botao;
			while(true){
		    if(kbhit){
		        botao = getch();
		    }else{
		        botao =' ';
		    }
		    if(botao==13)
		        break;
			}
			*/
			
	    	ClearScreen(bgChar);
	    	story.story_loss();
			ClearScreen(bgChar);
	    	
	    	// Se perder, recomeçar o jogo
	    	b.SetMemoria_de_jogo(0);
	    	if(b.GetMemoria_de_jogo() == 0){
	    		option = 0;
			}
			// Reiniciar Score
			scoreT.restart();
			resetMostValues();
			SetCursorPosition(WIDTH/2 - 15, HEIGHT/2 - 2);
	    	cout << "Now you're going to the menu";
	    	sleep(2.5);
		}
		else{ // Se ganhamos
		    //TESTE
		    /*
	    	SetCursorPosition(10, 10);
	    	cout << "GANHASTE";
			char botao;
			while(true){
		    if(kbhit){
		        botao = getch();
		    }else{
		        botao =' ';
		    }
		    if(botao==13)
		        break;
			}
			*/
			
			
			ClearScreen(bgChar);
			// Score aumenta com o tempo
			int scoreBonus = -0.035 * (int)(scoreT.getTimePassed() + tempoPassado) * (int)(scoreT.getTimePassed() + tempoPassado) + 500; // função de aumento do score com o tempo
			if(scoreBonus >= 0){
				score += scoreBonus; // função de aumento do tempo	
			}
			for(int i = 0; i < playerLives; i++) score += 200; // aumentar score com o numero de vidas
			
			// Tabela de score
			SetCursorPosition(WIDTH/2 - 7, HEIGHT/2);
			cout << "SCORE: " << score;
			sleep(3.5);
			
			// Guardar o score, o nome e o estado (HS e comparaçoes dentro da funçao do Marco)
			scoreManager.SetScore(b.GetMemoria_de_jogo());
			scoreManager.Bubble_Sort_score(score, playersN[0], b.GetMemoria_de_jogo());
			
			scoreT.restart();
			resetMostValues();
			
			// Aumentar o nível
			if(b.GetMemoria_de_jogo() != 4){
				b.SetMemoria_de_jogo(b.GetMemoria_de_jogo() + 1);
				b.Guardar_jogo(fich, b.GetMemoria_de_jogo(), playersN[0]);	
			}
			else {
				ClearScreen(bgChar);
				story.story_win();
				ClearScreen(bgChar);
				// CRÉDITOS
				ClearScreen(bgChar);
				option = 4;
			}
		}	
	}
	else{
		leftGame = false;
	}
}

void Game::updateUI(){
	// NOME
	SetCursorPosition(5, 1);
	cout << "Name: " << players[0].getName() << " ";
	
	// BOSS HP
	if(b.GetMemoria_de_jogo() == 4){
		SetCursorPosition((WIDTH - (initialBossHP + 9)) / 2, 2);
		cout << " Boss HP: ";
		for(int i = 0; i < bossHP; i++){
			cout << (char)219;
		}
		cout << " ";
	}
	
	// NIVEL
	SetCursorPosition(WIDTH/2 - 6, 1);
	cout << "Level: " << b.GetMemoria_de_jogo();
	
	// TEMPO
	SetCursorPosition(WIDTH - 16, 1);
	cout << "Time: " << scoreT.getTimePassed() + tempoPassado << " ";
	
	// SCORE
	SetCursorPosition(5, HEIGHT - 2);
	cout << "Score: " << score;
	
	// VIDAS
	SetCursorPosition(WIDTH - 20, HEIGHT - 2);
	cout << "Lives: ";	
	for(int i = 0; i < players[0].getLives(); i++){
		cout << "<3 ";
	}
	cout << "   ";
}

// Meter as velocidades nos valores normais
void Game::resetVelocities(){
	enemyVelocity = initialEnemyVelocity;
	shotVelocity = initialShotVelocity;
}

// Resetar os valores iniciais de cada nível
void Game::resetMostValues(){
	velBonus = initialBonus;
	shotChance = initialShotChance;
	resetVelocities();
	bossHP = initialBossHP;
	bossBonus = initialBossBonus;
	spaceBtEnemies = normalSpaceBtEnemies;
	numDeadEnemies = 0;
	tempoPassado = 0;
	score = 0;
}

// Uma pequena função para ver se o jogo acabou
void Game::checkGameOver(){
	if(numDeadEnemies >= numEnemies) gameOver = true;
	checkPlayersLives();
}

// Ver se o jogador morreu
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

// Colisões
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
					&& (enemies[i].isAlive() && shots[s].isAlive()) 
					&& (shots[s].getType() != -1)){
						if(!hasBoss || ((numEnemies - numDeadEnemies > 1) && i != 0 && shots[s].getType() != -1 )) enemies[i].setLife(false);	
						if(!hasBoss || ((numEnemies - numDeadEnemies > 1) && i != 0 && shots[s].getType() != -1 )) enemies[i].clearEntity();
						if(!hasBoss || ((numEnemies - numDeadEnemies > 1) && i != 0 && shots[s].getType() != -1 )) numDeadEnemies += 1;
						if(hasBoss && (numEnemies - numDeadEnemies == 1)) score += 15; // Total de 600 pontos para 40 de vida
						if(hasBoss && (numEnemies - numDeadEnemies == 1)) bossHP -= 1;
						if(hasBoss && bossHP <= 0){
				    		enemies[0].setLife(false);
				    		gameOver = true;
						}
						if(enemies[i].drawing == 1) score += 10;
						if(enemies[i].drawing == 2) score += 15;
						if(enemies[i].drawing == 3) score += 20;
						shots[s].setLife(false);
						shots[s].clearEntity();
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

// Movimento dos jogadores
void Game::updatePlayers(){
	for(int i = 0; i < numPlayers; i++){
		if (players[i].isAlive() == true) players[i].action();
	}
}

// Movimento dos inimigos/boss
void Game::updateEnemies(){
	
	int checkedCol = false;
	
	if (t.getTimePassed()>=1/(enemyVelocity)){
		
		if(enemies[0].y == 9 && enemies[0].x == WIDTH/2){ // O boss é o enemies[0]
			if(hasBoss && bossBonus == 0){ // Se toda a gente está morta excepto o boss
				bossBonus += 1;
				numEnemies += 3;
				for(int i = 0; i < numTotalShots; i++){
					if(shots[i].isAlive()){
						shots[i].setLife(false);
						shots[i].clearEntity();	
					}
				}
				for(int i = 1; i < numEnemies; i++){
					enemies[i] = Enemy(WIDTH/2 + 5 - 10*i, 16, 1, 1, 'X', 10, 0, true, 1);
				}
			}
		}
		
		for(int i = 0; i < numEnemies*2; i++){
			// Para ver se algum inimigo colidiu com a parede antes de movê-los
			// Daí o numEnemies*2, para fazer tudo no mesmo for
			if(hasBoss && (numEnemies-numDeadEnemies != 1)){
				if(i == 0) continue;
			}
			
			if(enemies[i].y >= barrierMaxHeight && enemies[i].isAlive()){
				gameOver = true;
				playerLost = true;
			}
			
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
		if(wasAllDrop >= 0 && wasAllDrop <= preventValue){
			wasAllDrop -= 1;
		}
		
		// Se algum deles colidir com a barreira então descem todos ao mesmo tempo
		if (allDrop && wasAllDrop <= 0){
			way = -way;
			wasAllDrop = preventValue;
			for(int i = 0; i < numEnemies; i++){
				if(hasBoss && i == 0 && (numEnemies - numDeadEnemies > 1)) continue;
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
	if(!hasBoss){
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
	else{
		if(numDeadEnemies == 3 && velBonus == 1){
			enemyVelocity += 5;
			velBonus += 1;
		}
		//
	}
}

// Os tiros do jogador
void Game::updatePlayerShots(){
	
	// Se alguém disparar, criar o tiro no array
	for(int i = 0; i < numTotalShots; i++){
		if(!(shots[i].isAlive())){
			for(int n = 0; n < numPlayers; n++){
				if(playerShot[n] == true && playerShotCD[n] <= 0){
					//shots[i] = Shot(playerShotX[n], playerShotY[n], 0, 0, '|', 1, true, 1);
					shots[i] = Shot(players[n].x, players[n].y - 1, 0, 0, charPlayerShot, 1, true, 1);
					playerShot[n] = false;
					playerShotCD[n] += shotCD;
				}
				else playerShot[n] = false;
			}
		}
	}
}

// O movimento dos tiros e os tiros dos inimigos
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
				int r;
				// TESTE
				//int r = 1;
				//SetCursorPosition(0, 1);
				//cout << "r: " << r << " ";
				if(hasBoss && (numEnemies - numDeadEnemies == 1)){
					r = getRandomNumber(1, bossShotChance);
					if(r == 1){
						int g = getRandomNumber(-enemies[i].getSizeX(), enemies[i].getSizeX());
						for(int t = 0; t < numTotalShots; t++){
							if(!(shots[t].isAlive())){
								shots[t] = Shot(enemies[i].x + g, enemies[i].y + enemies[i].getSizeY() + 1, 0, 0, charEnemyShot, 1, true, -1);
								break;
							}
						}
					}
					break;
				}
				if((numEnemies - numDeadEnemies) > 1 && i != 0){
					r = getRandomNumber(1, shotChance);
					if(r == 1){
						for(int t = 0; t < numTotalShots; t++){
							if(!(shots[t].isAlive())){
								shots[t] = Shot(enemies[i].x, enemies[i].y + enemies[i].getSizeY() + 1, 0, 0, charEnemyShot, 1, true, -1);
								break;
							}
						}
					}
				}
			}
			canShoot = true;
		}
		
		for(int i = 0; i < numPlayers; i++) if(!(playerShotCD[i]) <= 0) playerShotCD[i] -= 1;
	
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
		
    	if(hasBoss && bossHP > 0) enemies[0].drawEntity(); // Para evitar que o boss desapareça quando está parado
	}
}

