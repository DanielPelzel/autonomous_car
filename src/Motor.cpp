//
// Created by Daniel Pelzel on 01.04.26.
//

#include <Arduino.h>
#include "Motor.h"

Motor::Motor(uint8_t pinA, uint8_t pinB, uint8_t channel1, uint8_t channel2) {
    this->pinA = pinA;
    this->pinB = pinB;
    this->channel1 = channel1;
    this->channel2 = channel2;

    ledcSetup(channel1, 5000, 8);
    ledcAttachPin(pinA, channel1);

    ledcSetup(channel2, 5000, 8);
    ledcAttachPin(pinB, channel2);
}

void Motor::forward(int speed_percent) {
    int speed_PWM = map(speed_percent, 0, 100, 0, 255);
    ledcWrite(channel1, speed_PWM) ;
    ledcWrite(channel2, 0);
}

void Motor::backward(int speed_percent) {
    int speed_PWM = map(speed_percent, 0, 100, 0, 255);
    ledcWrite(channel1, 0);
    ledcWrite(channel2, speed_PWM);
}

void Motor::stop() {
    ledcWrite(channel1, 0 );
    ledcWrite(channel2, 0);
}
