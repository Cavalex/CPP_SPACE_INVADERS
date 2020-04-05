// Ficheiro com variáveis e funções "globais", que vamos usar em todos os ficheiros/classes do jogo

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <conio.h>

#ifndef GLOBAL_CPP
#define GLOBAL_CPP

// Estas não estão na tabela ASCII!!!
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
// Estas estão:
#define KEY_X 120


#define HEIGHT 35
#define WIDTH 75


#define chPlayer 'P'
#define bgChar ' '

void SetCursorPosition(int x, int y){
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = {x,y};
	SetConsoleCursorPosition(output, pos);
}

#endif
