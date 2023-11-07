
// Created by: Bonnie Zhu
// Created on: Oct 2023
// This program determines the distance between the object and the sensor

#include <Servo.h>

Servo servoNumber1;
const int TRIG_PIN = 3;
const int ECHO_PIN = 2;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(9600);
  servoNumber1.attach(7);
  servoNumber1.write(0);
}

void loop() {
  long duration;
  float distance;

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration * 0.0343) / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance > 50) {
    servoNumber1.write(90); 
  } else {
    servoNumber1.write(0); 
  }
}

