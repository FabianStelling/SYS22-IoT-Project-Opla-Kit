#include <Arduino.h>
#include "WiFiConnector.h"
#include "PingRemote.h"
#include "MoistureSensor.h"
#include "PirSensor.h"
#include "SimulatedSensor.h"


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
MoistureSensor moistureSensor(carrier, A5);
PirSensor pirSensor(carrier, A6);
SimulatedSensor simulatedSensorLowValue(0.1);
SimulatedSensor simulatedSensorHighValue(0.2);

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
    pingRemote.ping();
    Serial.print("Moisture value: "); Serial.println(moistureSensor.readSensorValue());
    Serial.print("PIRSensorValue: "); Serial.println(pirSensor.readSensorValue());
    Serial.print("Low Simulated Value: "); Serial.println(simulatedSensorLowValue.readSensorValue());
    Serial.print("High Simulated Value: "); Serial.println(simulatedSensorHighValue.readSensorValue());

    delay(1000); // Wait for a minute before the next ping
}
