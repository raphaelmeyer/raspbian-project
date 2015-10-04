#include "display_stub.h"

// ------------------------------------------------------------
Display_Stub::Display_Stub()
  : _spi(*this)
  , _rs()
  , _reset()
  , _memory()
  , _pos(0)
{
  _memory.fill(0xFF);
}

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
std::array<std::uint8_t, 3*16> const & Display_Stub::screen()
{
  return _memory;
}

// ------------------------------------------------------------
bool Display_Stub::notify_send(std::uint8_t value)
{
  if(_rs.high())
  {
    _memory[_pos] = value;
    _pos++;
  }
  else if(_rs.low())
  {
    if(value == 0x01) {
      _memory.fill(0x20);
      _pos = 0;
    }
    else if ((value & 0xFE) == 0x02)
    {
      _pos = 0;
    }
  }
  return true;
}

// ------------------------------------------------------------
Display_Stub::Spi_Stub::Spi_Stub(SpiListener & display)
  : _display(display)
{
}

// ------------------------------------------------------------
bool Display_Stub::Spi_Stub::send(std::uint8_t value)
{
  return _display.notify_send(value);
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

