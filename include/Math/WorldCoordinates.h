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

#include "Vector.h"

namespace solo {
namespace math {

class WorldCoordinates {
   private:
    double mXValue{0};
    double mYValue{0};
    double mZValue{0};

   public:
    static constexpr uint16_t WOLRD_COORDINATE_SIZE{24};

    WorldCoordinates() = default;

    WorldCoordinates(double x_value, double y_value, double z_value);

    virtual ~WorldCoordinates() = default;

    WorldCoordinates(const WorldCoordinates&) = default;
    WorldCoordinates(WorldCoordinates&&) = default;
    WorldCoordinates& operator=(const WorldCoordinates&) = default;
    WorldCoordinates& operator=(WorldCoordinates&&) = default;

    void SetX(double x_value);
    double GetX() const;

    void SetY(double y_value);
    double GetY() const;

    void SetZ(double z_value);
    double GetZ() const;

    void Set(double x_value, double y_value, double z_value);

    double GetDistance(const WorldCoordinates& location) const;

    static WorldCoordinates Lerp(const WorldCoordinates& source,
                                 const WorldCoordinates& destination,
                                 float point);
    void Lerp(const WorldCoordinates& destination, float point);
    bool operator==(const WorldCoordinates& value) const;
    bool operator!=(const WorldCoordinates& value) const;
    WorldCoordinates operator*(const WorldCoordinates& value) const;
    WorldCoordinates operator*(double value) const;
    WorldCoordinates operator*(float value) const;
    WorldCoordinates operator+(const WorldCoordinates& value) const;
    WorldCoordinates operator+(const Vector& value) const;
    WorldCoordinates& operator+=(const Vector& value);
    WorldCoordinates& operator=(const Vector& value);
    WorldCoordinates operator-(const WorldCoordinates& value) const;
    WorldCoordinates& operator-=(const WorldCoordinates& value);

    // Valid values 0 - x_value, 1 - y_value, 2 - z_value. throws OUT_OF_BOUNDS
    // exception for any other value.
    double& operator[](uint16_t position);
    const double& operator[](uint16_t position) const;
};

}  // namespace math
}  // namespace solo

#endif  // SOLO_MATH_WORLD_COORDINATES_H