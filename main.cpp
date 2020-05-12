#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <conio.h>
#include <unistd.h>
#include <ctime>
#include <vector>

#include "LOGO_cpc.h"

#include "Entity.cpp"
#include "Enemy.cpp"
#include "Player.cpp"
#include "Timer.cpp"
#include "Game.cpp"
// Não podemos incluir a classe Shot pq já está incluída no Player.cpp
//#include "Shot.cpp"
//#include "GlobalSettings.cpp"

using namespace std;

// AGORA O JOGO

int main(){
	
	// O gerador de números aleatórios
	srand(time(NULL));

	// Mudar o tamanho da consola
	SetConsoleSize(WIDTH, HEIGHT);
	
	// Só para "limpar" o fundo, relativamete inútil
	ClearScreen(bgChar);
	Game game;
	
	// O menu
	int option = menu();
	switch(option){
		case 1:
			// Criar o jogo com 20 inimigos e 1 jogador
			game = Game(20, 1);
			game.start();
			break;
		case 2:
			// load game:
			cout << "OPÇAO 2";
			break;
		default:
			break;
	}
	
	// Pausar consola até o user premir o Enter
	cin.get();
	return 0;
}
