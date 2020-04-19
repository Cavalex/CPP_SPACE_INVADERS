#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <conio.h>

#include "GlobalSettings.cpp"

#ifndef ENEMY_H
#define ENEMY_H

class Enemy : public Entity {
	public: 
		Enemy(int, int, int, int, char, double, int, bool);
		Enemy();
		void moveHorizontally();
		void moveVertically();
		bool collidedWall();
		double getVelocity();
		void setLife(bool);
		bool isAlive();
		
	private:
		double velocity; // Tem que ser um double para fazer contas com casas decimais
		int typeOfMove;
		//int way; // -1 Esquerda / 1 Direita
		bool alive;
};

#endif

