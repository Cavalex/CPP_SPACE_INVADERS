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
		Enemy(int, int, int, int, char, double, int, int);
		void move();
		double getVelocity();
		
	private:
		double velocity; // Tem que ser um double para fazer contas com casas decimais
		int typeOfMove;
		int way; // -1 Esquerda / 1 Direita
};

#endif

