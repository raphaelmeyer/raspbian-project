#include <gmock/gmock.h>

#include <application/application.h>
#include <application/display.h>

using namespace ::testing;

namespace {

// ------------------------------------------------------------
class Display_Mock : public iDisplay {
  public:
    MOCK_METHOD0(init, void());
    MOCK_METHOD1(write, void(std::string const & text));
};

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
