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
#include "HS.cpp" // Classe que guarda/dá load ao high score
#include "Carr_Guar.cpp" // Para Carregar/Guardar o jogo
#include "Carr_Guar.h"// carregar e guardar jogo, e Menus de funcionamento de Novo jogo e Carregar Jogo.
#include "LOGO_cpc.h"// logotipo inicial
#include "Entity.cpp" // Entity, de onde derivam os inimigos, o jogador, as barreiras e o boss
#include "Enemy.cpp"// Inimigo
#include "Player.cpp"// Jogador
#include "Timer.cpp" // O Timer
#include "Game.cpp"// Niveis
#include "Boss.cpp" // Boss
//#include "GlobalSettings.cpp"
// Não podemos incluir a classe Shot pq já está incluída no Player.cpp
//#include "Shot.cpp"

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
	HS sco; // iniciação da associação da class HB (High Score)
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
				b.Menu_Carregar_Guardar_jogo(1);
				b.Print_Menu();
				fich=b.Menu_Controlo_player();
				if(fich==4){
					option =0;
					break;
				}
				Nome_player = b.Nome();//Atribuição do nome do jogador
				playersN[0] = Nome_player;
				b.Guardar_jogo(fich, 1, Nome_player);
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
			case 3:
				// Não é presiso transportar nenhuma variavel para iniciar a função, pois ela não vai depender nem do nome 
				//do jogador, nem de qualquer score , nem do nivel... Ela inicia-se sozinha pelo código em baixo.
				// Mas ela retorna a "opção_menu" "0" (que não tem de ser obrigatóriamente "0") para que o utilizador retorne ao 
				//menu principal. 
				
				nivel_op=1;// nivel permanente 
				sco.Build_Menu_HS_constante();// constroí o Menu High Score
				
				for(;;){// ciclo infinito
					nivel_op=sco.High_score_player_control(nivel_op);// Permite o controlo do utlizdor no menu
					if(nivel_op==8){// Método para sair do menu High Score e voltar para o menu principal (quando o utilizador clica em "Back")
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
				if(b.GetMemoria_de_jogo() == 1){
					ClearScreen(bgChar);
					game = Game(20, 1);
					game.start();
				}
				else if(b.GetMemoria_de_jogo() == 2){
					ClearScreen(bgChar);
					game = Game(20, 1);
					game.start();
				}
				else if(b.GetMemoria_de_jogo() == 3){
					ClearScreen(bgChar);
					game = Game(20, 1);
					game.start();
				}
				else if(b.GetMemoria_de_jogo() == 4){
					ClearScreen(bgChar);
					game = Game(1, 1, true);
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
		sleep(0.001); // Para não consumir tanta memória
	}
	
	// Pausar consola até o user premir o Enter
	//cin.get();
	return 0;
}
