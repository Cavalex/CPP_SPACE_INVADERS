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
#define barrierChar 'H'

using namespace std;

// vamos ignorar esta primeira vari�vel pq acrescentamos um cooldown nos tiros,
// ter um limite de tiros � in�til
int numShotsPP = 5; // numero de tiros por jogador
int numTotalShots = 100;

const char playerControls[4][3] = {{KEY_UP, KEY_LEFT, KEY_RIGHT},
							{119, 97, 100}, // W, A, D
							{105, 106, 108}, // I, J, L
							{116, 102, 104}}; // T, F, H
							
// J� que os tiros estavam a dar o problema de recurs�o � melhor coloc�-los aqui
// na forma de um bool, que depois � atualizado na fun��o updateShots() do Game.
bool playerShot[4] = {false, false, false, false};
int playerShotX[4] = {-1, -1, -1, -1}; // A posi��o onde � para colocar os tiros
int playerShotY[4] = {-1, -1, -1, -1}; // A posi��o onde � para colocar os tiros
int playerShotCD[4] = {0, 0, 0, 0}; // O cooldown dos tiros para evitar que os jogadores os spamem
int shotCD = 3; // Para evitar que o jogador spame tiros

int barrierCharInt = 219; // O car�ter das barreiras em int
bool allDrop = false; // vari�el para fazer descer os inimigos em sintonia
double spaceBtEnemies = 5; // O espa�o entre os inimigos (de centro a centro)
int numEnemyShots = 0; // O n�mero de tiros inimigos, provavelmente n�o vai ser preciso
int numBarriers = 8; // numero de barreiras no jogo

double shotVelocity = 7;
double enemyVelocity = 5; // A velocidade dos inimigos, 5 � o ideal, 10 � r�pido e 2 lento
int way = 1; // sentido de movimento dos inimigos; -1 esquerda , 1 direita

string playersN[4] = {"Cavalex", "Joao", "Marco" ,"Matheus"};

// Colocar o ponteiro nas coordenadas dadas
void SetCursorPosition(int x, int y){
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = {x,y};
	SetConsoleCursorPosition(output, pos);
}

// Mudar o tamanho da consola
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

// "Limpar" a consola com o char dado -> �til para fazer "pausa" no jogo a meio e recome�ar
void ClearScreen(char ch){
	for (int y = 0; y < HEIGHT; y++){
		for (int x = 0; x < WIDTH; x++){
			SetCursorPosition(x, y);
			cout << ch;
		}
	}
}

#endif
