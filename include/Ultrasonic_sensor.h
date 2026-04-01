#pragma once
#include <cstdint>

struct SensorPins {
    uint8_t trigPin;
    uint8_t echoPin;
};

class UltrasonicSensor {
private:

    uint8_t trigPin;
    uint8_t echoPin;
public:
    UltrasonicSensor(SensorPins pins);

    /**
     * @brief measures distance in cm
     * @note assumes speed of sound = 343 m/s at ~20°C room tempreture
     *       accuricy decreases at higer/lower temperetures
     * @return distance in cm, return 400 of no object is detected
     */
    float getDistance() const;
};
