#include <wiringPi.h>
#include <softPwm.h>
#include <stdlib.h>
#include <stdio.h>
#include "ledfuncs.h"

int main(int argc, char* argv[]) { 
	wiringPiSetup();
	softPwmCreate(0, 0, 100);
	switch (atoi(argv[1])) {
		case 0:
			steady(50);
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
