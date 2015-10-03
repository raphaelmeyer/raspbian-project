#include <application/spi.h>
#include <application/gpio.h>

#include <array>

class Display_Stub
{
  public:
    iSpi & spi();
    iGpio & rs();
    iGpio & reset();

  private:

    class Spi_Stub : public iSpi
    {
      public:
        virtual bool send(std::uint8_t value) override final;
    };

    class Gpio_Stub : public iGpio
    {
      public:
        virtual bool init(Direction direction) override final;
        virtual bool set(Signal signal) override final;

        bool low() { return _level == Signal::Low; }
        bool high() { return _level == Signal::High; }

      private:
        Signal _level;
    };

    Spi_Stub _spi;
    Gpio_Stub _rs;
    Gpio_Stub _reset;

    std::array<std::uint8_t, 16*3> _memory;
    unsigned int _pos;
};

