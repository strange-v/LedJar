#ifndef PERIPHERY_h
#define PERIPHERY_h

#include <Arduino.h>
#include <avr/sleep.h>
#include <avr/wdt.h>
#include <avr/power.h>

#ifndef cbi
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif
#ifndef sbi
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif

void setupExternalInterrupt();
void turnAdcOff();
void turnAdcOn();
void turnModulesOff();
void turnModulesOn();
void sleepMcu();
void idleMcu();

#endif
