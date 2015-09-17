#include <gmock/gmock.h>

#include <application/display.h>

using namespace ::testing;

class Dogm163_Mock : public iDogm163 {
  public:
    MOCK_METHOD1(write_command, bool(std::uint8_t command));
};

/*
Function Set      0 0 0 0 1 1 1 0 0 1 $39 8-Bit Datenlänge, 2 Zeilen, Instruction table 1
Bias Set          0 0 0 0 0 1 0 1 0 1 $15 BS: 1/5, 3-zeiliges LCD
Power Control     0 0 0 1 0 1 0 1 0 1 $55 Booster ein, Kontrast C5, C4setzen
Follower Control  0 0 0 1 1 0 1 1 1 0 $6E Spannungsfolger und Verstärkung setzen
Contrast Set      0 0 0 1 1 1 0 0 1 0 $72 Kontrast C3, C2, C1 setzen
Function Set      0 0 0 0 1 1 1 0 0 0 $38 Zurück zur Instruction table 0
Display ON/OFF    0 0 0 0 0 0 1 1 1 1 $0F Display ein, Cursor ein, Cursor blinken
Clear Display     0 0 0 0 0 0 0 0 0 1 $01 Display löschen, Cursor Home
Entry Mode Set    0 0 0 0 0 0 0 1 1 0 $06 Cursor Auto-Increment

*/

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

  testee.init();

}

