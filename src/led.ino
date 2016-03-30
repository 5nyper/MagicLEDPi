#include <Adafruit_NeoPixel.h>

#define PIN 7

Adafruit_NeoPixel strip = Adafruit_NeoPixel(24, PIN, NEO_GRB + NEO_KHZ800);

enum Color {
  red,
  green,
  blue,
  purple,
  pink,
  orange,
  white
};

uint32_t colors[] = {strip.Color(255,0,0), strip.Color(0,255,0), strip.Color(0,0,255), strip.Color(160,32,240), strip.Color(255,192,203), strip.Color(255,165,0), strip.Color(255,255,255)};

int g = 0;

void setup() {
  strip.begin();
  strip.show();
  strip.setBrightness(25);
}

void loop() {
  
}

void carStart() {
  for (int i = 0; i<=24; i++) {
    strip.setPixelColor(i, colors[white]);
    strip.show();
  }
}
