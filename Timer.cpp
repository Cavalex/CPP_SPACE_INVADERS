#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <conio.h>
#include <unistd.h>
#include <ctime>

#ifndef TIMER_CPP
#define TIMER_CPP

class Timer
{
	public:
	    Timer() { restart(); }
		void restart() { begin = clock(); }
	    double getTimePassed() { return (clock() - begin) / (double)CLOCKS_PER_SEC; }
	private:
		clock_t begin;
};

#endif
