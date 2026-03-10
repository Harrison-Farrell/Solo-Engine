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

#ifndef SOLO_MATH_EULER_ANGLES_H
#define SOLO_MATH_EULER_ANGLES_H

#include <stdint.h>

namespace solo {
namespace math {

class EulerAngles {
   private:
    float mPsi{0};
    float mTheta{0};
    float mPhi{0};

   public:
    static constexpr uint16_t EULER_ANGLES_SIZE{12};

    EulerAngles() = default;

    // In Radians
    EulerAngles(float psi, float theta, float phi);

    virtual ~EulerAngles() = default;

    EulerAngles(const EulerAngles&) = default;
    EulerAngles(EulerAngles&&) = default;
    EulerAngles& operator=(const EulerAngles&) = default;
    EulerAngles& operator=(EulerAngles&&) = default;

    void SetPsiInRadians(float psi);
    float GetPsiInRadians() const;
    void SetPsiInDegrees(float psi);
    float GetPsiInDegrees() const;

    void SetThetaInRadians(float theta);
    float GetThetaInRadians() const;
    void SetThetaInDegrees(float theta);
    float GetThetaInDegrees() const;

    void SetPhiInRadians(float phi);
    float GetPhiInRadians() const;
    void SetPhiInDegrees(float phi);
    float GetPhiInDegrees() const;

    bool operator==(const EulerAngles& value) const;
    bool operator!=(const EulerAngles& value) const;
    EulerAngles operator*(const EulerAngles& value) const;
    EulerAngles operator+(const EulerAngles& value) const;
    EulerAngles& operator+=(const EulerAngles& value);
    EulerAngles operator-(const EulerAngles& value) const;
    EulerAngles& operator-=(const EulerAngles& value);

    float& operator[](uint16_t position);
    const float& operator[](uint16_t position) const;

    friend EulerAngles operator*(const EulerAngles& lhs, float rhs) {
        return EulerAngles{lhs.mPsi * rhs, lhs.mTheta * rhs, lhs.mPhi * rhs};
    }
    friend EulerAngles operator*(float lhs, const EulerAngles& rhs) {
        return rhs * lhs;
    }
};

}  // namespace math
}  // namespace solo

#endif  // SOLO_MATH_EULER_ANGLES_H
