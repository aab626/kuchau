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


void registerLEncoderPins(uint8_t pinLA, uint8_t pinLB)
{
    Serial.printf("[%s] Registering L Encoder Pins\n", getTimestamp());
    Serial.printf("[%s] L Encoder A (C1): %d\n", getTimestamp(), pinLA);
    Serial.printf("[%s] L Encoder B (C2): %d\n", getTimestamp(), pinLB);
    pinEncoderLA = pinLA;
    pinEncoderLB = pinLB;
    encoderL.attachHalfQuad(pinEncoderLA, pinEncoderLB);
    ESP32Encoder::useInternalWeakPullResistors = UP;
}

void registerREncoderPins(uint8_t pinRA, uint8_t pinRB)
{
    Serial.printf("[%s] Registering R Encoder Pins\n", getTimestamp());
    Serial.printf("[%s] R Encoder A (C1): %d\n", getTimestamp(), pinRA);
    Serial.printf("[%s] R Encoder B (C2): %d\n", getTimestamp(), pinRB);
    pinEncoderRA = pinRA;
    pinEncoderRB = pinRB;
    encoderR.attachHalfQuad(pinEncoderRA, pinEncoderRB);
    ESP32Encoder::useInternalWeakPullResistors = UP;
}

int64_t getCountLEncoder()
{
    return encoderL.getCount();
}

int64_t getCountREncoder()
{
    return encoderR.getCount();
}
