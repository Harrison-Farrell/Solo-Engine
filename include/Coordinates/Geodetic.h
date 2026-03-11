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

#ifndef SOLO_COORDINATES_GEODETIC_H
#define SOLO_COORDINATES_GEODETIC_H

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <tuple>
#include <utility>

#include "Math/UnitConversions.h"

namespace solo {
namespace coordinate {

/// @enum Reference Ellipsoids
/// data taken from Wikipedia and DoD, WGS84, DMA TR 8350.2-B,1 Sept. 1991
enum class EllipsoidReference : uint8_t {
    Airy,                   // 1
    Airy_Modified,          // 2
    Australian_National,    // 3
    Bessel_1841,            // 4
    Bessel_1841_Namibia,    // 5
    Clarke_1866,            // 6
    Clarke_1880,            // 7
    Everest_Sabah_Sarawak,  // 8
    Everest_1830,           // 9
    Everest_1948,           // 10
    Everest_1956,           // 11
    Everest_1969,           // 12
    Fischer_1960,           // 13
    Fischer_1960_Modified,  // 14
    Fischer_1968,           // 15
    GRS_1980,               // 16
    Helmert_1906,           // 17
    Hough,                  // 18
    International_1924,     // 19
    Karsovsky_1940,         // 20
    SGS_1985,               // 21
    South_American_1969,    // 22
    Sphere_6371km,          // 23
    WGS_1960,               // 24
    WGS_1966,               // 25
    WGS_1972,               // 26
    WGS_1984                // 27
};

struct EllipsoidParameters {
    double major_axis;
    double minor_axis;
};

/// @brief Ellipsoid data table
/// data taken from Wikipedia and DoD, WGS84, DMA TR 8350.2-B,1 Sept. 1991
static constexpr EllipsoidParameters ELLIPSOID_DATA[] = {
    {6377563.396, 6356256.909},       // Airy
    {6377340.189, 6356034.448},       // Airy_Modified
    {6378160.000, 6356774.719},       // Australian_National
    {6377397.155, 6356078.963},       // Bessel_1841
    {6377483.865, 6356078.963},       // Bessel_1841_Namibia
    {6378206.400, 6356583.800},       // Clarke_1866
    {6378249.145, 6356514.870},       // Clarke_1880
    {6377298.556, 6356097.550},       // Everest_Sabah_Sarawak
    {6377276.345, 6356075.413},       // Everest_1830
    {6377304.063, 6356103.039},       // Everest_1948
    {6377301.243, 6356100.228},       // Everest_1956
    {6377295.664, 6356094.668},       // Everest_1969
    {6378166.000, 6356784.284},       // Fischer_1960
    {6378155.000, 6356773.320},       // Fischer_1960_Modified
    {6378150.000, 6356768.337},       // Fischer_1968
    {6378137.000, 6356752.314},       // GRS_1980
    {6378200.000, 6356818.170},       // Helmert_1906
    {6378270.000, 6356794.343},       // Hough
    {6378388.000, 6356911.946},       // International_1924
    {6378245.000, 6356863.019},       // Karsovsky_1940
    {6378136.000, 6356751.302},       // SGS_1985
    {6378160.000, 6356774.719},       // South_American_1969
    {6371000.0, 6371000.0},           // Sphere_6371km
    {6378165.000, 6356783.287},       // WGS_1960
    {6378145.000, 6356759.769},       // WGS_1966
    {6378135.000, 6356750.520},       // WGS_1972
    {6378137.000, 6356752.314245}     // WGS_1984
};

/// @brief Get the major and minor axes of an ellipsoid
/// @param reference Reference ellipsoid
/// @return Pair containing (major axis, minor axis)
template <class Type>
[[nodiscard]] constexpr std::pair<Type, Type> GetEllipsoidAxis(
    EllipsoidReference reference) {
    const auto& params = ELLIPSOID_DATA[static_cast<size_t>(reference)];
    return {static_cast<Type>(params.major_axis),
            static_cast<Type>(params.minor_axis)};
}

/// @brief Convert geodetic coordinates to geocentric coordinates
/// @param geodetic_latitude Geodetic latitude
/// @param geodetic_longitude Geodetic longitude
/// @param geodetic_height Geodetic height
/// @param reference Reference ellipsoid
/// @return Tuple containing (Geocentric X, Geocentric Y, Geocentric Z)
template <class Type>
[[nodiscard]] constexpr std::tuple<Type, Type, Type> GeodeticToGeocentric(
    Type geodetic_latitude, Type geodetic_longitude, Type geodetic_height,
    EllipsoidReference reference) {
    geodetic_latitude = solo::math::DegToRad(geodetic_latitude);
    geodetic_longitude = solo::math::DegToRad(geodetic_longitude);

    auto [major_axis, minor_axis] = GetEllipsoidAxis<Type>(reference);

    Type esq = (std::pow(major_axis, 2) - std::pow(minor_axis, 2)) /
               std::pow(major_axis, 2);
    Type V = major_axis /
             std::sqrt(1 - (esq * std::pow(std::sin(geodetic_latitude), 2)));

    Type geocentric_x = (V + geodetic_height) * std::cos(geodetic_latitude) *
                        std::cos(geodetic_longitude);
    Type geocentric_y = (V + geodetic_height) * std::cos(geodetic_latitude) *
                        std::sin(geodetic_longitude);
    Type geocentric_z =
        ((1 - esq) * V + geodetic_height) * std::sin(geodetic_latitude);

    return {geocentric_x, geocentric_y, geocentric_z};
}

/// @brief Convert geocentric coordinates to geodetic coordinates
/// @param geocentric_x Geocentric X
/// @param geocentric_y Geocentric Y
/// @param geocentric_z Geocentric Z
/// @param reference Reference ellipsoid
/// @return Tuple containing (Geodetic latitude, Geodetic longitude, Geodetic
/// height)
template <class Type>
[[nodiscard]] constexpr std::tuple<Type, Type, Type> GeocentricToGeodetic(
    Type geocentric_x, Type geocentric_y, Type geocentric_z,
    EllipsoidReference reference) {
    // This is the 'closed form solution'
    // equations described by
    // https://microem.ru/files/2012/08/GPS.G1-X-00006.pdf and many other places
    // on the web. start at wikipedia, "ECEF"

    auto [first, second] = GetEllipsoidAxis<Type>(reference);

    Type const e2 = (first * first - second * second) /
                    (first * first);  // eccentricity (first)
    Type const e_prime2 = (first * first - second * second) /
                          (second * second);  // eccentricity (second)

    // 'auxiliary values'
    Type const p =
        std::sqrt(geocentric_x * geocentric_x + geocentric_y * geocentric_y);
    Type const theta =
        static_cast<Type>(std::atan2((geocentric_z * first), (p * second)));

    // latitude
    Type geodetic_latitude = static_cast<Type>(std::atan2(
        (geocentric_z + (e_prime2)*second * std::pow(std::sin(theta), 3)),
        (p - (e2 * first * std::pow(std::cos(theta), 3)))));

    // Radius of curvature
    Type const N = first / std::sqrt(1 - e2 * std::sin(geodetic_latitude) *
                                             std::sin(geodetic_latitude));

    // altitude
    Type cosLat = std::cos(geodetic_latitude);
    Type geodetic_height = 0;
    Type const COS_THRESHOLD = 0.0000001;
    if ((cosLat > -COS_THRESHOLD) &&
        (cosLat < COS_THRESHOLD))  // Very near the poles
        geodetic_height = std::abs(geocentric_z) - second;
    else
        geodetic_height = p / cosLat - N;

    // longitude
    Type geodetic_longitude =
        static_cast<Type>(std::atan2(geocentric_y, geocentric_x));

    geodetic_longitude = solo::math::RadToDeg(geodetic_longitude);
    geodetic_latitude = solo::math::RadToDeg(geodetic_latitude);

    return {geodetic_latitude, geodetic_longitude, geodetic_height};
}

/// @brief Rotate first vector about an axis
/// @param destination Destination vector
/// @param source Source vector
/// @param axis Axis vector
/// @param angle Angle in radians
template <class Type>
constexpr void RotateAboutAxis(Type destination[3], Type const source[3],
                               Type const axis[3], Type angle) {
    double st = std::sin(angle);
    double ct = std::cos(angle);

    destination[0] = static_cast<Type>(
        (1.0 - ct) *
            (axis[0] * axis[0] * source[0] + axis[0] * axis[1] * source[1] +
             axis[0] * axis[2] * source[2]) +
        ct * source[0] + st * (axis[1] * source[2] - axis[2] * source[1]));
    destination[1] = static_cast<Type>(
        (1.0 - ct) *
            (axis[0] * axis[1] * source[0] + axis[1] * axis[1] * source[1] +
             axis[1] * axis[2] * source[2]) +
        ct * source[1] + st * (axis[2] * source[0] - axis[0] * source[2]));
    destination[2] = static_cast<Type>(
        (1.0 - ct) *
            (axis[0] * axis[2] * source[0] + axis[1] * axis[2] * source[1] +
             axis[2] * axis[2] * source[2]) +
        ct * source[2] + st * (axis[0] * source[1] - axis[1] * source[0]));
}

/// @brief Cross product of two vectors
/// @param destination Destination vector
/// @param first First vector
/// @param second Second vector
template <class Type>
constexpr void Cross(Type destination[3], Type const first[3],
                     Type const second[3]) {
    destination[0] = first[1] * second[2] - second[1] * first[2];
    destination[1] = second[0] * first[2] - first[0] * second[2];
    destination[2] = first[0] * second[1] - second[0] * first[1];
}

/// @brief Dot product of two vectors
/// @param first First vector
/// @param second Second vector
/// @return Dot product
template <class Type>
[[nodiscard]] constexpr Type Dot(Type const first[3], Type const second[3]) {
    return first[0] * second[0] + first[1] * second[1] + first[2] * second[2];
}

/// @brief Convert heading, pitch, and roll to Euler angles
/// @param heading Heading in radians
/// @param pitch Pitch in radians
/// @param roll Roll in radians
/// @param Lat Latitude in radians
/// @param Lon Longitude in radians
/// @return Tuple containing (Psi, Theta, Phi) in radians
template <class Type>
[[nodiscard]] constexpr std::tuple<Type, Type, Type> HeadingPitchRollToEuler(
    Type heading, Type pitch, Type roll, Type Lat, Type Lon) {
    // local NED
    constexpr Type E0[3] = {0.0, 1.0, 0.0};
    constexpr Type N0[3] = {0.0, 0.0, 1.0};

    Type E[3];
    RotateAboutAxis(E, E0, N0, Lon);

    Type const me[3] = {-E[0], -E[1], -E[2]};

    Type N[3];
    RotateAboutAxis(N, N0, me, Lat);

    Type D[3];
    Cross(D, N, E);

    /*
     *  Orientation
     */
    // rotate about D by heading
    Type N1[3], E1[3], D1[3];
    RotateAboutAxis(N1, N, D, heading);
    RotateAboutAxis(E1, E, D, heading);
    std::copy_n(D, 3, D1);

    // rotate about E1 vector by pitch
    Type N2[3], E2[3], D2[3];
    RotateAboutAxis(N2, N1, E1, pitch);
    std::copy_n(E1, 3, E2);
    RotateAboutAxis(D2, D1, E1, pitch);

    // rotate about N2 by roll
    Type N3[3], E3[3], D3[3];
    std::copy_n(N2, 3, N3);
    RotateAboutAxis(E3, E2, N2, roll);
    RotateAboutAxis(D3, D2, N2, roll);

    // calculate angles from vectors
    constexpr Type x0[3] = {1.0, 0.0, 0.0};
    constexpr Type y0[3] = {0.0, 1.0, 0.0};
    constexpr Type z0[3] = {0.0, 0.0, 1.0};

    Type Psi = static_cast<Type>(std::atan2(Dot(N3, y0), Dot(N3, x0)));
    Type Theta = static_cast<Type>(
        std::atan2(-Dot(N3, z0), std::hypot(Dot(N3, x0), Dot(N3, y0))));

    Type y2[3];
    RotateAboutAxis(y2, y0, z0, Psi);

    Type z2[3];
    RotateAboutAxis(z2, z0, y2, Theta);

    Type Phi = static_cast<Type>(std::atan2(Dot(E3, z2), Dot(E3, y2)));
    return {Psi, Theta, Phi};
}

/// @brief Convert Euler angles to heading, pitch, and roll
/// @param Lat Latitude in radians
/// @param Lon Longitude in radians
/// @param Psi Psi angle in radians
/// @param Theta Theta angle in radians
/// @param Phi Phi angle in radians
/// @return Tuple containing (Heading, Pitch, Roll) in radians
template <class Type>
[[nodiscard]] constexpr std::tuple<Type, Type, Type> EulerToHeadingPitchRoll(
    Type Lat, Type Lon, Type Psi, Type Theta, Type Phi) {
    // local NED vectors in ECEF coordinate frame
    Type N[3];
    Type E[3];
    Type D[3];

    // Calculate NED from lat and lon
    // local NED
    constexpr Type E0[3] = {0.0, 1.0, 0.0};
    constexpr Type N0[3] = {0.0, 0.0, 1.0};

    // 'E'
    RotateAboutAxis(E, E0, N0, Lon);

    Type const me[3] = {-E[0], -E[1], -E[2]};

    // 'N'
    RotateAboutAxis(N, N0, me, Lat);

    // 'D'
    Cross(D, N, E);

    /*
     *  Orientation:
     *    input : (x0,y0,z0)=(N,E,D) and (Psi,Theta,Phi Euler angles)
     *    output: (x3,y3,z3)=body vectors in local frame
     */
    // rotate about Z by Psi
    constexpr Type X[3] = {1.0, 0.0, 0.0};
    constexpr Type Y[3] = {0.0, 1.0, 0.0};
    constexpr Type Z[3] = {0.0, 0.0, 1.0};

    Type X1[3], Y1[3], Z1[3];
    RotateAboutAxis(X1, X, Z, Psi);
    RotateAboutAxis(Y1, Y, Z, Psi);
    std::copy_n(Z, 3, Z1);

    // rotate about Y1 vector by Theta
    Type X2[3], Y2[3], Z2[3];
    RotateAboutAxis(X2, X1, Y1, Theta);
    std::copy_n(Y1, 3, Y2);
    RotateAboutAxis(Z2, Z1, Y1, Theta);

    // rotate about X2 by Phi
    Type X3[3], Y3[3], Z3[3];
    std::copy_n(X2, 3, X3);
    RotateAboutAxis(Y3, Y2, X2, Phi);
    RotateAboutAxis(Z3, Z2, X2, Phi);

    // calculate angles from vectors
    Type x0[3], y0[3], z0[3];
    std::copy_n(N, 3, x0);
    std::copy_n(E, 3, y0);
    std::copy_n(D, 3, z0);

    Type heading = static_cast<Type>(std::atan2(Dot(X3, y0), Dot(X3, x0)));
    Type pitch = static_cast<Type>(
        std::atan2(-Dot(X3, z0), std::hypot(Dot(X3, x0), Dot(X3, y0))));

    Type y2[3];
    RotateAboutAxis(y2, y0, z0, heading);

    Type z2[3];
    RotateAboutAxis(z2, z0, y2, pitch);

    Type roll = static_cast<Type>(std::atan2(Dot(Y3, z2), Dot(Y3, y2)));
    return {heading, pitch, roll};
}
} // coordinate
} // solo

#endif  // SOLO_COORDINATES_GEODETIC_H