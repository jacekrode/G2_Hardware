#ifndef BATTERY_H
#define BATTERY_H

#include <Arduino.h>
#include <Wire.h>

class Battery {
public:
    Battery(uint8_t voltagePin, uint8_t tempPin);
    void init();
    float getVoltage();
    float getTemperature();
    float getPercentage();
    bool isLowVoltage();
    bool isOverVoltage();
    bool isOverTemperature();
    void checkBatteryStatus();

private:
    uint8_t _voltagePin;
    uint8_t _tempPin;
    float _voltage;
    float _temperature;
    float _percentage;
    const float _lowVoltageThreshold = 3.3; // Example threshold
    const float _highVoltageThreshold = 4.2; // Example threshold
    const float _highTemperatureThreshold = 60.0; // Example threshold
    void shutdownESP32();
};

#endif // BATTERY_H
