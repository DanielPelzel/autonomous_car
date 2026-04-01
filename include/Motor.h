#pragma once
#include <cstdint>

struct MotorPins {
    uint8_t pinA;
    uint8_t pinB;
    uint8_t channel1;
    uint8_t channel2;
};

/**
 * @brief Controls Dc Motor via L9110S Driver
 *
 * Uses two PWM signals (forward / backwards) to control the Motor
 */
class Motor {
private:
    //Jeder Motor hat eigene Pins
    uint8_t pinA; //insert pin numbers
    uint8_t pinB; //insert pin numbers
    uint8_t channel1; //insert Channel number
    uint8_t channel2; //insert channel number

    static const uint16_t PWM_FREQUENCY = 5000;
    static const uint8_t PWM_Bits = 8;


public:
    /**
     *
     * @param pinA GPIO Pin forward
     * @param pinB GPIO Pin backward
     * @param channel1 PWM Channel for pinA
     * @param channel2 PWM Channel for pinB
     */
    Motor(MotorPins pins);

    /**
     * @brief car drives forward
     * @param speed_percent speed in percent (0-100)
     */
    void forward(int speed_percent);

    /**
     * @brief car drives backward
     * @param speed_percent speed in percent (0-100)
     */
    void backward(int speed_percent);

    /**
     * @brief car stops
     */
    void stop();
};
