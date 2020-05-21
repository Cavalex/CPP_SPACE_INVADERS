#include "Carr_Guar.h"// inclusão da class Carr_Guar
#include <Windows.h>// função gotoxy( x , y )
#include <iostream>
#include <string> // biblioteca de strings
#include <fstream> // streams de ficheiros
#include <conio.h> // Kbhit()
#include <sstream> // streams de strings
// defines para ler teclas "arrow": 
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ENTER 13


#define Ymax 21
#define Xmax 66

using namespace std;

void gotoxy(int x, int y) //função para mudar a posiçao do cursor que recebe dois valores que vão servir de coordenadas
{
    COORD P={x,y};//criar um ponto com coordenadas
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),P);//mover o cursor para o ponto
}

//confimação que o ficheiro existe:
int Carr_Guar::Fich_confirm(int opcao){
	if(opcao ==1){
		ifstream s1("guardar jogo 1.txt");
		ifstream s2("guardar jogo 2.txt");
		ifstream s3("guardar jogo 3.txt");
		
		if (s1 == NULL){
		
			system ("cls");
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t    FILE NOT FOUND \n\t\t\t\t      ERROR 404"<< endl;
			sleep(2);
			system("cls");
			s1.close();
			return 5;
		}else {
			s1.close();
			return opcao;
		}
		
	}	
		
	if( opcao == 2){
		ifstream s2("guardar jogo 2.txt");
		if (s2 == NULL){
			system ("cls");
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t    FILE NOT FOUND \n\t\t\t\t      ERROR 404"<< endl;
			sleep(2);
			system("cls");
			s2.close();
			return 5;
		}else {
			s2.close();
			return opcao;
		}
	}
		
	if( opcao == 3 ){
		ifstream s3("guardar jogo 3.txt");
		if (s3 == NULL){
			system ("cls");
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t    FILE NOT FOUND \n\t\t\t\t      ERROR 404"<< endl;
			sleep(2);
			system("cls");
			s3.close();
			return 5;
		}else {
			s3.close();
			return opcao;
		}
	}		
} 

// Gets:
string Carr_Guar::GetNome_do_jogador(){
	return nome_do_jogador; 
}

int Carr_Guar::GetMemoria_de_jogo(){
	return memoria_de_jogo;
}
int Carr_Guar::GetFicheiro(){
	return this->Ficheiro; 
}
//Sets
void Carr_Guar::SetNome_do_jogador(string nome){
	this-> nome_do_jogador = nome;
}

void Carr_Guar::SetMemoria_de_jogo(int i){
	this-> memoria_de_jogo = i;
}

