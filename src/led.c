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
	softPwmWrite(RED, 0);
	system("gpio write 4 0");
   	softPwmWrite(GREEN, 0);
	system("gpio write 1 0");
	softPwmWrite(BLUE, 0);
	system("gpio write 5 0");
	exit(0);
}

int main(int argc, char* argv[]) { 
	if (signal(SIGINT, onExit) == SIG_ERR)
  		;
	wiringPiSetup();
	softPwmCreate(RED, 0, 100);
	softPwmCreate(GREEN, 0, 100);
	softPwmCreate(BLUE, 0, 100);
	switch (atoi(argv[1])) {
		case 0:
			showcase(100);
			break;		
		case 1:
			two(50);
			break;
		case 2:
			fade(50);
			break;
	}
	
	return 0;
}
