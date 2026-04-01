#pragma once
#include "Motor.h"
#include "Ultrasonic_sensor.h"


class Car {
private:
    Motor leftMotor;
    Motor rightMotor;
    UltrasonicSensor ultrasonicSensor;

public:

    Car(MotorPins leftPins, MotorPins rightPins, SensorPins sensorPins);

    void driveForward(int speed_percent);
    void driveBackward(int speed_percent);
    void stop();
    void turnRight(int speed_percent);
    void turnLeft(int speed_percent);

};
