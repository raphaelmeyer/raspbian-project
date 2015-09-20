#include "application/dogm163.h"

#include "application/gpio.h"
#include "application/spi.h"
#include "application/time.h"

// ------------------------------------------------------------
std::chrono::microseconds const Dogm163::reset_pulse(200);
std::chrono::milliseconds const Dogm163::reset_time(50);

// ------------------------------------------------------------
Dogm163::Dogm163(iTime const & time, iSpi & spi, iGpio & rs, iGpio & reset)
  : _time(time)
  , _spi(spi)
  , _rs(rs)
  , _reset(reset)
{
}

// ------------------------------------------------------------
void Dogm163::init()
{
}

// ------------------------------------------------------------
void Dogm163::reset()
{
  _reset.set(Signal::Low);
  _time.sleep(reset_pulse);
  _reset.set(Signal::High);
  _time.sleep(reset_time);
}

