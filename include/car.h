#pragma once
#include "Motor.h"
#include "Ultrasonic_sensor.h"

/**
 * @brief Autonomous car with obstacle avoidance
 * Uses two DC motors and one ultrasonic sensor
 */
class Car {
private:
    Motor leftMotor;
    Motor rightMotor;
    UltrasonicSensor ultrasonicSensor;

public:
    /**
     *
     * @param leftPins Motor pins for left motor
     * @param rightPins motor pins for right motor
     * @param sensorPins sensor pins for ultrasonic sensor
     */
    Car(MotorPins leftPins, MotorPins rightPins, SensorPins sensorPins);

    /**
     * @brief drives forward
     * @param speed_percent speed in percent from 0-100
     */
    void driveForward(int speed_percent);

    /**
     * @brief drives backward
     * @param speed_percent speed in percent from 0-100
     */
    void driveBackward(int speed_percent);

    /**
     *@brief stops
     */
    void stop();

    /**
     * @brief turns right
     * @param speed_percent speed in percent from 0-100
     */
    void turnRight(int speed_percent);

    /**
     * @brief turns left
     * @param speed_percent speed in percent from 0-100
     */
    void turnLeft(int speed_percent);

    /**
     * @brief checks if obstacle is in front of the car
     * @return true if obstacle is in front of the car
     */
    bool isObstacleInFront();

    void avoidObstacle();

};
