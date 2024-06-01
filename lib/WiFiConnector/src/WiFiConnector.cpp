//
// Created by HP on 25.05.2024.
//

#include "WiFiConnector.h"

WiFiConnector::WiFiConnector(const char* ssid, const char* password, LogFunction logFunction)
    :ssid(ssid), password(password), logFunction(logFunction) {};

void WiFiConnector::connect() {
    logFunction("connect to ");
    logFunction(ssid);

    WiFi.begin(ssid, password);
    while(WiFi.status() != WL_CONNECTED) {
        delay(500);
        logFunction(getStatusMessage());
    }
}

const char* WiFiConnector::getStatusMessage() {
    switch (WiFi.status()) {
        case WL_IDLE_STATUS:
            return "Idle";
        case WL_NO_SSID_AVAIL:
            return "No SSID available";
        case WL_SCAN_COMPLETED:
            return "Scan completed";
        case WL_CONNECTED:
            return "Connected";
        case WL_CONNECT_FAILED:
            return "Connection failed";
        case WL_CONNECTION_LOST:
            return "Connection lost";
        case WL_DISCONNECTED:
            return "Disconnected";
        default:
            return "Unknown status";
    }
}