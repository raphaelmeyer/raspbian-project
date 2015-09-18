#include <gmock/gmock.h>

#include <application/display.h>
#include <application/dogm163.h>

using namespace ::testing;

class Dogm163_Mock : public iDogm163 {
  public:
    MOCK_METHOD1(write_command, bool(std::uint8_t command));
};

TEST(display, is_initialized_with_a_sequence_of_commands)
{
  Dogm163_Mock dogm163;
  Display testee(dogm163);

  InSequence init;

  EXPECT_CALL(dogm163, write_command(0x39))
    .WillOnce(Return(true));

  EXPECT_CALL(dogm163, write_command(0x15))
    .WillOnce(Return(true));

  EXPECT_CALL(dogm163, write_command(0x55))
    .WillOnce(Return(true));

  EXPECT_CALL(dogm163, write_command(0x6E))
    .WillOnce(Return(true));

  EXPECT_CALL(dogm163, write_command(0x72))
    .WillOnce(Return(true));

  EXPECT_CALL(dogm163, write_command(0x38))
    .WillOnce(Return(true));

  EXPECT_CALL(dogm163, write_command(0x0F))
    .WillOnce(Return(true));

  EXPECT_CALL(dogm163, write_command(0x01))
    .WillOnce(Return(true));

  EXPECT_CALL(dogm163, write_command(0x06))
    .WillOnce(Return(true));

  testee.init();
}

