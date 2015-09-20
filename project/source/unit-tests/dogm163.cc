#include <gmock/gmock.h>

#include <application/dogm163.h>

#include "mocks.h"

using namespace ::testing;

// spi mode
// CPOL = 1 ?
// CPHA = 1 ?

// Init sequence (to be reviewed)
// 39, 15, 78, 5E, 6A, 0C, 01, 06

// ------------------------------------------------------------
TEST(dogm163_initialization, configures_RS_as_output_sets_it_to_low)
{
  Time_Mock time;
  NiceMock<Gpio_Mock> reset;
  Gpio_Mock rs;
  Spi_Mock spi;

  Dogm163 testee(time, spi, rs, reset);

  EXPECT_CALL(rs, init(Direction::Output));
  EXPECT_CALL(rs, set(Signal::Low));

  testee.init();
}

// ------------------------------------------------------------
TEST(dogm163_initialization, configures_Reset_as_output_sets_it_to_low)
{
  Time_Mock time;
  Gpio_Mock reset;
  NiceMock<Gpio_Mock> rs;
  Spi_Mock spi;

  Dogm163 testee(time, spi, rs, reset);

  EXPECT_CALL(reset, init(Direction::Output));
  EXPECT_CALL(reset, set(Signal::Low));

  testee.init();
}

// ------------------------------------------------------------
TEST(dogm163, waits_for_controller_after_reset)
{
  Time_Mock time;
  Gpio_Mock reset;
  Gpio_Mock rs;
  Spi_Mock spi;

  Dogm163 testee(time, spi, rs, reset);

  std::chrono::microseconds const reset_pulse(200);
  std::chrono::milliseconds const reset_time(50);

  EXPECT_CALL(reset, set(Signal::Low));
  EXPECT_CALL(time, sleep(reset_pulse));
  EXPECT_CALL(reset, set(Signal::High));
  EXPECT_CALL(time, sleep(reset_time));

  testee.reset();
}

// ------------------------------------------------------------
TEST(dogm163, DISABLED_sets_RS_to_low_when_sending_a_command)
{
  FAIL();
}

// ------------------------------------------------------------
TEST(dogm163, DISABLED_sends_command_over_spi)
{
  FAIL();
}

