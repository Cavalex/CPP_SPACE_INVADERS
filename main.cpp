#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <conio.h>
#include <unistd.h>
#include <ctime>
#include <vector>

#include "Carr_Guar.cpp"
#include "Carr_Guar.h"
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
	
	bool isGameOn = true;
	
	// O gerador de números aleatórios
	srand(time(NULL));

	// Mudar o tamanho da consola
	SetConsoleSize(WIDTH, HEIGHT);
	
	// Só para "limpar" o fundo, relativamete inútil
	ClearScreen(bgChar);
	Game game;
	
	// O logo do jogo
	logo();
	
	// O menu
	int option = menu();
	Carr_Guar b;
	while(isGameOn){
		switch(option){
			case 0:
				option = menu();
				break;
			case 1:
				// Criar o jogo com 20 inimigos e 1 jogador
				option = Novo_jogo(b, 1);
				break;
			case 2:
				// load game:
				cout << "OPÇAO 2";
				break;
			case 5:
				isGameOn = false;
				break;
			case 6:
				if(b.GetMemoria_de_jogo() == 0){
					ClearScreen(bgChar);
					game = Game(20, 1);
					game.start();
				}else{
					cout << "\nErro!!!! A memória de jogo é: " << b.GetMemoria_de_jogo();
					sleep(1000);
				}
				break;
			default:
				break;
		}	
	}
	
	// Pausar consola até o user premir o Enter
	//cin.get();
	return 0;
}
