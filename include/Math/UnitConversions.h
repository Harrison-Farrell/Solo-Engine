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

namespace constant {
static constexpr double k2PI = 180.0;
static constexpr double kFeet2Meters = 3.2808;
static constexpr double kSixty = 60.0;
static constexpr double kThreeThousandSixHundred = 3600;
}  // namespace constant

/// @brief Radians to Degrees conversion
/// @tparam Type
/// @param Rad
/// @return
template <class Type>
inline Type RadToDeg(Type rad) {
    return static_cast<Type>(rad * (constant::k2PI / std::numbers::pi));
}

/// @brief Degrees to Radians conversion
/// @tparam Type
/// @param Deg
/// @return
template <class Type>
inline Type DegToRad(Type deg) {
    return static_cast<Type>(deg * (std::numbers::pi / constant::k2PI));
}

template <class Type>
inline Type FeetToMeters(Type feet) {
    return static_cast<Type>(feet / constant::kFeet2Meters);
}

template <class Type>
inline Type MetersToFeet(Type meters) {
    return static_cast<Type>(meters * constant::kFeet2Meters);
}

template <class Type>
inline void DecimalToDMS(Type decimal, Type& degrees_out, Type& minutes_out,
                         Type& seconds_out) {
    decimal = std::abs(decimal);  // Make sure the value is not negative
    degrees_out = static_cast<Type>(static_cast<uint32_t>(decimal));
    decimal -= degrees_out;  // Degrees

    minutes_out = static_cast<Type>(decimal * constant::kSixty);

    decimal =
        minutes_out - static_cast<Type>(static_cast<uint32_t>(minutes_out));

    minutes_out =
        static_cast<Type>(static_cast<uint32_t>(minutes_out));    // Minutes
    seconds_out = static_cast<Type>(decimal * constant::kSixty);  // Seconds
}

template <class Type>
inline Type DMSToDecimal(Type degrees, Type minutes, Type seconds) {
    return static_cast<Type>(degrees + (minutes / constant::kSixty) +
                             (seconds / constant::kThreeThousandSixHundred));
}
}  // namespace math
}  // namespace solo

#endif  // SOLO_MATH_UNIT_CONVERSIONS_H
