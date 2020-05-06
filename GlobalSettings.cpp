// Ficheiro com variáveis e funções "globais", que vamos usar em todos os ficheiros/classes do jogo

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <conio.h>
#include <time.h>
#include <locale.h>

// Variável para evitar incluir o ficheiro várias vezes
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
#define WIDTH 90

#define bgChar ' '
#define barrierChar 'H'

using namespace std;

// vamos ignorar esta primeira variável pq acrescentamos um cooldown nos tiros,
// ter um limite de tiros é inútil
int numShotsPP = 5; // numero de tiros por jogador
int numTotalShots = 400;

char playerControls[4][3] = {{72, 75, 77},
							{119, 97, 100}, // W, A, D
							{105, 106, 108}, // I, J, L
							{116, 102, 104}}; // T, F, H

char playerControls2[4][3] = {{VK_UP, VK_LEFT, VK_RIGHT},
							{'W', 'A', 'D'}, // W, A, D
							{105, 106, 108}, // I, J, L
							{116, 102, 104}}; // T, F, H
							
// Já que os tiros estavam a dar o problema de recursão é melhor colocá-los aqui
// na forma de um bool, que depois é atualizado na função updateShots() do Game.
bool playerShot[4] = {false, false, false, false};
int playerShotX[4] = {-1, -1, -1, -1}; // A posição onde é para colocar os tiros
int playerShotY[4] = {-1, -1, -1, -1}; // A posição onde é para colocar os tiros
int playerShotCD[4] = {0, 0, 0, 0}; // O cooldown dos tiros para evitar que os jogadores os spamem
int shotCD = 6; // Para evitar que o jogador spame tiros

bool ignore5 = false;
bool continue5 = false;
bool ignore4 = false;
bool continue4 = false;
bool ignore3 = false;
bool continue3 = false;
bool ignore2 = false;
bool continue2 = false;

bool canShoot = true; // variável para sabermos se um inimigo pode ou não disparar
int shotChance = 30; // > dispara menos vezes; < dispara mais vezes
int enemyYInit = 5; // X inicial dos inimigos da primeira linha
int enemyYDifference = 4; // A diferença entre os X's dos inimigos da primeira linha para a segunda
int barrierCharInt = 219; // O caráter das barreiras em int
bool allDrop = false; // variáel para fazer descer os inimigos em sintonia
double spaceBtEnemies = 5; // O espaço entre os inimigos (de centro a centro)
int numEnemyShots = 0; // O número de tiros inimigos, provavelmente não vai ser preciso
int numBarriers = 8; // numero de barreiras no jogo

double shotVelocity = 10; // A velocidade dos tiros
double enemyVelocity = 5; // A velocidade dos inimigos, 5 é o ideal, 10 é rápido e 2 lento
int way = 1; // sentido de movimento dos inimigos; -1 esquerda , 1 direita

string playersN[4] = {"Cavalex", "Joao", "Marco" ,"Matheus"};

int getRandomNumber(int min, int max){
	// um número aleatório entre 0 e a
	int r = (rand() % (max + 1 - min)) + min;
	return r;
}

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

// "Limpar" a consola com o char dado -> útil para fazer "pausa" no jogo a meio e recomeçar
void ClearScreen(char ch){
	for (int y = 0; y < HEIGHT; y++){
		for (int x = 0; x < WIDTH; x++){
			SetCursorPosition(x, y);
			cout << ch;
		}
	}
}

#endif
