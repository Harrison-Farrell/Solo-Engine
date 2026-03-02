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
#include <stdexcept>
#include <string>

#include "Math/Vector.h"

solo::math::WorldCoordinates::WorldCoordinates(double X, double Y, double Z)
    : m_f64X(X), m_f64Y(Y), m_f64Z(Z) {}

void solo::math::WorldCoordinates::SetX(double X) { m_f64X = X; }

double solo::math::WorldCoordinates::GetX() const { return m_f64X; }

void solo::math::WorldCoordinates::SetY(double Y) { m_f64Y = Y; }

double solo::math::WorldCoordinates::GetY() const { return m_f64Y; }

void solo::math::WorldCoordinates::SetZ(double Z) { m_f64Z = Z; }

double solo::math::WorldCoordinates::GetZ() const { return m_f64Z; }

void solo::math::WorldCoordinates::Set(double X, double Y, double Z) {
    m_f64X = X;
    m_f64Y = Y;
    m_f64Z = Z;
}

double solo::math::WorldCoordinates::GetDistance(
    const solo::math::WorldCoordinates& Other) {
    solo::math::WorldCoordinates w = *this - Other;
    double f =
        (w.m_f64X * w.m_f64X) + (w.m_f64Y * w.m_f64Y) + (w.m_f64Z * w.m_f64Z);
    return std::sqrt(f);
}

solo::math::WorldCoordinates solo::math::WorldCoordinates::Lerp(
    const solo::math::WorldCoordinates& From,
    const solo::math::WorldCoordinates& To, float T) {
    return From + ((To - From) * T);
}

void solo::math::WorldCoordinates::Lerp(const solo::math::WorldCoordinates& To,
                                        float T) {
    *this = Lerp(*this, To, T);
}

bool solo::math::WorldCoordinates::operator==(
    const solo::math::WorldCoordinates& Value) const {
    if (m_f64X != Value.m_f64X) return false;
    if (m_f64Y != Value.m_f64Y) return false;
    if (m_f64Z != Value.m_f64Z) return false;
    return true;
}

bool solo::math::WorldCoordinates::operator!=(
    const solo::math::WorldCoordinates& Value) const {
    return !(*this == Value);
}

solo::math::WorldCoordinates solo::math::WorldCoordinates::operator*(
    const solo::math::WorldCoordinates& Value) const {
    solo::math::WorldCoordinates tmp = *this;
    tmp.m_f64X *= Value.m_f64X;
    tmp.m_f64Y *= Value.m_f64Y;
    tmp.m_f64Z *= Value.m_f64Z;
    return tmp;
}

solo::math::WorldCoordinates solo::math::WorldCoordinates::operator*(
    double Value) const {
    solo::math::WorldCoordinates tmp = *this;
    tmp.m_f64X *= Value;
    tmp.m_f64Y *= Value;
    tmp.m_f64Z *= Value;
    return tmp;
}

solo::math::WorldCoordinates solo::math::WorldCoordinates::operator*(
    float Value) const {
    solo::math::WorldCoordinates tmp = *this;
    tmp.m_f64X *= Value;
    tmp.m_f64Y *= Value;
    tmp.m_f64Z *= Value;
    return tmp;
}

solo::math::WorldCoordinates solo::math::WorldCoordinates::operator+(
    const solo::math::WorldCoordinates& Value) const {
    solo::math::WorldCoordinates tmp = *this;
    tmp.m_f64X += Value.m_f64X;
    tmp.m_f64Y += Value.m_f64Y;
    tmp.m_f64Z += Value.m_f64Z;
    return tmp;
}

solo::math::WorldCoordinates solo::math::WorldCoordinates::operator+(
    const Vector& Value) const {
    solo::math::WorldCoordinates tmp = *this;
    tmp.m_f64X += Value.GetX();
    tmp.m_f64Y += Value.GetY();
    tmp.m_f64Z += Value.GetZ();
    return tmp;
}

solo::math::WorldCoordinates& solo::math::WorldCoordinates::operator+=(
    const Vector& Value) {
    m_f64X += Value.GetX();
    m_f64Y += Value.GetY();
    m_f64Z += Value.GetZ();
    return *this;
}

const solo::math::WorldCoordinates& solo::math::WorldCoordinates::operator=(
    const Vector& Value) {
    m_f64X = Value.GetX();
    m_f64Y = Value.GetY();
    m_f64Z = Value.GetZ();
    return *this;
}

solo::math::WorldCoordinates solo::math::WorldCoordinates::operator-(
    const solo::math::WorldCoordinates& Value) const {
    solo::math::WorldCoordinates tmp = *this;
    tmp.m_f64X -= Value.m_f64X;
    tmp.m_f64Y -= Value.m_f64Y;
    tmp.m_f64Z -= Value.m_f64Z;
    return tmp;
}

solo::math::WorldCoordinates& solo::math::WorldCoordinates::operator-=(
    const solo::math::WorldCoordinates& Value) {
    m_f64X -= Value.m_f64X;
    m_f64Y -= Value.m_f64Y;
    m_f64Z -= Value.m_f64Z;
    return *this;
}

double& solo::math::WorldCoordinates::operator[](uint16_t i) {
    switch (i) {
        case 0:
            return m_f64X;
        case 1:
            return m_f64Y;
        case 2:
            return m_f64Z;
        default:
            throw std::out_of_range("Vector index: " + std::to_string(i) +
                                    " is out of range");
    }
}

const double& solo::math::WorldCoordinates::operator[](uint16_t i) const {
    switch (i) {
        case 0:
            return m_f64X;
        case 1:
            return m_f64Y;
        case 2:
            return m_f64Z;
        default:
            throw std::out_of_range("Vector index: " + std::to_string(i) +
                                    " is out of range");
    }
}
