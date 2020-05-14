#include "HS.h"
#include <iostream>
#include <string>
#include <fstream> // ficheiros
#include <conio.h> // Kbhit()
#include <sstream>
// defines para ler teclas "arrow": 
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ENTER 13

//dimensões do menu
#define DMi 21
#define DMj 66

using namespace std;

void HS::Build_Menu_HS_constante(){
	int v=0, v1=0, v2=49, v3=0;
	char highscore[10]={'H','I','G','H',' ','S','C','O','R','E'};
	char back[4]={'B','a','c','k'};
	int taca[364]={ 0,0, 0,0, 0,0, 0,0, 0,1, 0,0, 0,0, 0,0, 1,0, 0,0, 0,0, 0,0, 0,0,
					0,0, 0,0, 0,0, 0,0, 0,0, 1,0, 0,0, 0,1, 0,0, 0,0, 0,0, 0,0, 0,0,
					0,0, 0,0, 0,0, 0,0, 0,0, 0,1, 0,0, 1,0, 0,0, 0,0, 0,0, 0,0, 0,0,
					0,0, 0,0, 1,1, 1,1, 1,1, 1,1, 1,1, 1,1, 1,1, 1,1, 1,1, 0,0, 0,0,
					0,0, 0,0, 1,1, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 1,1, 0,0, 0,0,
					0,0, 0,1, 1,1, 0,1, 2,2, 1,1, 1,1, 1,1, 2,2, 1,0, 1,1, 1,0, 0,0,
					0,0, 1,0, 1,1, 0,0, 2,2, 1,1, 1,1, 1,1, 2,2, 0,0, 1,1, 0,1, 0,0,
					0,1, 0,0, 1,1, 0,0, 0,0, 2,2, 1,1, 2,2, 0,0, 0,0, 1,1, 0,0, 1,0,
					0,0, 0,0, 1,1, 0,0, 0,0, 0,0, 1,1, 0,0, 0,0, 0,0, 1,1, 0,0, 0,0,
					0,0, 0,0, 1,1, 0,0, 0,0, 2,2, 2,2, 2,2, 0,0, 0,0, 1,1, 0,0, 0,0,
					0,0, 0,0, 1,1, 1,1, 1,1, 1,1, 1,1, 1,1, 1,1, 1,1, 1,1, 0,0, 0,0,
					0,0, 0,0, 0,0, 1,1, 0,0, 0,0, 0,0, 0,0, 0,0, 1,1, 0,0, 0,0, 0,0,
					0,0, 0,0, 3,3, 1,1, 0,0, 0,0, 0,0, 0,0, 0,0, 1,1, 3,3, 0,0, 0,0,
					0,0, 1,1, 2,2, 1,1, 0,0, 0,0, 0,0, 0,0, 0,0, 1,1, 2,2, 1,1, 0,0,};
					
	//construção das bordas e limites do menu highscore
	for(int i=0 ; i < DMi ; i++){
		for(int j=0 ; j<DMj ; j++){
			if(i==0 || i== DMi-1 || i==3 || (j== 31 &&(i!=1 && i!=2 && i!=3) )|| j== 0 || j== DMj-1){
				this -> Hs[i][j] =223;
			}else if(j==v1+27 && v1<10){
				this -> Hs[i][j]= highscore[v1];
				v1++;
			}else if((i==7|| i==9 || i== 11 || i== 13 || i== 15 || i==17) && j>40 && j<55){ 
				if(i==17 && v3!=4 && j>45){
					this -> Hs[i][j]=back[v3];// desenho do "Back"
					v3++;
				}
				else if(i!=17){
					this -> Hs[i][j]='.';//valores de '.'
				}else {
					this -> Hs[i][j]=' ';
				}
			}else if ((i==7|| i==9 || i== 11 || i== 13 || i== 15) && (j== 33 || j== 34)){//valores de '1', '2', '3' ...
				switch (j){
					case 34:
						this -> Hs[i][j]=169;
						break;
					case 33:
						this -> Hs[i][j]=v2;
						v2++;
						break;
				}
			}
			else {
				this -> Hs[i][j] =' ';
			}
		}
	}
	
	//construção do desenho taça:				
	for(int i=5 ; i < 19 ; i++){
		for(int j=3 ; j<29 ; j++){
			switch( taca[v]){
				case 1:
					this -> Hs[i][j] =219;
					break;
				case 2:
					this -> Hs[i][j] =223;
					break;
				case 3:
					this -> Hs[i][j] =220;
					break;
			}
			v++;
		}
	}
	
}

