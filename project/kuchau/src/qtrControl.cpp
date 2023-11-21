#include <Arduino.h>
#include <QTRSensors.h>
#include "utils.h"

// Pins
uint8_t pinQTR1AL;
uint8_t pinQTR1AR;

uint8_t pinQTR8A_IR;
uint8_t pinQTR8A_2;
uint8_t pinQTR8A_3;
uint8_t pinQTR8A_4;
uint8_t pinQTR8A_5;
uint8_t pinQTR8A_6;
uint8_t pinQTR8A_7;

// Variables
QTRSensors qtr1A;
QTRSensors qtr8A;
const int nSensors1A = 2;
const int nSensors8A = 6;
int timeout = 2500;

uint8_t sensorPins1A[nSensors1A];

uint16_t sensorValues1A[nSensors1A];
uint16_t sensorValues8A[nSensors8A];



// void registerLQTRPins(  uint8_t p_pinQTR1AL, uint8_t p_pinQTR1AR, 
//                         uint8_t p_pinQTR8A_IR, uint8_t p_pinQTR8A_2, uint8_t p_pinQTR8A_3, uint8_t p_pinQTR8A_4, uint8_t p_pinQTR8A_5, uint8_t p_pinQTR8A_6, uint8_t p_pinQTR8A_7)
// {
//     Serial.printf("[%s] Registering L Motor Pins\n", getTimestamp());
//     Serial.printf("[%s] QTR-1A L: %d\n", getTimestamp(), p_pinQTR1AL);
//     Serial.printf("[%s] QTR-1A R: %d\n", getTimestamp(), p_pinQTR1AR);
//     Serial.printf("[%s] QTR-8A IR: %d\n", getTimestamp(), p_pinQTR8A_IR);
//     Serial.printf("[%s] QTR-8A 2: %d\n", getTimestamp(), p_pinQTR8A_2);
//     Serial.printf("[%s] QTR-8A 3: %d\n", getTimestamp(), p_pinQTR8A_3);
//     Serial.printf("[%s] QTR-8A 4: %d\n", getTimestamp(), p_pinQTR8A_4);
//     Serial.printf("[%s] QTR-8A 5: %d\n", getTimestamp(), p_pinQTR8A_5);
//     Serial.printf("[%s] QTR-8A 6: %d\n", getTimestamp(), p_pinQTR8A_6);
//     Serial.printf("[%s] QTR-8A 7: %d\n", getTimestamp(), p_pinQTR8A_7);

//     pinQTR8A_IR = p_pinQTR8A_IR;
//     pinQTR8A_2 = p_pinQTR8A_2;
//     pinQTR8A_3 = p_pinQTR8A_3;
//     pinQTR8A_4 = p_pinQTR8A_4;
//     pinQTR8A_5 = p_pinQTR8A_5;
//     pinQTR8A_6 = p_pinQTR8A_6;
//     pinQTR8A_7 = p_pinQTR8A_7;


//     qtr8A.setTypeRC();
//     qtr8A.setSensorPins((const uint8_t[]){p_pinQTR8A_2, p_pinQTR8A_3, p_pinQTR8A_4, p_pinQTR8A_5, p_pinQTR8A_6, p_pinQTR8A_7}, nSensors8A);
//     qtr8A.setEmitterPin(pinQTR8A_IR);
//     qtr8A.setTimeout(timeout);
// }

void registerQTR1APins(uint8_t p_pinQTR1AL, uint8_t p_pinQTR1AR)
{
    Serial.printf("[%s] Registering QTR-1A Pins\n", getTimestamp());
    Serial.printf("[%s] QTR-1A L: %d\n", getTimestamp(), p_pinQTR1AL);
    Serial.printf("[%s] QTR-1A R: %d\n", getTimestamp(), p_pinQTR1AR);
    
    pinQTR1AL = p_pinQTR1AL;
    pinQTR1AR = p_pinQTR1AR;
    
    sensorPins1A[0] = pinQTR1AL;
    sensorPins1A[1] = pinQTR1AR;

    qtr1A.setTypeAnalog();
    qtr1A.setSensorPins(sensorPins1A, nSensors1A);
    qtr1A.setTimeout(timeout);
}

void updateQTR1A()
{
    qtr1A.read(sensorValues1A);
}

uint16_t getLQTR()
{
    return sensorValues1A[0];
}

uint16_t getRQTR()
{
    return sensorValues1A[1];
}
