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
}

void checkForUndervoltage()
{
    turnAdcOn();
    delay(10);
    uint16_t voltage = vcc.getValue_mV();
    turnAdcOff();
    
    undervoltage = voltage <= VOLTAGE_MIN;
    if (undervoltage)
    {
        blink(3);
        mode = LedMode::Off;
        sleepMode = true;
    }
}