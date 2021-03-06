#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <conio.h>
#include <unistd.h>
#include <ctime>
#include <vector>

//Includes de Classes:
#include "HS.cpp" // Classe que guarda/d� load ao high score
#include "Carr_Guar.cpp" // Para Carregar/Guardar o jogo
#include "Carr_Guar.h"// carregar e guardar jogo, e Menus de funcionamento de Novo jogo e Carregar Jogo.
#include "LOGO_cpc.h"// logotipo inicial
#include "Entity.cpp" // Entity, de onde derivam os inimigos, o jogador, as barreiras e o boss
#include "Enemy.cpp"// Inimigo
#include "Player.cpp"// Jogador
#include "Timer.cpp" // O Timer
#include "story.cpp"
#include "Game.cpp"// Niveis
//#include "GlobalSettings.cpp"
// N�o podemos incluir a classe Shot pq j� est� inclu�da no Player.cpp
//#include "Shot.cpp"

using namespace std;

// AGORA O JOGO

int main(){
	
	bool isGameOn = true;
	
	// O gerador de n�meros aleat�rios
	srand(time(NULL));

	// Mudar o tamanho da consola
	SetConsoleSize(WIDTH, HEIGHT);
	
	// S� para "limpar" o fundo, relativamete in�til
	ClearScreen(bgChar);
	Game game;
	
	// O logo do jogo
	logo();

	// O menu
	HS sco; // inicia��o da associa��o da class HB (High Score)
	option = menu();
	int nivel_op;
	string Nome_player;
	while(isGameOn){
		switch(option){
			case 0:
				option = menu();
				break;
			case 1:
				// Criar o jogo
				b.Menu_Carregar_Guardar_jogo(1);// Constr�i o Menu de New game (1)
				b.Print_Menu();
				fich=b.Menu_Controlo_player(1);// funcionalidades do controlo do utilizador com a Variavel de ID op_menu;  
				if(fich==4){// fich � igual a 4 quando o utilizador clica no "back"
					option =0;// retorna para o menu principal
					break;
				}
				Nome_player = b.Nome();//Atribui��o do nome do jogador
				playersN[0] = Nome_player;
				b.Guardar_jogo(fich, 1, Nome_player);// guarda p jogo ( id ficheiro , nivel 1 , Nome criado )
				b.SetNome_do_jogador(Nome_player);// set nome do jogador
				b.SetFicheiro(fich);  // set id ficheiro
				b.SetMemoria_de_jogo(1); // set o estado de jogo.
				story.story_intro(); // introdu��o da hist�ria.
				option =6;// entra na op��o dos niveis.
				break;
			case 2:
				// load game:
				b.Menu_Carregar_Guardar_jogo(2);// Constr�i o Menu de Load a Game (2)
				b.Print_Menu();
				fich=b.Menu_Controlo_player(2);// funcionalidades do controlo do utilizador com a Variavel de ID op_menu; 
				if(fich==4){// volta para o menu principal
					option =0;
					break;
				}
				if(fich==5){
					option =2;
					break;
				}
				b.Carregar_jogo(fich);
				playersN[0]= b.GetNome_do_jogador();
				option=6;
				break;
			case 3:
				// N�o � presiso transportar nenhuma variavel para iniciar a fun��o, pois ela n�o vai depender nem do nome 
				//do jogador, nem de qualquer score , nem do nivel... Ela inicia-se sozinha pelo c�digo em baixo.
				// Mas ela retorna a "op��o_menu" "0"  para que o utilizador retorne ao menu principal. 
				
				nivel_op=1;// nivel permanente 
				sco.Build_Menu_HS_constante();// constro� o Menu High Score
				
				for(;;){// ciclo infinito
					nivel_op=sco.High_score_player_control(nivel_op);// Permite o controlo do utlizdor no menu
					if(nivel_op==8){// M�todo para sair do menu High Score e voltar para o menu principal (quando o utilizador clica em "Back")
						option = 0;
						break;
					}
				}
				break;
			case 4:
				menu_credits();
				option = 0;
				break;
			
			case 5:
				if(!menu_Exit()) isGameOn = false;
				else {
					option = 0;
				}
				break;
				
			case 6:
				if(b.GetMemoria_de_jogo() == 1){// nivel 1
					ClearScreen(bgChar);
					story.story_lvl1();
					ClearScreen(bgChar);
					game = Game(20, 1);
					game.start();
				}
				else if(b.GetMemoria_de_jogo() == 2){ //nivel 2
					ClearScreen(bgChar);
					story.story_lvl2();
					ClearScreen(bgChar);
					game = Game(30, 1);
					game.start();
				}
				else if(b.GetMemoria_de_jogo() == 3){ // nivel 3
					ClearScreen(bgChar);
					story.story_lvl3();
					ClearScreen(bgChar);
					game = Game(40, 1);
					game.start();
				}
				else if(b.GetMemoria_de_jogo() == 4){ // nivel boss
					ClearScreen(bgChar);
					story.story_boss();
					ClearScreen(bgChar);
					game = Game(1, 1, true);
					game.start();
				}
				else{
					cout << "\nErro!!!! A mem�ria de jogo �: " << b.GetMemoria_de_jogo(); // erro de leitura da memoria de jogo
					sleep(1000);
				}
				break;
			default:
				break;
		}
		sleep(0.001); // Para n�o consumir tanta mem�ria
	}
	
	// Pausar consola at� o user premir o Enter
	//cin.get();
	return 0;
}
