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

Player::Player(int x, int y, int sAX, int sAY, char ch, string n, int s, bool aliv, int nu)
	: Entity (x, y, sAX, sAY, ch)
{
	this->name = n;
	this->score = s;
	this->alive = aliv;
	this->num = nu;
}

Player::Player()
	: Entity (-50, -50, 0, 0, ' ')
{
	this->name = "NULL";
	this->score = 0;
	this->alive = false;
	this->num = 0;
}

void Player::action(){
	
	if (kbhit()){
		char key = getch();
		int value = key;
	    // movimento
	    if (value != 0){
	    	
	    	/*
    		// Se disparar vai colocar a vari�vel do disparo como verdadeira
	        if(value == playerControls[num-1][0])
	        	shoot();
	        // movimento para a esquerda
	        if(value == playerControls[num-1][1])
	            moveTo(x - 1, y);
			// movimento para a direita
	        if(value == playerControls[num-1][2])
	            moveTo(x + 1, y);
	        */
	        
			if(GetKeyState(playerControls2[num-1][0]) & 0x8000 /*Check if high-order bit is set (1 << 15)*/)
			{
			    shoot();
			}
	        if(GetKeyState(playerControls2[num-1][1]) & 0x8000 /*Check if high-order bit is set (1 << 15)*/)
			{
			    moveTo(x - 1, y);
			}
			if(GetKeyState(playerControls2[num-1][2]) & 0x8000 /*Check if high-order bit is set (1 << 15)*/)
			{
			    moveTo(x + 1, y);
			}
		}
	}
}

// Um get para saber se est� vivo ou n�o, quase todas as classes t�m isto
bool Player::isAlive(){ return alive; }

void Player::shoot(){
	playerShot[num-1] = true;
	playerShotX[num-1] = x;
	playerShotY[num-1] = y + sizeY;
}

