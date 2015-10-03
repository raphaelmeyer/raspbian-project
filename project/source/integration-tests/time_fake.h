#ifndef time_fake_h
#define time_fake_h

#include <application/time.h>

class Time_Fake : public iTime
{
  public:
    virtual void sleep(std::chrono::microseconds const & duration) const override final {}
    virtual void sleep(std::chrono::milliseconds const & duration) const override final {}
    virtual void sleep(std::chrono::seconds const & duration) const override final {}

};

#endif

