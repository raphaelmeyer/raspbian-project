#include <application/application.h>
#include <application/display.h>
#include <application/dogm163.h>
#include <application/gpio.h>
#include <application/spi.h>

int main() {

  Spi spi0;
  Gpio rs;

  Dogm163 dogm163(rs, spi0);
  Display display(dogm163);

  Application application(display);

  //application.run();
}

