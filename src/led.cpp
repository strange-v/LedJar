#include <led.h>

void toggleMode()
{
    switch (mode)
    {
    case LedMode::Minimal:
        setMode(LedMode::Low);
        break;
    case LedMode::Low:
        setMode(LedMode::Medium);
        break;
    case LedMode::Medium:
        setMode(LedMode::Full);
        break;
    case LedMode::Full:
        setMode(LedMode::Minimal);
        break;
    case LedMode::Off:
        setMode(LedMode::Low);
        break;
    }
}

void setMode(LedMode ledMode)
{
    switch (ledMode)
    {
    case LedMode::Minimal:
        setLeds(PWM_MIN, PWM_MIN, PWM_MIN);
        break;
    case LedMode::Low:
        setLeds(PWM_LOW, PWM_LOW, PWM_LOW);
        break;
    case LedMode::Medium:
        setLeds(PWM_MEDIUM, PWM_MEDIUM, PWM_MEDIUM);
        break;
    case LedMode::Full:
        setLeds(PWM_FULL, PWM_FULL, PWM_FULL);
        break;
    case LedMode::Off:
        setLeds(0, 0, 0);
        break;
    }

    mode = ledMode;
}

void setLeds(int64_t led0, int64_t led1, int64_t led2)
{
    analogWrite(LED0, led0);
    analogWrite(LED1, led1);
    analogWrite(LED2, led2);
}

void blink(uint8_t num)
{
    uint8_t start = PWM_MEDIUM;
    uint8_t end = 0;

    for (uint8_t i = 0; i < num; i++)
    {
        analogWrite(LED0, start);
        analogWrite(LED1, start);
        analogWrite(LED2, start);
        delay(300);
        analogWrite(LED0, end);
        analogWrite(LED1, end);
        analogWrite(LED2, end);
        delay(300);
    }
}