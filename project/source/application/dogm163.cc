#include "application/dogm163.h"
#include "application/gpio.h"

Dogm163::Dogm163(iGpio & rs)
  : rs(rs)
{
}

bool Dogm163::write_command(std::uint8_t command)
{
  rs.set(Signal::Low);
  return true;
}

