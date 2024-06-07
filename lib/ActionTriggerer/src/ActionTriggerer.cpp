//
// Created by HP on 07.06.2024.
//

#include "ActionTriggerer.h"

ActionTriggerer::ActionTriggerer(ISensor* sensor, IAction* action, float threshold)
    : sensor(sensor), action(action), threshold(threshold) {}

void ActionTriggerer::check() {
    float sensorValue = sensor->readSensorValue();
    if (sensorValue < threshold) {
        action->doAction();
    }
}
