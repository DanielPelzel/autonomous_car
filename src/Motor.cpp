//
// Created by Daniel Pelzel on 01.04.26.
//

#include <Arduino.h>
#include "Motor.h"

Motor::Motor(MotorPins pins) {
    this->pinA = pins.pinA;
    this->pinB = pins.pinB;
    this->channel1 = pins.channel1;
    this->channel2 = pins.channel2;

    ledcSetup(channel1, PWM_FREQUENCY, PWM_Bits);
    ledcAttachPin(pinA, channel1);

    ledcSetup(channel2, PWM_FREQUENCY,PWM_Bits);
    ledcAttachPin(pinB, channel2);
}

void Motor::forward(int speed_percent) {
    //Prrozent auf PWM umrechnen
    int speed_PWM = map(speed_percent, 0, 100, 0, 255);
    ledcWrite(channel1, speed_PWM) ;
    ledcWrite(channel2, 0);
}

void Motor::backward(int speed_percent) {
    //Prozent auf PWM umrechnen
    int speed_PWM = map(speed_percent, 0, 100, 0, 255);
    ledcWrite(channel1, 0);
    ledcWrite(channel2, speed_PWM);
}

void Motor::stop() {
    ledcWrite(channel1, 0 );
    ledcWrite(channel2, 0);
}
