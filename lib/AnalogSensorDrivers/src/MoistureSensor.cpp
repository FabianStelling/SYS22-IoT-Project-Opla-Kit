//
// Created by HP on 07.06.2024.
//

#include "MoistureSensor.h"

MoistureSensor::MoistureSensor(MKRIoTCarrier carrier, const int sensorPin) : AnalogSensor(carrier, sensorPin) {}


float MoistureSensor::computeCalibratedValue(int measuredValue) {
    return (((float) measuredValue) - MIN_MOISTURE_VALUE)/ (MAX_MOISTURE_VALUE - MIN_MOISTURE_VALUE);

}