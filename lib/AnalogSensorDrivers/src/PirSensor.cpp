//
// Created by HP on 07.06.2024.
//

#include "PirSensor.h"


PirSensor::PirSensor(MKRIoTCarrier carrier, const int sensorPin) : AnalogSensor(carrier, sensorPin) {}

/**
* The motion sensor detects either movement or no movement. Since it has an analog output, we map all values
* over 512 to 1.0 and all values below 512 to no movement detected.
* TODO: Datentyp 'float' durch ein Objekt ersetzen.
*/
float PirSensor::computeCalibratedValue(int measuredValue) {
    if (measuredValue > 512) {
        return 1.0;
    }
    else {
        return 0.0;
    }
}