#include <Arduino.h>

// Pines Puente H
// Velocidad motor B
#define PWMB 22
// Motor Izquierdo,  B
#define BIN2 19
#define BIN1 18
// Encencido de puente H
#define STBY 5
// Motor Derecho,  A
#define AIN1 4
#define AIN2 13
// Velocidad motor A
#define PWMA 15

// Pin buzzer
#define BUZZER 21

int loopCount = 0;
float tDelay = 0.1;

float t = 0.0f;
int totalSeconds = 0;
int lastCheckSeconds = totalSeconds;

int pwmOutput = 110;
int secondDelta = 25;
int pwmIncrement = 10;

int lastCheckBuzz = totalSeconds;
int secondBuzzDelta = 5;

void setup()
{
  Serial.printf("[SETUP] Starting");
  Serial.begin(115200);

  if (pwmOutput == 0){
    pwmOutput += pwmIncrement;
  }
  Serial.printf("[SETUP] Initializing PWM a/b: %d\n", pwmOutput);

  // pin puente h
  pinMode(STBY, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  tone(BUZZER, 1000);
  delay(100);
  noTone(BUZZER);
  digitalWrite(STBY, HIGH);
}

void loop()
{
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMB, pwmOutput);

  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, pwmOutput);

  delay(1000*tDelay);

  t += tDelay;
  totalSeconds = round(t);

  // buzz every secondBuzzDelta seconds
  noTone(BUZZER);
  if ((totalSeconds > lastCheckBuzz) && (totalSeconds % secondBuzzDelta == 0))
  {
    tone(BUZZER, 1000);
    lastCheckBuzz = totalSeconds;
  }

  // increment pwmOutput by pwmIncrement every secondDelta seconds
  if ((totalSeconds > lastCheckSeconds) && (totalSeconds % secondDelta == 0))
  {
    pwmOutput = min(255, pwmOutput + pwmIncrement);
    lastCheckSeconds = totalSeconds;
    Serial.printf("[L: %d | %02d:%02d | %d] Setting PWM a/b: %d\n", loopCount, totalSeconds/60, totalSeconds%60, totalSeconds, pwmOutput);
  }

  loopCount += 1;
  }
