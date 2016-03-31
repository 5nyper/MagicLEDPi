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

class Both { // this is for using them both at the same time.
  public:
    Both(int lef, int righ);
    void setColor(int lef, int righ);
    void init();
    void setBright(int x);
    void fade();
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
    int leftC = red;
    int rightC = red;
};

Both::Both(int lef, int righ) {
  headL = Adafruit_NeoPixel(24, lef, NEO_GRB + NEO_KHZ800);
  headR = Adafruit_NeoPixel(24, righ, NEO_GRB + NEO_KHZ800);
}
void Both::setColor(int lef, int righ) {
  Serial.println(lef);
  Serial.println(righ);
  leftC = lef;
  rightC = righ;
  for (int i = 0; i<=24; i++) {
    headL.setPixelColor(i, colors[leftC]);
    headL.show();
    delay(1000);
    headR.setPixelColor(i, colors[rightC]);
    headR.show();
  }
}
void Both::init() {
  headL.begin();
  headL.show();
  headR.begin();
  headR.show();
}
void Both::setBright(int x) {
  headL.setBrightness(x);
  headR.setBrightness(x);
}

void Both::fade() {
  for (int i = BRIGHTNESS; i<=150; i++) {
    headL.show();
    headR.setBrightness(i);
    headR.show();
    delay(1);
  }
  for (int i = 150; i>=BRIGHTNESS; i--) {
    headL.show();
    headR.setBrightness(i);
    headR.show();
    delay(1);
  }
}

class Headlight : public Both {
  public:
    Adafruit_NeoPixel ring;
    Headlight(int pin);
    void showcase();
    void setColor(int col);
    void fade();
    void heartbeat();
    void getColor();
  private:
    int color;
};

Headlight::Headlight(int pin) : Both(0, 0) {
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
  Serial.println("that function");
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

void Headlight::getColor() {
  Serial.println(color);
}

Both ledring(6,7);
Headlight left(6);
Headlight right(7);

void setup() {
  Serial.begin(9600);
  left.ring.begin();
  left.ring.show();
  left.ring.setBrightness(BRIGHTNESS);
  right.ring.begin();
  right.ring.show();
  right.ring.setBrightness(BRIGHTNESS);
  ledring.init();
  ledring.setBright(BRIGHTNESS);
  ledring.setColor(white, orange);
  delay(2000);
}

void loop() {
  ledring.fade();
}
