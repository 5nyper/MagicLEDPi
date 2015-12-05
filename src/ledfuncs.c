#include "ledfuncs.h"

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
			softPwmWrite(0, x);
			delay(10);
		}
		for (x = value; x>LOW_FADE; x--) {
			softPwmWrite(0, x);
			delay(10);
		}
	}
}
void steady(int value) {
	while(1) {
		softPwmWrite(0, value);
	}
}
