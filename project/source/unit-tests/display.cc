#include <gmock/gmock.h>

#include <application/display.h>

#include "mocks.h"

using namespace ::testing;

namespace {

// ------------------------------------------------------------
TEST(display_initialization, inits_and_resets_controller)
{
  Dogm163_Mock dogm163;
  Display testee(dogm163);

  InSequence init;

  EXPECT_CALL(dogm163, init());
  EXPECT_CALL(dogm163, reset());

  testee.init();
}

// ------------------------------------------------------------
TEST(display, clear_the_display)
{
  Dogm163_Mock dogm163;
  Display testee(dogm163);

  EXPECT_CALL(dogm163, write_command(Command::ClearDisplay));

  testee.clear();
}

// ------------------------------------------------------------
TEST(display, write_text)
{
  Dogm163_Mock dogm163;
  Display testee(dogm163);

  std::string const text = "hello";
  std::vector<uint8_t> const expected = {'h','e','l','l','o'};

  EXPECT_CALL(dogm163, write_data(expected));

  testee.write(text);
}

} // namespace

