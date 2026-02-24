/*
 * --------------------------------------------------------------------------
 * Author:      Harrison Farrell
 * Project:     Solo-Engine Simulation Engine
 * Copyright:   (c) 2026 Harrison Farrell. All Rights Reserved.
 *
 * Licensed under the GNU Affero General Public License v3.0 (AGPL-3.0).
 * This program is distributed WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See <https://www.gnu.org/licenses/agpl-3.0.html> for full details.
 * --------------------------------------------------------------------------
 */

#include "Math/Matrix.h"

#include <gtest/gtest.h>

// anonymous namespace to prevent name collisions
namespace {

TEST(Vector3_Test, Constructor) {
    solo::math::Vector3 vector;
    ASSERT_EQ(vector.x, 0.0);
    ASSERT_EQ(vector.y, 0.0);
    ASSERT_EQ(vector.z, 0.0);
}

TEST(Vector3_Test, ConstructorWithValues) {
    solo::math::Vector3 vector(1.0, 2.0, 3.0);
    ASSERT_EQ(vector.x, 1.0);
    ASSERT_EQ(vector.y, 2.0);
    ASSERT_EQ(vector.z, 3.0);
}

TEST(Vector3_Test, Add) {
    solo::math::Vector3 vector(1.0, 2.0, 3.0);
    solo::math::Vector3 other(4.0, 5.0, 6.0);
    solo::math::Vector3 result = vector + other;
    ASSERT_EQ(result.x, 5.0);
    ASSERT_EQ(result.y, 7.0);
    ASSERT_EQ(result.z, 9.0);
}

TEST(Vector3_Test, AddAssign) {
    solo::math::Vector3 vector(1.0, 2.0, 3.0);
    solo::math::Vector3 other(4.0, 5.0, 6.0);
    vector += other;
    ASSERT_EQ(vector.x, 5.0);
    ASSERT_EQ(vector.y, 7.0);
    ASSERT_EQ(vector.z, 9.0);
}

TEST(Vector3_Test, Multiply) {
    solo::math::Vector3 vector(1.0, 2.0, 3.0);
    solo::math::Vector3 result = vector * 2.0;
    ASSERT_EQ(result.x, 2.0);
    ASSERT_EQ(result.y, 4.0);
    ASSERT_EQ(result.z, 6.0);
}

TEST(Vector3_Test, Dot) {
    solo::math::Vector3 vector(1.0, 2.0, 3.0);
    solo::math::Vector3 other(4.0, 5.0, 6.0);
    double result = vector.dot(other);
    ASSERT_EQ(result, 32.0);
}

TEST(Vector3_Test, Cross) {
    solo::math::Vector3 vector(1.0, 2.0, 3.0);
    solo::math::Vector3 other(4.0, 5.0, 6.0);
    solo::math::Vector3 result = vector.cross(other);
    ASSERT_EQ(result.x, -3.0);
    ASSERT_EQ(result.y, 6.0);
    ASSERT_EQ(result.z, -3.0);
}

} // namespace