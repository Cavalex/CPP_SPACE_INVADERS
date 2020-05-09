#include<iostream>
#include<Windows.h>
#include<string>
#include<conio.h>
#include<Time.h>

#include "GlobalSettings.cpp"

#define TAMANHO_X 21

#define KEY_UP 72 //tecla seta para cima
#define KEY_DOWN 80//tecla seta para baixo
#define ENTER 13//tecla enter

//int cx=(TAMANHO_X-WIDTH)/2;
int cx = 0;
//int cy=HEIGHT/4;
int cy = 0;

using namespace std;

void gotoxy(int x, int y) //fun��o para mudar a posi�ao do cursor que recebe dois valores que v�o servir de coordenadas
{
    COORD P={x,y};//criar um ponto com coordenadas
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),P);//mover o cursor para o ponto
}

void logo(void)//fun��o para desenhar logotipo inicial
{
	int x,y;
	int linhasl=0;//variaveis para centrar
	int desenho[20][55]={
	0,0,0,0,0,0,0,0,0,0,0,0,178,178,178,178,0,0,64,64,64,64,64,0,0,0,0,178,178,0,0,0,0,178,178,178,0,0,0,0,0,178,178,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,178,0,0,0,0,178,0,64,0,0,0,0,64,0,0,47,0,0,92,0,0,178,0,0,0,178,0,0,0,47,178,178,92,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,178,0,0,0,178,178,0,64,0,0,0,0,64,0,178,0,42,42,0,178,0,178,0,0,0,0,178,0,178,47,0,0,92,178,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,178,0,0,178,178,0,64,0,0,0,0,64,0,178,92,0,0,47,178,0,178,0,0,0,0,0,0,178,178,178,178,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,178,0,0,0,0,64,64,64,64,64,0,0,178,0,178,178,0,178,0,178,0,0,0,0,0,0,178,178,178,178,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,178,0,0,0,64,0,0,0,0,0,0,178,0,0,0,0,178,0,178,0,0,0,0,0,0,178,178,178,178,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,178,178,0,0,178,0,0,64,0,0,0,0,0,0,178,0,0,0,0,178,0,178,0,0,0,0,178,0,178,92,0,0,47,178,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,178,178,0,0,0,178,0,64,0,0,0,0,0,0,178,0,0,0,0,178,0,178,0,0,0,178,0,0,0,92,178,178,47,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,178,178,178,178,0,0,64,0,0,0,0,0,0,178,0,0,0,0,178,0,0,178,178,178,0,0,0,0,0,178,178,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,95,95,0,0,95,95,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,157,157,157,157,157,157,0,124,124,0,0,124,124,0,92,0,0,0,0,0,47,0,0,88,88,88,88,0,0,178,178,178,178,178,0,0,0,0,178,178,0,0,0,0,0,0,0,0,47,178,178,178,178,92,
	0,0,0,157,157,0,0,0,124,124,0,0,124,124,0,0,92,0,0,0,47,0,0,0,88,0,0,88,0,0,0,178,0,0,0,178,0,0,178,0,0,178,0,0,169,169,169,169,0,178,0,0,0,0,178,
	0,0,0,157,157,0,0,0,124,0,124,0,124,124,0,0,0,92,0,47,0,0,0,88,88,0,0,88,88,0,0,178,0,0,0,178,0,178,0,0,0,0,178,0,169,0,0,169,0,178,0,0,0,0,0,
	0,0,0,157,157,0,0,0,124,0,0,124,124,124,0,92,0,0,118,0,0,47,0,88,88,0,0,88,88,0,0,178,0,0,0,178,0,0,178,0,0,0,0,0,169,0,0,169,0,178,0,0,0,0,0,
	0,0,0,157,157,0,0,0,124,124,0,0,124,124,0,0,92,0,0,0,47,0,0,88,88,0,0,88,88,0,178,178,178,0,0,178,0,0,178,0,0,0,0,0,169,0,0,169,0,88,178,178,178,178,92,
	0,0,0,157,157,0,0,0,124,124,124,0,0,124,0,0,0,92,0,47,0,0,0,88,88,88,88,88,88,0,0,178,0,0,0,178,0,178,178,178,178,178,0,0,169,169,169,169,0,178,0,0,0,0,178,
	0,0,0,157,157,0,0,0,124,124,0,124,0,124,0,92,0,0,118,0,0,47,0,88,0,0,0,0,88,0,0,178,0,0,0,178,0,0,178,0,0,0,0,0,169,169,0,0,0,92,178,178,178,178,178,
	0,0,0,157,157,0,0,0,124,124,0,0,124,124,0,0,92,0,0,0,47,0,0,88,0,0,0,0,88,0,0,178,0,0,0,178,0,0,178,0,178,178,0,0,169,0,169,0,0,0,0,0,0,0,178,
	0,157,157,157,157,157,157,0,124,124,0,0,124,124,0,0,0,92,0,47,0,0,0,88,0,0,0,0,88,0,178,178,178,178,178,0,0,178,178,178,0,0,178,0,169,0,0,169,0,178,178,178,178,178,47,
	0,0,0,0,0,0,0,0,238,238,0,0,238,238,0,0,0,0,118,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    };//matriz com caracteres do desenho do mapa usando a tabela ASCII
	for(x=0;x<20;x++)//desenhar a matriz no ecr�
	{
		linhasl++;
		gotoxy(cx,linhasl+cy);
		for(y=0;y<54;y++)
		{
		    cout<<(char)desenho[x][y];	
		}
		cout<<endl;
	}
	Sleep(2500);//tempo final
}

