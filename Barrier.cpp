#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <conio.h>
#include <vector>

#include "GlobalSettings.cpp"
#include "Barrier.h"
#include "Shot.h"

using namespace std;

Barrier::Barrier(int x, int y, int sAX, int sAY, char ch, bool aliv)
	: Entity (x, y, sAX, sAY, ch)
{
	this->alive = aliv;
	this->size = (sAX * 2 + 1) + (sAY + 2 + 1);
	deadSquaresX.push_back(-1);
	deadSquaresY.push_back(-1);
}

Barrier::Barrier()
	: Entity (-50, -50, 0, 0, ' ')
{
	this->alive = false;
	this->size = 0;
	deadSquaresX.push_back(-1);
	deadSquaresY.push_back(-1);
}

bool Barrier::isAlive(){ return alive; }

void Barrier::setLife(bool b){ alive = b; }

int Barrier::getSize(){ return size; }

void Barrier::setSize(int s){ 
	size = s;
	if(size <= 0){
		alive = false;
	}
}


