#include <Servo.h>

const int analogInPin = A0;  // Adjust for board
int sensorValue = 0;
int pos = 0;
const int ledPin =  12;      // Adjust for board

Servo myservo;

void setup() {
  myservo.attach(9);  // Adjust for board
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
}

void loop() {

  //Code to jitter the servo, prevent jamming before sorting the next coin
  for (pos = 82; pos >= 75; pos -= 1) {
    myservo.write(pos);
    delay(10);
  }
  for (pos = 75; pos <= 82; pos += 1) {
    myservo.write(pos);
    delay(10);
  }
  delay(1000);
  for (pos = 82; pos >= 30; pos -= 1) {
    myservo.write(pos);
    delay(10);
  }
  for (pos = 30; pos <= 100; pos += 1) {
    myservo.write(pos);
    delay(10);
  }
  for (pos = 100; pos >= 82; pos -= 1) {
    myservo.write(pos);
    delay(10);
  }
  delay(1000);

  //Reading photo transistor value
  sensorValue = analogRead(analogInPin);
  Serial.println(sensorValue);

  //If the photo transistor detects the green coin
  if (0 < sensorValue && sensorValue < 800) {
    for (pos = 75; pos <= 160; pos += 1) {
      myservo.write(pos);
      delay(5);
    }
    for (pos = 160; pos >= 80; pos -= 1) {
      myservo.write(pos);
      delay(5);
    }
    delay(1000);
  }

  //If the photo transistor detects the wooden coin
  if (799 < sensorValue && sensorValue < 1000) {
    for (pos = 90; pos >= 0; pos -= 1) {
      myservo.write(pos);
      delay(5);
    }
    for (pos = 0; pos <= 82; pos += 1) {
      myservo.write(pos);
      delay(5);
    }
    delay(1000);
  }
}
