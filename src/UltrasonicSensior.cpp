//
// Created by Daniel Pelzel on 01.04.26.
//

#include "Ultrasonic_sensor.h"
#include <Arduino.h>

UltrasonicSensor::UltrasonicSensor(SensorPins pins) {
    this->trigPin = pins.trigPin;
    this->echoPin = pins.echoPin;
}
float UltrasonicSensor::getDistance() const{
    //Pin reset
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    //trigger impulse
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    //capture signal
    float distance_cm = pulseIn(echoPin, HIGH)/58.0;

    //TODO add timeout (23200 = 4m) to handel out-of-range-measurements
    //long duration = pulseIn(echoPin, HIGH, 23323);
    //if (duration == 0) return 400;

    return distance_cm;
}
