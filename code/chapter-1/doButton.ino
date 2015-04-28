/* Call a function when a private event is published from the IFTTT Do Button App.

*/

#include "math.h"

int redLed = D4;
int blueLed = D5;
int greenLed = D6;

bool redLedOn = false;
bool blueLedOn = false;
bool greenLedOn = false;


void doLights() // Here is the function for changing the color of the lights
{
    int decision = random(2);
    if (decision == 0)
    {
        digitalWrite(redLed, HIGH);
        digitalWrite(blueLed, LOW);
        digitalWrite(greenLed, LOW);

        redLedOn = true;
        blueLedOn = false;
        greenLedOn = false;
        return;
    }
    if (decision == 1)
    {
      digitalWrite(redLed, LOW);
      digitalWrite(blueLed, HIGH);
      digitalWrite(greenLed, LOW);

      redLedOn = false;
      blueLedOn = true;
      greenLedOn = false;
      return;

    }
    if (decision == 2)
    {
      digitalWrite(redLed, LOW);
      digitalWrite(blueLed, LOW);
      digitalWrite(greenLed, HIGH);

      redLedOn = false;
      blueLedOn = false;
      greenLedOn = false;
      return;
    }
}

void doSomething(const char *event, const char *data)
{
  doLights();
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
