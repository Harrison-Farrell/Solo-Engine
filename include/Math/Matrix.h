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

#ifndef SOLO_MATH_MATRIX_H
#define SOLO_MATH_MATRIX_H

#include <array>

namespace solo {
namespace math {

/**
 * @brief Represents a 3D vector.
 */
class Vector3 {
public:
    double x, y, z;

    Vector3();
    Vector3(double x, double y, double z);

    /**
     * @brief Adds another vector to this vector.
     * @param other The vector to add.
     * @return The resulting vector.
     */
    Vector3 operator+(const Vector3& other) const;

    /**
     * @brief Adds and assigns another vector to this vector.
     * @param other The vector to add.
     * @return Reference to this vector.
     */
    Vector3& operator+=(const Vector3& other);

    /**
     * @brief Multiplies this vector by a scalar.
     * @param scalar The scalar to multiply by.
     * @return The resulting vector.
     */
    Vector3 operator*(double scalar) const;

    /**
     * @brief Calculates the dot product of this vector and another.
     * @param other The other vector.
     * @return The dot product.
     */
    double dot(const Vector3& other) const;

    /**
     * @brief Calculates the cross product of this vector and another.
     * @param other The other vector.
     * @return The resulting cross product vector.
     */
    Vector3 cross(const Vector3& other) const;
};

// Forward declaration of Matrix3 and Matrix4 (if needed later)
class Matrix3;
class Matrix4;

/**
 * @brief Multiplies a Vector3 by a Matrix3.
 * @param vec The vector.
 * @param mat The 3x3 matrix.
 * @return The resulting transformed vector.
 */
Vector3 operator*(const Vector3& vec, const Matrix3& mat);

/**
 * @brief Multiplies a Matrix3 by a Vector3.
 * @param mat The 3x3 matrix.
 * @param vec The vector.
 * @return The resulting transformed vector.
 */
Vector3 operator*(const Matrix3& mat, const Vector3& vec);

/**
 * @brief Represents a 3x3 Matrix and provides static calculation methods.
 */
class Matrix3 {
public:
    // 3x3 matrix data stored in row-major order
    std::array<double, 9> data;

    Matrix3();

    /**
     * @brief Returns an identity matrix.
     * @return Identity Matrix3.
     */
    static Matrix3 identity();

    /**
     * @brief Multiplies two matrices resulting in a new matrix.
     * @param a The left matrix.
     * @param b The right matrix.
     * @return The resulting matrix.
     */
    static Matrix3 multiply(const Matrix3& a, const Matrix3& b);

    /**
     * @brief Adds two matrices.
     * @param a The first matrix.
     * @param b The second matrix.
     * @return The resulting matrix.
     */
    static Matrix3 add(const Matrix3& a, const Matrix3& b);

    /**
     * @brief Subtracts matrix b from matrix a.
     * @param a The first matrix.
     * @param b The second matrix.
     * @return The resulting matrix.
     */
    static Matrix3 subtract(const Matrix3& a, const Matrix3& b);

    /**
     * @brief Transposes the given matrix.
     * @param a The matrix to transpose.
     * @return The resulting transposed matrix.
     */
    static Matrix3 transpose(const Matrix3& a);
};

/**
 * @brief Represents a 4x4 Matrix and provides static calculation methods.
 */
class Matrix4 {
public:
    // 4x4 matrix data stored in row-major order
    std::array<double, 16> data;

    Matrix4();

    /**
     * @brief Returns an identity matrix.
     * @return Identity Matrix4.
     */
    static Matrix4 identity();

    /**
     * @brief Multiplies two matrices resulting in a new matrix.
     * @param a The left matrix.
     * @param b The right matrix.
     * @return The resulting matrix.
     */
    static Matrix4 multiply(const Matrix4& a, const Matrix4& b);

    /**
     * @brief Adds two matrices.
     * @param a The first matrix.
     * @param b The second matrix.
     * @return The resulting matrix.
     */
    static Matrix4 add(const Matrix4& a, const Matrix4& b);

    /**
     * @brief Subtracts matrix b from matrix a.
     * @param a The first matrix.
     * @param b The second matrix.
     * @return The resulting matrix.
     */
    static Matrix4 subtract(const Matrix4& a, const Matrix4& b);

    /**
     * @brief Transposes the given matrix.
     * @param a The matrix to transpose.
     * @return The resulting transposed matrix.
     */
    static Matrix4 transpose(const Matrix4& a);
};

} // namespace math
} // namespace solo

#endif // SOLO_MATH_MATRIX_H
