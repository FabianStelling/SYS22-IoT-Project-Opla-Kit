#include "PingRemote.h"

PingRemote::PingRemote(const char* url, WiFiSSLClient wifi, LogFunction logFunction)
    : url(url), wifi(wifi), logFunction(logFunction) {}

void PingRemote::ping() {
    HttpClient http(wifi, url, 443);  // Replace 443 with 80 if using HTTP

    logFunction("Starting HTTP request...");

    http.beginRequest();
    int result = http.get("/");
    http.endRequest();

    if (result == 0) {
        int httpCode = http.responseStatusCode();
        if (httpCode > 0) {
            String response = "HTTP GET request to " + String(url) + " returned code: " + String(httpCode);
            logFunction(response.c_str());
        } else {
            String error = "HTTP GET request to " + String(url) + " failed, error: " + String(httpCode);
            logFunction(error.c_str());
        }
    } else {
        String error = "Failed to connect to " + String(url) + ", error: " + String(getErrorMessage(result));
        logFunction(error.c_str());
    }
}

const char* PingRemote::getErrorMessage(int errorCode) {
    switch (errorCode) {
        case 0:
            return "Success";
        case -1:
            return "Connection refused";
        case -2:
            return "Send header failed";
        case -3:
            return "Timeout";
        case -4:
            return "Not connected";
        case -5:
            return "Connection lost";
        case -6:
            return "No memory";
        case -7:
            return "Read error";
        default:
            return "Unknown error";
    }
}
