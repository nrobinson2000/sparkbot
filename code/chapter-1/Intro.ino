//Copy and paste this file into the Spark IDE
/*This firmware controls the arms and head movement using the two buttons on SparkBot's hands.  Whenever you press a button, the
corresponding arm moves either up or down, the moodlight system turns either red, blue or green randomly, and the head moves to a random
angle.  This firmware was released for SparkBot under the GPL licence.

Written by Nathan Robinson.  Last edit: Mar 29, 2015
*/

#include "math.h" //This is the library that includes the random function.

Servo rightservo; //Here we create three servo instances using the Servo class.
Servo leftservo;
Servo neckservo;

int neckangle = 0; //The angle at which the neck will turn

int rightbutton = D7; //The two buttons.  These are attached to pins D7 and A5 on the photon.
int leftbutton = A5;

int redled = D4; //Here we define the three diffent RGB LED pins.
int blueled = D5;
int greenled =D6;

int choice = 0; //This variable is used when the lights turn a random color.

void setup()
{
rightservo.attach(D0); //Here we attach the three servos
leftservo.attach(D1);
neckservo.attach(D2);

pinMode(rightbutton, INPUT);  //We define the two button pins as inputs.
pinMode(leftbutton, INPUT);

neckservo.write(90);  //We set each of the servos to 90 degrees, kind of like a reset.
rightservo.write(90);
leftservo.write(90);
}

void light() // Here is the function for changing the color of the lights
{
    choice = random(2);
    if (choice == 0)
    {
        red();
    }
    if (choice == 1)
    {
        blue();
    }
    if (choice == 2)
    {
        green();
    }
}

void rightarm() //This function takes care of the right arm movements
{
if (rightservo.read() >= 90)
    {
    rightservo.write(0);
    }

if (rightservo.read() < 90)
    {
    rightservo.write(180);   
    }
light();
}

void leftarm() //This function takes care of the left arm movements
{
if (leftservo.read() >= 90)
    {
    leftservo.write(0);
    }

if (leftservo.read() < 90)
    {
    leftservo.write(180);   
    }
light();
}

void red() //This function turns on the red, and turns off the blue and green
{
   digitalWrite(redled, HIGH);
   digitalWrite(blueled, LOW);
   digitalWrite(greenled, LOW);
}

void blue() //This function turns on the blue, and turns off the red and green
{
  digitalWrite(blueled, HIGH);
  digitalWrite(redled, LOW);
  digitalWrite(greenled, LOW);
}

void green() //This function turns on the green, and turns off the red and blue
{
    digitalWrite(greenled, HIGH);
    digitalWrite(redled, LOW);
    digitalWrite(blueled, LOW);
}

void moveNeck() //This function turns the neck to a random angle between 0 and 180
{
    neckangle = random(180);
    neckservo.write(neckangle);
}

void loop() //This is the main loop.  Whenever a button is pressed, it calls the function for that arm and the neck function
{
    if (digitalRead(rightbutton) == HIGH)
    {
        rightarm();
        moveNeck();
    }
    
    if (digitalRead(leftbutton) == HIGH)
    {
        leftarm();
        moveNeck();
    }
}
