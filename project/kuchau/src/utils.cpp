#include <Arduino.h>

char timestamp[13];

char *getTimestamp()
{
    int totalSeconds = round(millis() / 1000);
    int hours = totalSeconds / 3600;
    int minutes = (totalSeconds - hours * 3600) / 60;
    int seconds = totalSeconds % 60;
    int milliseconds = (millis() / 1000.0 - totalSeconds) * 1000;

    snprintf(timestamp, sizeof(timestamp), "%02d:%02d:%02d.%03d", hours, minutes, seconds, milliseconds);
    return timestamp;
}

void setPinMode(uint8_t pin, uint8_t mode, String pinName, String modeName)
{
    Serial.printf("[SETUP %s] Setting pin: [%s:%02d] to: %s:0x%02d\n", getTimestamp(), pinName, pin, modeName, mode);
    pinMode(pin, mode);
}

const char *fTest(String name)
{
    return ("hello " + name).c_str();
}

