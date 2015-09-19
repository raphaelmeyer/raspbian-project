#include <gmock/gmock.h>

#include <application/application.h>
#include <application/display.h>

using namespace ::testing;

namespace {

// ------------------------------------------------------------
class Display_Mock : public iDisplay {
  public:
    MOCK_METHOD0(init, bool());
};

// ------------------------------------------------------------
TEST(application, initializes_display)
{
  Display_Mock display;
  Application testee(display);

  EXPECT_CALL(display, init())
    .WillOnce(Return(true));

  ASSERT_TRUE(testee.init());
}

} // namespace

