#ifndef dogm163_h
#define dogm163_h

#include <cstdint>
#include <chrono>

// ------------------------------------------------------------
class iGpio;
class iSpi;
class iTime;

// ------------------------------------------------------------
class iDogm163 {
  public:
    virtual void init() = 0;
    virtual void reset() = 0;
};

// ------------------------------------------------------------
class Dogm163 : public iDogm163 {
  public:
    Dogm163(iTime const & time, iSpi & spi, iGpio & rs, iGpio & reset);

    virtual void init() override final;
    virtual void reset() override final;

  private:
    iTime const & _time;
    iSpi & _spi;
    iGpio & _rs;
    iGpio & _reset;

    static std::chrono::microseconds const reset_pulse_time;
    static std::chrono::milliseconds const reset_time;
};

#endif

