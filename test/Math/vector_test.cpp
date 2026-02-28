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

#include "Math/Vector.h"

#include <gtest/gtest.h>

// anonymous namespace to prevent name collisions
namespace {

TEST(vector_test, GetMagnitude) {
    solo::math::Vector vec(3, 4, 12);
    EXPECT_EQ(13, vec.GetMagnitude());
}

TEST(vector_test, GetDistance) {
    solo::math::Vector vecA(3, 4, 12);
    solo::math::Vector vecB(5, 6, 14);
    solo::math::Vector vecC(-3, -5, -14);
    EXPECT_NEAR(3.464, vecA.GetDistance(vecB), 0.001);
    EXPECT_NEAR(28.160, vecA.GetDistance(vecC), 0.001);
}

TEST(vector_test, array_subscript_operator) {
    solo::math::Vector vecA(3, 4, 12);
    EXPECT_EQ(3, vecA[0]);
    EXPECT_EQ(4, vecA[1]);
    EXPECT_EQ(12, vecA[2]);
    EXPECT_THROW(vecA[3], std::out_of_range);
}
}  // namespace