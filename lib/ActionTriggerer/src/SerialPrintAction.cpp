//
// Created by HP on 07.06.2024.
//

#include "SerialPrintAction.h"

SerialPrintAction::SerialPrintAction(const char* message) : message(message) {}

void SerialPrintAction::doAction() {
    Serial.println(message);
}
