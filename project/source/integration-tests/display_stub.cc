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
    virtual bool send(std::uint8_t value) override final { return false; }
};

// ------------------------------------------------------------
class Gpio : public iGpio
{
  public:
    virtual bool init(Direction direction) override final { return false; }
    virtual bool set(Signal signal) override final { return false; }
};

} // namespace

// ------------------------------------------------------------
class Stub::Dogm163::Impl : public SpiListener, public ResetListener
{
  public:
    Impl();

    virtual bool notify_send(std::uint8_t value) { return true; };
    virtual void notify_reset() {};

    std::array<std::uint8_t, 3*16> const & screen() { return _memory; }

    iSpi & spi() { return _spi; }
    iGpio & rs() { return _rs; }
    iGpio & reset() { return _reset; }

  private:

    Spi _spi;
    Gpio _rs;
    Gpio _reset;

    std::array<std::uint8_t, 16*3> _memory;
};

// ------------------------------------------------------------
Stub::Dogm163::Impl::Impl()
  : _spi()
  , _rs()
  , _reset()
  , _memory()
{
  _memory.fill(0xFF);
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

