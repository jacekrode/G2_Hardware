#include "battery.h"
#include <Adafruit_Sensor.h>
#include <Adafruit_TMP006.h> // Suggestion.

Adafruit_TMP006 tmp006;

Battery::Battery(uint8_t voltagePin, uint8_t tempPin)
    : _voltagePin(voltagePin), _tempPin(tempPin), _voltage(0.0), _temperature(0.0), _percentage(0.0) {}

void Battery::init() {
    pinMode(_voltagePin, INPUT);
    pinMode(_tempPin, INPUT);
    tmp006.begin();
}

float Battery::getVoltage() {
    int sensorValue = analogRead(_voltagePin);
    _voltage = sensorValue * (5.0 / 1023.0); // Assuming 5V reference voltage
    return _voltage;
}

float Battery::getTemperature() {
    _temperature = tmp006.readObjTempC();
    return _temperature;
}

float Battery::getPercentage() {
    // Example calculation for battery percentage
    // This should be adjusted based on the specific battery characteristics
    _percentage = (_voltage - 3.0) / (4.2 - 3.0) * 100.0;
    _percentage = constrain(_percentage, 0.0, 100.0);
    return _percentage;
}

bool Battery::isLowVoltage() {
    return _voltage < _lowVoltageThreshold;
}

bool Battery::isOverVoltage() {
    return _voltage > _highVoltageThreshold;
}

bool Battery::isOverTemperature() {
    return _temperature > _highTemperatureThreshold;
}

void Battery::checkBatteryStatus() { // The case is to provide boilerplate code to better align with real-world battery management systems (BMS).
    getVoltage();
    getTemperature();
    if (isLowVoltage() || isOverVoltage() || isOverTemperature()) {
        shutdownESP32();
    }
}

void Battery::shutdownESP32() {
    // Perform actions to shutdown the ESP32
    // This could include saving state, sending a notification, etc.
    // Serial.println("Shutting down ESP32 due to battery conditions...");
    // Example: Enter deep sleep mode
    esp_sleep_enable_timer_wakeup(10000000); // Wake up after 10 seconds
    esp_deep_sleep_start();
}
