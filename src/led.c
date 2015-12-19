#include <wiringPi.h>
#include <softPwm.h>
#include <stdlib.h>
#include <stdio.h>
#include "ledfuncs.h"
#include <signal.h>
#include <unistd.h>

void onExit(int sig)
{
  if (sig == SIGINT)
	softPwmWrite(REDl, 0);
	system("gpio write 4 0");
   	softPwmWrite(GREENl, 0);
	system("gpio write 1 0");
	softPwmWrite(BLUEl, 0);
	system("gpio write 5 0");
	exit(0);
}

int main(int argc, char* argv[]) { 
	int r,g,b;
	if (signal(SIGINT, onExit) == SIG_ERR)
  		;
	wiringPiSetup();
	softPwmCreate(REDl, 0, 100);
	softPwmCreate(GREENl, 0, 100);
	softPwmCreate(BLUEl, 0, 100);
	switch (atoi(argv[2])) {
		case 0:                  //RED
			r = 100;
			g = 0;
			b = 0;
			break;		
		case 1:                  //GREEN
			r = 0;
			g = 100;
			b = 0;
			break;
		case 2:                  //BLUE
			r = 0;
			g = 0;
			b = 100;
			break;
		case 3:                  //PURPLE
			r = 50;
			g = 1;
			b = 70;
			break;
		case 4:                  //PINK
			r = 15;
			g = 0;
			b = 70;
			break;
		case 5:                  //ORANGE
			r = 100;
			g = 5;
			b = 0;
			break;
		case 6:                  //WHITE
			r = 100;
			g = 100;
			b = 100;
			break;
	}
	switch (atoi(argv[1])) {
		case 0:
			showcase(100);
			break;		
		case 1:
			steady(r,g,b);
			break;
		case 2:
			two(r,g,b);
			break;
		case 3:
			fade(r,g,b);
			break;
	}
	
	return 0;
}
