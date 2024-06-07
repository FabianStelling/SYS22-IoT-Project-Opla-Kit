#include <Arduino.h>
#include "WiFiConnector.h"
#include "PingRemote.h"
#include "MoistureSensor.h"


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

MKRIoTCarrier carrier;

void setup() {
    Serial.begin(9600);
    while (!Serial) {
        delay(100);
    }
    if (!carrier.begin()) {
        Serial.println("Failed to initialize MKR IoT Carrier");
    }
    wifiConnector.connect();
}

void loop() {
    MoistureSensor moistureSensor(carrier, A5);
    //pingRemote.ping();
    Serial.print("Moisture value: "); Serial.println(moistureSensor.readSensorValue());


    delay(1000); // Wait for a minute before the next ping
}
