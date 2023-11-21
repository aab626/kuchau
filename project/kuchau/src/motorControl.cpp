#include <Arduino.h>
#include "utils.h"

// Pins
uint8_t pinMotorLNegative;
uint8_t pinMotorLPositive;
uint8_t pinMotorLPWM;
uint8_t pinMotorRNegative;
uint8_t pinMotorRPositive;
uint8_t pinMotorRPWM;

// Variables
int motorLDirection;
int motorRDirection;

void registerLMotorPins(uint8_t pinNegative, uint8_t pinPositive, uint8_t pinPWM)
{
    Serial.printf("[%s] Registering L Motor Pins\n", getTimestamp());
    Serial.printf("[%s] L Motor Negative: %d\n", getTimestamp(), pinNegative);
    Serial.printf("[%s] L Motor Positive: %d\n", getTimestamp(), pinPositive);
    Serial.printf("[%s] L Motor PWM:      %d\n", getTimestamp(), pinPWM);
    pinMotorLNegative = pinNegative;
    pinMotorLPositive = pinPositive;
    pinMotorLPWM = pinPWM;
}

void registerRMotorPins(uint8_t pinNegative, uint8_t pinPositive, uint8_t pinPWM)
{
    Serial.printf("[%s] Registering R Motor Pins\n", getTimestamp());
    Serial.printf("[%s] R Motor Negative: %d\n", getTimestamp(), pinNegative);
    Serial.printf("[%s] R Motor Positive: %d\n", getTimestamp(), pinPositive);
    Serial.printf("[%s] R Motor PWM:      %d\n", getTimestamp(), pinPWM);
    pinMotorRNegative = pinNegative;
    pinMotorRPositive = pinPositive;
    pinMotorRPWM = pinPWM;
}

void stopLMotor()
{
    Serial.printf("[%s] Stopping L Motor\n", getTimestamp());
    digitalWrite(pinMotorLNegative, LOW);
    digitalWrite(pinMotorLPositive, LOW);
    motorLDirection = 0;
}

void forwardLMotor()
{
    Serial.printf("[%s] Setting L Motor to FORWARD\n", getTimestamp());
    digitalWrite(pinMotorLNegative, LOW);
    digitalWrite(pinMotorLPositive, HIGH);
    motorLDirection = 1;
}

void backwardLMotor()
{
    Serial.printf("[%s] Setting L Motor to BACKWARD\n", getTimestamp());
    digitalWrite(pinMotorLNegative, HIGH);
    digitalWrite(pinMotorLPositive, LOW);
    motorLDirection = -1;
}

void reverseLMotor()
{
    if (motorLDirection == 1)
    {
        backwardLMotor();
    } else if (motorLDirection == -1)
    {
        forwardLMotor();
    }
}

int getLMotorDirection()
{
    return motorLDirection;
}

void setPWMLMotor(int pwmValue)
{
    Serial.printf("[%s] Setting L Motor PWM: %d\n", getTimestamp(), pwmValue);
    analogWrite(pinMotorLPWM, pwmValue);
}

void stopRMotor()
{
    Serial.printf("[%s] Stopping R Motor\n", getTimestamp());
    digitalWrite(pinMotorRNegative, LOW);
    digitalWrite(pinMotorRPositive, LOW);
    motorRDirection = 0;
}

void forwardRMotor()
{
    Serial.printf("[%s] Setting R Motor to FORWARD\n", getTimestamp());
    digitalWrite(pinMotorRNegative, LOW);
    digitalWrite(pinMotorRPositive, HIGH);
    motorRDirection = 1;
}

void backwardRMotor()
{
    Serial.printf("[%s] Setting R Motor to BACKWARD\n", getTimestamp());
    digitalWrite(pinMotorRNegative, HIGH);
    digitalWrite(pinMotorRPositive, LOW);
    motorRDirection = -1;
}

void reverseRMotor()
{
    if (motorRDirection == 1)
    {
        backwardRMotor();
    }
    else if (motorRDirection == -1)
    {
        forwardRMotor();
    }
}

int getRMotorDirection()
{
    return motorRDirection;
}

void setPWMRMotor(int pwmValue)
{
    Serial.printf("[%s] Setting R Motor PWM: %d\n", getTimestamp(), pwmValue);
    analogWrite(pinMotorRPWM, pwmValue);
}
