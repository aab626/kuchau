#include <Arduino.h>
#include <ESP32Encoder.h>
#include "utils.h"

// Pins
uint8_t pinEncoderLA;
uint8_t pinEncoderLB;
uint8_t pinEncoderRA;
uint8_t pinEncoderRB;

// Encoder objects
ESP32Encoder encoderL;
ESP32Encoder encoderR;

void registerLEncoderPins(uint8_t pinA, uint8_t pinB)
{
    Serial.printf("[%s] Registering L Encoder Pins\n", getTimestamp());
    Serial.printf("[%s] L Encoder A (C1): %d\n", getTimestamp(), pinA);
    Serial.printf("[%s] L Encoder B (C2): %d\n", getTimestamp(), pinB);
    pinEncoderLA = pinA;
    pinEncoderLB = pinB;
    encoderL.attachHalfQuad(pinEncoderLA, pinEncoderLB);
}

void registerREncoderPins(uint8_t pinA, uint8_t pinB)
{
    Serial.printf("[%s] Registering R Encoder Pins\n", getTimestamp());
    Serial.printf("[%s] R Encoder A (C1): %d\n", getTimestamp(), pinA);
    Serial.printf("[%s] R Encoder B (C2): %d\n", getTimestamp(), pinB);
    pinEncoderRA = pinA;
    pinEncoderRB = pinB;
    encoderR.attachHalfQuad(pinEncoderRA, pinEncoderRB);
}

int64_t getCountLEncoder()
{
    return encoderL.getCount();
}

int64_t getCountREncoder()
{
    return encoderR.getCount();
}
