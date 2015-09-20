#ifndef display_h
#define display_h

#include <cstdint>
#include <string>

// ------------------------------------------------------------
class iGpio;

// ------------------------------------------------------------
class iDisplay {
  public:
    virtual void init() = 0;
    virtual void write(std::string const & text) = 0;
};

// ------------------------------------------------------------
class Display : public iDisplay {
  public:
    Display(iGpio & reset);

    virtual void init() override final;
    virtual void write(std::string const & text) override final;

  private:
    iGpio & reset;
};

#endif

