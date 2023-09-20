#pragma once

#include <ql/indexes/indexmanager.hpp>
#include <ql/settings.hpp>

namespace QuantLib {

    using QuantLib::SavedSettings;
    using QuantLib::IndexManager;

    class TopLevelFixture {
      public:
        TopLevelFixture() {
            // Restore settings after each test.
            SavedSettings restore;
        }

        ~TopLevelFixture() {
            // Clear all fixings before running a test to avoid interference.
            IndexManager::instance().clearHistories();
        }

#if BOOST_VERSION <= 105300
        // defined to avoid unused-variable warnings. It doesn't
        // work after Boost 1.53 because the functions were
        // overloaded and the address can't be resolved.
        void _use_check(const void* = &boost::test_tools::check_is_close,
                        const void* = &boost::test_tools::check_is_small) const {}
#endif
    };
}