#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <conio.h>

#include "Entity.cpp"
//#include "Menu.cpp"
#include "Player.cpp"
//#include "Shot.cpp"
//#include "GlobalSettings.cpp"

using namespace std;

void SetConsoleSize(int width, int height){
	HANDLE wHnd;    // Handle to write to the console.
	HANDLE rHnd;

	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	rHnd = GetStdHandle(STD_INPUT_HANDLE);
    // Change the window title:
    SetConsoleTitle("Space Invaders!");
    
    // Set up the required window size:
    SMALL_RECT windowSize = {0, 0, width - 1, height - 1};
    COORD bufferSize = {width, height};
    
    SetConsoleWindowInfo(wHnd, 1, &windowSize);
    SetConsoleScreenBufferSize(wHnd, bufferSize);
}

void ClearScreen(const string& ch){
	for (int y = 0; y < HEIGHT; y++){
		for (int x = 0; x < WIDTH; x++){
			SetCursorPosition(x, y);
			cout << ch;
		}
	}
}

// AGORA O JOGO
/*
void movePlayer(int x, int y, int oldX = 0, int oldY = 0){
	SetCursorPosition(oldX, oldY);
	cout << bgChar;
	SetCursorPosition(x, y);
	cout << chPlayer;
}
*/
int main(){
	
	// Mudar o tamanho da consola
	SetConsoleSize(WIDTH, HEIGHT);
	//////////////////////////////
	/*
	int initX = WIDTH / 2;
	int initY = HEIGHT / 2;
	int oldX = initX;
	int oldY = initY;
	int x = initX;
	int y = initY;
	*/
	
	// NÃO ESTÁ A DAR
	// Talvez seja melhor não colocar o menu numa classe
	/*
	Menu menu = Menu();
	menu.showOptions();
	*/
	
	/*
	// posição inicial do jogador
	movePlayer(x, y);
		
	char key = getch();
    int value = key;
	*/
	
	// Desenhar esta entity
	Player hero = Player(WIDTH / 2, HEIGHT - 2, 1, 0, 'O', "Cavalex", 0);
	Entity e = Entity(50, 25, 2, 2, 'X');
	e.drawEntity();
	e.moveTo(5, 5);
	hero.shoot(1, 1, '|', 5);
	
	////////////////////// Game Loop
    //while(value != KEY_X){
    while(true){
    	hero.moveAction();
    	
    	/*
    	// Ultimos valores do player, para serem "limpos"
		oldX = x;
        oldY = y;
    	
    	// movimento
        switch(getch()){
	        case KEY_UP:
	            y -= 1;
	            break;
	        case KEY_DOWN:
	            y += 1;
	            break;
	        case KEY_LEFT:
	            x -= 1;
				break;
	        case KEY_RIGHT:
	            x += 1;
				break;
        }
		
		movePlayer(x, y, oldX, oldY);
		
        key = getch();
        value = key;
        */
    }
	
	cin.get();
	return 0;
}
