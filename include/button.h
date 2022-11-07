#ifndef BUTTON_h
#define BUTTON_h

#include <Arduino.h>
#include <led.h>

#define BTN1 2
#define BTN2 3
#define CLICK_PERIOD 50
#define LONG_CLICK_PERIOD 1500

extern volatile uint64_t btnPressStartTime;
extern volatile uint8_t btnState;
extern volatile bool btnClick;
extern bool undervoltage;
extern bool needCheckUndervoltage;

void loopButton();
void onShortClick();
void onLongClick();

#endif
