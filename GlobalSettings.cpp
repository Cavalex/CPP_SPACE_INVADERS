// Ficheiro com vari�veis e fun��es "globais", que vamos usar em todos os ficheiros/classes do jogo

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <conio.h>
#include <time.h>

// Vari�vel para evitar incluir o ficheiro v�rias vezes
#ifndef GLOBAL_CPP
#define GLOBAL_CPP

// Estas n�o est�o na tabela ASCII!!!
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
// Estas est�o:
#define KEY_X 120

#define HEIGHT 35
#define WIDTH 75

#define bgChar ' '

bool allDrop = false;
double spaceBtEnemies = 5;
int numEnemyShots = 0;
int numPlayerShots = 0;
double globalVelocity = 5;
int way = 1;

using namespace std;

void SetCursorPosition(int x, int y){
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = {x,y};
	SetConsoleCursorPosition(output, pos);
}

void timer(int n) {
    // Tempo inicial
    clock_t start_time = clock();

    // Uma esp�cie de sleep, a fun��o timer s� acaba quando o while terminar,
    //logo s� termina quando se passar o tempo que colocamos no par�metro.
    while (clock() < start_time + n)
		;
}

void SetConsoleSize(int width, int height){
	HANDLE wHnd;    // Handle to write to the console.
	HANDLE rHnd;

	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	rHnd = GetStdHandle(STD_INPUT_HANDLE);
    // Change the window title:
    SetConsoleTitle("Space Invaders!");
    
    // Set up the required window size:
    SMALL_RECT windowSize = {0, 0, width - 1, height - 1};
    COORD bufferSize = {width, height};
    
    SetConsoleWindowInfo(wHnd, 1, &windowSize);
    SetConsoleScreenBufferSize(wHnd, bufferSize);
}

void ClearScreen(char ch){
	for (int y = 0; y < HEIGHT; y++){
		for (int x = 0; x < WIDTH; x++){
			SetCursorPosition(x, y);
			cout << ch;
		}
	}
}

#endif
