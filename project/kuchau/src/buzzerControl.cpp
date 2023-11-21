#include <Arduino.h>
#include <utils.h>

uint8_t buzzerSignalPin;

void registerBuzzerPins(uint8_t pinSignal)
{
    Serial.printf("[%s] Registering Buzzer Pins\n", getTimestamp());
    Serial.printf("[%s] SIGNAL Pin: %d\n", getTimestamp(), pinSignal);
    buzzerSignalPin = pinSignal;
}

void playTone(int frequency, float durationMs)
{
    Serial.printf("[%s] Playing tone on Buzzer: %d [f: %d, ms: %7.3f]\n", getTimestamp(), buzzerSignalPin, frequency, durationMs);
    tone(buzzerSignalPin, frequency, durationMs);
}