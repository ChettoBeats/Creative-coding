#include <Adafruit_CircuitPlayground.h>

const int NUM_PIXELS = 10;

// SPL range
const float MIN_DB = 50.0;
const float MAX_DB = 90.0;

float spl;

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
  CircuitPlayground.setBrightness(255);
}

void loop() {
  // measure loudness over 10 ms
  spl = CircuitPlayground.mic.soundPressureLevel(10);

  // print
  Serial.print("SPL: ");
  Serial.println(spl);

  // Keep SPL inside range
  if (spl < MIN_DB) spl = MIN_DB;
  if (spl > MAX_DB) spl = MAX_DB;

  // Map SPL (50–90) to 0–255 for color wheel
  int hue = map((int)spl, (int)MIN_DB, (int)MAX_DB, 0, 255);

  // get color
  long color = CircuitPlayground.colorWheel(hue);

  // sets leds to that color
  for (int i = 0; i < NUM_PIXELS; i++) {
    CircuitPlayground.setPixelColor(i, color);
  }

  delay(20);
}
