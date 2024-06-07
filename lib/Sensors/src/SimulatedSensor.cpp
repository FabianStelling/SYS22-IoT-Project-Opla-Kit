//
// Created by HP on 07.06.2024.
//

#include "SimulatedSensor.h"

SimulatedSensor::SimulatedSensor(const float calibratedValue) : calibratedValue(calibratedValue) {}


float SimulatedSensor::readSensorValue() {
    return calibratedValue;
}
