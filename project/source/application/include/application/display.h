#ifndef display_h
#define display_h

#include <cstdint>
#include <string>

// ------------------------------------------------------------
class iDogm163;

// ------------------------------------------------------------
class iDisplay {
  public:
    virtual void init() = 0;
    virtual void write(std::string const & text) = 0;
};

// ------------------------------------------------------------
class Display : public iDisplay {
  public:
    Display(iDogm163 & dogm163);

    virtual void init() override final;
    virtual void write(std::string const & text) override final;

  private:
    iDogm163 & _dogm163;
};

#endif

