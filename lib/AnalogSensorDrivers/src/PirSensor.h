//
// Created by HP on 07.06.2024.
//

#ifndef PIRSENSOR_H
#define PIRSENSOR_H

#include "AnalogSensor.h"


class PirSensor : public AnalogSensor {
public:
    PirSensor(MKRIoTCarrier carrier, const int sensorPin);
protected:
    float computeCalibratedValue(int measuredValue) override;
};



#endif //PIRSENSOR_H
