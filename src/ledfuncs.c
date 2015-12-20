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
void fade(int r, int g, int b) {
	int i;
	while(1) { 
		for (i = 100; i>10; i--){
			softPwmWrite(REDl, r*i/100);
			softPwmWrite(GREENl, g*i/100);
			softPwmWrite(BLUEl, b*i/100);
			delay(10);
		}
		for (i = 10; i<100; i++){
			softPwmWrite(REDl, r*i/100);
			softPwmWrite(GREENl, g*i/100);
			softPwmWrite(BLUEl, b*i/100);
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
	
