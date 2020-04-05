#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <conio.h>

#include "GlobalSettings.cpp"
#include "Entity.h"

using namespace std;

Entity::Entity(int x, int y, int sAX, int sAY, char ch){
	this->x = x;
	this->y = y;
	this->ch = ch;
	this->sizeX = sAX;
	this->sizeY = sAY;
}

// Dar print � posi��o central da Entity
void Entity::showPosition(){
	cout << "[" << x << ", " << y << "]";
}

// Desenhar o ch em x e y
void Entity::draw(){
	SetCursorPosition(x, y);
	cout << ch;
}

// Apagar o ch num x e y escolhido por n�s
void Entity::clear() {
	SetCursorPosition(x, y);
	cout << bgChar;
}

// Desenhar o ch num x e y escolhido por n�s
void Entity::drawOn(int xC, int yC) {
	SetCursorPosition(xC, yC);
	cout << ch;
}

// Apagar o ch num x e y escolhido por n�s
void Entity::clearOn(int xC, int yC) {
	SetCursorPosition(xC, yC);
	cout << bgChar;
}

// Desenhar o ch num quadrado de tamanho definido pelo user
void Entity::drawEntity() {
	for (int yS = -sizeY; yS <= sizeY; yS++){
		for (int xS = -sizeX; xS <= sizeX; xS++){
			drawOn(xS + x, yS + y);
		}
	}
}

void Entity::clearEntity() {
	for (int yS = -sizeY; yS <= sizeY; yS++){
		for (int xS = -sizeX; xS <= sizeX; xS++){
			clearOn(xS + x, yS + y);
		}
	}
}

void Entity::setPos(int xM, int yM){
	// J� vamos incluir aqui a colis�o com a fronteira do mapa
	// Notar que esta fun��o n�o apaga a �ltima posi��o em que a Entity esteve
	x = (xM - sizeX <= 0 || xM + sizeX >= WIDTH - 1) ? x : xM; 
	y = (yM - sizeY <= 0 || yM + sizeY >= HEIGHT - 1) ? y : yM; 
}

void Entity::moveTo(int xM, int yM){
	int lastX = x;
	int lastY = y;
	clearEntity();
	setPos(xM, yM);
	drawEntity();
}

// Estas fun��es podem ser substitu�das por vari�veis p�blicas, 
// � um bocado in�til ter que fazer isto, mas pronto...

int Entity::getSizeX() { return sizeX; }

int Entity::getSizeY() { return sizeY; }

int Entity::getX() { return x; }

int Entity::getY() { return y; }

char Entity::getCh() { return ch; }
