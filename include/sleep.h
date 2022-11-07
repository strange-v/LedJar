#ifndef SLEEP_h
#define SLEEP_h

#include <Arduino.h>
#include <avr/sleep.h>
#include <avr/wdt.h>
#include <periphery.h>
#include <mode.h>

#define SLEEP_DELAY 5000

extern volatile bool activity;
extern volatile uint64_t lastActivityTime;
extern volatile bool sleepMode;
extern LedMode mode;
extern bool undervoltage;

void loopSleep();

#endif
