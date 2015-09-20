#include "application/display.h"
#include "application/gpio.h"

// ------------------------------------------------------------
Display::Display(iGpio & reset)
  : reset(reset)
{
}

// ------------------------------------------------------------
void Display::init()
{
  reset.set(Signal::Low);
  reset.set(Signal::High);
}

// ------------------------------------------------------------
void Display::write(std::string const & text)
{
}

