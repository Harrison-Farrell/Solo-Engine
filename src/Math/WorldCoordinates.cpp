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

#include "Math/WorldCoordinates.h"

#include <cmath>
#include <cstdint>
#include <stdexcept>
#include <string>  // NOLINT(misc-include-cleaner) std::to_string()

#include "Math/Vector.h"

solo::math::WorldCoordinates::WorldCoordinates(double x_value, double y_value,
                                               double z_value)
    : mXValue(x_value), mYValue(y_value), mZValue(z_value) {}

void solo::math::WorldCoordinates::SetX(double x_value) { mXValue = x_value; }

double solo::math::WorldCoordinates::GetX() const { return mXValue; }

void solo::math::WorldCoordinates::SetY(double y_value) { mYValue = y_value; }

double solo::math::WorldCoordinates::GetY() const { return mYValue; }

void solo::math::WorldCoordinates::SetZ(double z_value) { mZValue = z_value; }

double solo::math::WorldCoordinates::GetZ() const { return mZValue; }

void solo::math::WorldCoordinates::Set(double x_value, double y_value,
                                       double z_value) {
    mXValue = x_value;
    mYValue = y_value;
    mZValue = z_value;
}

double solo::math::WorldCoordinates::GetDistance(
    const solo::math::WorldCoordinates& location) const {
    const solo::math::WorldCoordinates world = *this - location;
    const double x_y_z_squared = (world.mXValue * world.mXValue) +
                                 (world.mYValue * world.mYValue) +
                                 (world.mZValue * world.mZValue);
    return std::sqrt(x_y_z_squared);
}

solo::math::WorldCoordinates solo::math::WorldCoordinates::Lerp(
    const solo::math::WorldCoordinates& source,
    const solo::math::WorldCoordinates& destination, float point) {
    return source + ((destination - source) * point);
}

void solo::math::WorldCoordinates::Lerp(
    const solo::math::WorldCoordinates& destination, float point) {
    *this = Lerp(*this, destination, point);
}

bool solo::math::WorldCoordinates::operator==(
    const solo::math::WorldCoordinates& value) const {
    if (mXValue != value.mXValue) {
        return false;
    }
    if (mYValue != value.mYValue) {
        return false;
    }
    if (mZValue != value.mZValue) {
        return false;
    }
    return true;
}

bool solo::math::WorldCoordinates::operator!=(
    const solo::math::WorldCoordinates& value) const {
    return !(*this == value);
}

solo::math::WorldCoordinates solo::math::WorldCoordinates::operator*(
    const solo::math::WorldCoordinates& value) const {
    solo::math::WorldCoordinates tmp = *this;
    tmp.mXValue *= value.mXValue;
    tmp.mYValue *= value.mYValue;
    tmp.mZValue *= value.mZValue;
    return tmp;
}

solo::math::WorldCoordinates solo::math::WorldCoordinates::operator*(
    double value) const {
    solo::math::WorldCoordinates tmp = *this;
    tmp.mXValue *= value;
    tmp.mYValue *= value;
    tmp.mZValue *= value;
    return tmp;
}

solo::math::WorldCoordinates solo::math::WorldCoordinates::operator*(
    float value) const {
    solo::math::WorldCoordinates tmp = *this;
    tmp.mXValue *= value;
    tmp.mYValue *= value;
    tmp.mZValue *= value;
    return tmp;
}

solo::math::WorldCoordinates solo::math::WorldCoordinates::operator+(
    const solo::math::WorldCoordinates& value) const {
    solo::math::WorldCoordinates tmp = *this;
    tmp.mXValue += value.mXValue;
    tmp.mYValue += value.mYValue;
    tmp.mZValue += value.mZValue;
    return tmp;
}

solo::math::WorldCoordinates solo::math::WorldCoordinates::operator+(
    const Vector& value) const {
    solo::math::WorldCoordinates tmp = *this;
    tmp.mXValue += value.GetX();
    tmp.mYValue += value.GetY();
    tmp.mZValue += value.GetZ();
    return tmp;
}

solo::math::WorldCoordinates& solo::math::WorldCoordinates::operator+=(
    const Vector& value) {
    mXValue += value.GetX();
    mYValue += value.GetY();
    mZValue += value.GetZ();
    return *this;
}

solo::math::WorldCoordinates& solo::math::WorldCoordinates::operator=(
    const Vector& value) {
    mXValue = value.GetX();
    mYValue = value.GetY();
    mZValue = value.GetZ();
    return *this;
}

solo::math::WorldCoordinates solo::math::WorldCoordinates::operator-(
    const solo::math::WorldCoordinates& value) const {
    solo::math::WorldCoordinates tmp = *this;
    tmp.mXValue -= value.mXValue;
    tmp.mYValue -= value.mYValue;
    tmp.mZValue -= value.mZValue;
    return tmp;
}

solo::math::WorldCoordinates& solo::math::WorldCoordinates::operator-=(
    const solo::math::WorldCoordinates& value) {
    mXValue -= value.mXValue;
    mYValue -= value.mYValue;
    mZValue -= value.mZValue;
    return *this;
}

double& solo::math::WorldCoordinates::operator[](uint16_t position) {
    switch (position) {
        case 0:
            return mXValue;
        case 1:
            return mYValue;
        case 2:
            return mZValue;
        default:
            throw std::out_of_range(
                "Vector index: " + std::to_string(position) +
                " is out of range");
    }
}

const double& solo::math::WorldCoordinates::operator[](
    uint16_t position) const {
    switch (position) {
        case 0:
            return mXValue;
        case 1:
            return mYValue;
        case 2:
            return mZValue;
        default:
            throw std::out_of_range(
                "Vector index: " + std::to_string(position) +
                " is out of range");
    }
}