void Carr_Guar::SetFicheiro(int fich){
	this->Ficheiro = fich;
}

 Carr_Guar::Menu_Carregar_Guardar_jogo(int op){//construção dos desenhos permanentes 
	int v=0;//inteiro para indicar as possições das strings abaixo:
	int MAX;
	if(op==1){
		 MAX=8;
	}else{
		 MAX=11;
	}
	// numero "1":
	int UM [30]= {0  ,0   , 220,220 , 0  ,0,
				  223,0   , 219,219 , 0  ,0,
				  0  ,0   , 219,219 , 0  ,0,
				  0  ,0   , 219,219 , 0  ,0,
				  220,0   , 219,219 , 220,220};
	// numero "2":
	int DOIS [30]= {0  ,220 , 220,0 , 220,0,
				    223,0   , 0  ,0 , 219,219,
				    0  ,0   , 0  ,0 , 219,223,
				    220,223 , 223,0 , 0  ,0,
				    219,220 , 220,0 , 219,219};
	// numero "3":
	int TRES [30]= {0  ,0   , 220,220 , 0  ,0,
				    223,0   , 0  ,0   , 219,219,
				    0  ,0   , 220,220 , 223,223,
				    0  ,0   , 0  ,0   , 219,219,
				    223,0   , 220,220 , 223,223};
	
	string nome1, nome2, nome3;// nomes gravados nos ficheiros.
	string estado1, estado2, estado3;// memorias de jogo gravados nos ficheiros.
	string load_a_game ="LOAD A GAME";
	string New_game= "NEW GAME";
	string back ="BACK";
	string slot ="SLOT";
	string name = "NAME:";
	string level ="LEVEL:";
	
	int lenn1, lenn2, lenn3, lene1, lene2, lene3;
	//REPRESENTAÇÃO DOS LIMITES, LINHAS, ESPAÇOS VAZIOS E PREENCHIDOS:
	for(int i=0;i<Ymax;i++){// "0" a "21" linhas.
		for(int j=0;j<Xmax;j++){// "0" a "66" colunas.
			if(i<3 && ((j>=0 && j<=22 )|| (j>=44 && j<66))){
				Menu[i][j]=219; 
			}else if(i==0 || j==0 || i== Ymax-1 || i== Ymax-4 || j== Xmax-1 || ((j==22||j==44) && (i>2&&i<Ymax-4))){
				Menu[i][j]=223;
			}else if(i==2 && (j>22 && j<44 )){
				Menu[i][j]=220;	
			}
			else {
				Menu[i][j]=' ';
			}
		}
	}
	// REPRESENTAÇÃO DOS NOMES E MEMORIA DE JOGO GUARDADOS NOS FICHEIROS:
	ifstream guardar1 ("guardar jogo 1.txt");// ficheiro 1
	if(guardar1== NULL){// Caso o ficheiro 1 não exista, fazer:
		nome1= "ERROR";
		estado1 = "404";
	}else{
		guardar1 >> nome1 >> estado1; 
		guardar1.close();
		if(estado1=="4"){
			estado1="BOSS";// sbstitui o "level: 3" por "level: BOSS 1" 
		}
	}
	
	ifstream guardar2 ("guardar jogo 2.txt");	
	if(guardar2== NULL){// Caso o ficheiro 2 não exista, fazer:
		nome2= "ERROR";
		estado2 ="404";
	}else{
		guardar2 >> nome2 >> estado2; 
		guardar2.close();
		if(estado2=="4"){
			estado2="BOSS";// sbstitui o "level: 3" por "level: BOSS 1"
		}
	}
	
	ifstream guardar3 ("guardar jogo 3.txt");
	if(guardar3== NULL){// Caso o ficheiro 3 não exista, fazer:
		nome3= "ERROR";
		estado3 = "404";
	}else{
		guardar3 >> nome3 >> estado3; 
		guardar3.close();
		if(estado3=="4"){
			estado3="BOSS";// sbstitui o "level: 3" por "level: BOSS 1"
		}
	}
	//atribuição dos tamanhos das strings:
	lenn1=nome1.length();
	lene1=estado1.length();
	lenn2=nome2.length();
	lene2=estado2.length();
	lenn3=nome3.length();
	lene3=estado3.length();
	
	// REPRESENTAÇÃO DAS STRINGS NA MATRIZ:
	for(int j=0;j<MAX;j++){// máx de posições com carateres = 11, a contar com o "0" ( "0 a 10 posições" ).
		if(MAX==8){
			Menu [1][28 + j]=New_game[j];
		}	
		if(MAX==11){
			Menu [1][28 + j]=load_a_game[j];// 11 caracteres.
		}
		
		if(j<=4){// 4 caracteres
			Menu [ 4][8  + j]=slot[j];	
			Menu [ 4][30 + j]=slot[j];
			Menu [ 4][52 + j]=slot[j];
			Menu [18][30 + j]=back[j];
		}
		if(j<=5){// 5 caracteres.
			Menu [14][4  + j]=name[j];
			Menu [14][26 + j]=name[j];
			Menu [14][48 + j]=name[j];
		}
		if(j<=6){// 6 caracteres.
			Menu [15][4  + j]=level[j];
			Menu [15][26 + j]=level[j];
			Menu [15][48 + j]=level[j];
		}
		// representação dos nomes e dos niveis guardados em todos od ficheiros (ficheiro NULL tem o nome "ERROR" e nivel "404".
		if(j<lenn1){//nome de ficheiro 1
			Menu [14][11 + j]=nome1[j];
		}
		if(j<lene1){// nivel de ficheiro 1
			Menu [15][12 + j]=estado1[j];
		}
		if(j<lenn2){//nome de ficheiro 2
			Menu [14][33 + j]=nome2[j];
		}
		if(j<lene2){// nivel de ficheiro 2
			Menu [15][34 + j]=estado2[j];
		}
		if(j<lenn3){//nome de ficheiro 3
			Menu [14][55 + j]=nome3[j];
		}
		if(j<lene3){// nivel de ficheiro 3
			Menu [15][56  + j]=estado3[j];
		}
	}
	
	//REPRESENTAÇÃO DOS DESENHOS DOS NUMEROS "1", "2", "3":
	for(int i=0;i<5;i++){// 5 linhas.
		for(int j=0;j<6;j++){// 6 colunas.
			Menu[7+i][8+j]=UM[v];// "1".
			Menu[7+i][30+j]=DOIS[v];// "2".
			Menu[7+i][52+j]=TRES[v];// "3".
			v++;
		}
	}

}

