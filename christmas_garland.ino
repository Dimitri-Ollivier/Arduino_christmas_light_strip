/*
* Christmas garland 
* authors: HUON Nicolas, SORIN Aimeric, OLLIVIER Dimitri
* last-modification: 13/12/2022
*/

#include "FastLED.h"
#define NUM_LEDS 144
#define LED_PIN 6
#define BUTTON_ON_OFF_PIN 5

int buttonOnOffState = 0;

CRGB leds[NUM_LEDS];

bool isLedsActive = false;

void setup() {
  // put your setup code here, to run once:

  // init button on/off
  pinMode(BUTTON_ON_OFF_PIN, INPUT);
  digitalWrite(BUTTON_ON_OFF_PIN, HIGH);

  // inti LED
  FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, NUM_LEDS);

  //LEDS.showColor(CRGB(229, 122, 68));
  //delay(1500);
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

  if(isLedsActive) {
      showLeds(2);
      delay(1500);
      showLeds(5);
      delay(1500);
    } else {
      reset();
    }
}

void reset() {
  LEDS.clearData();
  LEDS.showColor(CRGB(0, 0, 0));
}

void showLeds(int int count, CRGB color) {
  reset();
  
  for(int n = 1; n <+ NUM_LEDS; n= n + count) {
    leds[n] = CRGB(188, 71, 73);
  }

  LEDS.show();
}
