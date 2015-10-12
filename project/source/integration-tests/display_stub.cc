#include "display_stub.h"

#include <application/spi.h>
#include <application/gpio.h>

// ------------------------------------------------------------
class SpiListener
{
  public:
    virtual bool notify_send(std::uint8_t value) = 0;
};

// ------------------------------------------------------------
class ResetListener
{
  public:
    virtual void notify_reset() = 0;
};

namespace Stub {

// ------------------------------------------------------------
class Spi : public iSpi
{
  public:
    Spi(SpiListener & listener);

    virtual bool send(std::uint8_t value) override final;

  private:
    SpiListener & _listener;
};

// ------------------------------------------------------------
class Gpio : public iGpio
{
  public:
    Gpio();

    virtual bool init(Direction direction) override final;
    virtual bool set(Signal signal) override final;

    Signal state() const { return _state; }
    Direction direction() const { return _direction; }

  private:
    Signal _state;
    Direction _direction;
};

// ------------------------------------------------------------
class Reset : public iGpio
{
  public:
    Reset(ResetListener & listener);

    virtual bool init(Direction direction) override final;
    virtual bool set(Signal signal) override final;

  private:
    Signal _state;
    Direction _direction;
    ResetListener & _listener;
};

} // namespace

// ------------------------------------------------------------
class Stub::Dogm163::Impl : public SpiListener, public ResetListener
{
  public:
    Impl();

    virtual bool notify_send(std::uint8_t value);
    virtual void notify_reset();

    std::array<std::uint8_t, 3*16> const & screen() { return _memory; }

    iSpi & spi() { return _spi; }
    iGpio & rs() { return _rs; }
    iGpio & reset() { return _reset; }

  private:

    Spi _spi;
    Gpio _rs;
    Reset _reset;

    std::array<std::uint8_t, 16*3> _memory;
    unsigned int _pos = 0;
};

// ------------------------------------------------------------
Stub::Spi::Spi(SpiListener & listener)
  : _listener(listener)
{
}

// ------------------------------------------------------------
bool Stub::Spi::send(std::uint8_t value)
{
  return _listener.notify_send(value);
}

// ------------------------------------------------------------
Stub::Gpio::Gpio()
  : _state(Signal::Undefined)
  , _direction(Direction::Undefined)
{
}

// ------------------------------------------------------------
bool Stub::Gpio::init(Direction direction)
{
  _direction = direction;
  return true;
}

// ------------------------------------------------------------
bool Stub::Gpio::set(Signal signal)
{
  if(_direction == Direction::Output)
  {
    _state = signal;
  }
  return false;
}

// ------------------------------------------------------------
Stub::Reset::Reset(ResetListener & listener)
  : _state(Signal::Undefined)
  , _direction(Direction::Undefined)
  , _listener(listener)
{
}

// ------------------------------------------------------------
bool Stub::Reset::init(Direction direction)
{
  return direction == Direction::Output;
}

// ------------------------------------------------------------
bool Stub::Reset::set(Signal signal)
{
  if(_direction != Direction::Output)
  {
    return false;
  }

  if(_state == Signal::Low)
  {
    if(signal == Signal::High)
    {
      _listener.notify_reset();
    }
  }

  _state = Signal::High;
  return true;
}

// ------------------------------------------------------------
Stub::Dogm163::Impl::Impl()
  : _spi(*this)
  , _rs()
  , _reset(*this)
  , _memory()
  , _pos(0)
{
  _memory.fill(0x20);
}

// ------------------------------------------------------------
bool Stub::Dogm163::Impl::notify_send(std::uint8_t value)
{
  if(_rs.state() == Signal::High)
  {
    _memory[_pos] = value;
    _pos++;
  }
  return true;
}

// ------------------------------------------------------------
void Stub::Dogm163::Impl::notify_reset()
{
  _memory.fill(0x20);
  _pos = 0;
}

// ------------------------------------------------------------
Stub::Dogm163::Dogm163()
  : _impl(new Dogm163::Impl())
{
}

// ------------------------------------------------------------
Stub::Dogm163::~Dogm163()
{
}

// ------------------------------------------------------------
iSpi & Stub::Dogm163::spi()
{
  return _impl->spi();
}

// ------------------------------------------------------------
iGpio & Stub::Dogm163::rs()
{
  return _impl->rs();
}

// ------------------------------------------------------------
iGpio & Stub::Dogm163::reset()
{
  return _impl->reset();
}

// ------------------------------------------------------------
std::array<std::uint8_t, 3*16> const & Stub::Dogm163::screen()
{
  return _impl->screen();
}

