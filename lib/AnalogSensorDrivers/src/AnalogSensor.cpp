//
// Created by HP on 07.06.2024.
//

//
// Created by HP on 07.06.2024.
//

#include "AnalogSensor.h"
#include <Arduino.h>

AnalogSensor::AnalogSensor(MKRIoTCarrier carrier, const int sensorPin) : carrier(carrier), sensorPin(sensorPin) {}

float AnalogSensor::readSensorValue() {
    return computeCalibratedValue(analogRead(sensorPin));
}
