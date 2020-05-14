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
		
	private:
		int drawing; // Para um 3x3
		int inimigo1[9] = {176, 0 ,176, 204,206,185, 194,179,194};
		int inimigo2[9] = {200,203,188,204,178,185,194, 0 ,194};
		double velocity; // Tem que ser um double para fazer contas com casas decimais
		int typeOfMove;
		//int way; // -1 Esquerda / 1 Direita
		bool alive;
};

#endif

