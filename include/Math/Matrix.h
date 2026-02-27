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

#include <stdint.h>

#include <algorithm>
#include <cstring>
#include <iostream>
#include <memory>

#include "Vector.h"

namespace solo {
namespace math {

/**
 * @brief Templated class for performing Matrix mathematics
 * @param Class Type
 * @param Number of columns
 * @param Number of rows
 */
template <class Type, uint8_t cols, uint8_t rows>
class Matrix {
   public:
    Type data[cols][rows];

    /**
     * @brief Default on constructor
     * @note Matrix initially set as an identity matrix
     */
    Matrix() {
        for (uint16_t i = 0; i < cols; ++i) {
            for (uint16_t j = 0; j < rows; ++j) {
                if (i == j)
                    data[i][j] = 1;
                else
                    data[i][j] = 0;
            }
        }
    };

    /**
     * @brief Addition binary operator overload.
     * @param Matrix
     */
    Matrix operator+(const Matrix& Value) {
        Matrix m = *this;
        for (uint16_t i = 0; i < cols; ++i) {
            for (uint16_t j = 0; j < rows; ++j) {
                m.data[i][j] += Value.data[i][j];
            }
        }

        return m;
    };

    /**
     * @brief Addition assignment operator overload.
     * @param Matrix
     */
    Matrix& operator+=(const Matrix& Value) {
        for (uint16_t i = 0; i < cols; ++i) {
            for (uint16_t j = 0; j < rows; ++j) {
                data[i][j] += Value.data[i][j];
            }
        }

        return *this;
    };

    /**
     * @brief Subtraction binary operator overload.
     * @param Matrix
     */
    Matrix operator-(const Matrix& Value) {
        Matrix m = *this;
        for (uint16_t i = 0; i < cols; ++i) {
            for (uint16_t j = 0; j < rows; ++j) {
                m.data[i][j] -= Value.data[i][j];
            }
        }

        return m;
    };

    /**
     * @brief Subtraction assignment operator overload.
     * @param Matrix
     */
    Matrix& operator-=(const Matrix& Value) {
        for (uint16_t i = 0; i < cols; ++i) {
            for (uint16_t j = 0; j < rows; ++j) {
                data[i][j] -= Value.data[i][j];
            }
        }

        return *this;
    };

    /**
     * @brief Multiplication binary operator overload.
     * @param Matrix
     */
    Matrix operator*(const Matrix& Value) {
        Matrix result;
        Type sum = 0;

        for (uint16_t i = 0; i < rows; ++i) {
            for (uint16_t j = 0; j < cols; ++j) {
                for (uint16_t k = 0; k < cols; k++) {
                    sum += this->data[i][k] * Value.data[k][j];
                }

                result.data[i][j] = sum;
                sum = 0;
            }
        }
        memcpy(this->data, result.data, sizeof(Type) * rows * cols);
        return *this;
    };

    /**
     * @brief Matrix scalar multiplication
     * @param T scalar value
     */
    template <class T>
    Matrix operator*(const T Value) {
        Matrix m = *this;
        for (uint16_t i = 0; i < cols; ++i) {
            for (uint16_t j = 0; j < rows; ++j) {
                m.data[i][j] *= Value;
            }
        }

        return m;
    };

    /**
     * @brief Matrix scalar assignment multiplication
     * @param T scalar value
     */
    template <class T>
    Matrix& operator*=(const T Value) {
        for (uint16_t i = 0; i < cols; ++i) {
            for (uint16_t j = 0; j < rows; ++j) {
                data[i][j] *= Value;
            }
        }

        return *this;
    };

    Vector operator*(const Vector& Value) {
        Vector res;
        for (uint16_t i = 0; i < rows; ++i) {
            for (uint16_t j = 0; j < cols; ++j) {
                res[i] += data[i][j] * Value[j];
            }
        }
        return res;
    };

    void inPlaceTranspose() {
        if (cols != rows) return;

        for (uint16_t i = 0; i < rows; ++i) {
            for (uint16_t j = 0; j < i; ++j) {
                std::swap(this->data[i][j], this->data[j][i]);
            }
        }
    }

    /**
     * @brief Ostream operator for printing Matrix
     * @param os stream output
     * @param m Matrix
     */
    friend std::ostream& operator<<(std::ostream& os, const Matrix& m) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                os << m.data[i][j] << " ";
            }
            os << "\n";  // Add newline after each row
        }
        return os;  // Return stream for chaining
    }
};

/**
 * @brief 3x3 Matrix of type float
 */
typedef Matrix<float, 3, 3> Matrix3d;

}  // namespace math
}  // namespace solo

#endif  // SOLO_MATH_MATRIX_H
