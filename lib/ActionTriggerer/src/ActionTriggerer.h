//
// Created by HP on 07.06.2024.
//

#ifndef ACTIONTRIGGERER_H
#define ACTIONTRIGGERER_H

#include "ISensor.h"
#include "IAction.h"

class ActionTriggerer {
public:
    ActionTriggerer(ISensor* sensor, IAction* action, float threshold);
    void check();

private:
    ISensor* sensor;
    IAction* action;
    float threshold;
};

#endif // ACTIONTRIGGERER_H
