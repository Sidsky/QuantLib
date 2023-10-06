#ifndef QUANTLIB_QUANTLIBGLOBALFIXTURE_HPP
#define QUANTLIB_QUANTLIBGLOBALFIXTURE_HPP

#include "speedlevel.hpp"

class QuantLibGlobalFixture {
  public:
    QuantLibGlobalFixture();
    virtual ~QuantLibGlobalFixture();

    static SpeedLevel & getInstance ();
    SpeedLevel speed_level(int argc, char** argv);

  private:
    static SpeedLevel speed;
    decltype(std::chrono::steady_clock::now()) start;
    decltype(std::chrono::steady_clock::now()) stop;
};

#endif // QUANTLIB_QUANTLIBGLOBALFIXTURE_HPP