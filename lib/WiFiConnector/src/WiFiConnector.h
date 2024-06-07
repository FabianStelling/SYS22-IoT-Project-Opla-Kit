//
// Created by HP on 25.05.2024.
//

#ifndef WIFICONNECTOR_H
#define WIFICONNECTOR_H

#include "WiFiNINA.h"

class WiFiConnector {
public:
    using LogFunction = void (*)(const char*);
    WiFiConnector(const char* ssid, const char* password, LogFunction logFunction);
    void connect();
    const char* getStatusMessage();
private:
    const char* ssid;
    const char* password;
    LogFunction logFunction;
};



#endif //WIFICONNECTOR_H