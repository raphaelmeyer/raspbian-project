#include "application/application.h"
#include "application/display.h"

// ------------------------------------------------------------
Application::Application(iDisplay & display)
  : display(display)
{
}

// ------------------------------------------------------------
bool Application::init()
{
  display.init();
  return true;
}

// ------------------------------------------------------------
bool Application::run()
{
  display.write("Hello World");
  return true;
}

