#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <conio.h>

#include "GlobalSettings.cpp"

#include "Menu.h"

void Menu::showOptions(){
	for(int i = 0; i < options.size(); i++){
		SetCursorPosition(i * 2, 0);
		cout << options[i];
	}
}
