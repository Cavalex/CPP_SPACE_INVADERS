#ifndef HS_H
#define HS_H
#include <iostream>
#include <string>
#define DMi 21
#define DMj 66
using namespace std;

class HS
{
	public:

		int High_score_player_control(int);// permite o controlo do player
		void Build_Menu_HS_constante();//constroi a estrutura permanente do menu high score;
		void Guarda_Score(int); // guarda o score em função do nivel
		void Print_Menu(); // função da class Menu
		void Bubble_Sort_score(int, string, int);// recebe o score do nivel e compara com os outros scores ja existentes 
		void SetScore(int);//função que vai buscar o score guardado num dos respetivos ficheiros associado ao nivel
		
		
	protected:
		string nome1,nome2,nome3,nome4, nome5;// nomes das entidades do top 5 melhores scores
		int p1, p2, p3, p4, p5, memoria; // scores inteiro
		string score1,score2,score3,score4,score5; //strings de score 
		char Hs[DMi][DMj]; // matriz de desenho do menu de high score
};

#endif
