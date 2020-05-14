// Ficheiro com vari�veis e fun��es "globais", que vamos usar em todos os ficheiros/classes do jogo

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <conio.h>
#include <time.h>
#include <locale.h>
#include <vector>

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
#define WIDTH 90

#define bgChar ' '
#define barrierChar 'H'

using namespace std;

// vamos ignorar esta primeira vari�vel pq acrescentamos um cooldown nos tiros,
// ter um limite de tiros � in�til
int numShotsPP = 5; // numero de tiros por jogador
int numTotalShots = 200;

char playerControls[4][3] = {{72, 75, 77},
							{119, 97, 100}, // W, A, D
							{105, 106, 108}, // I, J, L
							{116, 102, 104}}; // T, F, H

char playerControls2[4][3] = {{VK_UP, VK_LEFT, VK_RIGHT},
							{'W', 'A', 'D'}, // W, A, D
							{105, 106, 108}, // I, J, L
							{116, 102, 104}}; // T, F, H
				
int option; // O valor que foi selecionado no menu
Carr_Guar b; // O objeto que vai ser usado para controlar o estado do jogo.
int score = 0;
int fich; // O ficheiro onde o jogo est� a ser "corrido" (salvar/guardar)
					
//TESTE
int j = 0;

// J� que os tiros estavam a dar o problema de recurs�o � melhor coloc�-los aqui
// na forma de um bool, que depois � atualizado na fun��o updateShots() do Game.
bool playerShot[4] = {false, false, false, false};
int playerShotX[4] = {-1, -1, -1, -1}; // A posi��o onde � para colocar os tiros
int playerShotY[4] = {-1, -1, -1, -1}; // A posi��o onde � para colocar os tiros
int playerShotCD[4] = {0, 0, 0, 0}; // O cooldown dos tiros para evitar que os jogadores os spamem
int shotCD = 6; // Para evitar que o jogador spame tiros
int playerLives = 3; // As vidas do jogador

// Para servir de refer�ncia, este valor n�o muda o tamanho das barreiras mas 
// n�o quero colocar nas colis�es barreiras-balas um "9" que pode parecer aleat�rio
int barrierAverageSize = 9; 
int numBarriers = 9; // numero de barreiras no jogo
int barrierMaxHeight = HEIGHT - 8; // altura das barreiras relativamente ao ch�o

bool canShoot = true; // vari�vel para sabermos se um inimigo pode ou n�o disparar
int initialShotChance = 20;
int shotChance = initialShotChance; // > dispara menos vezes; < dispara mais vezes
int enemyYInit = 5; // X inicial dos inimigos da primeira linha
int enemyYDifference = 4; // A diferen�a entre os X's dos inimigos da primeira linha para a segunda
int barrierCharInt = 219; // O car�ter das barreiras em int
bool allDrop = false; // vari�vel para fazer descer os inimigos em sintonia
int wasAllDrop = 0; // d� track ao �ltimo estado de allDrop
double spaceBtEnemies = 5; // O espa�o entre os inimigos (de centro a centro)
int numEnemyShots = 0; // O n�mero de tiros inimigos, provavelmente n�o vai ser preciso

double initialShotVelocity = 10;
double shotVelocity = initialShotVelocity; // A velocidade dos tiros
double initialEnemyVelocity = 5;
double initialBonus = 1;
double velBonus = initialBonus;
double enemyVelocity = initialEnemyVelocity; // A velocidade dos inimigos, 5 � o ideal, 10 � r�pido e 2 lento
int way = 1; // sentido de movimento dos inimigos; -1 esquerda , 1 direita

string playersN[4] = {"Cavalex", "Joao", "Marco" ,"Matheus"};

int getRandomNumber(int min, int max){
	// um n�mero aleat�rio entre 0 e a
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
