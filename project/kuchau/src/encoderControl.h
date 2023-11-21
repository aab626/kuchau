#include <arduino.h>

void registerLEncoderPins(uint8_t pinA, uint8_t pinB);
void registerREncoderPins(uint8_t pinA, uint8_t pinB);
int64_t getCountLEncoder();
int64_t getCountREncoder();