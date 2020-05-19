#ifndef CARR_GUAR_H
#define CARR_GUAR_H
#include <iostream>
#include <string>
#include <conio.h>
#include <unistd.h>

#define Ymax 21
#define Xmax 66
using namespace std;

class Carr_Guar
{
	
	public:
		Menu_Carregar_Guardar_jogo(int);// constrói o Menu do Carregar ou New game
		int Menu_Controlo_player();// função de controlo do utilizador
		void Print_Menu(); // print o Menu.
		void Guardar_jogo(int, int, string);// função que guarda o nome, e o estado 
		
		int Fich_confirm(int);
		
		// Gets:
		int GetFicheiro();
		int GetMemoria_de_jogo();
		string GetNome_do_jogador();
		// Sets:
		void SetNome_do_jogador(string);
		void SetMemoria_de_jogo(int);
		void SetFicheiro(int);
		string Nome();
		void Carregar_jogo(int);// carrega o jogo.
		
		
	protected:

		int memoria[2];
		int memoria_de_jogo;
		string nome_do_jogador;
		int Ficheiro;
		
		string Menu[Ymax][Xmax];
		
};

#endif
