#include <Arduino.h>
#include "utils.h"
#include "motorControl.h"
#include "buzzerControl.h"
#include "encoderControl.h"
#include "qtrControl.h"

// Pinout
// H-Bridge
#define PIN_HB_STBY 5       // H-Bridge standby
#define PIN_HB_AIN1 4       // Motor A negative
#define PIN_HB_AIN2 13      // Motor A positive
#define PIN_HB_PWMA 15      // Motor A PWM input
#define PIN_HB_BIN1 18      // Motor B negative
#define PIN_HB_BIN2 19      // Motor B positive
#define PIN_HB_PWMB 22      // Motor B PWM input

// Buzzer
#define PIN_BUZZER 21       // Buzzer signal

// Encoders
#define PIN_ENCODER_A_A 39       // Encoder A pin A (C1)
#define PIN_ENCODER_A_B 36       // Encoder A pin B (C2)
#define PIN_ENCODER_B_A 16       // Encoder B pin A (C1)
#define PIN_ENCODER_B_B 17       // Encoder B pin B (C2)

// QTR 1A
#define QTR1A_A 35
#define QTR1A_B 34

// Program constants
#define SERIAL_SPEED 115200
#define LOOP_DELAY_MS 100

void setup()
{
    // Initialize and wait for serial
    Serial.begin(SERIAL_SPEED);
    while (!Serial);
    Serial.printf("\n[SETUP %s] Starting KUCHAU LINE FOLLOWER\n", getTimestamp());
    Serial.printf("[SETUP %s] Serial Speed set to: %d\n", getTimestamp(), SERIAL_SPEED);

    // Pin mode setting
    // H-Bridge
    Serial.printf("[SETUP %s] Setting pin modes\n", getTimestamp());
    setPinMode(PIN_HB_STBY, OUTPUT, "PIN_HB_STBY", "OUTPUT");
    setPinMode(PIN_HB_AIN1, OUTPUT, "PIN_HB_AIN1", "OUTPUT");
    setPinMode(PIN_HB_AIN2, OUTPUT, "PIN_HB_AIN2", "OUTPUT");
    setPinMode(PIN_HB_PWMA, OUTPUT, "PIN_HB_PWMA", "OUTPUT");
    setPinMode(PIN_HB_BIN1, OUTPUT, "PIN_HB_BIN1", "OUTPUT");
    setPinMode(PIN_HB_BIN2, OUTPUT, "PIN_HB_BIN2", "OUTPUT");
    setPinMode(PIN_HB_PWMB, OUTPUT, "PIN_HB_PWMB", "OUTPUT");

    // Buzzer
    setPinMode(PIN_BUZZER, OUTPUT, "PIN_BUZZER", "OUTPUT");

    // Encoders
    setPinMode(PIN_ENCODER_A_A, INPUT, "PIN_ENCA_A", "INPUT");
    setPinMode(PIN_ENCODER_A_B, INPUT, "PIN_ENCA_B", "INPUT");
    setPinMode(PIN_ENCODER_B_A, INPUT, "PIN_ENCB_A", "INPUT");
    setPinMode(PIN_ENCODER_B_B, INPUT, "PIN_ENCB_B", "INPUT");

    // Enabling H-Bridge
    Serial.printf("[SETUP %s] Enabling H-Bridge\n", getTimestamp());
    digitalWrite(PIN_HB_STBY, HIGH);

    // Pin registration
    registerLMotorPins(PIN_HB_AIN1, PIN_HB_AIN2, PIN_HB_PWMA);
    registerRMotorPins(PIN_HB_BIN1, PIN_HB_BIN2, PIN_HB_PWMB);
    registerBuzzerPins(PIN_BUZZER);
    registerLEncoderPins(PIN_ENCODER_A_A, PIN_ENCODER_A_B);
    registerREncoderPins(PIN_ENCODER_B_A, PIN_ENCODER_B_B);
    // registerQTR1APins(QTR1A_A, QTR1A_B);

    // Play sound to indicate setup is over
    Serial.printf("[SETUP %s] Playing SETUP-OVER sound\n", getTimestamp());
    playTone(500, 250);
    playTone(750, 250);
    playTone(500, 250);
    playTone(1000, 250);
    playTone(500, 250);
    playTone(750, 250);
    playTone(500, 250);
    playTone(250, 250);
    delay(250*8+1000);

    // test
    forwardLMotor();
    setPWMLMotor(50);

    forwardRMotor();
    setPWMRMotor(50);

    playTone(500, 1000);


    // Serial.printf("%s\n", fTest("genaro ql"));

}

// test vars
int state = 0;
int lastt = 0;
int pwm = 50;

void loop()
{
    
    // Encoder testing
    Serial.printf("[%s] L:%lld | R: %lld\n", getTimestamp(), getCountLEncoder(), getCountREncoder());

    if (millis() - lastt > 1000)
    {
        Serial.printf("[%s] Incrementing PWM (%d -> %d)\n", getTimestamp(), pwm, pwm+1);
        pwm = min(255, pwm+1);
        setPWMLMotor(pwm);
        setPWMRMotor(pwm);
        
        if (pwm % 10 == 0) {
            playTone(750, 250);
            delay(250);
            Serial.printf("[%s] Reversing motors (%d -> %d)\n", getTimestamp(), getRMotorDirection(), -getRMotorDirection());
            reverseLMotor();
            reverseRMotor();
        }

        lastt = millis();
    }

    // QTR 1A testing
    updateQTR1A();
    Serial.printf("[%s] L:%d | R: %d\n", getTimestamp(), getLQTR(), getRQTR());

    // End of Loop
    delay(LOOP_DELAY_MS);
}
