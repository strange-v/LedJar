#include <voltage.h>

void loopUndervoltageProtection()
{
    uint64_t ms = millis();

    if (needCheckUndervoltage || ms - lastUndervoltageCheckTime > CHECK_VOLTAGE_PERIOD || lastUndervoltageCheckTime > ms)
    {
        needCheckUndervoltage = false;
        lastUndervoltageCheckTime = ms;
        checkForUndervoltage();
    }
    
    // if (undervoltage && !needCheckUndervoltage)
    // {
    //     digitalWrite(3, !digitalRead(3));
    //     wdt_disable();
    //     setupExternalInterrupt();
    //     sleepMcu();
    //     wdt_enable(WDTO_8S);
    // }
}

void checkForUndervoltage()
{
    turnAdcOn();
    delay(10);
    uint16_t voltage = vcc.getValue_mV();
    turnAdcOff();
    // digitalWrite(3, !digitalRead(3));
    undervoltage = voltage <= VOLTAGE_MIN;
    if (undervoltage)
    {
        blink(3);
        mode = LedMode::Off;
        sleepMode = true;
    }
}