#include "FastLED.h"

#define BRIGHTNESS 75

#define LEFT_LEDS 24
#define RIGHT_LEDS 24

#define LEFT 0
#define RIGHT 1

#define PINR 7
#define PINL 6

class Headlights {
  public:
    Headlights(int lef, int righ);
    void setColor(CRGB lef, CRGB righ);
    void setColor(CRGB col);
    void fade();
    void heartbeat();
    CRGB all[RIGHT_LEDS + LEFT_LEDS];
    CRGB *headL, *headR;
    CRGB leftC = CRGB::SkyBlue, rightC = CRGB::SkyBlue, allC = CRGB::SkyBlue;

};

Headlights::Headlights(int lef, int righ) {
  headL = all;
  headR = all + RIGHT_LEDS;
  FastLED.addLeds<NEOPIXEL, PINL>(headL, LEFT_LEDS);
  FastLED.addLeds<NEOPIXEL, PINR>(headR, RIGHT_LEDS);
}
void Headlights::setColor(CRGB lef, CRGB righ) {
  leftC = lef;
  rightC = righ;
  for (int i = 0; i<24; i++) {
    headL[i] = lef;
    headR[i] = righ;
  }
  FastLED.show();
}
void Headlights::setColor(CRGB col) {
  allC, leftC, rightC = col;
  for (int i = 0; i<48; i++) {
    all[i] = col;
  }
  FastLED.show();
}

void Headlights::fade() {
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

void Headlights::heartbeat() {
  FastLED.clear(); FastLED.show();
  delay(100);
  this->setColor(allC);
  delay(100);
  FastLED.clear(); FastLED.show();
  delay(100);
  this->setColor(allC);
  delay(250);
}

Headlights ledring(6,7);

class Singlelight {
  public:
    Singlelight(int sid);
    void setColor(CRGB col);
    void fade();
    void heartbeat();
  private:
    int side;
    CRGB leftC = ledring.leftC, rightC = ledring.rightC;
};

Singlelight::Singlelight(int sid) {
  side = sid;
}

void Singlelight::setColor(CRGB col) {
  if (side == LEFT) {
      leftC = col;
      ledring.leftC = leftC;
      for (int i = 0; i<24; i++) {
        ledring.headL[i] = col;
    }
  }
    else {
      rightC = col;
      ledring.rightC = rightC;
      for (int i = 0; i<24; i++) {
        ledring.headR[i] = col;
    }
  }
  FastLED.show();
}

void Singlelight::fade() {
  for (int i = BRIGHTNESS; i<=250; i++) {
    FastLED[side].showLeds(i);
    delay(1);
  }
  for (int i = 250; i>=BRIGHTNESS; i--) {
    FastLED[side].showLeds(i);
    delay(1);
  }
}

void Singlelight::heartbeat() {
  leftC = ledring.leftC;
  rightC = ledring.rightC;
  if (side == LEFT) {
    FastLED[LEFT].clearLedData(); FastLED.show();
    this->setColor(leftC);
    delay(100);
    FastLED[LEFT].clearLedData(); FastLED.show();
    delay(100);
    this->setColor(leftC);
    delay(100);
    FastLED[LEFT].clearLedData(); FastLED.show();
    delay(100);
    this->setColor(leftC);
  }
  else {
    FastLED[RIGHT].clearLedData(); FastLED.show();
    this->setColor(rightC);
    delay(100);
    FastLED[RIGHT].clearLedData(); FastLED.show();
    delay(100);
    this->setColor(rightC);
    delay(100);
    FastLED[RIGHT].clearLedData(); FastLED.show();
    delay(100);
    this->setColor(rightC);
  }
}

Singlelight right(RIGHT);
Singlelight left(LEFT);  // 6: left, 7: right

void setup() {
  Serial.begin(9600);
  FastLED.setBrightness(BRIGHTNESS);
  ledring.setColor(CRGB::SkyBlue);
  FastLED.show();
}

void loop() {
  if (Serial.available() > 0) {
    char arg1 = Serial.read();
    delay(10);
    char arg2 = Serial.read();
    Serial.println(arg1);
    Serial.println(arg2);
    switch (arg1) {
      case 'c':
        switch(arg2) {
          case '1':
            ledring.setColor(CRGB::Red);
            break;
          case '2':
            ledring.setColor(CRGB::Blue);
            break;
          case '3':
            ledring.setColor(CRGB::Green);
            break;
          case '4':
            ledring.setColor(CRGB::Yellow);
            break;
          case '5':
            ledring.setColor(CRGB::Purple);
            break;
          case '6':
            ledring.setColor(CRGB::Orange);
            break;
          case '7':
            ledring.setColor(CRGB::Pink);
            break;
          case '8':
            while(Serial.available() == 0)
              ledring.fade();
            break;
          case '9':
            while(Serial.available() == 0) {
              right.heartbeat();
              left.heartbeat();
            }
            break;
          case '0':
            FastLED.clear();
            FastLED.show();
            break;
          default:
            ledring.setColor(CRGB::SkyBlue);
            break;
        }
        break;
      case 'b':
        switch(arg2) {
          case '1':
            right.setColor(CRGB::Red);
            break;
          case '2':
            right.setColor(CRGB::Blue);
            break;
          case '3':
            right.setColor(CRGB::Green);
            break;
          case '4':
            right.setColor(CRGB::Yellow);
            break;
          case '5':
            right.setColor(CRGB::Purple);
            break;
          case '6':
            right.setColor(CRGB::Orange);
            break;
          case '7':
            right.setColor(CRGB::Pink);
            break;
          case '8':
            while(Serial.available() == 0)
              right.fade();
            break;
          case '9':
            while(Serial.available() == 0)
              right.heartbeat();
            break;
          case '0':
            FastLED[RIGHT].clearLedData();
            FastLED.show();
            break;
          default:
            right.setColor(CRGB::SkyBlue);
            break;
        }
        break;
      case 'a':
        switch(arg2) {
          case '1':
            left.setColor(CRGB::Red);
            break;
          case '2':
            left.setColor(CRGB::Blue);
            break;
          case '3':
            left.setColor(CRGB::Green);
            break;
          case '4':
            left.setColor(CRGB::Yellow);
            break;
          case '5':
            left.setColor(CRGB::Purple);
            break;
          case '6':
            left.setColor(CRGB::Orange);
            break;
          case '7':
            left.setColor(CRGB::Pink);
            break;
          case '8':
            while(Serial.available() == 0)
              left.fade();
            break;
          case '9':
            while(Serial.available() == 0)
              left.heartbeat();
            break;
          case '0':
            FastLED[LEFT].clearLedData();
            FastLED.show();
            break;
          default:
            left.setColor(CRGB::White);
            break;
        }
        break;
      default:
        ledring.setColor(CRGB::SkyBlue);
      }
  }
  else {
    ;
  }
}
