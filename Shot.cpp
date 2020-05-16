#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <conio.h>

#include "GlobalSettings.cpp"
#include "Shot.h"

using namespace std;

Shot::Shot(int x, int y, int sAX, int sAY, char ch, int d, bool al, int tp)
	: Entity(x, y, sAX, sAY, ch)
{
	this->dmg = d;
	this->alive = al;
	this->type = tp;
}

Shot::Shot()
	: Entity(-100, -100, 0, 0, ' ')
{
	this->dmg = 0;
	this->alive = false;
	this->type = 0;
}

void Shot::checkAlive(){
	if(x < 0 || y < 0){
		alive = false;
	}
}

bool Shot::isAlive(){
	return alive;
}

void Shot::setLife(bool b){
	alive = b;
}

void Shot::move(){
	if(type == 1) moveTo(x, y-1); // tiro jogador
	else if(type == -1) moveTo(x, y+1); // tiro inimigo
}

int Shot::getType(){ return type; }

void Shot::checkCol(){
	if(y <= 1 || y >= HEIGHT - 2){
		alive = false;
		clearEntity();
	}
}
