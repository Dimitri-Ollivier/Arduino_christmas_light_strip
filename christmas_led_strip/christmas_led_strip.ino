/*
* Christmas led strip 
* authors: HUON Nicolas, SORIN Aimeric, LECAT Baptiste, OLLIVIER Dimitri
* last-modification: 16/12/2022
*/

#include "FastLED.h"
#define NUM_LEDS 144
#define LED_PIN 6
#define BUTTON_ON_OFF_PIN 5
#define BUTTON_PROG_PIN 4

int buttonOnOffState = 1;

CRGB leds[NUM_LEDS];

bool isLedsActive = false;
int progNum = 0;
int progCount = 2;

void setup() {
  // put your setup code here, to run once:

  // init button on/off
  pinMode(BUTTON_ON_OFF_PIN, INPUT);
  digitalWrite(BUTTON_ON_OFF_PIN, HIGH);

  // init button prog
  pinMode(BUTTON_PROG_PIN, INPUT);
  digitalWrite(BUTTON_PROG_PIN, HIGH);

  // inti LED
  FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, NUM_LEDS);

  LEDS.showColor(CRGB(0, 0, 0));
  LEDS.setBrightness(20);
  Serial.begin(9600);
  Serial.println("nouveau test");
}

void loop() {
  // put your main code here, to run repeatedly:

  if(digitalRead(BUTTON_ON_OFF_PIN) == LOW) {
    isLedsActive = !isLedsActive;
    Serial.println(isLedsActive);
    delay(100);
  }  

  if(digitalRead(BUTTON_PROG_PIN) == LOW) {
    progNum++;
    
    if(progNum == progCount + 1) {
      progNum = 1;
    }

    Serial.print("Program number : ");
    Serial.println(progNum);
    delay(100);
  }  

  if(isLedsActive) {
    switch (progNum) {
  case 1:
      firstProg();
    break;
  case 2:
      secondProg();
    break;
  default:
    // statements
    break;
}
    } else {
      reset();
    }
}

void reset() {
  LEDS.clearData();
  LEDS.showColor(CRGB(0, 0, 0));
}

void firstProg() {
  showLeds(1, 2, CRGB(188, 71, 73));
  delay(1500);
  showLeds(2, 2, CRGB(188, 71, 73));
  delay(1500);
}

void secondProg() {
  showLeds(1, 1, CRGB(188, 0, 73));
  delay(1500);
  showLeds(1, 1, CRGB(0, 0, 73));
  delay(1500);
}

void showLeds(int startAt, int count, CRGB color) {
  reset();
  
  for(int n = startAt; n <+ NUM_LEDS; n= n + count) {
    leds[n] = color;
  }

  LEDS.show();
}
