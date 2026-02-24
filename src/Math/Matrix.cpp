/*
 * --------------------------------------------------------------------------
 * Author:      Harrison Farrell
 * Project:     Solo-Engine Simulation Engine
 * Copyright:   (c) 2026 Harrison Farrell. All Rights Reserved.
 *
 * Licensed under the GNU Affero General Public License v3.0 (AGPL-3.0).
 * This program is distributed WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See <https://www.gnu.org/licenses/agpl-3.0.html> for full details.
 * --------------------------------------------------------------------------
 */

#include "Math/Matrix.h"

namespace solo {
namespace math {

Vector3::Vector3() : x(0.0), y(0.0), z(0.0) {}

Vector3::Vector3(double x, double y, double z) : x(x), y(y), z(z) {}

Vector3 Vector3::operator+(const Vector3& other) const {
    return Vector3(x + other.x, y + other.y, z + other.z);
}

Vector3& Vector3::operator+=(const Vector3& other) {
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

Vector3 Vector3::operator*(double scalar) const {
    return Vector3(x * scalar, y * scalar, z * scalar);
}

double Vector3::dot(const Vector3& other) const {
    return x * other.x + y * other.y + z * other.z;
}

Vector3 Vector3::cross(const Vector3& other) const {
    return Vector3(y * other.z - z * other.y, z * other.x - x * other.z,
                   x * other.y - y * other.x);
}

Matrix3::Matrix3() { data.fill(0.0); }

Matrix3 Matrix3::identity() {
    Matrix3 result;
    result.data[0] = 1.0;
    result.data[4] = 1.0;
    result.data[8] = 1.0;
    return result;
}

Matrix3 Matrix3::multiply(const Matrix3& a, const Matrix3& b) {
    Matrix3 result;
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            double sum = 0.0;
            for (int k = 0; k < 3; ++k) {
                sum += a.data[row * 3 + k] * b.data[k * 3 + col];
            }
            result.data[row * 3 + col] = sum;
        }
    }
    return result;
}

Matrix3 Matrix3::add(const Matrix3& a, const Matrix3& b) {
    Matrix3 result;
    for (int i = 0; i < 9; ++i) {
        result.data[i] = a.data[i] + b.data[i];
    }
    return result;
}

Matrix3 Matrix3::subtract(const Matrix3& a, const Matrix3& b) {
    Matrix3 result;
    for (int i = 0; i < 9; ++i) {
        result.data[i] = a.data[i] - b.data[i];
    }
    return result;
}

Matrix3 Matrix3::transpose(const Matrix3& a) {
    Matrix3 result;
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            result.data[col * 3 + row] = a.data[row * 3 + col];
        }
    }
    return result;
}

Vector3 operator*(const Vector3& vec, const Matrix3& mat) {
    return Vector3(
        vec.x * mat.data[0] + vec.y * mat.data[3] + vec.z * mat.data[6],
        vec.x * mat.data[1] + vec.y * mat.data[4] + vec.z * mat.data[7],
        vec.x * mat.data[2] + vec.y * mat.data[5] + vec.z * mat.data[8]);
}

Vector3 operator*(const Matrix3& mat, const Vector3& vec) {
    return Vector3(
        mat.data[0] * vec.x + mat.data[1] * vec.y + mat.data[2] * vec.z,
        mat.data[3] * vec.x + mat.data[4] * vec.y + mat.data[5] * vec.z,
        mat.data[6] * vec.x + mat.data[7] * vec.y + mat.data[8] * vec.z);
}

Matrix4::Matrix4() {}
}  // namespace math
}  // namespace solo
