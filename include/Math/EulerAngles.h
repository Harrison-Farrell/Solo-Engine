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

/// @brief Class representing Euler angles (psi, theta, phi)
class EulerAngles {
   private:
    float mPsi{0};
    float mTheta{0};
    float mPhi{0};

   public:
    static constexpr uint16_t EULER_ANGLES_SIZE{12};

    /// @brief Default constructor
    EulerAngles() = default;

    /// @brief EularAngles class constuctor
    /// @param psi angle in radians
    /// @param theta angle in radians
    /// @param phi angle in radians
    EulerAngles(float psi, float theta, float phi);

    /// @brief Default destructor
    virtual ~EulerAngles() = default;

    /// @brief Copy constructor
    EulerAngles(const EulerAngles&) = default;
    
    /// @brief Move constructor
    EulerAngles(EulerAngles&&) = default;
    
    /// @brief Copy assignment operator
    EulerAngles& operator=(const EulerAngles&) = default;
    
    /// @brief Move assignment operator
    EulerAngles& operator=(EulerAngles&&) = default;

    /// @brief Set psi angle in radians
    /// @param psi Angle in radians
    void SetPsiInRadians(float psi);
    
    /// @brief Get psi angle in radians
    /// @return Angle in radians
    float GetPsiInRadians() const;
    
    /// @brief Set psi angle in degrees
    /// @param psi Angle in degrees
    void SetPsiInDegrees(float psi);
    
    /// @brief Get psi angle in degrees
    /// @return Angle in degrees
    float GetPsiInDegrees() const;

    /// @brief Set theta angle in radians
    /// @param theta Angle in radians
    void SetThetaInRadians(float theta);
    
    /// @brief Get theta angle in radians
    /// @return Angle in radians
    float GetThetaInRadians() const;
    
    /// @brief Set theta angle in degrees
    /// @param theta Angle in degrees
    void SetThetaInDegrees(float theta);
    
    /// @brief Get theta angle in degrees
    /// @return Angle in degrees
    float GetThetaInDegrees() const;

    /// @brief Set phi angle in radians
    /// @param phi Angle in radians
    void SetPhiInRadians(float phi);
    
    /// @brief Get phi angle in radians
    /// @return Angle in radians
    float GetPhiInRadians() const;
    
    /// @brief Set phi angle in degrees
    /// @param phi Angle in degrees
    void SetPhiInDegrees(float phi);
    
    /// @brief Get phi angle in degrees
    /// @return Angle in degrees
    float GetPhiInDegrees() const;

    /// @brief Equality operator
    /// @param value EulerAngles to compare against
    /// @return True if equal, false otherwise
    bool operator==(const EulerAngles& value) const;
    
    /// @brief Inequality operator
    /// @param value EulerAngles to compare against
    /// @return True if not equal, false otherwise
    bool operator!=(const EulerAngles& value) const;
    
    /// @brief Multiplication operator (element-wise)
    /// @param value EulerAngles to multiply by
    /// @return Resulting EulerAngles
    EulerAngles operator*(const EulerAngles& value) const;
    
    /// @brief Addition operator
    /// @param value EulerAngles to add
    /// @return Resulting EulerAngles
    EulerAngles operator+(const EulerAngles& value) const;
    
    /// @brief Addition assignment operator
    /// @param value EulerAngles to add
    /// @return Reference to this object
    EulerAngles& operator+=(const EulerAngles& value);
    
    /// @brief Subtraction operator
    /// @param value EulerAngles to subtract
    /// @return Resulting EulerAngles
    EulerAngles operator-(const EulerAngles& value) const;
    
    /// @brief Subtraction assignment operator
    /// @param value EulerAngles to subtract
    /// @return Reference to this object
    EulerAngles& operator-=(const EulerAngles& value);

    /// @brief Subscript operator (non-const)
    /// @param position Index (0=psi, 1=theta, 2=phi)
    /// @return Reference to the angle value
    float& operator[](uint16_t position);
    
    /// @brief Subscript operator (const)
    /// @param position Index (0=psi, 1=theta, 2=phi)
    /// @return Const reference to the angle value
    const float& operator[](uint16_t position) const;

    /// @brief Scalar multiplication operator
    /// @param lhs EulerAngles instance
    /// @param rhs Scalar value
    /// @return Resulting EulerAngles
    friend EulerAngles operator*(const EulerAngles& lhs, float rhs) {
        return EulerAngles{lhs.mPsi * rhs, lhs.mTheta * rhs, lhs.mPhi * rhs};
    }
    
    /// @brief Scalar multiplication operator
    /// @param lhs Scalar value
    /// @param rhs EulerAngles instance
    /// @return Resulting EulerAngles
    friend EulerAngles operator*(float lhs, const EulerAngles& rhs) {
        return rhs * lhs;
    }
};

}  // namespace math
}  // namespace solo

#endif  // SOLO_MATH_EULER_ANGLES_H
