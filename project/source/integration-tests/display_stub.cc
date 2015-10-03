#include "display_stub.h"

// ------------------------------------------------------------
iSpi & Display_Stub::spi()
{
  return _spi;
}

// ------------------------------------------------------------
iGpio & Display_Stub::rs()
{
  return _rs;
}

// ------------------------------------------------------------
iGpio & Display_Stub::reset()
{
  return _reset;
}

// ------------------------------------------------------------
bool Display_Stub::Spi_Stub::send(std::uint8_t value)
{
  return true;
}

// ------------------------------------------------------------
bool Display_Stub::Gpio_Stub::init(Direction direction)
{
  return true;
}

// ------------------------------------------------------------
bool Display_Stub::Gpio_Stub::set(Signal signal)
{
  _level = signal;
  return true;
}

