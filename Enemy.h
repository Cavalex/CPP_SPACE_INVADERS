#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <conio.h>
#include <vector>

#include "GlobalSettings.cpp"

#ifndef ENEMY_H
#define ENEMY_H

using namespace std;

class Enemy : public Entity {
	public:
		Enemy(int, int, int, int, char, double, int, bool, int);
		Enemy();
		void moveHorizontally();
		void moveVertically();
		bool collidedWall();
		double getVelocity();
		void setLife(bool);
		bool isAlive();
		void drawEntity();
		void drawOn(int, int, char);
		void moveTo(int, int);
		
		int drawing; // Para um 3x3
		
	private:
		int inimigo1[9] = {176, 0 ,176, 204,206,185, 194,179,194};
		int inimigo2[9] = {200,203,188,204,178,185,194, 0 ,194};
		int inimigo3[9] = {203,95,203, 178,206,178,186, 0 ,186};
		int inimigo4[9] = {254,223,254, 254,220,254, 0,194,0};
		int boss[217] = {
		32,32,32,32,32,32,32,32,32,32,219,219,219,219,219,219,219,219,219,219,219,32,32,32,32,32,32,32,32,32,32,
		32,32,32,32,32,32,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,32,32,32,32,32,32,
		32,32,32,32,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,32,32,32,32,
		32,32,219,219,219,219,32,32,219,219,219,219,32,32,219,219,219,32,32,219,219,219,219,32,32,219,219,219,219,32,32,
		219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,
		32,32,32,32,219,219,219,219,219,219,32,32,32,32,219,219,219,32,32,32,32,219,219,219,219,219,219,32,32,32,32,
		32,32,32,32,32,32,219,219,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,219,219,32,32,32,32,32,32
		};
		double velocity; // Tem que ser um double para fazer contas com casas decimais
		int typeOfMove;
		//int way; // -1 Esquerda / 1 Direita
		bool alive;
};

#endif

