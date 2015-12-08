#include "ledfuncs.h"
#include <wiringPi.h>
#include <softPwm.h>
#include <stdlib.h>

void two(int value) {
	while(1) {
		softPwmWrite(0, value);
		delay(100);
		softPwmWrite(0, 0);
		delay(100);
		softPwmWrite(0, value);
		delay(100);
		softPwmWrite(0, 0);
		delay(100);
		delay(200);
	}
}
void fade(int value) {
	int x;
	while(1) {
		for (x = LOW_FADE; x<value; x++) {
			softPwmWrite(RED, x);
			softPwmWrite(GREEN, x);
			softPwmWrite(BLUE, x);
			delay(10);
		}
		for (x = value; x>LOW_FADE; x--) {
			softPwmWrite(RED, x);
			softPwmWrite(GREEN, x);
			softPwmWrite(BLUE, x);
			delay(10);
		}
	}
}
void steady(char* index) {
	while(1) {
//atoi(&index[2])
		softPwmWrite(RED, 100);
		softPwmWrite(GREEN, 20);
		softPwmWrite(BLUE, 0);
	}
}
void showcase(int value) {
	softPwmWrite(RED, value);
	delay(1000);
	softPwmWrite(RED, 0);
	softPwmWrite(GREEN, value);
	delay(1000);
	softPwmWrite(GREEN, 0);
	softPwmWrite(BLUE, value);
	delay(1000);
	softPwmWrite(BLUE, 0);
	while (1) {
		softPwmWrite(RED, 50);
		softPwmWrite(GREEN, 1);   // PURPLE
		softPwmWrite(BLUE, 70);
		delay(200);
		softPwmWrite(RED, 100);
		softPwmWrite(GREEN, 5);   // ORANGE
		softPwmWrite(BLUE, 0);
		delay(200);
		softPwmWrite(RED, 100);
		softPwmWrite(GREEN, 100);   // WHITE
		softPwmWrite(BLUE, 90);
		delay(200);
		softPwmWrite(RED, 15);
		softPwmWrite(GREEN, 0);   // PINK
		softPwmWrite(BLUE, 70);
		delay(200);
	}
}
	