//vai buscar os scores aos ficheiros:
void HS::SetScore(int nivel){
		 if(nivel== 1){
		 ifstream nivel_1("s nivel1.txt");
			 nivel_1 >> this->nome1 >> this-> score1;
			 nivel_1 >> this->nome2 >> this-> score2;
			 nivel_1 >> this->nome3 >> this-> score3;
			 nivel_1 >> this->nome4 >> this-> score4;
			 nivel_1 >> this->nome5 >> this-> score5;
			 
			nivel_1.close();	
		 }
			 
		else if(nivel==2){
			 ifstream nivel_2("s nivel2.txt");
			 nivel_2 >> this->nome1 >> this-> score1;
			 nivel_2 >> this->nome2 >> this-> score2;
			 nivel_2 >> this->nome3 >> this-> score3;
			 nivel_2 >> this->nome4 >> this-> score4;
			 nivel_2 >> this->nome5 >> this-> score5;
			 
			 nivel_2.close();	
		}
		
		else if(nivel==3){
			 ifstream nivel_3("s nivel3.txt");
			 nivel_3 >> this->nome1 >> this-> score1;
			 nivel_3 >> this->nome2 >> this-> score2;
			 nivel_3 >> this->nome3 >> this-> score3;
			 nivel_3 >> this->nome4 >> this-> score4;
			 nivel_3 >> this->nome5 >> this-> score5;
			 
			nivel_3.close();
		}
		else{
			 ifstream nivel_boss ("s nivel boss.txt");
			 nivel_boss >> this->nome1 >> this-> score1;
			 nivel_boss >> this->nome2 >> this-> score2;
			 nivel_boss >> this->nome3 >> this-> score3;
			 nivel_boss >> this->nome4 >> this-> score4;
			 nivel_boss >> this->nome5 >> this-> score5;
			 
			nivel_boss.close(); 
		}
	//converção de string para inteiro:
	 stringstream s1(score1);
	 stringstream s2(score2);
	 stringstream s3(score3);
	 stringstream s4(score4);
	 stringstream s5(score5);
	 
	 s1 >> p1;
	 s2 >> p2;
	 s3 >> p3;
	 s4 >> p4;
	 s5 >> p5;

}


