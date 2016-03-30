#include <Adafruit_NeoPixel.h>

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

class Headlight {
  friend class Both;  // this class is for singling out either left or right headlight
  public:
    Adafruit_NeoPixel ring;
    Headlight(int pin);
    void showcase();
    virtual void setColor(int col);
    void fade();
    void heartbeat();
  protected:
     uint32_t colors[7] = {ring.Color(255,0,0),
                     ring.Color(0,255,0),
                     ring.Color(0,0,255),
                     ring.Color(160,32,240),
                     ring.Color(255,192,203),
                     ring.Color(255,165,0),
                     ring.Color(255,255,255)};
     int color = red;
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

class Both { // this is for using them both at the same time.
  public:
    Both(int lef, int righ) {
      headL = Adafruit_NeoPixel(24, lef, NEO_GRB + NEO_KHZ800);
      headR = Adafruit_NeoPixel(24, righ, NEO_GRB + NEO_KHZ800);
    }
    void setColor(int col) {
      color = col;
      for (int i = 0; i<=24; i++) {
        headL.setPixelColor(i, colors[color]);
        headR.setPixelColor(i, colors[color]);
        headL.show();
        headR.show();
      }
    }
    void init() {
      headL.begin();
      headL.show();
      headR.begin();
      headR.show();
    }
    void setBright(int x) {
      headL.setBrightness(x);
      headR.setBrightness(x);
    }
    Adafruit_NeoPixel headL;
    Adafruit_NeoPixel headR;
  protected:
    uint32_t colors[7] = {headL.Color(255,0,0),
                    headL.Color(0,255,0),
                    headL.Color(0,0,255),
                    headL.Color(160,32,240),
                    headL.Color(255,192,203),
                    headL.Color(255,165,0),
                    headL.Color(255,255,255)};
    int color = red;
};

Both ledring(6,7);

void setup() {
  ledring.init();
  ledring.setBright(BRIGHTNESS);
}

void loop() {
  ledring.setColor(green);
}
