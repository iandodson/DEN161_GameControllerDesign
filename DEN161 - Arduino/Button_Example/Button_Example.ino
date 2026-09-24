#include "Button_Debounce.h"
#include <Keyboard.h>


void setup() {
  buttonUsed[PIN_15] = true; //A
  buttonUsed[PIN_14] = true; //W
  buttonUsed[PIN_16] = true; //D
  buttonUsed[PIN_10] = true; //S

  buttonUsed[PIN_2] = true; //R-click
  buttonUsed[PIN_A1] = true; //L-click

  buttonUsed[PIN_15] = true;

  pullUp = true;
  buttonSetup();
  Serial.begin(9600);

  Keyboard.begin();

}

void loop() {
  int buttonCheck;

  buttonCheck = buttonDebounce(PIN_15);
  if (buttonCheck == 1)
  {
    Serial.println("Pressed 15");
    Keyboard.press('a');
  }
  else if (buttonCheck == 2)
  {
    Serial.println("Released 15");
    Keyboard.release('a');
  }

  buttonCheck = buttonDebounce(PIN_14);
  if (buttonCheck == 1)
  {
    Serial.println("Pressed 14");
    Keyboard.press('w');
  }
  else if (buttonCheck == 2)
  {
    Serial.println("Realeased 14");
    Keyboard.release('w');
  }

  buttonCheck = buttonDebounce(PIN_16);
  if (buttonCheck == 1)
  {
    Serial.println("Pressed 16");
    Keyboard.press('d');
  }
  else if (buttonCheck == 2)
  {
    Serial.println("Released 16");
    Keyboard.release('d');
  }

  buttonCheck = buttonDebounce(PIN_10);
  if (buttonCheck == 1)
  {
    Serial.println("Pressed 10");
    Keyboard.press('s');
  }
  else if (buttonCheck == 2)
  {
    Serial.println("Released 10");
    Keyboard.release('s');
  }
  
  buttonCheck = buttonDebounce(PIN_2);
  if (buttonCheck == 1)
  {
    Serial.println("Pressed 2");
  }
  else if (buttonCheck == 2)
  {
    Serial.println("Released 2");
  }

  buttonCheck = buttonDebounce(PIN_A1);
  if (buttonCheck == 1)
  {
    Serial.println("Pressed A1");
  }
  else if (buttonCheck == 2)
  {
    Serial.println("Released A1");
  }
  Keyboard.end();

}
