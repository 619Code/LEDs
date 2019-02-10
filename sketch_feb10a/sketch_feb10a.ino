#include <FastLED.h>
#define LED_PIN                 7
#define NUM_LEDS                150 // Must be a multiple of 2
#define SANDSTORM_LENGTH        15000
#define MAINGAME_LENGTH         105000
#define ENDGAME_LENGTH          30000
#define BETWEEN_MATCHES_LENGTH  15000

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
}
void loop() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(255, 85, 0);
    FastLED.show();
    delay(SANDSTORM_LENGTH/NUM_LEDS);
    leds[i] = CRGB(0, 0, 255);
    FastLED.show();
  }
  delay(MAINGAME_LENGTH-5000);
  for (int m = 0; m < 5; m++) {
    for (int l = 0; l < NUM_LEDS; l++) {
      leds[l] = CRGB(0, 0, 0);
    }
    delay(500);
    FastLED.show();
    for (int n = 0; n < NUM_LEDS; n++) {
      leds[n] = CRGB(0, 0, 255);
    }
    delay(500);
    FastLED.show();
  }
  for (int j = 0; j < NUM_LEDS; j++) {
    leds[j] = CRGB(255, 85, 0);
    FastLED.show();
    delay((ENDGAME_LENGTH-5000)/NUM_LEDS);
  }
  for (int p = 0; p < 5; p++) {
    for (int q = 0; q < NUM_LEDS; q++) {
      leds[q] = CRGB(0, 0, 0);
    }
    delay(500);
    FastLED.show();
    for (int r = 0; r < NUM_LEDS; r++) {
      leds[r] = CRGB(255, 85, 0);
    }
    delay(500);
    FastLED.show();
  }
  for (int s = 0; s < BETWEEN_MATCHES_LENGTH/100; s++) {
    for (int t = 0; t < NUM_LEDS; t++) {
      if (t % 2 == 0) {
        if (s % 2 == 0) {
          leds[t] = CRGB(0, 0, 255);
        }
        else {
          leds[t] = CRGB(255, 85, 0);
        }
      } 
      else {
        if (s % 2 == 0) {
          leds[t] = CRGB(255, 85, 0);
        }
        else {
          leds[t] = CRGB(0, 0, 255);
        }
      }
    }
    FastLED.show();
    delay(100);
  }
  leds[NUM_LEDS/2 - 1] = CRGB(0, 255, 0);
  leds[NUM_LEDS - 1] = CRGB(255, 0, 0);
  //leds[0] = CRGB(255, 0, 0);
  //FastLED.show();
  //delay(500);  
  //leds[1] = CRGB(0, 255, 0);
  //FastLED.show();
  //delay(500);
  //leds[2] = CRGB(0, 0, 255);
  //FastLED.show();
  //delay(500);
  //leds[5] = CRGB(150, 0, 255);
  //FastLED.show();
  //delay(500);
  //leds[9] = CRGB(255, 200, 20);
  //FastLED.show();
  //delay(500);
  //leds[14] = CRGB(85, 60, 180);
  //FastLED.show();
  //delay(500);
  //leds[19] = CRGB(50, 255, 20);
  //FastLED.show();
  //delay(500);
}
