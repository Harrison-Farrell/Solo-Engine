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
    Vector(float x_value, float y_value, float z_value);

    /// @brief Deconstruct the Vector object
    ~Vector() = default;

    Vector(const Vector&) = default;
    Vector(Vector&&) = default;
    Vector& operator=(const Vector&) = default;
    Vector& operator=(Vector&&) = default;

    /// @brief Set x axis value
    /// @param x value
    void SetX(float x_value) { mXValue = x_value; }

    /// @brief Get x axis value
    /// @return x value
    float GetX() const { return mXValue; }

    /// @brief Set y axis value
    /// @param y value
    void SetY(float y_value) { mYValue = y_value; }

    /// @brief Get y axis value
    /// @return y value
    float GetY() const { return mYValue; }

    /// @brief Set z axis value
    /// @param z value
    void SetZ(float z_value) { mZValue = z_value; }

    /// @brief Get z axis value
    /// @return z value
    float GetZ() const { return mZValue; }

    /// @brief Set all three points of the vector
    /// @param x value
    /// @param y value
    /// @param z value
    void Set(float x_value, float y_value, float z_value);

    /// @brief Calculates and returns the magnitude or length.
    /// @return magnitude
    float GetMagnitude() const;

    /// @brief Calculates the distance from this vector to an other.
    /// @param vec to calculate distance to
    /// @return float distance
    float GetDistance(const Vector& vec) const;

    bool operator==(const Vector& value) const;
    bool operator!=(const Vector& value) const;
    Vector operator*(const Vector& value) const;
    Vector operator*(double value) const;
    Vector operator*(float value) const;
    Vector operator+(const Vector& value) const;
    Vector& operator+=(const Vector& value);
    Vector operator-(const Vector& value) const;
    Vector& operator-=(const Vector& value);

    float& operator[](uint16_t position);
    const float& operator[](uint16_t position) const;

   private:
    float mXValue{0};
    float mYValue{0};
    float mZValue{0};
};
}  // namespace math
}  // namespace solo

#endif  // SOLO_MATH_VECTOR_H