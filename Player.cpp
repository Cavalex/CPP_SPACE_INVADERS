#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <conio.h>

#include "GlobalSettings.cpp"
#include "Player.h"
#include "Shot.cpp"
#include "Game.h"

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

void Player::action(Game game){
	
	if (kbhit()){
		char key = getch();
		int value = key;
	    // movimento
	    if (value != 0){
	    	switch(value){
		        case playerControls[num-1][0]:
		        	for(int i = 0; i < numShotsPP * numPlayers; i++){
		        		if (!(game.shots[i].isALive())) game.shots[i] = Shot(x, y-1-sizeY, 0, 0, '|', 1, true);	
					}
					break;
		        /*
		        case KEY_DOWN:
		            moveTo(x, y + 1);
		            break;
		        */
		        case KEY_LEFT:
		            moveTo(x - 1, y);
					break;
		        case KEY_RIGHT:
		            moveTo(x + 1, y);
					break;
				default:
					break;
		    }
		}
	}
}

/*
void Player::shoot(int sX, int sY, char cha, int d){
	// O tiro é logo eliminado quando a função acaba, 
	// vamos ter de criar uma classe "Game" que "recorde" todos
	// os dados do jogo e podemos acrescentar lá o Shot
	// ou, para ser mais eficaz, criamos um array nas variáveis globais e colocamos lá o tiro.
	Shot s = Shot(x, y - sizeY - 1, sX, sY, cha, d);
}
*/

bool Player::isAlive(){ return alive; }

