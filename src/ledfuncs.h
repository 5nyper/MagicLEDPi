#ifndef LEDFUNCS_H_   /* Include guard */
#define LEDFUNCS_H_

#define LOW_FADE 5
#define REDl 4
#define GREENl 1
#define BLUEl 5

void two(int r, int g, int b);
void fade(int a, int c, int d);
void steady(int r, int g, int b);
void showcase(int value);

#endif
