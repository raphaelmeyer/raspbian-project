#ifndef mock_h
#define mock_h

#include <application/display.h>
#include <application/dogm163.h>
#include <application/gpio.h>
#include <application/time.h>
#include <application/spi.h>

namespace {

// ------------------------------------------------------------
class Display_Mock : public iDisplay {
  public:
    MOCK_METHOD0(init, void());
    MOCK_METHOD1(write, void(std::string const & text));
};

// ------------------------------------------------------------
class Dogm163_Mock : public iDogm163 {
  public:
    MOCK_METHOD0(init, void());
    MOCK_METHOD0(reset, void());
    MOCK_METHOD1(write, void(std::string const & text));
};

// ------------------------------------------------------------
class Gpio_Mock : public iGpio {
  public:
    MOCK_METHOD1(init, bool(Direction direction));
    MOCK_METHOD1(set, bool(Signal signal));
};

// ------------------------------------------------------------
class Spi_Mock : public iSpi {
  public:
    MOCK_METHOD1(send, bool(std::uint8_t value));
};

// ------------------------------------------------------------
class Time_Mock : public iTime {
  public:
    MOCK_CONST_METHOD1(sleep, void(std::chrono::microseconds const & duration));
    MOCK_CONST_METHOD1(sleep, void(std::chrono::milliseconds const & duration));
    MOCK_CONST_METHOD1(sleep, void(std::chrono::seconds const & duration));
};

} // namespace

#endif

