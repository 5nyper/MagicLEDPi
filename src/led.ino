#include <Adafruit_NeoPixel.h>

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
  public:
    Adafruit_NeoPixel ring;
    Headlight(int pin);
    void showcase(); 
  private:
    uint32_t colors[7] = {ring.Color(255,0,0), 
                     ring.Color(0,255,0), 
                     ring.Color(0,0,255), 
                     ring.Color(160,32,240), 
                     ring.Color(255,192,203), 
                     ring.Color(255,165,0), 
                     ring.Color(255,255,255)};
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

Headlight left(7);

void setup() {
  left.ring.begin();
  left.ring.show();
  left.ring.setBrightness(0);
  delay(5000);
  left.ring.setBrightness(200);
}

void loop() {
  left.showcase();
}