int HS:: High_score_player_control(int nivel){ // retorna o nivel (estado)
	
	char nl[5]={'L','E','V','E','L'};
	char nb[5]={'B','O','S','S',' '}, botao;
	if(nivel!=7){
		SetScore(nivel);
	}else{
		SetScore(this->memoria);
	}
	
	for(int i= 0;i<5;i++){
		if((  nivel ==4 ) && nivel !=7){
			this -> Hs[5][i+44]= nb[i];
			this -> Hs[5][50]=' ';
		}
		if( nivel !=4  && nivel !=7){
			this -> Hs[5][i+44]= nl[i];
			this -> Hs[5][ 50 ] = nivel +48;// em int -> 1( nivel) + 48 = 49 -> em char  int 49 = '1';
		}
	}
	//apaga o score e nome anterior
	for(int apaga=0 ; apaga < 6 ; apaga++){
		int linha =7;
		while(linha <=17){
			Hs[linha][apaga +36]= ' ';
			Hs[linha][apaga +56]= ' ';
			linha+=2;	
		}
		
	}
	// Atribuição dos tamanhos das strings dos nomes e dos scores:
	int lentn1 = nome1.length();
	int lentn2 = nome2.length();
	int lentn3 = nome3.length();
	int lentn4 = nome4.length();
	int lentn5 = nome5.length();
	
	int lents1 = score1.length();
	int lents2 = score2.length();
	int lents3 = score3.length();
	int lents4 = score4.length();
	int lents5 = score5.length();
	
	// Impressão dos Nomes associados aos Scores e vice-versa
	for(int numero_de_nomes_Imprimidos=0 ; numero_de_nomes_Imprimidos < 7;numero_de_nomes_Imprimidos++){
		int linha =7;
		// 1º lugar
		if(numero_de_nomes_Imprimidos < lentn1){
			Hs[linha][numero_de_nomes_Imprimidos + 36]= nome1[numero_de_nomes_Imprimidos ];
		}
		if(numero_de_nomes_Imprimidos < lents1){
			Hs[linha][numero_de_nomes_Imprimidos + 56]= score1[numero_de_nomes_Imprimidos ];
		}
		linha+=2;
		// 2º lugar
		if(numero_de_nomes_Imprimidos < lentn2){
			Hs[linha][numero_de_nomes_Imprimidos + 36]= nome2[numero_de_nomes_Imprimidos ];
		}
		if(numero_de_nomes_Imprimidos < lents2){
			Hs[linha][numero_de_nomes_Imprimidos + 56]= score2[numero_de_nomes_Imprimidos ];
		}
		linha+=2;
		// 3º lugar
		if(numero_de_nomes_Imprimidos < lentn3){
			Hs[linha][numero_de_nomes_Imprimidos + 36]= nome3[numero_de_nomes_Imprimidos ];
		}
		if(numero_de_nomes_Imprimidos < lents3){
			Hs[linha][numero_de_nomes_Imprimidos + 56]= score3[numero_de_nomes_Imprimidos ];
		}
		linha+=2;
		// 4º lugar
		if(numero_de_nomes_Imprimidos < lentn4){
			Hs[linha][numero_de_nomes_Imprimidos + 36]= nome4[numero_de_nomes_Imprimidos ];
		}
		if(numero_de_nomes_Imprimidos < lents4){
			Hs[linha][numero_de_nomes_Imprimidos + 56]= score4[numero_de_nomes_Imprimidos ];
		}
		linha+=2;
		// 5º lugar
		if(numero_de_nomes_Imprimidos < lentn5){
			Hs[linha][numero_de_nomes_Imprimidos + 36]= nome5[numero_de_nomes_Imprimidos ];
		}
		if(numero_de_nomes_Imprimidos < lents5){
			Hs[linha][numero_de_nomes_Imprimidos + 56]= score5[numero_de_nomes_Imprimidos ];
		}
		
	}
// possições iniciais dos ponteiros 
	Hs[ 5][42] ='<';
	Hs[ 5][52] ='>';
	Hs[17][51] =' ';
	// possições estéticas dos desenhos dos ponteiros ( exemplos: level 1 > ; < boss 2 ; Quando vai para o "Back":  level 2 )
	switch (nivel){
		case 1:
			this -> Hs[ 5][42] =' ';
			break;
		case 4:
			this ->Hs[5][52] = ' ';
			break;
		case 7:
			this -> Hs[17][51]= '<';
			this -> Hs[ 5][52]= ' ';
			this -> Hs[ 5][42] =' ';
			break;
	}
	
	Print_Menu(); //impressão do desenho em função da class Menu;
	for(;;){
		if(kbhit()){ //lê se algum botão foi premido
				botao=getch();		
		}else {
			botao=' ';
		}
		switch (botao){
			case 77: //direita
				if(nivel<4){
					nivel++;	
				}
				break;
			
			case 75: //esquerda
				if(nivel > 1 && nivel <5){
					nivel--;
				}
				break;
			case 80: //baixo
				if(nivel<7){
					this-> memoria = nivel;
					nivel = 7;	
				}
				break;
			
			case KEY_UP: //cima
				if(nivel==7){
					nivel= memoria;	
				}
				break;
			case ENTER: //enter
				if(nivel==7){ // sai do menu High Score
					system("cls");
					return 8;
				}
				break;
		}
		if(botao==72||botao==75||botao==80||botao==77){// permite sair só quando uma destas teclas for premida.
				break;
		}
	}
	system("cls");// apaga o ecrã.
	return nivel; // retorna o ultimo nivel obtido
}

