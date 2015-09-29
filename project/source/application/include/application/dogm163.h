#ifndef dogm163_h
#define dogm163_h

#include <cstdint>
#include <chrono>
#include <vector>

// ------------------------------------------------------------
class iGpio;
class iSpi;
class iTime;

// ------------------------------------------------------------
enum class Command {
  Undefined,
  ClearDisplay,
};

// ------------------------------------------------------------
class iDogm163 {
  public:
    virtual void init() = 0;
    virtual void reset() = 0;

    virtual void write_command(Command command) = 0;
    virtual void write_data(std::vector<uint8_t> const & data) = 0;
};

// ------------------------------------------------------------
class Dogm163 : public iDogm163 {
  public:
    Dogm163(iTime const & time, iSpi & spi, iGpio & rs, iGpio & reset);

    virtual void init() override final;
    virtual void reset() override final;

    virtual void write_command(Command command) override final {}
    virtual void write_data(std::vector<uint8_t> const & data) {};

  private:
    iTime const & _time;
    iSpi & _spi;
    iGpio & _rs;
    iGpio & _reset;

    static std::chrono::microseconds const reset_pulse_time;
    static std::chrono::milliseconds const reset_time;

    static std::vector<std::uint8_t> const init_sequence;
};

#endif

