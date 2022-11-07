#ifndef VOLTAGE_h
#define VOLTAGE_h

#include <Arduino.h>
#include <Vcc.h>
#include <periphery.h>
#include <led.h>

#define VOLTAGE_MIN 3000
#define CHECK_VOLTAGE_PERIOD 8000

extern Vcc vcc;
extern bool undervoltage;
extern bool needCheckUndervoltage;
extern uint64_t lastUndervoltageCheckTime;
extern volatile bool sleepMode;

void loopUndervoltageProtection();
void checkForUndervoltage();

#endif
