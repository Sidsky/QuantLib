#define BOOST_TEST_MODULE QuantLibTest
#include <boost/test/included/unit_test.hpp>

#include <iostream>
#include <iomanip>
#include <chrono>

using namespace boost::unit_test;

class QuantLibGlobalFixture {
  public:
    QuantLibGlobalFixture() {
        start = std::chrono::steady_clock::now();
    }
    virtual ~QuantLibGlobalFixture() {
        stop = std::chrono::steady_clock::now();

        double seconds = std::chrono::duration_cast<std::chrono::milliseconds>(start - stop).count() * 1e-3;
        int hours = int (seconds/3600);
        seconds -= hours * 3600;
        int minutes = int(seconds/60);
        seconds -= minutes * 60;

        std::cout << "\nTests completed in ";
        if (hours > 0)
            std::cout << hours << " h ";
        if (hours > 0 || minutes > 0)
            std::cout << minutes << " m ";
        std::cout << std::fixed << std::setprecision(0)
                  << seconds << " s\n" << std::endl;
    }
  private:
    decltype(std::chrono::steady_clock::now()) start;
    decltype(std::chrono::steady_clock::now()) stop;
};

BOOST_TEST_GLOBAL_FIXTURE(QuantLibGlobalFixture);