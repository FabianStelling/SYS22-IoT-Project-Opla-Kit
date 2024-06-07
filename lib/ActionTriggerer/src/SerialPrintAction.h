//
// Created by HP on 07.06.2024.
//

#ifndef SERIALPRINTACTION_H
#define SERIALPRINTACTION_H

#include "IAction.h"
#include <Arduino.h>

class SerialPrintAction : public IAction {
public:
    SerialPrintAction(const char* message);
    void doAction() override;

private:
    const char* message;
};

#endif // SERIALPRINTACTION_H
