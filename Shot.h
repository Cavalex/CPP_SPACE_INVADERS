#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <conio.h>

#include "GlobalSettings.cpp"

#ifndef SHOT_H
#define SHOT_H

class Shot : public Entity {
	public:
		Shot(int, int, int, int, char, int, bool, int);
		Shot();
		void setLife(bool);
		void checkAlive();
		bool isAlive();
		void move();
		void checkCol();
		
	private:
		int dmg;
		bool alive;
		// os tiros do jogador e dos inimigos têm movimentos diferentes, 
		// portanto vamos criar est variável para saber de quem são os tiros
		// 1 -> jogador (de baixo para cima)
		// 2 -> inimigo (de cima para baixo)
		int type;
};

#endif
