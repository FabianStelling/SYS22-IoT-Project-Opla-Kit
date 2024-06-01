#ifndef PINGREMOTE_H
#define PINGREMOTE_H

#include <Arduino.h>
#include <functional>
#include <ArduinoHttpClient.h>
#include <WiFiNINA.h> // Ensure this library is included

typedef std::function<void(const char*)> LogFunction;

class PingRemote {
public:
    PingRemote(const char* url, WiFiSSLClient wifi, LogFunction logFunction);
    void ping();
    const char* getErrorMessage(int errorCode);

private:
    const char* url;
    WiFiSSLClient wifi;
    LogFunction logFunction;
};

#endif // PINGREMOTE_H