// GUARDAR O JOGO:
void Carr_Guar::Guardar_jogo(int opcao, int estado, string nome){
	
	if(opcao==1){// caso , o jogo esteja carregado no ficheiro 1, entrar aqui:
		ofstream guardar1 ("guardar jogo 1.txt");// Abre o ficheiro para escrita.
		guardar1 << nome << " " << estado; 
		guardar1.close();// fecha o ficheiro.
	}
		
	else if(opcao==2){// caso , o jogo esteja carregado no ficheiro 2, entrar aqui:
		ofstream guardar2 ("guardar jogo 2.txt");// Abre o ficheiro para escrita.
		guardar2 << nome << " " << estado; 
		guardar2.close();// fecha o ficheiro.
	}
		
	else if(opcao==3){// caso , o jogo esteja carregado no ficheiro 3, entrar aqui:
		ofstream guardar3 ("guardar jogo 3.txt");// Abre o ficheiro para escrita.
		guardar3 << nome << " " << estado; 
		guardar3.close();// fecha o ficheiro.
	}
}
// CARREGAR JOGO:
void Carr_Guar::Carregar_jogo(int opcao){
		string nome; 
		int estado;
		if(opcao==1){// caso a Opção do player seja o ficheiro 1, fazer:
		ifstream guardar1 ("guardar jogo 1.txt");
		if(guardar1== NULL){// caso não abra:
			this-> memoria_de_jogo=404;
		}else{
			guardar1 >> nome >> estado; 	
		} 
		guardar1.close();//fecha ficheiro.
	}
		
	else if(opcao==2){// caso a Opção do player seja o ficheiro 2, fazer:
		ifstream guardar2 ("guardar jogo 2.txt");
		if(guardar2== NULL){// caso não abra:
			this-> memoria_de_jogo=404;
		}else{
			guardar2 >> nome >>estado; 	
		}
		guardar2.close();//fecha ficheiro.
	}
		
	else if(opcao==3){// caso a Opção do player seja o ficheiro 3, fazer:
		ifstream guardar3 ("guardar jogo 3.txt");
		if(guardar3== NULL){// caso não abra:
			this-> memoria_de_jogo=404;
		}else{
			guardar3 >> nome >> estado; 	
		} 
		guardar3.close();//fecha ficheiro.
	}
	this->nome_do_jogador = nome;
	this->Ficheiro = opcao;
	this->memoria_de_jogo = estado;
}

