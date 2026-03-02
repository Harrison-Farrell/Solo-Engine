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
   protected:
    double m_f64X{0};

    double m_f64Y{0};

    double m_f64Z{0};

   public:
    static constexpr uint16_t WORLD_COORDINATES_SIZE{24};

    WorldCoordinates() = default;

    WorldCoordinates(double X, double Y, double Z);

    virtual ~WorldCoordinates() = default;

    void SetX(double X);
    double GetX() const;

    void SetY(double Y);
    double GetY() const;

    void SetZ(double Z);
    double GetZ() const;

    void Set(double X, double Y, double Z);

    double GetDistance(const WorldCoordinates& Other);

    static WorldCoordinates Lerp(const WorldCoordinates& From,
                                 const WorldCoordinates& To, float T);
    void Lerp(const WorldCoordinates& To, float T);
    bool operator==(const WorldCoordinates& Value) const;
    bool operator!=(const WorldCoordinates& Value) const;
    WorldCoordinates operator*(const WorldCoordinates& Value) const;
    WorldCoordinates operator*(double Value) const;
    WorldCoordinates operator*(float Value) const;
    WorldCoordinates operator+(const WorldCoordinates& Value) const;
    WorldCoordinates operator+(const Vector& Value) const;
    WorldCoordinates& operator+=(const Vector& Value);
    const WorldCoordinates& operator=(const Vector& Value);
    WorldCoordinates operator-(const WorldCoordinates& Value) const;
    WorldCoordinates& operator-=(const WorldCoordinates& Value);

    // Valid values 0 - X, 1 - Y, 2 - Z. throws OUT_OF_BOUNDS exception for any
    // other value.
    double& operator[](uint16_t i);
    const double& operator[](uint16_t i) const;
};

}  // namespace math
}  // namespace solo

#endif  // SOLO_MATH_WORLD_COORDINATES_H