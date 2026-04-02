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

void Car::avoidObstacle() {
//TODO add Code for Obstacle avoidance
     float distance = ultrasonicSensor.getDistance();
    const float SAFETY_DISTANCE = 20.0f;
    const float OBSTACLE_DISTANCE = 10.0f;

    if (distance < OBSTACLE_DISTANCE){
        stop();
        delay(1000);

        while (distance < SAFETY_DISTANCE) {
            turnLeft(10);
            distance = ultrasonicSensor.getDistance();
        }
        delay(2000);
        driveForward(75);
    }else {
        driveForward(75);
    }

}
