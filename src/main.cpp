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

// motor objects for Left and Right Motors
Dmotor Lmotor(LmotorPin1, LmotorPin2);
Dmotor Rmotor(RmotorPin1, RmotorPin2);

// Distance sensor object
NewPing sonar(triggerPin, echoPin);

void setup() {
  // For debugging
  Serial.begin(115200);

  pinMode(LmotorPin1, OUTPUT);
  pinMode(LmotorPin2, OUTPUT);

  pinMode(RmotorPin1, OUTPUT);
  pinMode(RmotorPin2, OUTPUT);

  Lmotor.begin();
  Rmotor.begin();

  // Start out with the motors stopped
  Lmotor.Go(STOP);
  Rmotor.Go(STOP);
}

void loop() {
  delay(75);                      // Wait
  int distance = sonar.ping_in(); // Measure Distanfce
  Serial.println(distance);       // Display distance in serial monitor
  Serial.println("inches");

  // Move the motors
  Lmotor.Go(FORWARDS);
  Rmotor.Go(FORWARDS);
}
