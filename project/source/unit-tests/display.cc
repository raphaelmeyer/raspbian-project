#include <gmock/gmock.h>

#include <application/display.h>

using namespace ::testing;

class Dogm163_Mock : public iDogm163 {
  public:
    MOCK_METHOD1(write_command, bool(std::uint8_t command));
};


TEST(display, is_initialized_with_a_sequence_of_commands) {

  Dogm163_Mock dogm163;

  EXPECT_CALL(dogm163, write_command(_))
    .WillOnce(Return(true));

  Display testee(dogm163);
}

