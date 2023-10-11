#include "speedlevel.hpp"
#include "quantlibglobalfixture.hpp"

#include <boost/test/unit_test.hpp>

if_speed::if_speed(SpeedLevel speed) : speed(speed) {}

tt::assertion_result if_speed::operator()(utf::test_unit_id) const {
    tt::assertion_result level (QuantLibGlobalFixture::get_speed() <= speed);
    level.message() << "precondition failed";
    return level;
}