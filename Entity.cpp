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

// Dar print à posição central da Entity
void Entity::showPosition(){
	cout << "[" << x << ", " << y << "]";
}

// Desenhar o ch em x e y
void Entity::draw(){
	SetCursorPosition(x, y);
	cout << ch;
}

// Apagar o ch num x e y escolhido por nós
void Entity::clear() {
	SetCursorPosition(x, y);
	cout << bgChar;
}

// Desenhar o ch num x e y escolhido por nós
void Entity::drawOn(int xC, int yC) {
	SetCursorPosition(xC, yC);
	cout << ch;
}

// Apagar o ch num x e y escolhido por nós
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
	// Já vamos incluir aqui a colisão com a fronteira do mapa
	// Notar que esta função não apaga a última posição em que a Entity esteve
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

// Estas funções podem ser substituídas por variáveis públicas, 
// é um bocado inútil ter que fazer isto, mas pronto...

int Entity::getSizeX() { return sizeX; }

int Entity::getSizeY() { return sizeY; }

int Entity::getX() { return x; }

int Entity::getY() { return y; }

char Entity::getCh() { return ch; }
