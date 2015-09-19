#include "application/application.h"
#include "application/display.h"

// ------------------------------------------------------------
Application::Application(iDisplay & display)
  : display(display)
{
}

// ------------------------------------------------------------
void Application::init()
{
  display.init();
}

// ------------------------------------------------------------
void Application::run()
{
  display.write("Hello World");
}

