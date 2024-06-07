//
// Created by HP on 07.06.2024.
//

#ifndef SIMULATEDSENSOR_H
#define SIMULATEDSENSOR_H

#include "ISensor.h"

class SimulatedSensor : public ISensor {
public:
    explicit SimulatedSensor(float calibratedValue);
    float readSensorValue() override;
private:
    const float calibratedValue;
};



#endif //SIMULATEDSENSOR_H
