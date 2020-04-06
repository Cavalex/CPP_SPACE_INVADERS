#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <conio.h>

#include "GlobalSettings.cpp"
#include "Enemy.h"

Enemy::Enemy(int x, int y, int sAX, int sAY, char ch, int v, int t, int w)
	: Entity (x, y, sAX, sAY, ch)
{
	this->velocity = v;
	this->typeOfMove = t;
	this->way = w;
}

void Enemy::move(){
	//count += 1;
	// 0 é o movimento normal da esquerda para a direita
	//if (count % 1000 == 0){
		if (typeOfMove == 0){
			// Movimento vertical
			if (x - sizeX <= 1 || x + sizeX >= WIDTH - 2){
				way = -way;
				moveTo(x, y + 1);	
			}
			// Movimento horizontal
			if (way == -1) moveTo(x - 1, y);
			else if (way == 1) moveTo(x + 1, y);
		}
	//}
}

