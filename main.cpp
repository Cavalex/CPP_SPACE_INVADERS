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
// N�o podemos incluir a classe Shot pq j� est� inclu�da no Player.cpp
//#include "Shot.cpp"
//#include "GlobalSettings.cpp"

using namespace std;

// AGORA O JOGO

int main(){
	
	// O gerador de n�meros aleat�rios
	srand(time(NULL));

	// Mudar o tamanho da consola
	SetConsoleSize(WIDTH, HEIGHT);
	
	// S� para "limpar" o fundo, relativamete in�til
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
			cout << "OP�AO 2";
			break;
		default:
			break;
	}
	
	// Pausar consola at� o user premir o Enter
	cin.get();
	return 0;
}
