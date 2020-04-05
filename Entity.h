#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <conio.h>

#include "GlobalSettings.cpp"

#ifndef ENTITY_H
#define ENTITY_H

using namespace std;

class Entity {
	
	public:
		Entity(int, int, int, int, char);
		void showPosition();
		void draw();
		void clear();
		void drawOn(int, int);
		void clearOn(int, int);
		void drawEntity();
		void clearEntity();
		void moveTo(int, int);
		void setPos(int, int);

		int getX();
		int getY();
		int getSizeX();
		int getSizeY();
		char getCh();
		
		// Estas estão públicas para facilitar a leitura e poupar linhas de código
		int x;
		int y;
		int sizeX;
		int sizeY;
		char ch;

	private:
		/*
		int x;
		int y;
		int sizeX;
		int sizeY;
		char ch;
		*/
};

#endif
