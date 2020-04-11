#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <conio.h>

#include "GlobalSettings.cpp"
#include "Shot.h"

using namespace std;

Shot::Shot(int x, int y, int sAX, int sAY, char ch, int d, bool al)
	: Entity(x, y, sAX, sAY, ch)
{
	this->dmg = d;
	this->alive = al;
}

Shot::Shot()
	: Entity(-100, -100, 0, 0, ' ')
{
	this->dmg = 0;
	this->alive = false;
}

bool Shot::isALive(){
	return alive;
}
