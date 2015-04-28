//Mimic-Master.ino

Servo rightservo;
Servo leftservo;
Servo neckservo;

int neckAngle = 0;
int rightArmAngle = 0;
int leftArmAngle = 0;

int rightbutton = D7;
int leftbutton = A5;

int redled = D4;
int blueled = D5;
int greenled =D6;

bool redledOn = false;
bool blueledOn = false;
bool greenledOn = false;

int choice = 0;

void setup()
{
rightservo.attach(D0);
leftservo.attach(D1);
neckservo.attach(D2);

pinMode(rightbutton, INPUT);
pinMode(leftbutton, INPUT);

attachInterrupt(rightbutton, sync, RISING);

neckservo.write(90);
neckAngle = neckservo.read();
rightservo.write(90);
rightArmAngle = rightservo.read();
leftservo.write(90);
leftArmAngle = leftservo.read();
}

void sync()
{
  syncServos();
  syncLights();
}

void syncServos()
{
  if (neckAngle != neckservo.read())
  {
    Spark.publish("moveNeck", String(neckservo.read()));
  }

  if (rightArmAngle != rightservo.read())
  {
    Spark.publish("moveRight", String(rightservo.read()));
  }

  if (leftArmAngle != leftservo.read())
  {
    Spark.publish("moveLeft", String(leftservo.read()));
  }
}


void switchLights()
{
  if (choice == 0)
  {
    digitalWrite(redled, HIGH);
    redledOn = true;
    digitalWrite(blueled, LOW);
    blueledOn = false;
    digitalWrite(greenled, LOW);
    greenledOn = false;
    choice = 1;
    return;
  }

  if (choice == 1)
  {
    digitalWrite(redled, LOW);
    redledOn = false;
    digitalWrite(blueled, HIGH);
    blueledOn = true;
    digitalWrite(greenled, LOW);
    greenledOn = false;
    choice = 2;
    return;
  }

  if (choice == 2)
  {
    digitalWrite(redled, LOW);
    redledOn = false;
    digitalWrite(blueled, LOW);
    blueledOn = false;
    digitalWrite(greenled, HIGH);
    greenledOn = true;
    choice = 0;
    return;
  }
}

void syncLights()
{
  if (redledOn == true)
  {
    Spark.publish("RedLed");
    return;
  }

  if (blueledOn == true)
  {
    Spark.publish("BlueLed");
    return;
  }

  if (greenledOn == true)
  {
    Spark.publish("GreenLed");
    return;
  }
}
