#include "ledfuncs.h"
#include <wiringPi.h>
#include <softPwm.h>
#include <stdlib.h>

void two(int r, int g, int b) {
	while(1) {
		softPwmWrite(REDl, r);
		softPwmWrite(GREENl, g);
		softPwmWrite(BLUEl, b);
		delay(100);
		softPwmWrite(REDl, 0);
		softPwmWrite(GREENl, 0);
		softPwmWrite(BLUEl, 0);
		delay(100);
		softPwmWrite(REDl, r);
		softPwmWrite(GREENl, g);
		softPwmWrite(BLUEl, b);
		delay(100);
		softPwmWrite(REDl, 0);
		softPwmWrite(GREENl, 0);
		softPwmWrite(BLUEl, 0);
		delay(100);
		delay(200);
	}
}
void fade(int a, int c, int d) {             //TODO: fix some rgb values that chnage color from this
	int r,g,b;
	while(1) { //for (r = a, g = c, b = d; r>((int)a/2)-1 && g>((int)c/2)-1 && b>((int)d/2)-1; r--,g--,b--)
		for (r = a, g = c, b = d; r>10 || g>10 || b>10; r--,g--,b--) {  //WHITE, RED, GREEN, BLUE
			softPwmWrite(REDl, r);
			softPwmWrite(GREENl, g);
			softPwmWrite(BLUEl, b);
			delay(10);
		}
		for (; r<a || g<c || b<d; r++,g++,b++) {
			softPwmWrite(REDl, r);
			softPwmWrite(GREENl, g);
			softPwmWrite(BLUEl, b);
			delay(10);
		}
	}
}
void steady(int r, int g, int b) {
	while(1) {
		softPwmWrite(REDl, r);
		softPwmWrite(GREENl, g);
		softPwmWrite(BLUEl, b);
	}
}
void showcase(int value) {
	softPwmWrite(REDl, value);
	delay(1000);
	softPwmWrite(REDl, 0);
	softPwmWrite(GREENl, value);
	delay(1000);
	softPwmWrite(GREENl, 0);
	softPwmWrite(BLUEl, value);
	delay(1000);
	softPwmWrite(BLUEl, 0);
	while (1) {
		softPwmWrite(REDl, 50);
		softPwmWrite(GREENl, 1);   // PURPLE
		softPwmWrite(BLUEl, 70);
		delay(200);
		softPwmWrite(REDl, 100);
		softPwmWrite(GREENl, 5);   // ORANGE
		softPwmWrite(BLUEl, 0);
		delay(200);
		softPwmWrite(REDl, 100);
		softPwmWrite(GREENl, 100);   // WHITE
		softPwmWrite(BLUEl, 90);
		delay(200);
		softPwmWrite(REDl, 15);
		softPwmWrite(GREENl, 0);   // PINK
		softPwmWrite(BLUEl, 70);
		delay(200);
	}
}
	
