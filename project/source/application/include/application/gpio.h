#ifndef gpio_h
#define gpio_h

enum class Signal {
  Undefined,
  Low,
  High
};

class iGpio {
  public:
    virtual bool set(Signal signal) = 0;
};

#endif

