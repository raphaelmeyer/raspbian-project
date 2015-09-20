#include <application/application.h>
#include <application/display.h>
#include <application/dogm163.h>
#include <application/gpio.h>
#include <application/spi.h>
#include <application/time.h>

int main() {

  Gpio reset;
  Gpio rs;
  Spi spi0;

  Time time;

  Dogm163 dogm163(time, spi0, rs, reset);
  Display display(dogm163);
  Application application(display);

  application.init();
  application.run();
}

