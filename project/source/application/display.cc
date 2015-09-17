#include "application/display.h"

Display::Display(iDogm163 & dogm163)
  : dogm163(dogm163)
{
}

void Display::init()
{
  dogm163.write_command(0x39);
  dogm163.write_command(0x15);
  dogm163.write_command(0x55);
}

