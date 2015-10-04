#include <gmock/gmock.h>

#include "time_fake.h"
#include "display_stub.h"

#include <application/application.h>
#include <application/display.h>
#include <application/dogm163.h>

using namespace ::testing;

namespace {

// ------------------------------------------------------------
TEST(integration, dummy)
{
  Display_Stub display_stub;
  Time_Fake time;

  iGpio & rs = display_stub.rs();
  iGpio & reset = display_stub.reset();
  iSpi & spi = display_stub.spi();

  Dogm163 dogm163(time, spi, rs, reset);
  Display display(dogm163);
  Application app(display);

  app.run();

  std::array<std::uint8_t, 3*16> expected;
  expected.fill(0x20);

  ASSERT_THAT(display_stub.screen(), Eq(expected));
}

}

