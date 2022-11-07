#include <button.h>

void loopButton()
{
    uint64_t ms = millis();

    if (btnPressStartTime > 0 && btnState == LOW && ms - btnPressStartTime >= LONG_CLICK_PERIOD)
    {
        btnPressStartTime = 0;
        onLongClick();
    }

    if (btnClick)
    {
        btnClick = false;
        onShortClick();
    }
}

void onShortClick()
{
    if (undervoltage)
    {
        needCheckUndervoltage = true;
        return;
    }
    
    toggleMode();
}

void onLongClick()
{
    if (undervoltage)
    {
        needCheckUndervoltage = true;
        return;
    }
    
    if (mode == LedMode::Off)
        setMode(LedMode::Minimal);
    else
        setMode(LedMode::Off);
}