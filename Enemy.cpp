#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <conio.h>

#include "GlobalSettings.cpp"
#include "Enemy.h"

Enemy::Enemy(int x, int y, int sAX, int sAY, char ch, double velo, int type, bool aliv)
	: Entity (x, y, sAX, sAY, ch)
{
	this->velocity = velo;
	this->typeOfMove = type;
	this->alive = aliv;
}

Enemy::Enemy()
	: Entity (-50, -50, 0, 0, ' ')
{
	this->velocity = 0;
	this->typeOfMove = 0;
	this->alive = false;
}

void Enemy::moveHorizontally(){
	// 0 é o movimento normal da esquerda para a direita
	//if (typeOfMove == 0){
		// Só andam para os lados se não estiverem a andar para baixo
		/*
		if (x - sizeX <= 1 || x + sizeX >= WIDTH - 2){
			allDrop = true;	
			way = -way;
		}
		*/
		//else {
			// Movimento horizontal
			if (way == -1) moveTo(x - 1, y);
			else if (way == 1) moveTo(x + 1, y);	
		//}
	//}
}

void Enemy::moveVertically(){
	// Movimento vertical
	moveTo(x, y + 1);
}

bool Enemy::collidedWall(){
	if ((x - sizeX <= 1 && way == -1) || (x + sizeX >= WIDTH - 2 && way == 1)) return true;
	else return false;
}

double Enemy::getVelocity(){ return velocity; }

bool Enemy::isAlive(){ return alive; }

