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
	string Nome_player;
	int fich;
	while(isGameOn){
		switch(option){
			case 0:
				option = menu();
				break;
			case 1:
				// Criar o jogo com 20 inimigos e 1 jogador
				b.Menu_Carregar_Guardar_jogo(1);
				b.Print_Menu();
				fich=b.Menu_Controlo_player();
				if(fich==4){
					option =0;
					break;
				}
				Nome_player = b.Nome();
				playersN[0] = Nome_player;
				b.Guardar_jogo(option, 1, Nome_player);
				b.SetNome_do_jogador(Nome_player);
				b.SetFicheiro(fich);
				b.SetMemoria_de_jogo(1);
				option =6;
				break;
			case 2:
				// load game:
				b.Menu_Carregar_Guardar_jogo(2);
				b.Print_Menu();
				fich=b.Menu_Controlo_player();
				if(fich==4){// volta para o menu principal
					option =0;
					break;
				}
				b.Carregar_jogo(fich);
				playersN[0]= b.GetNome_do_jogador();
				option=6;
				break;
				
			case 5:
				isGameOn = false;
				break;
				
			case 6:
				if(b.GetMemoria_de_jogo() == 1){
					cout << "OPÇAO 1";
					ClearScreen(bgChar);
					game = Game(20, 1);
					game.start();
				}
				else if(b.GetMemoria_de_jogo() == 2){
					cout << "OPÇAO 2";
					ClearScreen(bgChar);
					game = Game(20, 1);
					game.start();
				}
				else if(b.GetMemoria_de_jogo() == 3){
					cout << "OPÇAO 3";
					ClearScreen(bgChar);
					game = Game(20, 1);
					game.start();
				}
				else if(b.GetMemoria_de_jogo() == 4){
					cout << "OPÇAO 4";
					sleep(100);
					ClearScreen(bgChar);
					game = Game(20, 1);
					game.start();
				}
				else{
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
