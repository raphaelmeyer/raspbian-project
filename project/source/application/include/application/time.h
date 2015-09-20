#ifndef time_h
#define time_h

#include <chrono>

// ------------------------------------------------------------
class iTime {
  public:
    virtual void sleep(std::chrono::microseconds const & duration) const = 0;
    virtual void sleep(std::chrono::milliseconds const & duration) const = 0;
    virtual void sleep(std::chrono::seconds const & duration) const = 0;
};

// ------------------------------------------------------------
class Time : public iTime
{
  public:
    virtual void sleep(std::chrono::microseconds const & duration) const override final {}
    virtual void sleep(std::chrono::milliseconds const & duration) const override final {}
    virtual void sleep(std::chrono::seconds const & duration) const override final {}

};

#endif

