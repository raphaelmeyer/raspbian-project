#ifndef gpio_h
#define gpio_h

// ------------------------------------------------------------
enum class Signal {
  Undefined,
  Low,
  High
};

// ------------------------------------------------------------
enum class Direction {
  Undefined,
  Input,
  Output
};

// ------------------------------------------------------------
class iGpio {
  public:
    virtual bool init(Direction direction) = 0;
    virtual bool set(Signal signal) = 0;
};

#endif

