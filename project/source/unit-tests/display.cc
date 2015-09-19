#include <gmock/gmock.h>

#include <application/display.h>
#include <application/dogm163.h>

using namespace ::testing;

// ------------------------------------------------------------
class Dogm163_Mock : public iDogm163 {
  public:
    MOCK_METHOD1(write_command, bool(std::uint8_t command));
};

// ------------------------------------------------------------
TEST(display, is_initialized_with_a_sequence_of_commands)
{
  Dogm163_Mock dogm163;
  Display testee(dogm163);

  InSequence init;

  // 38, 39, 14, 78, 5E, 6A, 0C, 01, 06

  testee.init();
}

