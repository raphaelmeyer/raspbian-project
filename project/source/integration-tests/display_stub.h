#include <array>
#include <memory>

class iSpi;
class iGpio;

namespace Stub {

class Dogm163
{
  public:
    Dogm163();
    virtual ~Dogm163();

    iSpi & spi();
    iGpio & rs();
    iGpio & reset();

    std::array<std::uint8_t, 3*16> const & screen();

  private:
    class Impl;
    std::unique_ptr<Impl> _impl;
};

}

