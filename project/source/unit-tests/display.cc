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
TEST(display, write_text)
{
  Dogm163_Mock dogm163;
  Display testee(dogm163);

  std::string const text = "hello";

  EXPECT_CALL(dogm163, write(text));

  testee.write(text);
}

} // namespace

