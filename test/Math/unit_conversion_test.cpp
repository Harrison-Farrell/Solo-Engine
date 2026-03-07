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

#include <gtest/gtest.h>

#include <numbers>

#include "Math/UnitConversions.h"

// anonymous namespace to prevent name collisions
namespace {

TEST(UnitConversion, DegToRad) {
    EXPECT_NEAR(0.261799, solo::math::DegToRad((double)15), 0.001);
    EXPECT_NEAR(-1.5708, solo::math::DegToRad((double)-90), 0.001);
    EXPECT_NEAR(std::numbers::pi, solo::math::DegToRad((double)180), 0.001);
}

TEST(UnitConversion, RadToDeg) {
    EXPECT_NEAR(15, solo::math::RadToDeg((double)0.261799), 0.001);
    EXPECT_NEAR(-90, solo::math::RadToDeg((double)-1.5708), 0.001);
    EXPECT_NEAR(180, solo::math::RadToDeg((double)std::numbers::pi), 0.001);
}

TEST(UnitConversion, FeetToMeters) {
    EXPECT_NEAR(0.3048, solo::math::FeetToMeters((double)1), 0.001);
    EXPECT_NEAR(6096.0741, solo::math::FeetToMeters((double)20000), 0.001);
    EXPECT_NEAR(0.6096, solo::math::FeetToMeters((double)2), 0.001);
}

TEST(UnitConversion, MetersToFeet) {
    EXPECT_NEAR(3.28084, solo::math::MetersToFeet((double)1), 0.01);
    EXPECT_NEAR(656.1600, solo::math::MetersToFeet((double)200), 0.01);
    EXPECT_NEAR(6.56168, solo::math::MetersToFeet((double)2), 0.01);
}

TEST(UnitConversion, DMSToDecimal) {
    EXPECT_NEAR(45.2816, solo::math::DMSToDecimal<double>(45, 16, 54), 0.001);
    EXPECT_NEAR(-89.8169, solo::math::DMSToDecimal<double>(-90, 10, 59), 0.001);
}

TEST(UnitConversion, DecimalToDMS) {
    double hours, minutes, seconds;
    solo::math::DecimalToDMS(45.2816, hours, minutes, seconds);
    EXPECT_NEAR(45, hours, 0.001);
    EXPECT_NEAR(16, minutes, 0.001);
    EXPECT_NEAR(53.7599, seconds, 0.001);
}
}  // namespace