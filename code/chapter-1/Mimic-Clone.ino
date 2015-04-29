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
Spark.subscribe("moveNeck", moveNeck);
Spark.subscribe("moveRight", moveRight);
Spark.subscribe("moveLeft", moveLeft);
Spark.subscribe("redLed", redLedChange);
Spark.subscribe("blueLed", blueLedChange);
Spark.subscribe("greenLed", greenLedChange);
}

void loop()
{/*Nothing to do here.*/}

void moveNeck(const char *event, const char *data)
{
  neckservo.write(atoi(data));
  return;
}

void moveRight(const char *event, const char *data)
{
  rightservo.write(atoi(data));
  return;
}

void moveLeft(const char *event, const char *data)
{
  leftservo.write(atoi(data));
  return;
}

void redLedChange(const char *event, const char *data)
{
  digitalWrite(redled, HIGH);
  digitalWrite(blueled, LOW);
  digitalWrite(greenled, LOW);
  return;
}

void blueLedChange(const char *event, const char *data)
{
  digitalWrite(redled, LOW);
  digitalWrite(blueled, HIGH);
  digitalWrite(greenled, LOW);
  return;
}

void greenLedChange(const char *event, const char *data)
{
  digitalWrite(redled, LOW);
  digitalWrite(blueled, LOW);
  digitalWrite(greenled, HIGH);
  return;
}
