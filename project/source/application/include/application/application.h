#ifndef application_h
#define application_h

// ------------------------------------------------------------
class iDisplay;

// ------------------------------------------------------------
class Application {
  public:
    Application(iDisplay & display);

    bool init();

  private:
    iDisplay & display;
};

#endif

