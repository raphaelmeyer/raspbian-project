#ifndef display_h
#define display_h

#include <cstdint>
#include <vector>

class iDogm163 {
  public:
    virtual bool write_command(std::uint8_t command) = 0;
};

class iDisplay {
  public:
    virtual void init() = 0;
};

class Display : public iDisplay {
  public:
    Display(iDogm163 & dogm163);

    virtual void init() override final;

  private:
    iDogm163 & dogm163;

    static std::vector<uint8_t> const initialization;
};

#endif

