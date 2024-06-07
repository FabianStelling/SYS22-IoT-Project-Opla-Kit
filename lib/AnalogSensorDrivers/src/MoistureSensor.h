//
// Created by HP on 07.06.2024.
//

#ifndef MOISTURESENSOR_H
#define MOISTURESENSOR_H

#include <Arduino_MKRIoTCarrier.h>

// Create an instance of the MKR IoT Carrier

class MoistureSensor {
public:
    MoistureSensor(MKRIoTCarrier carrier, const int sensorPin);

    float readSensorValue();

private:
    static float computeCalibratedValue(int measuredValue);

    constexpr static float MIN_MOISTURE_VALUE = 800.0;
    constexpr static float MAX_MOISTURE_VALUE = 1023.0;
    MKRIoTCarrier carrier;
    int sensorPin;
};



#endif //MOISTURESENSOR_H
