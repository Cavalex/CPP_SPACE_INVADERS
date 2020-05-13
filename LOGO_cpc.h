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
#define KEY_RIGHT 77
#define KEY_LEFT 75

//int cx=(TAMANHO_X-WIDTH)/2;
int cx = 0;
//int cy=HEIGHT/4;
int cy = 0;

using namespace std;

void logo(void)//fun��o para desenhar logotipo inicial
{
	int x,y;
	int linhasl=0,a,b;//variaveis para centrar
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
	a=(WIDTH-54)/2;
	b=(HEIGHT-20)/2;
	for(x=0;x<20;x++)//desenhar a matriz no ecr�
	{	
		gotoxy(a,b+linhasl);
		linhasl++;
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
	char m[21][67]={0};//matriz nula
	char r[19][20]={
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
	cx=(WIDTH-66)/2;
	cy=(HEIGHT-20)/2;
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
	gotoxy(0,0);//tirar para fora do menu
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
				    gotoxy(0,0);
				}
				else//se chegar ao fim das op��es volta ao inicio das op��es
				{
					y1=8+cy;
					gotoxy(x1,y1);
					cout<<a;
					gotoxy(0,0);
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
				    gotoxy(0,0);
				}
				else//se chegar ao inicio das op��es volta ao fim das op��es
				{
					y1=16+cy;
					gotoxy(x1,y1);
					cout<<a;
					gotoxy(0,0);
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

bool menu_credits()
{
	
	int cx,cy,linhasret=0,tecla;
	char m[21][67]={0};//matriz nula
	cx=(WIDTH-66)/2;
	cy=(HEIGHT-20)/2;
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
	gotoxy(cx+28,cy+3);
	cout<<"Creditos"<<endl<<endl<<endl;
	gotoxy(cx+1,cy+7);
	cout<<"Trabalho realizado por:";
	gotoxy(cx+3,cy+10);
	cout<<"-Marco Oliveira A91945;";
	gotoxy(cx+3,cy+12);
	cout<<"-Marco Cunha A91981;";
	gotoxy(cx+3,cy+14);
	cout<<"-Matheus Costa A91997";
	gotoxy(cx+3,cy+16);
	cout<<"-Mateus Medeiros Pereira A91924";
	gotoxy(cx+3,cy+18);
	cout<<"-Joao Manuel Alves Pereira A91919";
	gotoxy(cx+5,cy+20);
	cout<<"Press Enter to back...";
	do
	{
	    tecla=getch();//n�mero da tecla
	if(ENTER==tecla)
	{
		system("cls");
		return true;
	}
    }while(ENTER!=tecla);
}

bool menu_Exit()
{
	int cx,cy,linhasret=0,tecla,option=0;
	char m[21][67]={0};//matriz nula
	cx=(WIDTH-66)/2;
	cy=(HEIGHT-20)/2;
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
	gotoxy(cx+20,cy+8);
	cout<<"Do you want to exit the game?"<<endl;
	gotoxy(cx+28,cy+15);
	cout<<"YES OR NO";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);
	gotoxy(cx+28,cy+15);
	cout<<"YES";
	option=2;
	gotoxy(0,0);
	do
	{
	do
	{
		tecla=getch();//n�mero da tecla
	}while(tecla!=ENTER && tecla!=KEY_RIGHT && tecla!=KEY_LEFT);
	switch(tecla)
	{
		case KEY_RIGHT:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
			gotoxy(cx+28,cy+15);
			cout<<"YES";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);
			gotoxy(cx+35,cy+15);
			cout<<"NO";
			option=1;
			gotoxy(0,0);
			break;
		case KEY_LEFT:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
			gotoxy(cx+35,cy+15);
			cout<<"NO";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);
			gotoxy(cx+28,cy+15);
			cout<<"YES";
			option=2;
			gotoxy(0,0);
			break;
		case ENTER:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
			system("cls");
			if(option==1)
			{
			    return true;
		    }
		    if(option==2)
		    {
		        return false;
		    }
			break;
	}
	}while(true);
}
