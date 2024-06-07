//
// Created by HP on 07.06.2024.
//

#ifndef ISENSOR_H
#define ISENSOR_H

class ISensor {
public:
    virtual ~ISensor() = default;
    virtual float readSensorValue() = 0;
};

#endif // ISENSOR_H
