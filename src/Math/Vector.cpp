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

#include <cmath>
#include <stdexcept>
#include <string>

solo::math::Vector::Vector(float x, float y, float z) : x_{x}, y_{y}, z_{z} {};

void solo::math::Vector::Set(float x, float y, float z) {
    x_ = x;
    y_ = y;
    z_ = z;
}

float solo::math::Vector::GetMagnitude() const {
    return sqrt((x_ * x_) + (y_ * y_) + (z_ * z_));
}

float solo::math::Vector::GetDistance(const solo::math::Vector& vec) {
    Vector v = *this - vec;
    return v.GetMagnitude();
}

bool solo::math::Vector::operator==(const solo::math::Vector& Value) const {
    if (x_ != Value.x_) return false;
    if (y_ != Value.y_) return false;
    if (z_ != Value.z_) return false;
    return true;
}

bool solo::math::Vector::operator!=(const solo::math::Vector& Value) const {
    return !(*this == Value);
}

solo::math::Vector solo::math::Vector::operator*(
    const solo::math::Vector& Value) const {
    solo::math::Vector tmp = *this;
    tmp.x_ *= Value.x_;
    tmp.y_ *= Value.y_;
    tmp.z_ *= Value.z_;
    return tmp;
}

solo::math::Vector solo::math::Vector::operator*(double Value) const {
    solo::math::Vector tmp = *this;
    tmp.x_ *= Value;
    tmp.y_ *= Value;
    tmp.z_ *= Value;
    return tmp;
}

solo::math::Vector solo::math::Vector::operator*(float Value) const {
    solo::math::Vector tmp = *this;
    tmp.x_ *= Value;
    tmp.y_ *= Value;
    tmp.z_ *= Value;
    return tmp;
}

solo::math::Vector solo::math::Vector::operator+(
    const solo::math::Vector& Value) const {
    solo::math::Vector tmp = *this;
    tmp.x_ += Value.x_;
    tmp.y_ += Value.y_;
    tmp.z_ += Value.z_;
    return tmp;
}

solo::math::Vector& solo::math::Vector::operator+=(
    const solo::math::Vector& Value) {
    x_ += Value.x_;
    y_ += Value.y_;
    z_ += Value.z_;
    return *this;
}

solo::math::Vector solo::math::Vector::operator-(
    const solo::math::Vector& Value) const {
    solo::math::Vector tmp = *this;
    tmp.x_ -= Value.x_;
    tmp.y_ -= Value.y_;
    tmp.z_ -= Value.z_;
    return tmp;
}

solo::math::Vector& solo::math::Vector::operator-=(
    const solo::math::Vector& Value) {
    x_ -= Value.x_;
    y_ -= Value.y_;
    z_ -= Value.z_;
    return *this;
}

float& solo::math::Vector::operator[](uint16_t i) {
    switch (i) {
        case 0:
            return x_;
        case 1:
            return y_;
        case 2:
            return z_;
        default:
            throw std::out_of_range("Vector index: " + std::to_string(i) +
                                    " is out of range");
    };
}

const float& solo::math::Vector::operator[](uint16_t i) const {
    switch (i) {
        case 0:
            return x_;
        case 1:
            return y_;
        case 2:
            return z_;
        default:
            throw std::out_of_range("Vector index: " + std::to_string(i) +
                                    " is out of range");
    }
}
