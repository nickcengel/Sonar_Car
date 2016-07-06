#include "motr.h"
#include <NewPing.h>
#include <arduino.h>

// Pins for distance sensor

// Pins for motors
int LmotorPin1 = 3;
int LmotorPin2 = 5;

int RmotorPin1 = 6;
int RmotorPin2 = 9;

int lightSensorPin1 = A0;
int lightSensorPin2 = A1;

Dmotor Lmotor(LmotorPin1, LmotorPin2);
Dmotor Rmotor(RmotorPin1, RmotorPin2);

void setup() {

  Serial.begin(115200);
  pinMode(LmotorPin1, OUTPUT);
  pinMode(LmotorPin2, OUTPUT);

  pinMode(RmotorPin1, OUTPUT);
  pinMode(RmotorPin2, OUTPUT);

  Lmotor.begin();
  Rmotor.begin();

  Lmotor.Go(STOP);
  Rmotor.Go(STOP);

  delay(2000);
}

void loop() {
  int g = analogRead(A0);

  Serial.println("sensor: ");
  Serial.print(g);
  Serial.println();

  delay(50);
}
