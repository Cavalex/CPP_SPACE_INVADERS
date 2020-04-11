#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <conio.h>

#include "GlobalSettings.cpp"
#include "Barrier.h"
#include "Shot.h"

using namespace std;

Barrier::Barrier(int x, int y, int sAX, int sAY, char ch, bool aliv)
	: Entity (x, y, sAX, sAY, ch)
{
	this->alive = aliv;
}

Barrier::Barrier()
	: Entity (-50, -50, 0, 0, ' ')
{
	this->alive = false;
}

//Ver colisões com os tiros/inimigos
void Barrier::checkCol(){
	int a = 0;
}



