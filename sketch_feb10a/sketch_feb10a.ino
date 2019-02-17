#include <FastLED.h>
#define FIRST_LED_PIN           7
#define SECOND_LED_PIN          3

#define FIRST_NUM_LEDS          300    // Must be a multiple of 2
#define SECOND_NUM_LEDS         50

#define FLASH_ON                1    //0 = flashing off, 1 = flashing on
#define ENHANCEMENT_ON          1    //0 = enhancement off, 1 = enhancement on
#define DIMMING_ON              1    //0 = dimming off, 1 = dimming on

#define SANDSTORM_LENGTH        15000
#define MAINGAME_LENGTH         105000
#define ENDGAME_LENGTH          30000

#define BETWEEN_MATCHES_MODE    1    //0 = lights off, 1 = blue and orange flashing, 2 = random lights
#define BETWEEN_MATCHES_LENGTH  15000

CRGB leds[FIRST_NUM_LEDS];
CRGB leds_two[SECOND_NUM_LEDS];

int dim_factor = 1/(DIMMING_ON + 1)

void setup() {
  FastLED.addLeds<WS2812, FIRST_LED_PIN, GRB>(leds, FIRST_NUM_LEDS);
  FastLED.addLeds<WS2812, SECOND_LED_PIN, GRB>(leds_two, SECOND_NUM_LEDS);
}
void loop() {
  for (int a = 0; a < SECOND_NUM_LEDS; a++) {
    leds_two[a] = CRGB(255*dim_factor, 85*dim_factor, 0*dim_factor);
  }
  FastLED.show();
  for (int i = 0; i < FIRST_NUM_LEDS; i++) {
    leds[i] = CRGB(255*dim_factor, 85*dim_factor, 0*dim_factor);
    FastLED.show();
    delay(SANDSTORM_LENGTH/FIRST_NUM_LEDS);
    leds[i] = CRGB(0*dim_factor, 0*dim_factor, 255*dim_factor);
    FastLED.show();
  }
  for (int x = 0; x < FIRST_NUM_LEDS; x++) {
    leds[FIRST_NUM_LEDS - x - 1] = CRGB(255*dim_factor, 85*dim_factor, 0*dim_factor);
    FastLED.show();
    delay((MAINGAME_LENGTH-5000)/FIRST_NUM_LEDS);
    leds[FIRST_NUM_LEDS - x - 1] = CRGB(0*dim_factor, 0*dim_factor, 255*dim_factor);
    FastLED.show();
  }
  if (FLASH_ON == 1) {
    for (int m = 0; m < 5; m++) {
      for (int l = 0; l < FIRST_NUM_LEDS; l++) {
        leds[l] = CRGB(0*dim_factor, 0*dim_factor, 0*dim_factor);
      }
      for (int c = 0; c < SECOND_NUM_LEDS; c++) {
        leds_two[c] = CRGB(0*dim_factor, 0*dim_factor, 0*dim_factor);
      }
      delay(500);
      FastLED.show();
      for (int n = 0; n < FIRST_NUM_LEDS; n++) {
        leds[n] = CRGB(0*dim_factor, 0*dim_factor, 255*dim_factor);
      }
      for (int d = 0; d < SECOND_NUM_LEDS; d++) {
        leds_two[d] = CRGB(255*dim_factor, 85*dim_factor, 0*dim_factor);
      }
      delay(500);
      FastLED.show();
    }
  } else {
    delay(5000);
  }
  for (int j = 0; j < FIRST_NUM_LEDS; j++) {
    leds[j] = CRGB(255*dim_factor, 85*dim_factor, 0*dim_factor);
    FastLED.show();
    delay((ENDGAME_LENGTH-5000)/FIRST_NUM_LEDS);
  }
  if (FLASH_ON == 1) {
    for (int p = 0; p < 5; p++) {
      for (int q = 0; q < FIRST_NUM_LEDS; q++) {
        leds[q] = CRGB(0*dim_factor, 0*dim_factor, 0*dim_factor);
      }
      for (int e = 0; e < SECOND_NUM_LEDS; e++) {
        leds_two[e] = CRGB(0*dim_factor, 0*dim_factor, 0*dim_factor);
      }
      delay(500);
      FastLED.show();
      for (int r = 0; r < FIRST_NUM_LEDS; r++) {
        leds[r] = CRGB(255*dim_factor, 85*dim_factor, 0*dim_factor);
      }
      for (int f = 0; f < SECOND_NUM_LEDS; f++) {
        leds_two[f] = CRGB(255*dim_factor, 85*dim_factor, 0*dim_factor);
      }
      delay(500);
      FastLED.show();
    }
  } else {
    delay(5000);
  }
  if (BETWEEN_MATCHES_MODE == 2) {
    for (int b = 0; b < SECOND_NUM_LEDS; b++) {
      leds_two[b] = CRGB((rand() % 256)*dim_factor, (rand() % 256)*dim_factor, (rand() % 256)*dim_factor);
    }
  } else {
    if (BETWEEN_MATCHES_MODE == 0) {
      for (int g = 0; g < SECOND_NUM_LEDS; g++) {
        leds_two[g] = CRGB(0*dim_factor, 0*dim_factor, 0*dim_factor);
      }
    }
  }
  FastLED.show();
  if (BETWEEN_MATCHES_MODE == 0) {
    for (int u = 0; u < FIRST_NUM_LEDS; u++) {
      leds[u] = CRGB(0*dim_factor, 0*dim_factor, 0*dim_factor);
    }
    FastLED.show();
    delay(BETWEEN_MATCHES_LENGTH);
  } else {
    if (BETWEEN_MATCHES_MODE == 1) {
      for (int s = 0; s < BETWEEN_MATCHES_LENGTH/100; s++) {
        for (int t = 0; t < FIRST_NUM_LEDS; t++) {
          if (t % 2 == 0) {
            if (s % 2 == 0) {
              leds[t] = CRGB(0*dim_factor, 0*dim_factor, 255*dim_factor);
            }
            else {
              leds[t] = CRGB(255*dim_factor, 85*dim_factor, 0*dim_factor);
            }
          } 
          else {
            if (s % 2 == 0) {
              leds[t] = CRGB(255*dim_factor, 85*dim_factor, 0*dim_factor);
            }
            else {
              leds[t] = CRGB(0*dim_factor, 0*dim_factor, 255*dim_factor);
            }
          }
        }
        FastLED.show();
        delay(100);
      }
    } else {
      if (BETWEEN_MATCHES_MODE == 2) {
        for (int w = 0; w < 10; w++) {
          for (int v = 0; v < FIRST_NUM_LEDS; v++) {
            leds[v] = CRGB((rand() % 256)*dim_factor, (rand() % 256)*dim_factor, (rand() % 256)*dim_factor);
          }
          FastLED.show();
          delay(BETWEEN_MATCHES_LENGTH/10);
        }
      }
    }
  }
  if (ENHANCEMENT_ON == 1) {
    leds[FIRST_NUM_LEDS/2 - 1] = CRGB(0, 255, 0);
    leds[FIRST_NUM_LEDS - 1] = CRGB(255, 0, 0);
  }
}
