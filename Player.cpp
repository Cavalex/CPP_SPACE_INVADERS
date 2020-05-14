#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <conio.h>

#include "GlobalSettings.cpp"
#include "Player.h"
#include "Shot.cpp"

using namespace std;

Player::Player(int x, int y, int sAX, int sAY, char ch, string n, int s, bool aliv, int nu, int livess)
	: Entity (x, y, sAX, sAY, ch)
{
	this->name = n;
	this->score = s;
	this->alive = aliv;
	this->num = nu;
	this->lives = livess;
}

Player::Player()
	: Entity (-50, -50, 0, 0, ' ')
{
	this->name = "NULL";
	this->score = 0;
	this->alive = false;
	this->num = 0;
	this->lives = 0;
}

void Player::drawOn(int xC, int yC, char c){
	SetCursorPosition(xC, yC);
	cout << c;
}

void Player::drawEntity(){
	int i = 0;
	for (int yS = -sizeY; yS <= sizeY; yS++){
		for (int xS = -sizeX; xS <= sizeX; xS++){
			if(drawing == 1){
				drawOn(xS + x, yS + y, nave1[i]);	
			}
			/*
			else if(drawing == 2){
				drawOn(xS + x, yS + y, inimigo2[i]);
			}
			*/
			i++;
		}
	}
}

void Player::moveTo(int xM, int yM){
	int lastX = x;
	int lastY = y;
	clearEntity();
	setPos(xM, yM);
	drawEntity();
}

void Player::action(){
	
	if (kbhit()){
		char key = getch();
		int value = key;
	    // movimento
	    if (value != 0){
	    	
    		// Se disparar vai colocar a variável do disparo como verdadeira
	        if(value == playerControls[num-1][0])
	        	shoot();
	        // movimento para a esquerda
	        if(value == playerControls[num-1][1])
	            moveTo(x - 1, y);
			// movimento para a direita
	        if(value == playerControls[num-1][2])
	            moveTo(x + 1, y);
	        
			//if(GetKeyState(playerControls2[num-1][0]) & 0x8000 /*Check if high-order bit is set (1 << 15)*/)
			//{
			//    shoot();
			//}
	        //if(GetKeyState(playerControls2[num-1][1]) & 0x8000 /*Check if high-order bit is set (1 << 15)*/)
			//{
			//    moveTo(x - 1, y);
			//}
			//if(GetKeyState(playerControls2[num-1][2]) & 0x8000 /*Check if high-order bit is set (1 << 15)*/)
			//{
			//    moveTo(x + 1, y);
			//}
			
		}
	}
}

// Um get para saber se está vivo ou não, quase todas as classes têm isto
bool Player::isAlive(){ return alive; }

void Player::shoot(){
	playerShot[num-1] = true;
	playerShotX[num-1] = x;
	playerShotY[num-1] = y + sizeY;
}

string Player::getName(){
	return name;
}

void Player::gotHit(){
	lives -= 1;
	if(lives <= 0){
		// Matar o jogador
		alive = false;
		clearEntity();
		// Metê-lo fora do ecrã para evitar problemas
		x = -50;
		y = -50;
	}
}

int Player::getLives(){
	return lives;
}
