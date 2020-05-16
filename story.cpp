#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <conio.h>
#include <unistd.h>
#include <ctime>
#include <vector>

#include "story.h"

using namespace std;
//funçao reticencias
void Story::reticencias(){
	for(int i = 0; i < 3; i++){
		Sleep(1000);
		cout << ".";	
	}
}



void Story::story_intro(){
	system ("CLS");
	SetCursorPosition(WIDTH/3 ,HEIGHT/3);
	cout << "In an alternate reality";
	reticencias();
	Sleep(2000);
	SetCursorPosition(WIDTH/3 ,(HEIGHT/3)+1);
	cout <<"The world was very similar to ours until WWII,";
	Sleep(3000);
	SetCursorPosition(WIDTH/3 ,(HEIGHT/3)+2);
	cout << "with one exception, better technology.";
	Sleep(3000);
	SetCursorPosition(WIDTH/3 ,(HEIGHT/3)+3);
	cout << "The nazis were able to escape planet Earth to the Moon, ";
	Sleep(3000);
	SetCursorPosition(WIDTH/3 ,(HEIGHT/3)+4);
	cout << "where they prepared and counter attacked.";
	Sleep(3000);
	SetCursorPosition(WIDTH/3 ,(HEIGHT/3)+5);
	cout <<"On Earth, contrary to our reality, there was a clear winner"; 
	Sleep(3000);
	SetCursorPosition(WIDTH/3 ,(HEIGHT/3)+6);
	cout << "to the not so \"cold war\", the Soviet Union.";
	Sleep(3000);
	SetCursorPosition(WIDTH/3 ,(HEIGHT/3)+7);
	cout << "And now, with your honor and determination, you,";
	Sleep(3000);
	SetCursorPosition(WIDTH/3 ,(HEIGHT/3)+8);
	cout << "our only elite pilot remaining,";
	Sleep(3000);
	SetCursorPosition(WIDTH/3 ,(HEIGHT/3)+9);
	cout << "are the future of the blue planet";
	reticencias();
	Sleep(3000);
	SetCursorPosition(WIDTH/3 ,(HEIGHT/3)+10);
	cout << "GO ON COMRADE, SAVE THE WORLD.";
//	Sleep(100);
	SetCursorPosition(0 ,HEIGHT-3);
	cout << " Press any key to continue.";	
	//esperar para que se prima uma tecla
	getch();
}

void Story::story_lvl1(){
	system ("CLS");
	SetCursorPosition(WIDTH/3 ,HEIGHT/3);
	cout << "The enemies are coming,";
	SetCursorPosition(WIDTH/3 ,(HEIGHT/3)+1);
	Sleep(2000);
	cout <<"they seem to bring only one wave of ships,";
	SetCursorPosition(WIDTH/3 ,(HEIGHT/3)+2);
	Sleep(2000);
	cout << "this should be an easy task for you!";
	SetCursorPosition(WIDTH/3 ,(HEIGHT/3)+3);
	Sleep(2000);	
	
	Sleep(100);
	SetCursorPosition(0 ,HEIGHT-3);
	cout << " Press any key to continue.";	
	//esperar para que se prima uma tecla
	getch();	
}


void Story::story_lvl2(){
	system ("CLS");
	SetCursorPosition(WIDTH/3 ,HEIGHT/3);
	cout << "WOW Great job, as expected!";
	SetCursorPosition(WIDTH/3 ,(HEIGHT/3)+1);
	Sleep(3000);
	cout << "But prepare for your next battle.";
	SetCursorPosition(WIDTH/3 ,(HEIGHT/3)+2);
	Sleep(3000);
	cout << "We'vecaught sight of more enemies, take care!";

	Sleep(100);
	SetCursorPosition(0 ,HEIGHT-3);
	cout << " Press any key to continue.";	
	//esperar para que se prima uma tecla	
	getch();	
}


void Story::story_lvl3(){
	system ("CLS");
	SetCursorPosition(WIDTH/3 ,HEIGHT/3);
	cout << "Awesomely done, pilot!";
	SetCursorPosition(WIDTH/3 ,(HEIGHT/3)+1);
	Sleep(2000);
	cout << "Let's end this.";
	SetCursorPosition(WIDTH/3 ,(HEIGHT/3)+2);
	Sleep(2000);
	cout << "The SS are the only ones left,";
	SetCursorPosition(WIDTH/3 ,(HEIGHT/3)+3);
	Sleep(2000);
	cout << "before facing Hitler!!";

	Sleep(100);
	SetCursorPosition(0 ,HEIGHT-3);
	cout << " Press any key to continue.";	
	//esperar para que se prima uma tecla
	getch();	
}

void Story::story_boss(){
	system ("CLS");
	SetCursorPosition(WIDTH/3 ,HEIGHT/3);
	cout << "You've made it this far.";
	SetCursorPosition(WIDTH/3 ,(HEIGHT/3)+1);
	Sleep(3000);
	cout << "After all these battles, it's now time to win the war!";
	SetCursorPosition(WIDTH/3 ,(HEIGHT/3)+2);
	Sleep(3000);
	cout << "Hitler himself is on the ship you're about to face.";
	SetCursorPosition(WIDTH/3 ,(HEIGHT/3)+3);
	Sleep(3000);
	cout << "Don't be overconfident my friend, this will NOT be easy";
	reticencias();
	SetCursorPosition(WIDTH/3 ,(HEIGHT/3)+4);
	Sleep(3000);
	cout << "YOU HAVE MY RESPECT SOLDIER, SAVE US!";
	
	Sleep(100);
	SetCursorPosition(0 ,HEIGHT-3);
	cout << " Press any key to continue.";	
	//esperar para que se prima uma tecla
	getch();
}

void Story::story_win(){
	system ("CLS");
	SetCursorPosition(WIDTH/3 ,HEIGHT/3);
	cout << "You";
	reticencias();
	SetCursorPosition(WIDTH/3 ,(HEIGHT/3)+1);
	Sleep(4000);
	cout << "you actually won,";
	SetCursorPosition(WIDTH/3 ,(HEIGHT/3)+2);
	Sleep(3000);
	cout << "YOU SAVED OUR PLANET,";
	SetCursorPosition(WIDTH/3 ,(HEIGHT/3)+3);
	Sleep(3000);
	cout << "YOU ARE A HERO!";
	
	Sleep(100);
	SetCursorPosition(0 ,HEIGHT-3);
	cout << " Press any key to continue.";	
	//esperar para que se prima uma tecla
	getch();
}

void Story::story_loss(){
	system ("CLS");
	SetCursorPosition(WIDTH/3 ,HEIGHT/3);
	cout << "Oh no";
	reticencias();
	SetCursorPosition(WIDTH/3 ,(HEIGHT/3)+1);
	Sleep(1500);
	cout << "You lost.";
	SetCursorPosition(WIDTH/3 ,(HEIGHT/3)+2);
	Sleep(1500);
	cout << "The world has been";
	SetCursorPosition(WIDTH/3 ,(HEIGHT/3)+3);
	Sleep(1000);
	cout << "taken by the nazis,";
	SetCursorPosition(WIDTH/3 ,(HEIGHT/3)+4);
	Sleep(1500);
	cout << "today is a sad day";
	reticencias();	

	Sleep(100);
	SetCursorPosition(0 ,HEIGHT-3);
	cout << " Press any key to continue.";	
	//esperar para que se prima uma tecla	
	getch();
}

