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

#ifndef SOLO_MATH_WORLD_COORDINATES_H
#define SOLO_MATH_WORLD_COORDINATES_H

#include "Math/Vector.h"

namespace solo {
namespace math {

/// @brief Represents a 3D coordinate in world space using double precision
class WorldCoordinates {
   private:
    double mXValue{0};
    double mYValue{0};
    double mZValue{0};

   public:
    static constexpr uint16_t WOLRD_COORDINATE_SIZE{24};

    /// @brief Default constructor
    WorldCoordinates() = default;

    /// @brief Constructor with given coordinates
    /// @param x_value X coordinate
    /// @param y_value Y coordinate
    /// @param z_value Z coordinate
    WorldCoordinates(double x_value, double y_value, double z_value);

    /// @brief Default destructor
    virtual ~WorldCoordinates() = default;

    /// @brief Copy constructor
    WorldCoordinates(const WorldCoordinates&) = default;
    
    /// @brief Move constructor
    WorldCoordinates(WorldCoordinates&&) = default;
    
    /// @brief Copy assignment operator
    WorldCoordinates& operator=(const WorldCoordinates&) = default;
    
    /// @brief Move assignment operator
    WorldCoordinates& operator=(WorldCoordinates&&) = default;

    /// @brief Set the X coordinate
    /// @param x_value X value
    void SetX(double x_value);
    
    /// @brief Get the X coordinate
    /// @return X value
    double GetX() const;

    /// @brief Set the Y coordinate
    /// @param y_value Y value
    void SetY(double y_value);
    
    /// @brief Get the Y coordinate
    /// @return Y value
    double GetY() const;

    /// @brief Set the Z coordinate
    /// @param z_value Z value
    void SetZ(double z_value);
    
    /// @brief Get the Z coordinate
    /// @return Z value
    double GetZ() const;

    /// @brief Set all three coordinates
    /// @param x_value X value
    /// @param y_value Y value
    /// @param z_value Z value
    void Set(double x_value, double y_value, double z_value);

    /// @brief Calculate the Euclidean distance to another coordinate
    /// @param location Target coordinate
    /// @return Distance between points
    double GetDistance(const WorldCoordinates& location) const;

    /// @brief Linearly interpolate between two points
    /// @param source Starting coordinate
    /// @param destination Ending coordinate
    /// @param point Interpolation factor (0.0 to 1.0)
    /// @return Interpolated coordinate
    static WorldCoordinates Lerp(const WorldCoordinates& source,
                                 const WorldCoordinates& destination,
                                 float point);
                                 
    /// @brief Linearly interpolate towards a destination
    /// @param destination Ending coordinate
    /// @param point Interpolation factor (0.0 to 1.0)
    void Lerp(const WorldCoordinates& destination, float point);
    
    /// @brief Equality operator
    bool operator==(const WorldCoordinates& value) const;
    
    /// @brief Inequality operator
    bool operator!=(const WorldCoordinates& value) const;
    
    /// @brief Component-wise multiplication
    WorldCoordinates operator*(const WorldCoordinates& value) const;
    
    /// @brief Scalar multiplication (double)
    WorldCoordinates operator*(double value) const;
    
    /// @brief Scalar multiplication (float)
    WorldCoordinates operator*(float value) const;
    
    /// @brief Addition of two coordinates
    WorldCoordinates operator+(const WorldCoordinates& value) const;
    
    /// @brief Addition with a Vector
    WorldCoordinates operator+(const Vector& value) const;
    
    /// @brief Addition assignment with a Vector
    WorldCoordinates& operator+=(const Vector& value);
    
    /// @brief Assignment from a Vector
    WorldCoordinates& operator=(const Vector& value);
    
    /// @brief Subtraction of two coordinates
    WorldCoordinates operator-(const WorldCoordinates& value) const;
    
    /// @brief Subtraction assignment
    WorldCoordinates& operator-=(const WorldCoordinates& value);

    /// @brief Subscript access to coordinates
    /// @param position Index (0 - x, 1 - y, 2 - z)
    /// @throws std::out_of_range for invalid indices
    /// @return Reference to the coordinate value
    double& operator[](uint16_t position);
    
    /// @brief Const subscript access to coordinates
    /// @param position Index (0 - x, 1 - y, 2 - z)
    /// @throws std::out_of_range for invalid indices
    /// @return Const reference to the coordinate value
    const double& operator[](uint16_t position) const;
};

}  // namespace math
}  // namespace solo

#endif  // SOLO_MATH_WORLD_COORDINATES_H