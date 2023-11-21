#include <Arduino.h>

void registerLMotorPins(uint8_t pinNegative, uint8_t pinPositive, uint8_t pinPWM);
void registerRMotorPins(uint8_t pinNegative, uint8_t pinPositive, uint8_t pinPWM);

void stopLMotor();
void forwardLMotor();
void backwardLMotor();
void reverseLMotor();
void setPWMLMotor(int pwmValue);
int getLMotorDirection();

void stopRMotor();
void forwardRMotor();
void backwardRMotor();
void reverseRMotor();
void setPWMRMotor(int pwmValue);
int getRMotorDirection();