int menu(void)//retorna o numero da op��o
{
	system("cls");//limpar ecr�
	int linhasr=0,linhasret=0;//centrar
	char m[TAMANHO_X][67]={0};//matriz nula
	char r[TAMANHO_X-2][20]={
	0,0,0,0,0,0,0,0,0,178,178,178,178,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,178,0,0,0,0,178,0,0,0,0,0,0,
	178,178,178,0,0,0,0,178,0,0,0,0,0,0,178,0,0,0,0,0,
	0,0,178,178,0,0,178,0,0,0,0,0,0,0,0,178,0,0,0,0,
	178,178,178,178,0,0,178,0,0,178,178,178,178,0,0,178,0,0,0,0,
	0,0,0,178,0,0,178,0,0,178,178,178,178,0,0,178,0,0,0,0,
	0,0,0,178,0,0,178,0,0,0,0,0,0,0,0,178,0,0,0,0,
	0,0,0,178,0,178,178,0,0,0,0,0,0,0,0,178,178,0,0,0,
	0,0,0,178,178,178,0,0,0,0,0,0,0,0,0,0,178,178,178,0,
	0,0,0,0,0,178,0,178,'-','-','-','-','-','-',178,0,178,0,178,0,
	0,0,0,0,0,178,0,'|',92,0,0,0,0,'/','|',0,178,0,178,0,
	0,0,0,0,0,178,0,'|',0,178,178,178,178,0,'|',0,178,0,178,0,
	0,0,0,0,0,178,0,'|',0,178,178,178,178,0,'|',0,178,0,178,0,
	0,0,0,0,0,178,0,'|','/',0,0,0,0,92,'|',0,178,178,178,178,
	0,0,0,0,0,178,0,178,'-','-','-','-','-','-',178,0,178,178,0,178,
	0,0,0,0,0,178,0,0,0,0,0,0,0,0,0,0,178,178,0,178,
	0,0,0,0,0,0,178,0,178,178,178,178,178,178,0,178,0,0,0,0,
	0,0,0,0,0,0,178,0,178,0,0,0,0,178,0,178,0,0,0,0,
	0,0,0,0,0,0,178,178,178,0,0,0,0,178,178,178,0,0,0,0
	};//matriz do robot
	string n="-New Game";
	string l="-Load Game";
	string h="-High Score";
	string c="-Credits";
	string e="-Exit";
	char a[3]={195,205,206};//desenhar o selecionador
	for(int x=0;x<21;x++)//desenho dos extremos do ret�ngulo no ecr�
	{
		linhasret++;
		gotoxy(cx,linhasret+cy);
		for(int y=0;y<67;y++)
		{
			m[0][y]=178;
			m[x][0]=178;
			m[x][66]=178;
			m[20][y]=178;
			cout<<m[x][y];
		}
		cout<<endl;
	}
	for(int x2=0;x2<19;x2++)
	{   
	    linhasr++;
	    gotoxy(40+cx,linhasr+cy+1);//posi�ao do robo
		for(int y2=0;y2<20;y2++)
		{
			cout<<r[x2][y2];
		}
		cout<<endl;
	}//desenhar robo
	gotoxy(28+cx,5+cy);
	cout<<"SPACE INVADERS";
	gotoxy(10+cx,8+cy);
	cout<<n;//escrever no ecr� a op��o "New Game"
	gotoxy(33+cx,8+cy);
	cout<<"U";
	gotoxy(33+cx,9+cy);
	cout<<"M";
	gotoxy(33+cx,10+cy);
	cout<<"I";
	gotoxy(33+cx,11+cy);
	cout<<"N";
	gotoxy(33+cx,12+cy);
	cout<<"H";
	gotoxy(33+cx,13+cy);
	cout<<"O";
	gotoxy(10+cx,10+cy);
	cout<<l;//escrever no ecr� a op��o "Load Game"
	gotoxy(10+cx,12+cy);
	cout<<h;//escrever no ecr� a op��o "High Score"
	gotoxy(10+cx,14+cy);
	cout<<c;//escrever no ecr� a op��o "Credits"
	gotoxy(10+cx,16+cy);
	cout<<e;//escrever no ecr� a op��o "Exit"
	gotoxy(5+cx,8+cy);
	cout<<a;//desenha o cursor que se vai mover entre posi��es
	gotoxy(80+cx,22+cy);//tirar para fora do menu
	int x1=5,y1=8;//posi��o inicial do cursor
	x1+=cx;
	y1+=cy;
	do
	{
		int tecla=0;//guardar o n�mero da tecla pressionada
		do
		{
		    tecla=getch();//n�mero da tecla
		}while((tecla!=KEY_DOWN) && (tecla!=KEY_UP) && (tecla!=ENTER));
		switch (tecla)
		{
			case KEY_DOWN://seta para baixo
				gotoxy(x1,y1);//posi��o do cursor
				cout<<"   ";//apagar o cursor de sele��o
				y1+=2;//somar na posi��o y1
				if(y1<17+cy && y1>7+cy)//mover entre as op��es
				{
				    gotoxy(x1,y1);
				    cout<<a;
				    gotoxy(80+cx,22+cy);
				}
				else//se chegar ao fim das op��es volta ao inicio das op��es
				{
					y1=8+cy;
					gotoxy(x1,y1);
					cout<<a;
					gotoxy(80+cx,22+cy);
				}
				break;
			case KEY_UP://seta para cima
				gotoxy(x1,y1);//posi��o do cursor
				cout<<"   ";//apagar o cursor de sele��o
				y1-=2;//subtrair na posi��o y1
				if(y1<17+cy && y1>7+cy)//mover entre as op��es
				{
				    gotoxy(x1,y1);
				    cout<<a;
				    gotoxy(80+cx,22+cy);
				}
				else//se chegar ao inicio das op��es volta ao fim das op��es
				{
					y1=16+cy;
					gotoxy(x1,y1);
					cout<<a;
					gotoxy(80+cx,22+cy);
				}
				break;
			case ENTER://dependendo da sele��o selecionada retorna um n�mero
				system("cls");//limpar ecr� para abrir op��o selecionada
				y1-=cy;
				switch(y1)//op�ao do menu
				{
					case 8:
						return 1;
						break;
					case 10:
						return 2;
						break;
					case 12:
						return 3;
						break;
					case 14:
						return 4;
						break;
					case 16:
						return 5;
						break;
				}
				break;
	    }
	}while(1);
}


