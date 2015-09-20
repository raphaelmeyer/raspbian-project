#ifndef display_h
#define display_h

#include <cstdint>
#include <string>
#include <chrono>

// ------------------------------------------------------------
class iGpio;
class iTime;

// ------------------------------------------------------------
class iDisplay {
  public:
    virtual void init() = 0;
    virtual void write(std::string const & text) = 0;
};

// ------------------------------------------------------------
class Display : public iDisplay {
  public:
    Display(iGpio & reset, iTime const & time);

    virtual void init() override final;
    virtual void write(std::string const & text) override final;

  private:
    iGpio & reset;
    iTime const & time;

    static std::chrono::microseconds const reset_pulse;
    static std::chrono::milliseconds const reset_time;
};

#endif

