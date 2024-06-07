//
// Created by HP on 07.06.2024.
//

#ifndef MOISTURESENSOR_H
#define MOISTURESENSOR_H

#include "AnalogSensor.h"

// Create an instance of the MKR IoT Carrier

class MoistureSensor : public AnalogSensor {
public:
    MoistureSensor(MKRIoTCarrier carrier, const int sensorPin);
protected:
    float computeCalibratedValue(int measuredValue) override;
private:
    constexpr static float MIN_MOISTURE_VALUE = 800.0;
    constexpr static float MAX_MOISTURE_VALUE = 1023.0;
};



#endif //MOISTURESENSOR_H
