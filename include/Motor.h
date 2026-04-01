#pragma once
#include <cstdint>

class Motor {
private:
    uint_8_t pinA; //insert pin numbers
    uint8_t pinB; //insert pin numbers
    uint8_t channel1; //insert Channel number
    uint8_t channel2; //insert channel number 


public:
    Motor(int pinA, int pinB);
    void forward(int speed_percent);
    void backward(int speed_percent);
    void stop();
};
