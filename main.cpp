#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <conio.h>

#include "Entity.cpp"
#include "Enemy.cpp"
// O Menu ainda não está a dar e não nos precisamos de preocupar com isso agora
//#include "Menu.cpp"
#include "Player.cpp"
// Não podemos incluir a classe Shot pq já está incluída no Player.cpp
//#include "Shot.cpp"
//#include "GlobalSettings.cpp"

using namespace std;

// AGORA O JOGO
int main(){
	
	// Mudar o tamanho da consola
	SetConsoleSize(WIDTH, HEIGHT);
	
	ClearScreen(bgChar);
	
	Player hero = Player(WIDTH / 2, HEIGHT - 2, 1, 0, 'O', "Cavalex", 0);
	hero.drawEntity();
	
	/*
	Entity e = Entity(50, 25, 2, 2, 'X');
	e.drawEntity();
	e.moveTo(5, 5);
	*/
	// Ainda não consegue disparar, ver função Player::shoot()
	// hero.shoot(1, 1, '|', 5);
	
	Enemy e = Enemy(WIDTH / 2, 5, 2, 2, 'X', 1, 0, -1);
	
	int i = 0;
	int n = 1;
	//Game Loop
    while(true){
		if (hero.moveAction()){
			i += 1 * n;
			//cout << "AAAAAAAH";
		}
		else {
			i += 2 * n;
		}
		if (i % 10000 == 0){
			e.move();
		}
    }
	
	// Pausar consola até o user premir o Enter
	cin.get();
	return 0;
}
