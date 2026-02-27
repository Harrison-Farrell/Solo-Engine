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

#ifndef SOLO_MATH_VECTOR_H
#define SOLO_MATH_VECTOR_H

#include <stdint.h>

namespace solo {
namespace math {

/// @brief Class for mathematical vector in 3D space
/// X-axis
/// Y-axis
/// Z-axis
class Vector {
   public:
    /// @brief Construct a Vector object
    Vector() = default;

    /// @brief Construct a Vector object
    /// @param x-axis float
    /// @param y-axis float
    /// @param z-axis float
    Vector(float x, float y, float z);

    /// @brief Deconstruct the Vector object
    ~Vector() = default;

    /// @brief Set x axis value
    /// @param x value
    void SetX(float x) { x_ = x; }

    /// @brief Get x axis value
    /// @return x value
    float GetX() { return x_; }

    /// @brief Set y axis value
    /// @param y value
    void SetY(float y) { y_ = y; }

    /// @brief Get y axis value
    /// @return y value
    float GetY() { return y_; }

    /// @brief Set z axis value
    /// @param z value
    void SetZ(float z) { z_ = z; }

    /// @brief Get z axis value
    /// @return z value
    float GetZ() { return z_; }

    /// @brief Set all three points of the vector
    /// @param x value
    /// @param y value
    /// @param z value
    void Set(float x, float y, float z);

    /// @brief Calculates and returns the magnitude or length.
    /// @return magnitude
    float GetMagnitude() const;

    /// @brief Calculates the distance from this vector to an other.
    /// @param vec to calculate distance to
    /// @return float distance
    float GetDistance(const Vector& vec);

    bool operator==(const Vector& Value) const;
    bool operator!=(const Vector& Value) const;
    Vector operator*(const Vector& Value) const;
    Vector operator*(double Value) const;
    Vector operator*(float Value) const;
    Vector operator+(const Vector& Value) const;
    Vector& operator+=(const Vector& Value);
    Vector operator-(const Vector& Value) const;
    Vector& operator-=(const Vector& Value);

    float& operator[](uint16_t i);
    const float& operator[](uint16_t i) const;

   protected:
    float x_{0};
    float y_{0};
    float z_{0};
};
}  // namespace math
}  // namespace solo

#endif  // SOLO_MATH_VECTOR_H