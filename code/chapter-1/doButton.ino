/* Call a function when a private event is published from the IFTTT Do Button App.

*/

#include "math.h"

int redLed = D4;
int blueLed = D5;
int greenLed = D6;

bool redLedOn = false;
bool blueLedOn = false;
bool greenLedOn = false;



void doSomething(const char *event, const char *data)
{
  if (redLedOn == false && blueLedOn == false && greenLedOn == false)
  {
    digitalWrite(blueLed, HIGH);
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, LOW);
    blueLedOn = true;
    return;
  }

  if (redLedOn == false && blueLedOn == true && greenLedOn == false)
  {
    digitalWrite(greenLed, HIGH);
    digitalWrite(redLed, LOW);
    //pinMode

  }
}

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
