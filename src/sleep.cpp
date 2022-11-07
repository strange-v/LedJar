#include <sleep.h>

void loopSleep()
{
    uint64_t ms = millis();
    
    if (activity)
    {
        activity = false;
        lastActivityTime = ms;
    }

    if (!sleepMode && (ms - lastActivityTime > SLEEP_DELAY || lastActivityTime > ms))
    {
        sleepMode = true;
    }

    if (sleepMode)
    {
        if (mode == LedMode::Off)
        {
            wdt_disable();
            setupExternalInterrupt();
            sleepMcu();
            wdt_enable(WDTO_8S);
        }
        else
        {
            idleMcu();
        }
    }
}
