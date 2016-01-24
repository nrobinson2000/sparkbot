// This file may be needs to be flashed to the Nano in the Arduino IDE.

int ledPin = 13;
String readString;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  Serial.println("serial on/off test 0021"); // so I can keep track
}

void loop() {

  while (Serial.available()) {
    delay(3);
    char c = Serial.read();
    readString += c;
  }
  readString.trim();
  if (readString.length() >0) {
    if (readString == "on"){
      Serial.println("switching on");
      digitalWrite(ledPin, HIGH);
    }
    if (readString == "off")
    {
      Serial.println("switching off");
      digitalWrite(ledPin, LOW);
    }

    readString="";
  }
}