// CONTROLO DO PLAYER E DESENHOS VARIAVEIS:
int Carr_Guar::Menu_Controlo_player( int op_menu){
	char botao;
	int opcao=1;// Variavel retornada pelo "ENTER".
	char ponteiro = 254;// Representação do indicador da opção.
	int j=13;// j= x + 43.
	int i=4;// i= y + 10.
	// Posição inicial do ponteiro.
	gotoxy( 12+j,6 + i);// 
	cout << ponteiro;
	// Ciclo infiníto:
	for(;;){
		if(kbhit()){ //lê se algum botão foi premido.
				botao=getch();	// dá valor ao botão.	
		}else {
			botao=' ';
		}
		switch (botao){
			case 77: //direita
				if(opcao<3){// limite do funcionamento
					gotoxy( 12+j,6 + i);
					cout<<" ";// Apaga
					j+=22;// soma +22 ao "j".
					gotoxy( 12+j,6 + i);
					cout << ponteiro;// Imprime a nova posição do "ponteiro".
					opcao++;// soma +1 à "opcao".
				}
				break;
				
			case 75: //Esquerda
				if(opcao > 1 && opcao <=3){// limite do funcionamento
					gotoxy( 12+j,6 + i);
					cout<<" ";// Apaga
					j-=22;// Decrementa -22 ao "j".
					gotoxy( 12+j,6 + i);
					cout << ponteiro;// Imprime a nova posição do "ponteiro".
					opcao--;// Decrementa -1 à "opcao".
				}
				break;
				
			case 80: //baixo
				if(opcao<=3){// Condição do funcionamento
					gotoxy( 12+j,6 + i);
					cout<<" ";// Apaga
					this-> memoria[0] = opcao ;// guarda a "opcao", para mais tarde ser recuperada.
					this-> memoria[1] = j;// guarda o "j", para mais tarde ser recuperado.
					i=18;// linha do "BACK".
					j=35;// coluna Mais á direita do "BACK".
					gotoxy( 12+j,6 + i);
					cout << ponteiro;// Imprime a nova posição do "ponteiro".
					opcao = 4;	
				}
				break;
			
			case KEY_UP: //cima
				if(opcao==4){// condição do funcionamento
					gotoxy( 12+j,6 + i);
					cout<<" ";// Apaga
					j= memoria[1];// Recupera o "j".
					i=4;// linha dos slots
					gotoxy( 12+j,6 + i);
					cout << ponteiro; // Imprime a nova posição do "ponteiro".
					opcao= memoria[0];// Recupera a "opcao".			
				}
				break;
			case ENTER: //ENTER
					if(op_menu==2){
						opcao = Fich_confirm(opcao);	
					}
					system("cls");// Apaga o ecrã.
					
					return opcao;// retorna a variavel "opcao".
				break;
		}
	}
}

void Carr_Guar::Print_Menu(){
	cout<<"\n\n\n\n\n\n";// cursor = 6 + y;
	cout<<"            ";// cursor = 12 + x;
	for(int i=0;i<21;i++){
		for(int j=0;j<66;j++){
			cout<< Menu[i][j];
		}
		cout<< "\n            ";
	}
}

//função de Novo Jogo:
string Carr_Guar::Nome(){
	string nome;
	int easter_Egg = 0;
	
	int len ;
	do{
		char botao;
		cout<< "\n\n\n\n\t\tENTER YOUR NAME:_ _ _ _ (MAX 4 CHARACTERS!)\n\t\t:"	;
		cin >> nome;// nome criado pelo utilizador.
		len=nome.length();// atribui o tamanho da string
		if(len>4){// easter egg : Dumb.
			system("cls");	
			if(easter_Egg==0){
				cout<< "\n\n\n\n\t\t\t\tReally? ";
				sleep(3);
				easter_Egg++;
				system("cls");	
			}else if(easter_Egg==1){
				cout << "\n\n\n\n\t\tITS JUST 4 LETTERS!!! COME ON IT'S NOT THAT HARD..";
				sleep(4);
				easter_Egg++;
				system("cls");
			}else if(easter_Egg==2){
				cout << "\n\n\n\n\t\t\tFINE!!... here, I'll help you.. hehe";
				sleep(4);
				nome= "Dumb";
				system("cls");
				break;
			}
		}
	}while(len>4);
	if (easter_Egg ==2){
		cout<< "\n\n\n\n\t\t YOUR NAME TAG IS: "<< nome;
		sleep(2);
		cout<< "\n\n\t\t  AH AH Perfect!" ;
		sleep(2);
	}else{
		cout<< "\n\n\n\n\t\t YOUR NAMETAG IS: "<< nome;
		sleep(4);
	}
	system("cls");

	return nome; //retorna para o nivel 1
}


