#ifndef dogm163_h
#define dogm163_h

#include <cstdint>

class iGpio;
class iSpi;

class iDogm163 {
  public:
    virtual bool write_command(std::uint8_t command) = 0;
};

class Dogm163 : public iDogm163 {
  public:
    Dogm163(iGpio & rs, iSpi & spi);

    virtual bool write_command(std::uint8_t command) override final;

  private:
    iGpio & rs;
    iSpi & spi;
};

#endif

