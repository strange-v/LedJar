#ifndef LED_h
#define LED_h

#include <Arduino.h>
#include <mode.h>

#define LED0 0
#define LED1 1
#define LED2 4

#define PWM_MIN 25
#define PWM_LOW 75
#define PWM_MEDIUM 150
#define PWM_FULL 255

extern LedMode mode;

void toggleMode();
void setMode(LedMode ledMode);
void setLeds(int64_t led0, int64_t led1, int64_t led2);
void blink(uint8_t num);

#endif