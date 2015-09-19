#include "application/dogm163.h"
#include "application/gpio.h"
#include "application/spi.h"

// ------------------------------------------------------------
Dogm163::Dogm163(iGpio & rs, iSpi & spi)
  : rs(rs)
  , spi(spi)
{
}

// ------------------------------------------------------------
bool Dogm163::init()
{
  rs.init(Direction::Output);
  rs.set(Signal::Low);
  return true;
}

// ------------------------------------------------------------
bool Dogm163::write_command(std::uint8_t command)
{
  rs.set(Signal::Low);
  spi.send(command);
  return true;
}

