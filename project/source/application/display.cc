#include "application/display.h"

#include "application/dogm163.h"

// ------------------------------------------------------------
Display::Display(iDogm163 & dogm163)
  : _dogm163(dogm163)
{
}

// ------------------------------------------------------------
void Display::init()
{
  _dogm163.init();
  _dogm163.reset();
}

// ------------------------------------------------------------
void Display::clear()
{
  _dogm163.write_command(Command::ClearDisplay);
}

// ------------------------------------------------------------
void Display::write(std::string const & text)
{
  _dogm163.write(text);
}

