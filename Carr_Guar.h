#ifndef CARR_GUAR_H
#define CARR_GUAR_H
#include <iostream>
#include <string>

#define Ymax 21
#define Xmax 66
using namespace std;

class Carr_Guar
{
	
	public:
		Menu_Carregar_Guardar_jogo(int);// constr�i o Menu do Carregar ou New game
		int Menu_Controlo_player();// fun��o de controlo do utilizador
		void Print_Menu(); // print o Menu.
		void Guardar_jogo(int, int, string);// fun��o que guarda o nome, e o estado 
		// Gets:
		int GetFicheiro();
		int GetMemoria_de_jogo();
		string GetNome_do_jogador();
		// Sets:
		string SetNome_do_jogador(char);
		void SetMemoria_de_jogo(int);
		void SetFicheiro(int);
		
		void Carregar_jogo(int);// carrega o jogo.
		
		
	protected:

		int memoria[2];
		int memoria_de_jogo;
		string nome_do_jogador;
		int Ficheiro;
		
		string Menu[Ymax][Xmax];
		
};

#endif
