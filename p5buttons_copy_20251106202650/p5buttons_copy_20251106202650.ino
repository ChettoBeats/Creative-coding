#include <Adafruit_CircuitPlayground.h>

bool leftButtonPressed;
bool rightButtonPressed;

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
}

void loop() {
  leftButtonPressed = CircuitPlayground.leftButton();
  rightButtonPressed = CircuitPlayground.rightButton();
  
  //Serial.print("Left Button: ");
  if (leftButtonPressed) {
    Serial.print(1);
  } else {
    Serial.print(0);
  }
  
  if (rightButtonPressed) {
    Serial.print(2);
  } else {
    Serial.print(0);
  }
  Serial.println();
  
  delay(1000);
}