#include "application/dogm163.h"

#include "application/gpio.h"
#include "application/spi.h"
#include "application/time.h"

// ------------------------------------------------------------
std::chrono::microseconds const Dogm163::reset_pulse_time(200);
std::chrono::milliseconds const Dogm163::reset_time(50);

std::vector<std::uint8_t> const Dogm163::init_sequence{
  0x39, 0x15, 0x78, 0x5E, 0x6A, 0x0C, 0x01, 0x06};

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
  _reset.init(Direction::Output);
  _reset.set(Signal::Low);

  _rs.init(Direction::Output);
  _rs.set(Signal::Low);
}

// ------------------------------------------------------------
void Dogm163::reset()
{
  _reset.set(Signal::Low);
  _time.sleep(reset_pulse_time);
  _reset.set(Signal::High);
  _time.sleep(reset_time);

  _rs.set(Signal::Low);
  for(auto command : init_sequence) {
    _spi.send(command);
  }
}

// ------------------------------------------------------------
void Dogm163::write_command(Command command)
{
  _rs.set(Signal::Low);
}

// ------------------------------------------------------------
void Dogm163::write_data(std::vector<uint8_t> const & data)
{
  _rs.set(Signal::High);
}

