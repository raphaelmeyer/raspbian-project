#ifndef spi_h
#define spi_h

#include <cstdint>

// ------------------------------------------------------------
class iSpi {
  public:
    virtual bool send(std::uint8_t value) = 0;
};

// ------------------------------------------------------------
class Spi : public iSpi {
  public:
    virtual bool send(std::uint8_t value) override final;
};

#endif

