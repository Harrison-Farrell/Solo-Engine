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

TEST(test_matrix, constructor) {
    solo::math::Matrix3d matrix;
    ASSERT_EQ(matrix.data[0][0], 1);
    ASSERT_EQ(matrix.data[0][1], 0);
    ASSERT_EQ(matrix.data[0][2], 0);
    ASSERT_EQ(matrix.data[1][0], 0);
    ASSERT_EQ(matrix.data[1][1], 1);
    ASSERT_EQ(matrix.data[1][2], 0);
    ASSERT_EQ(matrix.data[2][0], 0);
    ASSERT_EQ(matrix.data[2][1], 0);
    ASSERT_EQ(matrix.data[2][2], 1);
}

TEST(test_matrix, additional_operator) {
    solo::math::Matrix3d m1;
    solo::math::Matrix3d m2;

    m1 = m1 + m2;
    ASSERT_EQ(m1.data[0][0], 2);
    ASSERT_EQ(m1.data[0][1], 0);
    ASSERT_EQ(m1.data[0][2], 0);
    ASSERT_EQ(m1.data[1][0], 0);
    ASSERT_EQ(m1.data[1][1], 2);
    ASSERT_EQ(m1.data[1][2], 0);
    ASSERT_EQ(m1.data[2][0], 0);
    ASSERT_EQ(m1.data[2][1], 0);
    ASSERT_EQ(m1.data[2][2], 2);

    m1 += m2;
    ASSERT_EQ(m1.data[0][0], 3);
    ASSERT_EQ(m1.data[0][1], 0);
    ASSERT_EQ(m1.data[0][2], 0);
    ASSERT_EQ(m1.data[1][0], 0);
    ASSERT_EQ(m1.data[1][1], 3);
    ASSERT_EQ(m1.data[1][2], 0);
    ASSERT_EQ(m1.data[2][0], 0);
    ASSERT_EQ(m1.data[2][1], 0);
    ASSERT_EQ(m1.data[2][2], 3);
}

TEST(test_matrix, subtraction_operator) {
    solo::math::Matrix3d m1;
    solo::math::Matrix3d m2;

    m1 = m1 - m2;
    ASSERT_EQ(m1.data[0][0], 0);
    ASSERT_EQ(m1.data[0][1], 0);
    ASSERT_EQ(m1.data[0][2], 0);
    ASSERT_EQ(m1.data[1][0], 0);
    ASSERT_EQ(m1.data[1][1], 0);
    ASSERT_EQ(m1.data[1][2], 0);
    ASSERT_EQ(m1.data[2][0], 0);
    ASSERT_EQ(m1.data[2][1], 0);
    ASSERT_EQ(m1.data[2][2], 0);

    m1 -= m2;
    ASSERT_EQ(m1.data[0][0], -1);
    ASSERT_EQ(m1.data[0][1], 0);
    ASSERT_EQ(m1.data[0][2], 0);
    ASSERT_EQ(m1.data[1][0], 0);
    ASSERT_EQ(m1.data[1][1], -1);
    ASSERT_EQ(m1.data[1][2], 0);
    ASSERT_EQ(m1.data[2][0], 0);
    ASSERT_EQ(m1.data[2][1], 0);
    ASSERT_EQ(m1.data[2][2], -1);
}

TEST(test_matrix, multiplication_operator) {
    solo::math::Matrix3d m1;
    solo::math::Matrix3d m2;
    for (uint16_t i = 0; i < 3; ++i) {
        for (uint16_t j = 0; j < 3; ++j) {
            m1.data[i][j] = 2;
            m2.data[i][j] = 2;
        }
    }

    m1 = m1 * m2;

    ASSERT_EQ(m1.data[0][0], 12);
    ASSERT_EQ(m1.data[0][1], 12);
    ASSERT_EQ(m1.data[0][2], 12);
    ASSERT_EQ(m1.data[1][0], 12);
    ASSERT_EQ(m1.data[1][1], 12);
    ASSERT_EQ(m1.data[1][2], 12);
    ASSERT_EQ(m1.data[2][0], 12);
    ASSERT_EQ(m1.data[2][1], 12);
    ASSERT_EQ(m1.data[2][2], 12);
}

TEST(test_matrix, scalar_multiplication) {
    solo::math::Matrix3d m1;
    for (uint16_t i = 0; i < 3; ++i) {
        for (uint16_t j = 0; j < 3; ++j) {
            m1.data[i][j] = 2;
        }
    }

    m1 *= 2;
    ASSERT_EQ(m1.data[0][0], 4);
    ASSERT_EQ(m1.data[0][1], 4);
    ASSERT_EQ(m1.data[0][2], 4);
    ASSERT_EQ(m1.data[1][0], 4);
    ASSERT_EQ(m1.data[1][1], 4);
    ASSERT_EQ(m1.data[1][2], 4);
    ASSERT_EQ(m1.data[2][0], 4);
    ASSERT_EQ(m1.data[2][1], 4);
    ASSERT_EQ(m1.data[2][2], 4);

    m1 *= 2;
    ASSERT_EQ(m1.data[0][0], 8);
    ASSERT_EQ(m1.data[0][1], 8);
    ASSERT_EQ(m1.data[0][2], 8);
    ASSERT_EQ(m1.data[1][0], 8);
    ASSERT_EQ(m1.data[1][1], 8);
    ASSERT_EQ(m1.data[1][2], 8);
    ASSERT_EQ(m1.data[2][0], 8);
    ASSERT_EQ(m1.data[2][1], 8);
    ASSERT_EQ(m1.data[2][2], 8);
}

TEST(test_matrix, in_place_transpose) {
    solo::math::Matrix3d m1;

    m1.data[0][0] = 3;
    m1.data[0][1] = 3;
    m1.data[0][2] = 3;

    m1.inPlaceTranspose();
    ASSERT_EQ(m1.data[0][0], 3);
    ASSERT_EQ(m1.data[0][1], 0);
    ASSERT_EQ(m1.data[0][2], 0);
    ASSERT_EQ(m1.data[1][0], 3);
    ASSERT_EQ(m1.data[1][1], 1);
    ASSERT_EQ(m1.data[1][2], 0);
    ASSERT_EQ(m1.data[2][0], 3);
    ASSERT_EQ(m1.data[2][1], 0);
    ASSERT_EQ(m1.data[2][2], 1);
}

}  // namespace