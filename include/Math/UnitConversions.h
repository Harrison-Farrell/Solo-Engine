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

/// @brief Radians to degrees conversion
/// @tparam Type Numeric type
/// @param rad Value in radians
/// @return Value in degrees
template <class Type>
inline Type RadToDeg(Type rad) {
    return static_cast<Type>(rad * (constant::k2PI / std::numbers::pi));
}

/// @brief Degrees to radians conversion
/// @tparam Type Numeric type
/// @param deg Value in degrees
/// @return Value in radians
template <class Type>
inline Type DegToRad(Type deg) {
    return static_cast<Type>(deg * (std::numbers::pi / constant::k2PI));
}

/// @brief Feet to meters conversion
/// @tparam Type Numeric type
/// @param feet Value in feet
/// @return Value in meters
template <class Type>
inline Type FeetToMeters(Type feet) {
    return static_cast<Type>(feet / constant::kFeet2Meters);
}

/// @brief Meters to feet conversion
/// @tparam Type Numeric type
/// @param meters Value in meters
/// @return Value in feet
template <class Type>
inline Type MetersToFeet(Type meters) {
    return static_cast<Type>(meters * constant::kFeet2Meters);
}

/// @brief Decimal degrees to Degrees, Minutes, Seconds (DMS) conversion
/// @tparam Type Numeric type
/// @param decimal Value in decimal degrees
/// @param degrees_out Output parameter for degrees
/// @param minutes_out Output parameter for minutes
/// @param seconds_out Output parameter for seconds
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

/// @brief Degrees, Minutes, Seconds (DMS) to decimal degrees conversion
/// @tparam Type Numeric type
/// @param degrees Value for degrees
/// @param minutes Value for minutes
/// @param seconds Value for seconds
/// @return Value in decimal degrees
template <class Type>
inline Type DMSToDecimal(Type degrees, Type minutes, Type seconds) {
    return static_cast<Type>(degrees + (minutes / constant::kSixty) +
                             (seconds / constant::kThreeThousandSixHundred));
}
}  // namespace math
}  // namespace solo

#endif  // SOLO_MATH_UNIT_CONVERSIONS_H
