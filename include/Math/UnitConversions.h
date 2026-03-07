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

#ifndef SOLO_MATH_UNIT_CONVERSIONS_H
#define SOLO_MATH_UNIT_CONVERSIONS_H

#include <cmath>
#include <numbers>

namespace solo {
namespace math {

/// @brief Radians to Degrees conversion
/// @tparam Type
/// @param Rad
/// @return
template <class Type>
inline Type RadToDeg(Type Rad) {
    return static_cast<Type>(Rad * (180.0 / std::numbers::pi));
}

/// @brief Degrees to Radians conversion
/// @tparam Type
/// @param Deg
/// @return
template <class Type>
inline Type DegToRad(Type Deg) {
    return static_cast<Type>(Deg * (std::numbers::pi / 180.0));
}

template <class Type>
inline Type FeetToMeters(Type Feet) {
    return static_cast<Type>(Feet / 3.2808);
}

template <class Type>
inline Type MetersToFeet(Type Meters) {
    return static_cast<Type>(Meters * 3.2808);
}

template <class Type>
inline void DecimalToDMS(Type Decimal, Type& DegOUT, Type& MinOUT,
                         Type& SecOUT) {
    Decimal = std::abs(Decimal);  // Make sure the value is not negative
    DegOUT = static_cast<Type>(static_cast<uint32_t>(Decimal));
    Decimal -= DegOUT;  // Degrees

    MinOUT = static_cast<Type>(Decimal * 60.0);

    Decimal = MinOUT - static_cast<Type>(static_cast<uint32_t>(MinOUT));

    MinOUT = static_cast<Type>(static_cast<uint32_t>(MinOUT));  // Minutes
    SecOUT = static_cast<Type>(Decimal * 60.0);                 // Seconds
}

template <class Type>
inline Type DMSToDecimal(Type Deg, Type Min, Type Sec) {
    return static_cast<Type>(Deg + (Min / 60.0) + (Sec / 3600.0));
}
}  // namespace math
}  // namespace solo

#endif  // SOLO_MATH_UNIT_CONVERSIONS_H
