#include <gmock/gmock.h>

#include <application/display.h>
#include <application/gpio.h>
#include <application/time.h>


using namespace ::testing;

// Init sequence (to be reviewed)
// 39, 15, 78, 5E, 6A, 0C, 01, 06

namespace {

// ------------------------------------------------------------
class Gpio_Mock : public iGpio {
  public:
    MOCK_METHOD1(init, bool(Direction direction));
    MOCK_METHOD1(set, bool(Signal signal));
};

// ------------------------------------------------------------
class Time_Mock : public iTime
{
  public:
    MOCK_CONST_METHOD1(sleep, void(std::chrono::microseconds const & duration));
    MOCK_CONST_METHOD1(sleep, void(std::chrono::milliseconds const & duration));
    MOCK_CONST_METHOD1(sleep, void(std::chrono::seconds const & duration));
};

// ------------------------------------------------------------
TEST(display_initialization, resets_controller)
{
  Time_Mock time;
  Gpio_Mock reset;
  Display testee(reset, time);

  InSequence init;

  std::chrono::microseconds const reset_pulse(200);
  std::chrono::milliseconds const reset_time(50);

  EXPECT_CALL(reset, set(Signal::Low));
  EXPECT_CALL(time, sleep(reset_pulse));
  EXPECT_CALL(reset, set(Signal::High));
  EXPECT_CALL(time, sleep(reset_time));

  testee.init();
}

// ------------------------------------------------------------

} // namespace

