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

#include "Math/Vector.h"

#include <cmath>
#include <cstdint>
#include <stdexcept>
#include <string>  // NOLINT(misc-include-cleaner) std::to_string()

solo::math::Vector::Vector(float x_value, float y_value, float z_value)
    : mXValue{x_value}, mYValue{y_value}, mZValue{z_value} {};

void solo::math::Vector::Set(float x_value, float y_value, float z_value) {
    mXValue = x_value;
    mYValue = y_value;
    mZValue = z_value;
}

float solo::math::Vector::GetMagnitude() const {
    return sqrt((mXValue * mXValue) + (mYValue * mYValue) +
                (mZValue * mZValue));
}

float solo::math::Vector::GetDistance(const solo::math::Vector& vec) const {
    const Vector return_distance = *this - vec;
    return return_distance.GetMagnitude();
}

bool solo::math::Vector::operator==(const solo::math::Vector& value) const {
    if (mXValue != value.mXValue) {
        return false;
    };
    if (mYValue != value.mYValue) {
        return false;
    };
    if (mZValue != value.mZValue) {
        return false;
    };
    return true;
}

bool solo::math::Vector::operator!=(const solo::math::Vector& value) const {
    return !(*this == value);
}

solo::math::Vector solo::math::Vector::operator*(
    const solo::math::Vector& value) const {
    solo::math::Vector tmp = *this;
    tmp.mXValue *= value.mXValue;
    tmp.mYValue *= value.mYValue;
    tmp.mZValue *= value.mZValue;
    return tmp;
}

solo::math::Vector solo::math::Vector::operator*(double value) const {
    solo::math::Vector tmp = *this;
    tmp.mXValue *= static_cast<float>(value);
    tmp.mYValue *= static_cast<float>(value);
    tmp.mZValue *= static_cast<float>(value);
    return tmp;
}

solo::math::Vector solo::math::Vector::operator*(float value) const {
    solo::math::Vector tmp = *this;
    tmp.mXValue *= value;
    tmp.mYValue *= value;
    tmp.mZValue *= value;
    return tmp;
}

solo::math::Vector solo::math::Vector::operator+(
    const solo::math::Vector& value) const {
    solo::math::Vector tmp = *this;
    tmp.mXValue += value.mXValue;
    tmp.mYValue += value.mYValue;
    tmp.mZValue += value.mZValue;
    return tmp;
}

solo::math::Vector& solo::math::Vector::operator+=(
    const solo::math::Vector& value) {
    mXValue += value.mXValue;
    mYValue += value.mYValue;
    mZValue += value.mZValue;
    return *this;
}

solo::math::Vector solo::math::Vector::operator-(
    const solo::math::Vector& value) const {
    solo::math::Vector tmp = *this;
    tmp.mXValue -= value.mXValue;
    tmp.mYValue -= value.mYValue;
    tmp.mZValue -= value.mZValue;
    return tmp;
}

solo::math::Vector& solo::math::Vector::operator-=(
    const solo::math::Vector& value) {
    mXValue -= value.mXValue;
    mYValue -= value.mYValue;
    mZValue -= value.mZValue;
    return *this;
}

float& solo::math::Vector::operator[](uint16_t position) {
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
    };
}

const float& solo::math::Vector::operator[](uint16_t position) const {
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
