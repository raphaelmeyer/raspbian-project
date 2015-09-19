#include "application/display.h"
#include "application/dogm163.h"

// ------------------------------------------------------------
std::vector<uint8_t> const Display::initialization{
  0x39, 0x15, 0x55, 0x6E, 0x72, 0x38, 0x0F, 0x01, 0x06
};

// ------------------------------------------------------------
Display::Display(iDogm163 & dogm163)
  : dogm163(dogm163)
{
}

// ------------------------------------------------------------
bool Display::init()
{
  for(auto command : initialization) {
    dogm163.write_command(command);
  }
  return true;
}

// ------------------------------------------------------------
bool Display::write(std::string const & text)
{
  return false;
}

