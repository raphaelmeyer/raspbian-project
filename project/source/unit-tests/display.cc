#include <gmock/gmock.h>

#include <application/display.h>
#include <application/gpio.h>

using namespace ::testing;

// Init sequence (to be reviewed)
// 39, 15, 78, 5E, 6A, 0C, 01, 06

// ------------------------------------------------------------
class Gpio_Mock : public iGpio {
  public:
    MOCK_METHOD1(init, bool(Direction direction));
    MOCK_METHOD1(set, bool(Signal signal));
};

// ------------------------------------------------------------
TEST(display_initialization, resets_controller)
{
  Gpio_Mock reset;
  Display testee(reset);

  InSequence init;

  EXPECT_CALL(reset, set(Signal::Low));
  EXPECT_CALL(reset, set(Signal::High));

  testee.init();
}

