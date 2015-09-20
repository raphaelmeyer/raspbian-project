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

} // namespace

