//
// Created by Siddharth Mehrotra on 11/9/2023.
//

#ifndef QUANTLIB_TOPLEVELFIXTURE_HPP
#define QUANTLIB_TOPLEVELFIXTURE_HPP

#include <boost/test/unit_test.hpp>
#include <ql/indexes/indexmanager.hpp>
#include <ql/settings.hpp>

namespace QuantLib {

    class toplevelfixture {
      public:
        toplevelfixture() {
            // Restore settings after each test.
            SavedSettings restore;
            // Clear all fixings before running a test to avoid interference.
            IndexManager::instance().clearHistories();
        }

        ~toplevelfixture() {}

#if BOOST_VERSION <= 105300
        // defined to avoid unused-variable warnings. It doesn't
        // work after Boost 1.53 because the functions were
        // overloaded and the address can't be resolved.
        void _use_check(const void* = &boost::test_tools::check_is_close,
                        const void* = &boost::test_tools::check_is_small) const {}
#endif
    };
}
#endif // QUANTLIB_TOPLEVELFIXTURE_HPP