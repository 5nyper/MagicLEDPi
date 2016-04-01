#include "FastLED.h"
#include "Adafruit_NeoPixel.h"

#define BRIGHTNESS 75

enum Color {
  red,
  green,
  blue,
  purple,
  pink,
  orange,
  white
};

class Both {
  public:
    Both(int lef, int righ);
    void setColor(int lef, int righ);
    void fade();
    CRGB headL[24];
    CRGB headR[24];
};

Both::Both(int lef, int righ) {
  FastLED.addLeds<NEOPIXEL, 6>(headL, 24);
  FastLED.addLeds<NEOPIXEL, 7>(headR, 24);
}
void Both::setColor(int lef, int righ) {
  for (int i = 0; i<24; i++) {
    headL[i] = lef;
    headR[i] = righ;
  }
  FastLED.show();   // RIGHT RING IS NOW GREEN
}

void Both::fade() {
  for (int i = BRIGHTNESS; i<=250; i++) {
    FastLED.setBrightness(i);
    FastLED.show();
    delay(1);
  }
  for (int i = 250; i>=BRIGHTNESS; i--) {
    FastLED.setBrightness(i);
    FastLED.show();
    delay(1);
  }
}

class Headlight {
  protected:
    uint32_t colors[7] = {ring.Color(255,0,0),
                    ring.Color(0,255,0),
                    ring.Color(0,0,255),
                    ring.Color(160,32,240),
                    ring.Color(255,192,203),
                    ring.Color(255,165,0),
                    ring.Color(255,255,255)};
    int color;
  public:
  Adafruit_NeoPixel ring;
  Headlight(int pin);
  void showcase();
  void setColor(int col);
  void fade();
  void heartbeat();
};

Headlight::Headlight(int pin) {
  ring = Adafruit_NeoPixel(24, pin, NEO_GRB + NEO_KHZ800);
}

void Headlight::showcase() {
  for (int k = 0; k < 7; k++) {
    for (int i = 0; i<=24; i++) {
      ring.setPixelColor(i, colors[k]);
      ring.show();
      delay(10);
    }
  }
}

void Headlight::setColor(int col) {
  color = col;
  for (int i = 0; i<=24; i++) {
    ring.setPixelColor(i, colors[color]);
    ring.show();
  }
}

void Headlight::fade() {
  for (int i = BRIGHTNESS; i<=250; i++) {
    ring.setBrightness(i);
    ring.show();
    delay(1);
  }
  for (int i = 250; i>=BRIGHTNESS; i--) {
    ring.setBrightness(i);
    ring.show();
    delay(1);
  }
}

void Headlight::heartbeat() {
  ring.clear(); ring.show();
  this->setColor(color);
  delay(100);
  ring.clear(); ring.show();
  delay(100);
  this->setColor(color);
  delay(100);
  ring.clear(); ring.show();
  delay(500);
}

Both ledring(6,7);  // 6: left, 7: right
Headlight left(6);
Headlight right(7);

void setup() {
  left.ring.begin();
  left.ring.show();
  left.ring.setBrightness(BRIGHTNESS);
  right.ring.begin();
  right.ring.show();
  right.ring.setBrightness(BRIGHTNESS);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  ledring.setColor(CRGB::White, CRGB::Pink);
  delay(2000);
  left.setColor(red);
  delay(2000);
  right.setColor(green);
  delay(2000);
}
