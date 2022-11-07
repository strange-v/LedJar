#include <Arduino.h>
#include <avr/sleep.h>
#include <avr/wdt.h>
#include <Vcc.h>
#include <sleep.h>
#include <periphery.h>
#include <mode.h>
#include <button.h>
#include <led.h>
#include <voltage.h>

Vcc vcc;

volatile uint64_t btnPressStartTime = 0;
volatile uint8_t btnState = HIGH;
volatile bool btnClick = false;

volatile bool activity = false;
volatile uint64_t lastActivityTime = 0;
volatile bool sleepMode = false;
LedMode mode = LedMode::Off;
bool undervoltage = false;
bool needCheckUndervoltage = false;
uint64_t lastUndervoltageCheckTime = 0;

ISR(WDT_vect)
{
}

ISR(PCINT0_vect)
{
    // NOTE: Disabling sleep mode inside interrupt routine
    MCUCR &= ~(1 << SE);

    uint8_t state = digitalRead(BTN1);
    uint64_t ms = millis();

    activity = true;
    sleepMode = false;

    if (btnPressStartTime == 0)
    {
        if (state == LOW)
        {
            btnPressStartTime = ms;
            btnState = state;
        }
        return;
    }
    else
    {
        if (btnState == state)
            return;

        uint64_t period = ms - btnPressStartTime;
        if (period >= CLICK_PERIOD && period < LONG_CLICK_PERIOD)
        {
            btnClick = true;
        }
        btnState = state;
        btnPressStartTime = 0;
    }
}

void setup()
{
    wdt_enable(WDTO_8S);

    turnModulesOff();

    pinMode(LED0, OUTPUT);
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(BTN1, INPUT);
    pinMode(BTN2, INPUT);

    setMode(LedMode::Off);
    setupExternalInterrupt();

    blink(1);
}

void loop()
{
    wdt_reset();

    loopButton();
    loopUndervoltageProtection();
    loopSleep();
}