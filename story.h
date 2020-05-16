#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <conio.h>
#include <unistd.h>
#include <ctime>
#include <vector>

#include "GlobalSettings.cpp"

#ifndef STORY_H
#define STORY_H

class Story{
	public:
		void reticencias();
		void story_intro();
		void story_lvl1();
		void story_lvl2();
		void story_lvl3();
		void story_boss();
		void story_win();
		void story_loss();
};

#endif
