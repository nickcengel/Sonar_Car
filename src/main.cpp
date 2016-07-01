#include "motr.h"
#include <NewPing.h>
#include <arduino.h>

// Pins for distance sensor
int triggerPin = 14;
int echoPin = 16;

// Pins for motors
int LmotorPin1 = 3;
int LmotorPin2 = 5;

int RmotorPin1 = 6;
int RmotorPin2 = 9;

int lightSensorPin = A0;
int oldLight = 0;
int newLight = 0;

int LEDpin1 = 8;
int LEDpin2 = 15;

Dmotor Lmotor(LmotorPin1, LmotorPin2);
Dmotor Rmotor(RmotorPin1, RmotorPin2);

NewPing sonar(triggerPin, echoPin);

void setup() {

  pinMode(LmotorPin1, OUTPUT);
  pinMode(LmotorPin2, OUTPUT);

  pinMode(RmotorPin1, OUTPUT);
  pinMode(RmotorPin2, OUTPUT);

  pinMode(LEDpin1, OUTPUT);
  pinMode(LEDpin2, OUTPUT);

  Lmotor.begin();
  Rmotor.begin();

  Lmotor.Go(STOP);
  Rmotor.Go(STOP);

  delay(2000);
  oldLight = analogRead(lightSensorPin);
}

void loop() {
  // digitalWrite(LEDpin, LOW);

  Lmotor.Go(FORWARDS);
  Rmotor.Go(FORWARDS);
  delay(100);

  int distance = sonar.ping_in();

  if ((distance > 0) & (distance < 8)) {
    digitalWrite(LEDpin2, HIGH);
    Lmotor.Go(FORWARDS);
    Rmotor.Go(BACKWARDS);
    delay(700);
  } else
    digitalWrite(LEDpin2, LOW);

  newLight = analogRead(lightSensorPin);

  if (newLight < oldLight) {
    Lmotor.Go(BACKWARDS);
    Rmotor.Go(FORWARDS);
    digitalWrite(LEDpin1, HIGH);
    delay(100);
  } else
    digitalWrite(LEDpin1, LOW);

  oldLight = newLight;
}
