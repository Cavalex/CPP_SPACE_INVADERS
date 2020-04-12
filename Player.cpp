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
	    	switch(value){
	    		// Se disparar vai colocar a variável do disparo como verdadeira
		        case KEY_UP:
		        	shoot();
					break;
		        /*
		        case KEY_DOWN:
		            moveTo(x, y + 1);
		            break;
		        */
		        // movimento para a esquerda
		        case KEY_LEFT:
		            moveTo(x - 1, y);
					break;
				// movimento para a direita
		        case KEY_RIGHT:
		            moveTo(x + 1, y);
					break;
				default:
					break;
		    }
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

