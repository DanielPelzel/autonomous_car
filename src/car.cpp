//
// Created by Daniel Pelzel on 01.04.26.
//
#include "Car.h"
#include <Arduino.h>

Car::Car(MotorPins left_motor_pins, MotorPins right_motor_pins, SensorPins sensor_pins)
    :leftMotor(left_motor_pins),
     rightMotor(right_motor_pins),
     ultrasonicSensor(sensor_pins)
{
}

void Car::driveForward(int speed_percent) {
    rightMotor.forward(speed_percent);
    leftMotor.forward(speed_percent);
}

void Car::driveBackward(int speed_percent) {
    rightMotor.backward(speed_percent);
    leftMotor.backward(speed_percent);
}

void Car::stop() {
    rightMotor.stop();
    leftMotor.stop();
}

void Car::turnRight(int speed_percent) {
    rightMotor.backward(speed_percent);
    leftMotor.forward(speed_percent);
}

void Car::turnLeft(int speed_percent) {
    rightMotor.forward(speed_percent);
    leftMotor.backward(speed_percent);
}
