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

#include <cstdint>
#include <stdexcept>
#include <string>  // NOLINT(misc-include-cleaner) std::to_string()

#include "Math/UnitConversions.h"

solo::math::EulerAngles::EulerAngles(float psi, float theta, float phi)
    : mPsi(psi), mTheta(theta), mPhi(phi) {}

void solo::math::EulerAngles::SetPsiInRadians(float psi) { mPsi = psi; }

float solo::math::EulerAngles::GetPsiInRadians() const { return mPsi; }

void solo::math::EulerAngles::SetPsiInDegrees(float psi) {
    mPsi = DegToRad(psi);
}

float solo::math::EulerAngles::GetPsiInDegrees() const {
    return RadToDeg(mPsi);
}

void solo::math::EulerAngles::SetThetaInRadians(float theta) { mTheta = theta; }

float solo::math::EulerAngles::GetThetaInRadians() const { return mTheta; }

void solo::math::EulerAngles::SetThetaInDegrees(float theta) {
    mTheta = DegToRad(theta);
}

float solo::math::EulerAngles::GetThetaInDegrees() const {
    return RadToDeg(mTheta);
}

void solo::math::EulerAngles::SetPhiInRadians(float phi) { mPhi = phi; }

float solo::math::EulerAngles::GetPhiInRadians() const { return mPhi; }

void solo::math::EulerAngles::SetPhiInDegrees(float phi) {
    mPhi = DegToRad(phi);
}

float solo::math::EulerAngles::GetPhiInDegrees() const {
    return RadToDeg(mPhi);
}

bool solo::math::EulerAngles::operator==(
    const solo::math::EulerAngles& value) const {
    if (mPsi != value.mPsi) {
        return false;
    }
    if (mTheta != value.mTheta) {
        return false;
    }
    if (mPhi != value.mPhi) {
        return false;
    }
    return true;
}

bool solo::math::EulerAngles::operator!=(
    const solo::math::EulerAngles& value) const {
    return !(*this == value);
}

solo::math::EulerAngles solo::math::EulerAngles::operator*(
    const solo::math::EulerAngles& value) const {
    solo::math::EulerAngles tmp = *this;
    tmp.mPsi *= value.mPsi;
    tmp.mTheta *= value.mTheta;
    tmp.mPhi *= value.mPhi;
    return tmp;
}

solo::math::EulerAngles solo::math::EulerAngles::operator+(
    const solo::math::EulerAngles& value) const {
    solo::math::EulerAngles tmp = *this;
    tmp.mPsi += value.mPsi;
    tmp.mTheta += value.mTheta;
    tmp.mPhi += value.mPhi;
    return tmp;
}

solo::math::EulerAngles& solo::math::EulerAngles::operator+=(
    const solo::math::EulerAngles& value) {
    mPsi += value.mPsi;
    mTheta += value.mTheta;
    mPhi += value.mPhi;
    return *this;
}

solo::math::EulerAngles solo::math::EulerAngles::operator-(
    const solo::math::EulerAngles& value) const {
    solo::math::EulerAngles tmp = *this;
    tmp.mPsi -= value.mPsi;
    tmp.mTheta -= value.mTheta;
    tmp.mPhi -= value.mPhi;
    return tmp;
}

solo::math::EulerAngles& solo::math::EulerAngles::operator-=(
    const solo::math::EulerAngles& value) {
    mPsi -= value.mPsi;
    mTheta -= value.mTheta;
    mPhi -= value.mPhi;
    return *this;
}

float& solo::math::EulerAngles::operator[](uint16_t position) {
    switch (position) {
        case 0:
            return mPsi;
        case 1:
            return mTheta;
        case 2:
            return mPhi;
        default:
            throw std::out_of_range(
                "Vector index: " + std::to_string(position) +
                " is out of range");
    }
}

const float& solo::math::EulerAngles::operator[](uint16_t position) const {
    switch (position) {
        case 0:
            return mPsi;
        case 1:
            return mTheta;
        case 2:
            return mPhi;
        default:
            throw std::out_of_range(
                "Vector index: " + std::to_string(position) +
                " is out of range");
    }
}
