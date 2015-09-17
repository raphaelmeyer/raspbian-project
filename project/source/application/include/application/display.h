#ifndef display_h
#define display_h

#include <cstdint>

class iDogm163 {
  public:
    virtual bool write_command(std::uint8_t command) = 0;
};

class Display {
  public:
    Display(iDogm163 & dogm163);

    void init();

  private:
    iDogm163 & dogm163;
};

#endif

