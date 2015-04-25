/* Call a function when a private event is published from the IFTTT Do Button App.

*/

#include "math.h"

int redLed = D4;
int blueLed = D5;
int greenLed = D6;

bool redLedOn = false;
bool blueLedOn = false;
bool greenLedOn = false;

void setup()
{
  Spark.subscribe("doButtonPressed", doSomething);

  pinMode(redLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
}

void loop()
{


}

void doSomething()
{
  if (redLedOn == false && blueLedOn == false && greenLedOn == false)
  {
    pinMode(blueLed, HIGH);
    pinMode(redLed, LOW);
    pinMode(greenLed, LOW);
    blueLedOn = true;
    return;
  }

  if (redLedOn == false && blueLedOn == true && greenLedOn == false)
  {
    pinMode(greenLed, HIGH);
    pinMode(redLed, LOW)
    pinMode

  }
}
