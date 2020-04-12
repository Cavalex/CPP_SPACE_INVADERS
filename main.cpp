#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <conio.h>
#include <unistd.h>
#include <ctime>

#include "Entity.cpp"
#include "Enemy.cpp"
// O Menu ainda não está a dar e não nos precisamos de preocupar com isso agora
#include "Player.cpp"
#include "Timer.cpp"
#include "Game.cpp"
// Não podemos incluir a classe Shot pq já está incluída no Player.cpp
//#include "Shot.cpp"
//#include "GlobalSettings.cpp"

using namespace std;

// AGORA O JOGO
int main(){

	// Mudar o tamanho da consola
	SetConsoleSize(WIDTH, HEIGHT);
	
	// Só para "limpar" o fundo, relativamete inútil
	ClearScreen(bgChar);

	// Criar o jogo com 20 inimigos e 1 jogador
	Game game = Game(20, 1);
	game.start();
	
	// Pausar consola até o user premir o Enter
	cin.get();
	return 0;
}
