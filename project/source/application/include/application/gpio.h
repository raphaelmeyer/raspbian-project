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

// ------------------------------------------------------------
class Gpio : public iGpio {
  public:
    virtual bool init(Direction direction) override final;
    virtual bool set(Signal signal) override final;
};

#endif

