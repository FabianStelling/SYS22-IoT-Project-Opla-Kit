//
// Created by HP on 07.06.2024.
//

#ifndef ANALOGSENSOR_H
#define ANALOGSENSOR_H

#include <Arduino_MKRIoTCarrier.h>
#include "ISensor.h"

class AnalogSensor : public ISensor {
public:
    AnalogSensor(MKRIoTCarrier carrier, const int sensorPin);

    float readSensorValue() override;

protected:
    virtual float computeCalibratedValue(int measuredValue) = 0;

    int sensorPin;
    MKRIoTCarrier carrier;

};

#endif //ANALOGSENSOR_H