//função que compara o score do jogo com os outros scores existentes 
void HS::Bubble_Sort_score(int score_Transporte, string nome_Transporte, int nivel){
    int v[5]; // vetor ordenador
	int guarda;// auxiliar inteiro
	SetScore( nivel);
// TRUE : quando o score_Transporte (score obtido num certo nivel) for maior do que o 5º lugar 
	if(score_Transporte > p5){		
 	  //transportar os valoes dos scores para um vetor
		v[0] = p1;
		v[1] = p2;
		v[2] = p3;
		v[3] = p4;
		v[4] = p5;
		v[5]= score_Transporte;
	   // bubble sort dos scores:
		for(int i=1;i<6;i++){		
			for(int j=0;j<5;j++){
				if( v[j]<v[j+1]){
					
					guarda=v[j];
					v[j]=v[j+1];
					v[j+1]=guarda;
					
				}
			}
		}
		// Associações de scores aos nomes:
		// Variaveis que impedem repetições de associações a scores iguais com nomes diferentes
		int n1=0,n2=0,n3=0,n4=0,n5=0,nt=0;
		// Tranfere os nomes para um ficheiro, para ordena-los: (o método resulta mas é duvidoso, agradecia sugestões)
		ofstream s ("Bubble Sort.txt");// abre o ficheiro para escrita;
		for(int i=0;i<5;i++){
				
			if(v[i]==p1 && n1==0){
			
				s << nome1 << endl;
				n1++;
			}
			if(v[i]==p2 && n2==0){
				s << nome2 << endl;
				n2++;
			}
			if(v[i]==p3 && n3==0){
				s << nome3 << endl;
				n3++;
			}
			if(v[i]==p4 && n4==0){
				s << nome4 << endl;
				n4++;
			}
			if(v[i]==p5 && n5==0){
				s << nome5 << endl;
				n1++;
			}
			if(v[i]==score_Transporte && nt==0){
				s << nome_Transporte << endl;
				nt++;
			}
		}
		s.close();// fecha ficheiro
		// vai buscar os nomes ordenados, para as strings de nomes  privados
		ifstream so ("Bubble Sort.txt");// abre o ficheiro para leitura
			so>> nome1;// 1º Lugar
			so>> nome2;// 2º Lugar
			so>> nome3;// 3º Lugar
			so>> nome4;// 4º Lugar
			so>> nome5;// 5º Lugar
			
			s.close();// fecha ficheiro;
	
	
			this -> p1 = v[0];// 1º Lugar
			this -> p2 = v[1];// 2º Lugar
			this -> p3 = v[2];// 3º Lugar
			this -> p4 = v[3];// 4º Lugar
			this -> p5 = v[4];// 5º Lugar
		Guarda_Score(nivel); // Guarda o score ordenado;
	}
}

// Guarda os nomes e os scores associados em função do "nivel" atribuido :
void HS::Guarda_Score(int nivel){
	if(nivel==1){// scores do nivel 1
		
		 ofstream nivel_1("s nivel1.txt");// Abre ficheiro para escrita
			 nivel_1 << this->nome1 << " " << this-> p1 << endl;
			 nivel_1 << this->nome2 << " " << this-> p2 << endl;
			 nivel_1 << this->nome3 << " " << this-> p3 << endl;
			 nivel_1 << this->nome4 << " " << this-> p4 << endl;
			 nivel_1 << this->nome5 << " " << this-> p5 << endl;
			 
			nivel_1.close();
	}
	if(nivel==2){// scores do nivel 2
		 ofstream nivel_2("s nivel2.txt");
			 nivel_2 << this->nome1 << " " << this-> p1 << endl;
			 nivel_2 << this->nome2 << " " << this-> p2 << endl;
			 nivel_2 << this->nome3 << " " << this-> p3 << endl;
			 nivel_2 << this->nome4 << " " << this-> p4 << endl;
			 nivel_2 << this->nome5 << " " << this-> p5 << endl;
			 
			nivel_2.close();
	}
	if(nivel==3){// scores do nivel nivel 3
		 ofstream nivel_3("s nivel3.txt");
			 nivel_3 << this->nome1 << " " << this-> p1 << endl;
			 nivel_3 << this->nome2 << " " << this-> p2 << endl;
			 nivel_3 << this->nome3 << " " << this-> p3 << endl;
			 nivel_3 << this->nome4 << " " << this-> p4 << endl;
			 nivel_3 << this->nome5 << " " << this-> p5 << endl;
			 
			nivel_3.close();
	}
	
	if(nivel==4){// scores do nivel boss
		 ofstream nivel_boss("s nivel boss.txt");
			 nivel_boss << this->nome1 << " " << this-> p1 << endl;
			 nivel_boss << this->nome2 << " " << this-> p2 << endl;
			 nivel_boss << this->nome3 << " " << this-> p3 << endl;
			 nivel_boss << this->nome4 << " " << this-> p4 << endl;
			 nivel_boss << this->nome5 << " " << this-> p5 << endl;
			 
			nivel_boss.close();
	}
}

void HS::Print_Menu(){// funçao da classe menu
	cout<< "\n\n\n\n\n		";
	for(int i=0 ; i < DMi ; i++){
		for(int j=0 ; j<DMj ; j++){
			cout<<  Hs[i][j];
		}
		cout<< "\n		";
	}
	
}
