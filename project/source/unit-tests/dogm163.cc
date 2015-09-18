#include <gmock/gmock.h>

#include <application/dogm163.h>
#include <application/gpio.h>
#include <application/spi.h>

using namespace ::testing;

class Spi_Mock : public iSpi {
  public:
    MOCK_METHOD1(send, bool(std::uint8_t value));
};

class Gpio_Mock : public iGpio {
  public:
    MOCK_METHOD1(set, bool(Signal signal));
};

TEST(dogm163, sets_RS_to_low_when_sending_a_command)
{
  Gpio_Mock rs;
  NiceMock<Spi_Mock> spi;
  Dogm163 testee(rs, spi);

  uint8_t const arbitrary_command = 0xAA;

  EXPECT_CALL(rs, set(Signal::Low)).
    WillOnce(Return(true));

  ASSERT_TRUE(testee.write_command(arbitrary_command));
}

TEST(dogm163, sends_command_over_spi)
{
  NiceMock<Gpio_Mock> rs;
  Spi_Mock spi;
  Dogm163 testee(rs, spi);

  ON_CALL(rs, set(_))
    .WillByDefault(Return(true));

  uint8_t const command = 0x5A;

  EXPECT_CALL(spi, send(command)).
    WillOnce(Return(true));

  ASSERT_TRUE(testee.write_command(command));
}

