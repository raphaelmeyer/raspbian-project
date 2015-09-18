#include <gmock/gmock.h>

#include <application/dogm163.h>
#include <application/gpio.h>

using namespace ::testing;

class Gpio_Mock : public iGpio {
  public:
    MOCK_METHOD1(set, bool(Signal signal));
};

TEST(dogm163, sets_RS_to_low_when_sending_a_command)
{
  Gpio_Mock rs;
  Dogm163 testee(rs);

  uint8_t const arbitrary_command = 0xAA;

  EXPECT_CALL(rs, set(Signal::Low)).
    WillOnce(Return(true));


  ASSERT_TRUE(testee.write_command(arbitrary_command));
}

TEST(dogm163, DISABLED_sends_command_over_spi)
{
  FAIL();
}

