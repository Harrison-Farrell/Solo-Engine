// -----------------------------------------------------------------------------
// Author:      Harrison Farrell
// Project:     Solo-Engine Simulation Engine
// Copyright:   (c) 2026 Harrison Farrell. All Rights Reserved.
//
// Licensed under the GNU Affero General Public License v3.0 (AGPL-3.0).
// This program is distributed WITHOUT ANY WARRANTY; without even the
// implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See <https://www.gnu.org/licenses/agpl-3.0.html> for full details.
// -----------------------------------------------------------------------------

#include "AIS/Utilities/NMEA_ASCII.h"

#include <gtest/gtest.h>

#include <bitset>

// anonymous namespace to prevent name collisions
namespace {

TEST(nmea_ascii_test, Basic6BitConversion) {
    // 0 = 0 + 48 = '0'
    EXPECT_EQ("0", solo::ais::utilities::ToNmeaAscii(std::bitset<6>("000000")));
    // 1 = 1 + 48 = '1'
    EXPECT_EQ("1", solo::ais::utilities::ToNmeaAscii(std::bitset<6>("000001")));
    // 39 = 39 + 48 = 'W'
    EXPECT_EQ("W", solo::ais::utilities::ToNmeaAscii(std::bitset<6>("100111")));
    // 40 = 40 + 56 = '`'
    EXPECT_EQ("`", solo::ais::utilities::ToNmeaAscii(std::bitset<6>("101000")));
    // 63 = 63 + 56 = 'w'
    EXPECT_EQ("w", solo::ais::utilities::ToNmeaAscii(std::bitset<6>("111111")));
}

TEST(nmea_ascii_test, MultipleOf6BitsConversion) {
    // 101000 (40 -> '`') + 000000 (0 -> '0')
    EXPECT_EQ("`0", solo::ais::utilities::ToNmeaAscii(
                        std::bitset<12>("101000000000")));

    // 111111 (63 -> 'w') + 100111 (39 -> 'W')
    EXPECT_EQ("wW", solo::ais::utilities::ToNmeaAscii(
                        std::bitset<12>("111111100111")));
}

TEST(nmea_ascii_test, NonMultipleOf6BitsConversion) {
    // 8 bit test
    // 101000 (40 -> '`') + 01 (padded to 010000 -> 16 + 48 = 64 -> '@')
    EXPECT_EQ("`@",
              solo::ais::utilities::ToNmeaAscii(std::bitset<8>("10100001")));

    // 14 bit test
    // 111111 (63 -> 'w') + 100111 (39 -> 'W') + 11 (padded to 110000 -> 48 + 56
    // = 104 -> 'h')
    EXPECT_EQ("wWh", solo::ais::utilities::ToNmeaAscii(
                         std::bitset<14>("11111110011111")));
}

}  // namespace
