#include <Arduino.h>
#include "WiFiConnector.h"
#include "PingRemote.h"


const char* ssid = "***";
const char* password = "***";
;
void logToSerial(const char* message) {
    Serial.println(message);
}

WiFiConnector wifiConnector(ssid, password, logToSerial);
const char* url = "www.google.com"; // Update to just the domain

WiFiSSLClient wifi;  // Use WiFiSSLClient for HTTPS
PingRemote pingRemote(url, wifi, logToSerial);

void setup() {
    Serial.begin(9600);
    while (!Serial) {
        delay(100);
    }
    wifiConnector.connect();
}

void loop() {
    pingRemote.ping();
    delay(10000); // Wait for a minute before the next ping

}
