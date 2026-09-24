//definitions for our button states
#define BUTTON_UNPRESSED 0
#define BUTTON_WAIT 1
#define BUTTON_PRESSED 2

//these definitions help convert to the array values
#define PIN_0 0
#define PIN_1 1
#define PIN_2 2
#define PIN_3 3
#define PIN_4 4
#define PIN_5 5
#define PIN_6 6
#define PIN_7 7
#define PIN_8 8
#define PIN_9 9
#define PIN_10 10
#define PIN_14 11
#define PIN_15 12
#define PIN_16 13
#define PIN_A0 14
#define PIN_A1 15
#define PIN_A2 16
#define PIN_A3 17


unsigned int buttonName[18] = {0, 1, 2, 3, A6, 5, A7, 7, A8, A9, A10, 14, 15, 16, A0, A1, A2, A3}; //Used to convert from array number to pin number
unsigned char buttonState[18] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};//Used to store the state fore each button sepperatly
unsigned long buttonTimer[18]; //used to store the timmer value for each button sepperately

//these values will be set to true for any pin being used for a button
bool buttonUsed[18] = {
  false, // pin 0
  false, // pin 1
  false, // pin 2
  false, // pin 3
  false, // pin A6
  false, // pin 5
  false, // pin A7
  false, // pin 7
  false, // pin A8
  false, // pin A9
  false, // pin A10
  false, // pin 14
  false, // pin 15
  false, // pin 16
  false, // pin A0
  false, // pin A1
  false, // pin A2
  false  // pin A3
};

//this will be set true if using a pull up configuration and false if using a pull down configuration
bool pullUp = true;

//this function is used to set up the button pins as inputs
void buttonSetup()
{
  for (int i = 0; i < 18; i++)//for all possible inputs
  {
    if (buttonUsed[i])//if this pin is being used for a button
    {
      if (pullUp)//if we are using a pull up configuration
      {
        pinMode(buttonName[i], INPUT_PULLUP);
      }
      else//pull down configuration
      {
        pinMode(buttonName[i], INPUT);
      }
    }
  }
}

//this function is used to flag a button. it will return a 1 one time when the button is pressed, a 
//2 one time when the button is released and a 0 the rest of the time. A return of 0 is used to indicate
//dont care
int buttonDebounce(int pin)
{
  //switch case for button state control
  switch (buttonState[pin])
  {
    case BUTTON_UNPRESSED:
 
      if (digitalRead(buttonName[pin]) == !pullUp)//if the button is pressed
      {
        buttonState[pin] = BUTTON_WAIT;
        buttonTimer[pin] = millis();//start the timer
      }
      return 0;
      break;

    case BUTTON_WAIT:
    
      if (digitalRead(buttonName[pin]) == !pullUp)//if the button is pressed
      {
        if (millis() - buttonTimer[pin] >= 5)//if 5 milliseconds has passed
        {
          buttonState[pin] = BUTTON_PRESSED;
          return 1;
        }
        else
        {
          return 0;
        }
      }
      else//if the button is realeased
      {
        buttonState[pin] = BUTTON_UNPRESSED;
        return 0;
      }
      break;

    case BUTTON_PRESSED:
    
      if (digitalRead(buttonName[pin]) == !pullUp)//if the button is pressed
      {
        return 0;
      }
      else //if the button is released
      {
        buttonState[pin] = BUTTON_UNPRESSED;
        return 2;
      }
      break;
  }
}
