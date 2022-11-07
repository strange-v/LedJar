#include <periphery.h>

void setupExternalInterrupt()
{
    sei();                  // enabling global interrupt
    GIMSK |= (1 << PCIE);   // Pin change interrupt enable
    PCMSK |= (1 << PCINT2); // Pin change interrupt to 2nd pin PB2
}

void turnAdcOff()
{
  ADCSRA = 0;
  power_adc_disable();
}

void turnAdcOn()
{
  power_adc_enable();
  ADCSRA = bit(ADEN);
}

void turnModulesOff()
{
  ADCSRA = 0;
  power_adc_disable();
  //power_timer0_disable();
  //power_timer1_disable();
}

void turnModulesOn()
{
  power_adc_enable();
  ADCSRA = bit(ADEN);

  //power_timer0_enable();
  //power_timer1_enable();

  delayMicroseconds(500);
}

void sleepMcu()
{
  cli();
  //cbi(ADCSRA, ADEN);                   // ADC off
  turnAdcOff();
  set_sleep_mode(SLEEP_MODE_PWR_DOWN); // sleep mode is set here
  sleep_enable();
  sei();

  sleep_mode(); // system sleeps here

  sleep_disable();
  // sbi(ADCSRA, ADEN); // ADC on
}

void idleMcu()
{
  cli();
  turnAdcOff();
  set_sleep_mode(SLEEP_MODE_IDLE); // sleep mode is set here
  sleep_enable();
  sei();

  sleep_mode(); // system sleeps here

  sleep_disable();
}
