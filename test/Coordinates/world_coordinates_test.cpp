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

#include <stdexcept>

#include "Coordinates/WorldCoordinates.h"
#include "Math/Vector.h"

namespace {

TEST(test_world_coordinates, default_constructor) {
    const solo::math::WorldCoordinates coords;
    EXPECT_DOUBLE_EQ(coords.GetX(), 0.0);
    EXPECT_DOUBLE_EQ(coords.GetY(), 0.0);
    EXPECT_DOUBLE_EQ(coords.GetZ(), 0.0);
}

TEST(test_world_coordinates, param_constructor) {
    const solo::math::WorldCoordinates coords(1.5, -2.5, 3.0);
    EXPECT_DOUBLE_EQ(coords.GetX(), 1.5);
    EXPECT_DOUBLE_EQ(coords.GetY(), -2.5);
    EXPECT_DOUBLE_EQ(coords.GetZ(), 3.0);
}

TEST(test_world_coordinates, getters_setters) {
    solo::math::WorldCoordinates coords;
    coords.SetX(10.0);
    coords.SetY(20.0);
    coords.SetZ(30.0);
    EXPECT_DOUBLE_EQ(coords.GetX(), 10.0);
    EXPECT_DOUBLE_EQ(coords.GetY(), 20.0);
    EXPECT_DOUBLE_EQ(coords.GetZ(), 30.0);

    coords.Set(-5.0, 15.0, -25.0);
    EXPECT_DOUBLE_EQ(coords.GetX(), -5.0);
    EXPECT_DOUBLE_EQ(coords.GetY(), 15.0);
    EXPECT_DOUBLE_EQ(coords.GetZ(), -25.0);
}

TEST(test_world_coordinates, distance) {
    const solo::math::WorldCoordinates c1(0.0, 0.0, 0.0);
    const solo::math::WorldCoordinates c2(3.0, 4.0, 0.0);
    EXPECT_DOUBLE_EQ(c1.GetDistance(c2), 5.0);

    const solo::math::WorldCoordinates c3(1.0, 2.0, 3.0);
    const solo::math::WorldCoordinates c4(4.0, 6.0, 3.0);
    EXPECT_DOUBLE_EQ(c3.GetDistance(c4), 5.0);
}

TEST(test_world_coordinates, lerp_static) {
    const solo::math::WorldCoordinates c1(0.0, 0.0, 0.0);
    const solo::math::WorldCoordinates c2(10.0, 20.0, 30.0);
    
    // Lerp mid-point
    const auto result = solo::math::WorldCoordinates::Lerp(c1, c2, 0.5f);
    EXPECT_DOUBLE_EQ(result.GetX(), 5.0);
    EXPECT_DOUBLE_EQ(result.GetY(), 10.0);
    EXPECT_DOUBLE_EQ(result.GetZ(), 15.0);

    // Lerp start-point
    const auto result2 = solo::math::WorldCoordinates::Lerp(c1, c2, 0.0f);
    EXPECT_DOUBLE_EQ(result2.GetX(), 0.0);
    EXPECT_DOUBLE_EQ(result2.GetY(), 0.0);
    EXPECT_DOUBLE_EQ(result2.GetZ(), 0.0);

    // Lerp end-point
    const auto result3 = solo::math::WorldCoordinates::Lerp(c1, c2, 1.0f);
    EXPECT_DOUBLE_EQ(result3.GetX(), 10.0);
    EXPECT_DOUBLE_EQ(result3.GetY(), 20.0);
    EXPECT_DOUBLE_EQ(result3.GetZ(), 30.0);
}

TEST(test_world_coordinates, lerp_instance) {
    solo::math::WorldCoordinates c1(0.0, 0.0, 0.0);
    const solo::math::WorldCoordinates c2(10.0, 20.0, 30.0);
    
    c1.Lerp(c2, 0.5f);
    EXPECT_DOUBLE_EQ(c1.GetX(), 5.0);
    EXPECT_DOUBLE_EQ(c1.GetY(), 10.0);
    EXPECT_DOUBLE_EQ(c1.GetZ(), 15.0);
}

TEST(test_world_coordinates, equality) {
    const solo::math::WorldCoordinates c1(1.0, 2.0, 3.0);
    const solo::math::WorldCoordinates c2(1.0, 2.0, 3.0);
    const solo::math::WorldCoordinates c3(1.1, 2.0, 3.0);

    EXPECT_TRUE(c1 == c2);
    EXPECT_FALSE(c1 == c3);

    EXPECT_FALSE(c1 != c2);
    EXPECT_TRUE(c1 != c3);
}

TEST(test_world_coordinates, operator_multiply_coords) {
    const solo::math::WorldCoordinates c1(2.0, 3.0, 4.0);
    const solo::math::WorldCoordinates c2(0.5, 2.0, 1.5);
    const auto result = c1 * c2;
    EXPECT_DOUBLE_EQ(result.GetX(), 1.0);
    EXPECT_DOUBLE_EQ(result.GetY(), 6.0);
    EXPECT_DOUBLE_EQ(result.GetZ(), 6.0);
}

TEST(test_world_coordinates, operator_multiply_scalar) {
    const solo::math::WorldCoordinates c1(2.0, 3.0, 4.0);
    
    // Double mult
    const auto res1 = c1 * 2.0;
    EXPECT_DOUBLE_EQ(res1.GetX(), 4.0);
    EXPECT_DOUBLE_EQ(res1.GetY(), 6.0);
    EXPECT_DOUBLE_EQ(res1.GetZ(), 8.0);

    // Float mult
    const auto res2 = c1 * 0.5f;
    EXPECT_DOUBLE_EQ(res2.GetX(), 1.0);
    EXPECT_DOUBLE_EQ(res2.GetY(), 1.5);
    EXPECT_DOUBLE_EQ(res2.GetZ(), 2.0);
}

TEST(test_world_coordinates, operator_add) {
    const solo::math::WorldCoordinates c1(1.0, 2.0, 3.0);
    const solo::math::WorldCoordinates c2(10.0, 20.0, 30.0);
    const auto result = c1 + c2;
    
    EXPECT_DOUBLE_EQ(result.GetX(), 11.0);
    EXPECT_DOUBLE_EQ(result.GetY(), 22.0);
    EXPECT_DOUBLE_EQ(result.GetZ(), 33.0);
}

TEST(test_world_coordinates, operator_add_vector) {
    const solo::math::WorldCoordinates c1(1.0, 2.0, 3.0);
    const solo::math::Vector vec(10.0f, 20.0f, 30.0f);
    
    const auto result = c1 + vec;
    EXPECT_DOUBLE_EQ(result.GetX(), 11.0);
    EXPECT_DOUBLE_EQ(result.GetY(), 22.0);
    EXPECT_DOUBLE_EQ(result.GetZ(), 33.0);

    solo::math::WorldCoordinates c2(1.0, 2.0, 3.0);
    c2 += vec;
    EXPECT_DOUBLE_EQ(c2.GetX(), 11.0);
    EXPECT_DOUBLE_EQ(c2.GetY(), 22.0);
    EXPECT_DOUBLE_EQ(c2.GetZ(), 33.0);
}

TEST(test_world_coordinates, operator_assign_vector) {
    solo::math::WorldCoordinates c1;
    const solo::math::Vector vec(5.0f, 6.0f, 7.0f);
    
    c1 = vec;
    EXPECT_DOUBLE_EQ(c1.GetX(), 5.0);
    EXPECT_DOUBLE_EQ(c1.GetY(), 6.0);
    EXPECT_DOUBLE_EQ(c1.GetZ(), 7.0);
}

TEST(test_world_coordinates, operator_sub) {
    const solo::math::WorldCoordinates c1(10.0, 20.0, 30.0);
    const solo::math::WorldCoordinates c2(1.0, 2.0, 3.0);
    
    const auto result = c1 - c2;
    EXPECT_DOUBLE_EQ(result.GetX(), 9.0);
    EXPECT_DOUBLE_EQ(result.GetY(), 18.0);
    EXPECT_DOUBLE_EQ(result.GetZ(), 27.0);

    solo::math::WorldCoordinates c3(10.0, 20.0, 30.0);
    c3 -= c2;
    EXPECT_DOUBLE_EQ(c3.GetX(), 9.0);
    EXPECT_DOUBLE_EQ(c3.GetY(), 18.0);
    EXPECT_DOUBLE_EQ(c3.GetZ(), 27.0);
}

TEST(test_world_coordinates, operator_subscript) {
    solo::math::WorldCoordinates c1(1.0, 2.0, 3.0);
    const solo::math::WorldCoordinates c2(10.0, 20.0, 30.0);

    EXPECT_DOUBLE_EQ(c1[0], 1.0);
    EXPECT_DOUBLE_EQ(c1[1], 2.0);
    EXPECT_DOUBLE_EQ(c1[2], 3.0);
    EXPECT_THROW(c1[3], std::out_of_range);

    EXPECT_DOUBLE_EQ(c2[0], 10.0);
    EXPECT_DOUBLE_EQ(c2[1], 20.0);
    EXPECT_DOUBLE_EQ(c2[2], 30.0);
    EXPECT_THROW(c2[3], std::out_of_range);

    c1[0] = -1.0;
    c1[1] = -2.0;
    c1[2] = -3.0;
    EXPECT_DOUBLE_EQ(c1.GetX(), -1.0);
    EXPECT_DOUBLE_EQ(c1.GetY(), -2.0);
    EXPECT_DOUBLE_EQ(c1.GetZ(), -3.0);
}

} // namespace
