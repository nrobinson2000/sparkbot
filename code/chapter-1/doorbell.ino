/*
Activate a doorbell from the IFTTT app.  When I arrive home, ring the doorbell.
*/

int doorbell = A2;
int currentDelay = 10000000000000000;

void setup()
{
  pinMode(doorbell, OUTPUT);
  Spark.subscribe("ArrivedAtHome", ringDoorbell);

}

void ringDoorbell(const char *event, const char *data)
{
   currentDelay = millis();
  digitalWrite(doorbell, HIGH);
}

void loop()
{
  if (millis() - currentDelay > 1000)
  {
    digitalWrite(doorbell, LOW);
  }

}
