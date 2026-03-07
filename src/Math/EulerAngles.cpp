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

#include "Math/EulerAngles.h"

#include <stdexcept>
#include <string>  // NOLINT(misc-include-cleaner) std::to_string()

#include "Math/UnitConversions.h"

solo::math::EulerAngles::EulerAngles(float Psi, float Theta, float Phi)
    : m_f32Psi(Psi), m_f32Theta(Theta), m_f32Phi(Phi) {}

void solo::math::EulerAngles::SetPsiInRadians(float Psi) { m_f32Psi = Psi; }

float solo::math::EulerAngles::GetPsiInRadians() const { return m_f32Psi; }

void solo::math::EulerAngles::SetPsiInDegrees(float Psi) {
    m_f32Psi = DegToRad(Psi);
}

float solo::math::EulerAngles::GetPsiInDegrees() const {
    return RadToDeg(m_f32Psi);
}

void solo::math::EulerAngles::SetThetaInRadians(float Theta) {
    m_f32Theta = Theta;
}

float solo::math::EulerAngles::GetThetaInRadians() const { return m_f32Theta; }

void solo::math::EulerAngles::SetThetaInDegrees(float Theta) {
    m_f32Theta = DegToRad(Theta);
}

float solo::math::EulerAngles::GetThetaInDegrees() const {
    return RadToDeg(m_f32Theta);
}

void solo::math::EulerAngles::SetPhiInRadians(float Phi) { m_f32Phi = Phi; }

float solo::math::EulerAngles::GetPhiInRadians() const { return m_f32Phi; }

void solo::math::EulerAngles::SetPhiInDegrees(float Phi) {
    m_f32Phi = DegToRad(Phi);
}

float solo::math::EulerAngles::GetPhiInDegrees() const {
    return RadToDeg(m_f32Phi);
}

bool solo::math::EulerAngles::operator==(
    const solo::math::EulerAngles& Value) const {
    if (m_f32Psi != Value.m_f32Psi) return false;
    if (m_f32Theta != Value.m_f32Theta) return false;
    if (m_f32Phi != Value.m_f32Phi) return false;
    return true;
}

bool solo::math::EulerAngles::operator!=(
    const solo::math::EulerAngles& Value) const {
    return !(*this == Value);
}

solo::math::EulerAngles solo::math::EulerAngles::operator*(
    const solo::math::EulerAngles& Value) const {
    solo::math::EulerAngles tmp = *this;
    tmp.m_f32Psi *= Value.m_f32Psi;
    tmp.m_f32Theta *= Value.m_f32Theta;
    tmp.m_f32Phi *= Value.m_f32Phi;
    return tmp;
}

solo::math::EulerAngles solo::math::EulerAngles::operator+(
    const solo::math::EulerAngles& Value) const {
    solo::math::EulerAngles tmp = *this;
    tmp.m_f32Psi += Value.m_f32Psi;
    tmp.m_f32Theta += Value.m_f32Theta;
    tmp.m_f32Phi += Value.m_f32Phi;
    return tmp;
}

solo::math::EulerAngles& solo::math::EulerAngles::operator+=(
    const solo::math::EulerAngles& Value) {
    m_f32Psi += Value.m_f32Psi;
    m_f32Theta += Value.m_f32Theta;
    m_f32Phi += Value.m_f32Phi;
    return *this;
}

solo::math::EulerAngles solo::math::EulerAngles::operator-(
    const solo::math::EulerAngles& Value) const {
    solo::math::EulerAngles tmp = *this;
    tmp.m_f32Psi -= Value.m_f32Psi;
    tmp.m_f32Theta -= Value.m_f32Theta;
    tmp.m_f32Phi -= Value.m_f32Phi;
    return tmp;
}

solo::math::EulerAngles& solo::math::EulerAngles::operator-=(
    const solo::math::EulerAngles& Value) {
    m_f32Psi -= Value.m_f32Psi;
    m_f32Theta -= Value.m_f32Theta;
    m_f32Phi -= Value.m_f32Phi;
    return *this;
}

float& solo::math::EulerAngles::operator[](uint16_t i) {
    switch (i) {
        case 0:
            return m_f32Psi;
        case 1:
            return m_f32Theta;
        case 2:
            return m_f32Phi;
        default:
            throw std::out_of_range("Vector index: " + std::to_string(i) +
                                    " is out of range");
    }
}

const float& solo::math::EulerAngles::operator[](uint16_t i) const {
    switch (i) {
        case 0:
            return m_f32Psi;
        case 1:
            return m_f32Theta;
        case 2:
            return m_f32Phi;
        default:
            throw std::out_of_range("Vector index: " + std::to_string(i) +
                                    " is out of range");
    }
}
