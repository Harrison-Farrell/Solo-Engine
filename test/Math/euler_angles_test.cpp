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
#include <stdexcept>

#include "Math/EulerAngles.h"

// anonymous namespace to prevent name collisions
namespace {
TEST(test_euler_angles, default_constructor) {
    const solo::math::EulerAngles angles;
    ASSERT_EQ(angles.GetPsiInDegrees(), 0);
    ASSERT_EQ(angles.GetThetaInDegrees(), 0);
    ASSERT_EQ(angles.GetPhiInDegrees(), 0);

    ASSERT_EQ(angles.GetPsiInRadians(), 0);
    ASSERT_EQ(angles.GetThetaInRadians(), 0);
    ASSERT_EQ(angles.GetPhiInRadians(), 0);
}

TEST(test_euler_angles, constructor) {
    const solo::math::EulerAngles angles(std::numbers::pi, std::numbers::pi,
                                         std::numbers::pi);
    ASSERT_EQ(angles.GetPsiInDegrees(), 180);
    ASSERT_EQ(angles.GetThetaInDegrees(), 180);
    ASSERT_EQ(angles.GetPhiInDegrees(), 180);

    EXPECT_FLOAT_EQ(angles.GetPsiInRadians(), std::numbers::pi);
    EXPECT_FLOAT_EQ(angles.GetThetaInRadians(), std::numbers::pi);
    EXPECT_FLOAT_EQ(angles.GetPhiInRadians(), std::numbers::pi);
}

TEST(test_euler_angles, set_get_radians) {
    solo::math::EulerAngles angles;
    angles.SetPsiInRadians(1.0f);
    angles.SetThetaInRadians(2.0f);
    angles.SetPhiInRadians(3.0f);

    EXPECT_FLOAT_EQ(angles.GetPsiInRadians(), 1.0f);
    EXPECT_FLOAT_EQ(angles.GetThetaInRadians(), 2.0f);
    EXPECT_FLOAT_EQ(angles.GetPhiInRadians(), 3.0f);
}

TEST(test_euler_angles, set_get_degrees) {
    solo::math::EulerAngles angles;
    angles.SetPsiInDegrees(90.0f);
    angles.SetThetaInDegrees(180.0f);
    angles.SetPhiInDegrees(270.0f);

    EXPECT_FLOAT_EQ(angles.GetPsiInDegrees(), 90.0f);
    EXPECT_FLOAT_EQ(angles.GetThetaInDegrees(), 180.0f);
    EXPECT_FLOAT_EQ(angles.GetPhiInDegrees(), 270.0f);
}

TEST(test_euler_angles, equality_operators) {
    const solo::math::EulerAngles a1(1.0f, 2.0f, 3.0f);
    const solo::math::EulerAngles a2(1.0f, 2.0f, 3.0f);
    const solo::math::EulerAngles a3(1.1f, 2.0f, 3.0f);
    const solo::math::EulerAngles a4(1.0f, 2.1f, 3.0f);
    const solo::math::EulerAngles a5(1.0f, 2.0f, 3.1f);

    EXPECT_TRUE(a1 == a2);
    EXPECT_FALSE(a1 == a3);
    EXPECT_FALSE(a1 == a4);
    EXPECT_FALSE(a1 == a5);

    EXPECT_FALSE(a1 != a2);
    EXPECT_TRUE(a1 != a3);
    EXPECT_TRUE(a1 != a4);
    EXPECT_TRUE(a1 != a5);
}

TEST(test_euler_angles, arithmetic_operators) {
    solo::math::EulerAngles a1(1.0f, 2.0f, 3.0f);
    const solo::math::EulerAngles a2(0.5f, 1.0f, 1.5f);

    const solo::math::EulerAngles sum = a1 + a2;
    EXPECT_FLOAT_EQ(sum.GetPsiInRadians(), 1.5f);
    EXPECT_FLOAT_EQ(sum.GetThetaInRadians(), 3.0f);
    EXPECT_FLOAT_EQ(sum.GetPhiInRadians(), 4.5f);

    const solo::math::EulerAngles diff = a1 - a2;
    EXPECT_FLOAT_EQ(diff.GetPsiInRadians(), 0.5f);
    EXPECT_FLOAT_EQ(diff.GetThetaInRadians(), 1.0f);
    EXPECT_FLOAT_EQ(diff.GetPhiInRadians(), 1.5f);

    const solo::math::EulerAngles mult = a1 * a2;
    EXPECT_FLOAT_EQ(mult.GetPsiInRadians(), 0.5f);
    EXPECT_FLOAT_EQ(mult.GetThetaInRadians(), 2.0f);
    EXPECT_FLOAT_EQ(mult.GetPhiInRadians(), 4.5f);

    a1 += a2;
    EXPECT_FLOAT_EQ(a1.GetPsiInRadians(), 1.5f);
    EXPECT_FLOAT_EQ(a1.GetThetaInRadians(), 3.0f);
    EXPECT_FLOAT_EQ(a1.GetPhiInRadians(), 4.5f);

    a1 -= a2;
    EXPECT_FLOAT_EQ(a1.GetPsiInRadians(), 1.0f);
    EXPECT_FLOAT_EQ(a1.GetThetaInRadians(), 2.0f);
    EXPECT_FLOAT_EQ(a1.GetPhiInRadians(), 3.0f);
}

TEST(test_euler_angles, scalar_multiplication) {
    const solo::math::EulerAngles a1(1.0f, 2.0f, 3.0f);
    
    const solo::math::EulerAngles mult1 = a1 * 2.0f;
    EXPECT_FLOAT_EQ(mult1.GetPsiInRadians(), 2.0f);
    EXPECT_FLOAT_EQ(mult1.GetThetaInRadians(), 4.0f);
    EXPECT_FLOAT_EQ(mult1.GetPhiInRadians(), 6.0f);

    const solo::math::EulerAngles mult2 = 3.0f * a1;
    EXPECT_FLOAT_EQ(mult2.GetPsiInRadians(), 3.0f);
    EXPECT_FLOAT_EQ(mult2.GetThetaInRadians(), 6.0f);
    EXPECT_FLOAT_EQ(mult2.GetPhiInRadians(), 9.0f);
}

TEST(test_euler_angles, indexing_operator) {
    solo::math::EulerAngles a1(1.0f, 2.0f, 3.0f);
    const solo::math::EulerAngles a2(4.0f, 5.0f, 6.0f);

    EXPECT_FLOAT_EQ(a1[0], 1.0f);
    EXPECT_FLOAT_EQ(a1[1], 2.0f);
    EXPECT_FLOAT_EQ(a1[2], 3.0f);
    EXPECT_THROW(a1[3], std::out_of_range);

    EXPECT_FLOAT_EQ(a2[0], 4.0f);
    EXPECT_FLOAT_EQ(a2[1], 5.0f);
    EXPECT_FLOAT_EQ(a2[2], 6.0f);
    EXPECT_THROW(a2[3], std::out_of_range);

    a1[0] = 7.0f;
    a1[1] = 8.0f;
    a1[2] = 9.0f;
    EXPECT_FLOAT_EQ(a1.GetPsiInRadians(), 7.0f);
    EXPECT_FLOAT_EQ(a1.GetThetaInRadians(), 8.0f);
    EXPECT_FLOAT_EQ(a1.GetPhiInRadians(), 9.0f);
}
}  // namespace