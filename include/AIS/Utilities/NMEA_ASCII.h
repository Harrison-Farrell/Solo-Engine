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

#ifndef SOLO_AIS_UTILITIES_NMEA_ASCII_H
#define SOLO_AIS_UTILITIES_NMEA_ASCII_H

#include <bitset>
#include <string>

namespace solo {
namespace ais {
namespace utilities {

template <std::size_t N>
std::string ToNmeaAscii(const std::bitset<N>& bits) {
    constexpr std::size_t bits_per_char = 6;
    constexpr std::size_t rounding_offset = bits_per_char - 1;
    constexpr unsigned char ascii_offset_lower = 48;
    constexpr unsigned char ascii_offset_upper = 56;
    constexpr unsigned char threshold = 40;

    std::string result;
    std::size_t num_chars = (N + rounding_offset) / bits_per_char;
    result.reserve(num_chars);

    for (std::size_t i = 0; i < num_chars; ++i) {
        unsigned char val = 0;
        for (std::size_t j = 0; j < bits_per_char; ++j) {
            std::size_t current_bit = (i * bits_per_char) + j;
            if (N > current_bit) {
                std::size_t bit_index = N - 1 - current_bit;
                if (bits.test(bit_index)) {
                    val |=
                        static_cast<unsigned char>(1 << (rounding_offset - j));
                }
            }
        }

        if (val < threshold) {
            val += ascii_offset_lower;
        } else {
            val += ascii_offset_upper;
        }
        result.push_back(static_cast<char>(val));
    }

    return result;
}

}  // namespace utilities
}  // namespace ais
}  // namespace solo

#endif  // SOLO_AIS_UTILITIES_NMEA_ASCII_H
