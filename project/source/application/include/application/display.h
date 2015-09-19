#ifndef display_h
#define display_h

#include <cstdint>
#include <vector>
#include <string>

// ------------------------------------------------------------
class iDogm163;

// ------------------------------------------------------------
class iDisplay {
  public:
    virtual bool init() = 0;
    virtual bool write(std::string const & text) = 0;
};

// ------------------------------------------------------------
class Display : public iDisplay {
  public:
    Display(iDogm163 & dogm163);

    virtual bool init() override final;
    virtual bool write(std::string const & text) override final;

  private:
    iDogm163 & dogm163;

    static std::vector<uint8_t> const initialization;
};

#endif

