#include "application/display.h"
#include "application/gpio.h"
#include "application/time.h"

// ------------------------------------------------------------
std::chrono::microseconds const Display::reset_pulse(200);

// ------------------------------------------------------------
Display::Display(iGpio & reset, iTime const & time)
  : reset(reset)
  , time(time)
{
}

// ------------------------------------------------------------
void Display::init()
{
  reset.set(Signal::Low);
  time.sleep(reset_pulse);
  reset.set(Signal::High);
}

// ------------------------------------------------------------
void Display::write(std::string const & text)
{
}

