#include <gmock/gmock.h>

#include <application/dogm163.h>

#include "mocks.h"

using namespace ::testing;

// spi mode
// CPOL = 1 ?
// CPHA = 1 ?

// Init sequence (to be reviewed)
// 39, 15, 78, 5E, 6A, 0C, 01, 06

namespace {

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
TEST(dogm163, resets_controller_with_gpio_reset_while_keeping_timings)
{
  Time_Mock time;
  Gpio_Mock reset;
  NiceMock<Gpio_Mock> rs;
  NiceMock<Spi_Mock> spi;

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
TEST(dogm163, configures_controller_after_reset)
{
  NiceMock<Time_Mock> time;
  NiceMock<Gpio_Mock> reset;
  Gpio_Mock rs;
  Spi_Mock spi;

  Dogm163 testee(time, spi, rs, reset);

  InSequence configure;

  EXPECT_CALL(rs, set(Signal::Low));
  EXPECT_CALL(spi, send(0x39));
  EXPECT_CALL(spi, send(0x15));
  EXPECT_CALL(spi, send(0x78));
  EXPECT_CALL(spi, send(0x5E));
  EXPECT_CALL(spi, send(0x6A));
  EXPECT_CALL(spi, send(0x0C));
  EXPECT_CALL(spi, send(0x01));
  EXPECT_CALL(spi, send(0x06));

// Init sequence (to be reviewed)
// 39, 15, 78, 5E, 6A, 0C, 01, 06

  testee.reset();
}

// ------------------------------------------------------------
TEST(dogm163, set_RS_low_when_writing_a_command)
{
  NiceMock<Time_Mock> time;
  NiceMock<Gpio_Mock> reset;
  Gpio_Mock rs;
  NiceMock<Spi_Mock> spi;

  Dogm163 testee(time, spi, rs, reset);

  EXPECT_CALL(rs, set(Signal::Low));

  testee.write_command(Command::ClearDisplay);
}

// ------------------------------------------------------------
TEST(dogm163, set_RS_high_when_writing_data)
{
  NiceMock<Time_Mock> time;
  NiceMock<Gpio_Mock> reset;
  Gpio_Mock rs;
  NiceMock<Spi_Mock> spi;

  Dogm163 testee(time, spi, rs, reset);

  std::vector<uint8_t> const data = {0x01, 0x02, 0x03, 0x04};

  EXPECT_CALL(rs, set(Signal::High));

  testee.write_data(data);
}

// ------------------------------------------------------------
TEST(dogm163, writes_data_over_spi)
{
  NiceMock<Time_Mock> time;
  NiceMock<Gpio_Mock> reset;
  NiceMock<Gpio_Mock> rs;
  Spi_Mock spi;

  Dogm163 testee(time, spi, rs, reset);

  std::vector<uint8_t> const data = {0x01, 0x02, 0x03, 0x04};

  EXPECT_CALL(spi, send(data[0]));
  EXPECT_CALL(spi, send(data[1]));
  EXPECT_CALL(spi, send(data[2]));
  EXPECT_CALL(spi, send(data[3]));

  testee.write_data(data);
}

} // namespace

