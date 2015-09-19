#ifndef application_h
#define application_h

// ------------------------------------------------------------
class iDisplay;

// ------------------------------------------------------------
class Application {
  public:
    Application(iDisplay & display);

    void init();
    void run();

  private:
    iDisplay & display;
};

#endif

