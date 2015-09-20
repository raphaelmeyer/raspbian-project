#include <application/application.h>
#include <application/display.h>
#include <application/dogm163.h>
#include <application/gpio.h>
#include <application/spi.h>

int main() {

  Gpio reset;
  Gpio rs;
  Spi spi0;

  Display display(reset);

  Application application(display);

  application.init();
  application.run();
}

