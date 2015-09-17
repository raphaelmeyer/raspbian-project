#include "application/display.h"

std::vector<uint8_t> const Display::initialization{
  0x39, 0x15, 0x55
};

Display::Display(iDogm163 & dogm163)
  : dogm163(dogm163)
{
}

void Display::init()
{
  for(auto command : initialization) {
    dogm163.write_command(command);
  }
}

