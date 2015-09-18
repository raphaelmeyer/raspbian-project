#include <gmock/gmock.h>

#include <application/dogm163.h>

TEST(dogm163, sets_RS_to_low_when_sending_a_command) {

  Dogm163 testee;

  uint8_t const arbitrary_command = 0xAA;

  ASSERT_TRUE(testee.write_command(arbitrary_command));
}

TEST(dogm163, sends_command_over_spi) {
}

