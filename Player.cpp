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

Player::Player(int x, int y, int sAX, int sAY, char ch, string n, int s)
	: Entity (x, y, sAX, sAY, ch)
{
	this->name = n;
	this->score = s;
}

void Player::moveAction(){
	
	char key = getch();
	int value = key;
	
    // movimento
    switch(value){
        case KEY_UP:
            moveTo(x, y - 1);
            break;
        case KEY_DOWN:
            moveTo(x, y + 1);
            break;
        case KEY_LEFT:
            moveTo(x - 1, y);
			break;
        case KEY_RIGHT:
            moveTo(x + 1, y);
			break;
    }
}

void Player::shoot(int sX, int sY, char cha, int d){
	// O tiro � logo eliminado quando a fun��o acaba, 
	// vamos ter de criar uma classe "Game" que "recorde" todos
	// os dados do jogo e podemos acrescentar l� o Shot
	// ou, para ser mais eficaz, criamos um array nas vari�veis globais e colocamos l� o tiro.
	Shot s = Shot(x, y - sizeY - 1, sX, sY, cha, d);
}
