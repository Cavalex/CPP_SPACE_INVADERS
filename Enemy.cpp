#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <conio.h>
#include <vector>

#include "GlobalSettings.cpp"
#include "Enemy.h"

Enemy::Enemy(int x, int y, int sAX, int sAY, char ch, double velo, int type, bool aliv, int d)
	: Entity (x, y, sAX, sAY, ch)
{
	this->velocity = velo;
	this->typeOfMove = type;
	this->alive = aliv;
	this->drawing = d;
}

Enemy::Enemy()
	: Entity (-50, -50, 0, 0, ' ')
{
	this->velocity = 0;
	this->typeOfMove = 0;
	this->alive = false;
	this->drawing = 1;
}

void Enemy::moveHorizontally(){
	if (way == -1) moveTo(x - 1, y);
	else if (way == 1) moveTo(x + 1, y);	
}

void Enemy::drawOn(int xC, int yC, char c){
	SetCursorPosition(xC, yC);
	cout << c;
}

void Enemy::drawEntity(){
	int i = 0;
	for (int yS = -sizeY; yS <= sizeY; yS++){
		for (int xS = -sizeX; xS <= sizeX; xS++){
			if(drawing == 1){
				drawOn(xS + x, yS + y, inimigo1[i]);	
			}
			else if(drawing == 2){
				drawOn(xS + x, yS + y, inimigo2[i]);
			}
			i++;
		}
	}
}

void Enemy::moveTo(int xM, int yM){
	int lastX = x;
	int lastY = y;
	clearEntity();
	setPos(xM, yM);
	drawEntity();
}

void Enemy::moveVertically(){
	// Movimento vertical
	moveTo(x, y + 1);
}

void Enemy::setLife(bool b){
	alive = b;
}

bool Enemy::collidedWall(){
	if ((x - sizeX <= 1 && way == -1) || (x + sizeX >= WIDTH - 2 && way == 1)) return true;
	else return false;
}

double Enemy::getVelocity(){ return velocity; }

bool Enemy::isAlive(){ return alive; }

