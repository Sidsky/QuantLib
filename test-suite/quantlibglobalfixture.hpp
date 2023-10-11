#ifndef QUANTLIB_QUANTLIBGLOBALFIXTURE_HPP
#define QUANTLIB_QUANTLIBGLOBALFIXTURE_HPP

#include "speedlevel.hpp"
#include <chrono>

class QuantLibGlobalFixture {
  public:
    QuantLibGlobalFixture();
    ~QuantLibGlobalFixture();
    static SpeedLevel get_speed ();
    SpeedLevel speed_level (int argc, char **argv);

  private:
    static SpeedLevel speed;
    decltype(std::chrono::steady_clock::now()) start;
    decltype(std::chrono::steady_clock::now()) stop;
};

#endif // QUANTLIB_QUANTLIBGLOBALFIXTURE_HPP