#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <conio.h>
#include <vector>

#include "GlobalSettings.cpp"
#include "Enemy.h"

Boss::Boss(int x, int y, char ch, double velo, int type, bool aliv, int l)
	: Enemy(x, y, 3, 15, ch, velo, type, aliv, 0)
{
	this->life = l;
}

void Boss::drawEntity(){
	int i = 0;
	for (int yS = -sizeY; yS <= sizeY; yS++){
		for (int xS = -sizeX; xS <= sizeX; xS++){
			if(drawing == 0){
				drawOn(xS + x, yS + y, boss[i]);	
			}
			i++;
		}
	}
}

