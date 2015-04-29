//Mimic-Clone.ino

Servo rightservo;
Servo leftservo;
Servo neckservo;

int redled = D4;
int blueled = D5;
int greenled = D6;

void setup()
{
rightservo.attach(D0);
leftservo.attach(D1);
neckservo.attach(D2);

neckservo.write(90);
rightservo.write(90);
leftservo.write(90);

//Subscriptions
Spark.subscribe("moveNeck", moveNeckSlave);
Spark.subscribe("moveRight", moveRightSlave);
Spark.subscribe("moveLeft", moveLeftSlave);
Spark.subscribe("redLed", redLedSlave);
Spark.subscribe("blueLed", blueLedSlave);
Spark.subscribe("greenLed", greenLedSlave);
}

void loop()
{/*Nothing to do here.*/}

void moveNeckSlave(const char *event, const char *data)
{
  neckservo.write(atoi(data));
  return;
}

void moveRightSlave(const char *event, const char *data)
{
  rightservo.write(atoi(data));
  return;
}

void moveLeftSlave(const char *event, const char *data)
{
  leftservo.write(atoi(data));
  return;
}

void redLedSlave(const char *event, const char *data)
{
  digitalWrite(redled, HIGH);
  digitalWrite(blueled, LOW);
  digitalWrite(greenled, LOW);
  return;
}

void blueLedSlave(const char *event, const char *data)
{
  digitalWrite(redled, LOW);
  digitalWrite(blueled, HIGH);
  digitalWrite(greenled, LOW);
  return;
}

void greenLedSlave(const char *event, const char *data)
{
  digitalWrite(redled, LOW);
  digitalWrite(blueled, LOW);
  digitalWrite(greenled, HIGH);
  return;
}
