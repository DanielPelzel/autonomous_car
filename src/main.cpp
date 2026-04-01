//
// Created by Daniel Pelzel on 01.04.26.
//

#include <Arduino.h>
#include "car.h"

MotorPins leftPins;
MotorPins rightPins;
SensorPins sensorPins;

Car myCar(leftPins, rightPins, sensorPins);

void setup() {
    Serial.begin(9600);
}

void loop() {
}