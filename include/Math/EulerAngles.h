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
   protected:
    float m_f32Psi{0};

    float m_f32Theta{0};

    float m_f32Phi{0};

   public:
    static constexpr uint16_t EULER_ANGLES_SIZE{12};

    EulerAngles() = default;

    // In Radians
    EulerAngles(float Psi, float Theta, float Phi);

    virtual ~EulerAngles() = default;

    void SetPsiInRadians(float Psi);
    float GetPsiInRadians() const;
    void SetPsiInDegrees(float Psi);
    float GetPsiInDegrees() const;

    void SetThetaInRadians(float Theta);
    float GetThetaInRadians() const;
    void SetThetaInDegrees(float Theta);
    float GetThetaInDegrees() const;

    void SetPhiInRadians(float Phi);
    float GetPhiInRadians() const;
    void SetPhiInDegrees(float Phi);
    float GetPhiInDegrees() const;

    bool operator==(const EulerAngles& Value) const;
    bool operator!=(const EulerAngles& Value) const;
    EulerAngles operator*(const EulerAngles& Value) const;
    EulerAngles operator+(const EulerAngles& Value) const;
    EulerAngles& operator+=(const EulerAngles& Value);
    EulerAngles operator-(const EulerAngles& Value) const;
    EulerAngles& operator-=(const EulerAngles& Value);

    float& operator[](uint16_t i);
    const float& operator[](uint16_t i) const;

    friend EulerAngles operator*(const EulerAngles& lhs, float rhs) {
        return EulerAngles{lhs.m_f32Psi * rhs, lhs.m_f32Theta * rhs,
                           lhs.m_f32Phi * rhs};
    }
    friend EulerAngles operator*(float lhs, const EulerAngles& rhs) {
        return rhs * lhs;
    }
};

}  // namespace math
}  // namespace solo

#endif  // SOLO_MATH_EULER_ANGLES_H
