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

#include "Coordinates/Geodetic.h"

#include <gtest/gtest.h>

#include <numbers>

#include "Math/UnitConversions.h"

// anonymous namespace to prevent name collisions
namespace {

// Needed before including Geodetic.h because Geodetic.h calls DegToRad and
// RadToDeg without namespace qualifications.
using namespace solo::math;

TEST(test_geodetic, GetEllipsoidAxisWGS84) {
    auto [major_axis, minor_axis] =
        GetEllipsoidAxis<double>(EllipsoidReference::WGS_1984);
    EXPECT_DOUBLE_EQ(major_axis, 6378137.000);
    EXPECT_DOUBLE_EQ(minor_axis, 6356752.314245);
}

TEST(test_geodetic, GeocentricGeodeticRoundtrip) {
    const double lat = 34.0;
    const double lon = -118.0;
    const double h = 1000.0;

    auto [x, y, z] =
        GeodeticToGeocentric(lat, lon, h, EllipsoidReference::WGS_1984);

    auto [out_lat, out_lon, out_h] =
        GeocentricToGeodetic(x, y, z, EllipsoidReference::WGS_1984);

    EXPECT_NEAR(lat, out_lat, 1e-5);
    EXPECT_NEAR(lon, out_lon, 1e-5);
    EXPECT_NEAR(h, out_h, 1e-3);
}

TEST(test_geodetic, RotateAboutAxis) {
    double source[3] = {1.0, 0.0, 0.0};
    double axis[3] = {0.0, 0.0, 1.0};
    double dest[3];
    double angle = std::numbers::pi / 2.0;  // 90 degrees

    RotateAboutAxis(dest, source, axis, angle);

    EXPECT_NEAR(dest[0], 0.0, 1e-7);
    EXPECT_NEAR(dest[1], 1.0, 1e-7);
    EXPECT_NEAR(dest[2], 0.0, 1e-7);
}

TEST(test_geodetic, CrossProduct) {
    double a[3] = {1.0, 0.0, 0.0};
    double b[3] = {0.0, 1.0, 0.0};
    double c[3];

    Cross(c, a, b);

    EXPECT_DOUBLE_EQ(c[0], 0.0);
    EXPECT_DOUBLE_EQ(c[1], 0.0);
    EXPECT_DOUBLE_EQ(c[2], 1.0);
}

TEST(test_geodetic, DotProduct) {
    double a[3] = {1.0, 2.0, 3.0};
    double b[3] = {4.0, -5.0, 6.0};

    double dot = Dot(a, b);
    EXPECT_DOUBLE_EQ(dot, 1.0 * 4.0 + 2.0 * (-5.0) + 3.0 * 6.0);
}

TEST(test_geodetic, EulerHeadingPitchRollRoundtrip) {
    double lat = DegToRad(34.0);
    double lon = DegToRad(-118.0);

    double heading = DegToRad(10.0);
    double pitch = DegToRad(20.0);
    double roll = DegToRad(30.0);

    auto [psi, theta, phi] =
        HeadingPitchRollToEuler(heading, pitch, roll, lat, lon);

    auto [out_h, out_p, out_r] =
        EulerToHeadingPitchRoll(lat, lon, psi, theta, phi);

    EXPECT_NEAR(heading, out_h, 1e-5);
    EXPECT_NEAR(pitch, out_p, 1e-5);
    EXPECT_NEAR(roll, out_r, 1e-5);
}

}  // namespace