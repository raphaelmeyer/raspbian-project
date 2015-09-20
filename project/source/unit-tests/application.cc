#include <gmock/gmock.h>

#include <application/application.h>

#include "mocks.h"

using namespace ::testing;

namespace {

// ------------------------------------------------------------
TEST(application, initializes_display)
{
  Display_Mock display;
  Application testee(display);

  EXPECT_CALL(display, init());

  testee.init();
}

// ------------------------------------------------------------
TEST(application, writes_hello_world)
{
  Display_Mock display;
  Application testee(display);

  EXPECT_CALL(display, write("Hello World"));

  testee.run();
}

} // namespace

