// This file may be need to be flashed to the Nano in the Arduino IDE.  Just open the "nano" directory and flash.

int redled = 6;
int greenled = 3;
int blueled = 5;

Servo rightservo;
Servo leftservo;
Servo neckservo;

String readString;

void setup()
{
  Serial.begin(9600);

  neckservo.attach(9);
  leftservo.attach(10);
  rightservo.attach(11);

  pinMode(redled, OUTPUT);
  pinMode(greenled, OUTPUT);
  pinMode(blueled, OUTPUT);
}

void loop()
{

  while (Serial.available())
  {
    delay(3);
    char c = Serial.read();
    readString += c;
  }

  readString.trim();

  if (readString.length() >0)
  {
  parseCommand(readString);

    readString="";
  }
}

int parseCommand(String command)
{
  if (command.startsWith("servo"))
  {
    String servoValues = command.subString(6);
    moveServos(servoValues);
  }

  if (command.startsWith("rgb"))
  {
    String rgbValues = command.subString(4);
    changeRGB(rgbValues);
  }

  if (command.startsWith("neck"))
  {
    Serial.println(neckservo.read());
  }

  if (command.startsWith("right"))
  {
    Serial.println(rightservo.read());
  }

  if (command.startsWith("left"))
  {
    Serial.println(leftservo.read());
  }
}

int moveServos(String data)
{
  String neckvalue = data.substring(0, 3);
  String rightvalue = data.substring(4, 7);
  String leftvalue = data.substring(8,11);

  if (neckvalue.toInt() != 200)
  {
    moveNeck(neckvalue.toInt());
  }
  if (rightvalue.toInt() != 200)
  {
    moveRight(rightvalue.toInt());
  }
  if (leftvalue.toInt() != 200)
  {
    moveLeft(leftvalue.toInt());
  }
}

void moveNeck(int value)
{
  neckservo.write(value);
  delay(15);
}

void moveRight(int value)
{
  rightservo.write(value);
  delay(15);
}

void moveLeft(int value)
{
  leftservo.write(value);
  delay(15);
}

int changeRGB(String data)
{
  String red = data.substring(0, 3);
  String green = data.substring(4, 7);
  String blue = data.substring(8,11);

  analogWrite(redled, red.toInt());
  analogWrite(greenled, green.toInt());
  analogWrite(blueled, blue.toInt());
}
