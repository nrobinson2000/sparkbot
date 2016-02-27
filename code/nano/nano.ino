// This file needs to be flashed to the Nano in the Arduino IDE.  Just open the "nano" directory and flash.
#include <Servo.h>

int redled = 6;
int greenled = 3;
int blueled = 5;

Servo neckservo;
Servo leftservo;
Servo rightservo;

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

  if (readString.length() > 0)
  {
    parseCommand(readString);

    readString = "";
  }
}

int parseCommand(String command)
{
  Serial.println(command);

  //  if (command.startsWith("servo"))
  //  {
  //    String servoValues = command.substring(6);
  //    moveServos(servoValues);
  //  }

  if (command.startsWith("rgb"))
  {
    String rgbValues = command.substring(4);
    changeRGB(rgbValues);
  }

  if (command.startsWith("moveNeck"))
  {
    String servoValues = command.substring(9);
    moveNeck(servoValues.toInt());
  }

  if (command.startsWith("moveLeft"))
  {
    String servoValues = command.substring(9);
    moveLeft(servoValues.toInt());
  }

  if (command.startsWith("moveRight"))
  {
    String servoValues = command.substring(10);
    moveRight(servoValues.toInt());
  }

  if (command.startsWith("servos"))
  {
    Serial.println("servos " + makeProper(neckservo.read()) + " " + makeProper(leftservo.read()) + " " + makeProper(rightservo.read()));
  }

  if (command.startsWith("neck"))
  {
    Serial.println("neck " + String(neckservo.read()));
  }

  if (command.startsWith("left"))
  {
    Serial.println("left " + String(leftservo.read()));
  }

  if (command.startsWith("right"))
  {
    Serial.println("right " + String(rightservo.read()));
  }
  
}

void moveNeck(int value)
{
  neckservo.write(value);
  delay(2);
}

void moveLeft(int value)
{
  leftservo.write(value);
  delay(2);
}

void moveRight(int value)
{
  rightservo.write(value);
  delay(2);
}

int changeRGB(String data)
{
  String red = data.substring(0, 3);
  String green = data.substring(4, 7);
  String blue = data.substring(8, 11);

  analogWrite(redled, red.toInt());
  analogWrite(greenled, green.toInt());
  analogWrite(blueled, blue.toInt());
}

String makeProper(int value)
{
  String valuedata;
  if (value < 100 && value > 9)
  {
    valuedata = String("0" + String(value));
  }
  if (value < 10)
  {
    valuedata = String("00" + String(value));
  }
  else
  {
    valuedata = String(value);
  }

  return valuedata;
}
