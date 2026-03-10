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

#ifndef SOLO_MATH_MATRIX_H
#define SOLO_MATH_MATRIX_H

#include <stdint.h>

#include <array>
#include <cstring>
#include <iostream>
#include <memory>
#include <utility>

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
    std::array<std::array<Type, cols>, rows> mData;

    /**
     * @brief Default on constructor
     * @note Matrix initially set as an identity matrix
     */
    Matrix() {
        for (uint16_t i = 0; i < cols; ++i) {
            for (uint16_t j = 0; j < rows; ++j) {
                if (i == j) {
                    mData[i][j] = 1;
                } else {
                    mData[i][j] = 0;
                }
            }
        }
    };

    /**
     * @brief Addition binary operator overload.
     * @param Matrix
     */
    Matrix operator+(const Matrix& value) {
        Matrix matrix = *this;
        for (uint16_t i = 0; i < cols; ++i) {
            for (uint16_t j = 0; j < rows; ++j) {
                matrix.mData[i][j] += value.mData[i][j];
            }
        }

        return matrix;
    };

    /**
     * @brief Addition assignment operator overload.
     * @param Matrix
     */
    Matrix& operator+=(const Matrix& value) {
        for (uint16_t i = 0; i < cols; ++i) {
            for (uint16_t j = 0; j < rows; ++j) {
                mData[i][j] += value.mData[i][j];
            }
        }

        return *this;
    };

    /**
     * @brief Subtraction binary operator overload.
     * @param Matrix
     */
    Matrix operator-(const Matrix& value) {
        Matrix matrix = *this;
        for (uint16_t i = 0; i < cols; ++i) {
            for (uint16_t j = 0; j < rows; ++j) {
                matrix.mData[i][j] -= value.mData[i][j];
            }
        }

        return matrix;
    };

    /**
     * @brief Subtraction assignment operator overload.
     * @param Matrix
     */
    Matrix& operator-=(const Matrix& value) {
        for (uint16_t i = 0; i < cols; ++i) {
            for (uint16_t j = 0; j < rows; ++j) {
                mData[i][j] -= value.mData[i][j];
            }
        }

        return *this;
    };

    /**
     * @brief Multiplication binary operator overload.
     * @param Matrix
     */
    Matrix operator*(const Matrix& value) {
        Matrix matrix;

        for (uint16_t i = 0; i < rows; ++i) {
            for (uint16_t j = 0; j < cols; ++j) {
                Type sum = 0;
                for (uint16_t k = 0; k < cols; ++k) {
                    sum += this->mData[i][k] * value.mData[k][j];
                }

                matrix.mData[i][j] = sum;
            }
        }
        return matrix;
    };

    /**
     * @brief Multiplication binary operator overload.
     * @param Matrix
     */
    Matrix operator*=(const Matrix& value) {
        Matrix matrix;

        for (uint16_t i = 0; i < rows; ++i) {
            for (uint16_t j = 0; j < cols; ++j) {
                Type sum = 0;
                for (uint16_t k = 0; k < cols; ++k) {
                    sum += this->mData[i][k] * value.mData[k][j];
                }

                matrix.mData[i][j] = sum;
            }
        }
        this->mData = std::move(matrix.mData);
        return matrix;
    };

    /**
     * @brief Matrix scalar multiplication
     * @param T scalar value
     */
    template <class T>
    Matrix operator*(const T value) {
        Matrix matrix = *this;
        for (uint16_t i = 0; i < cols; ++i) {
            for (uint16_t j = 0; j < rows; ++j) {
                matrix.mData[i][j] *= value;
            }
        }

        return matrix;
    };

    /**
     * @brief Matrix scalar assignment multiplication
     * @param T scalar value
     */
    template <class T>
    Matrix& operator*=(const T value) {
        for (uint16_t i = 0; i < cols; ++i) {
            for (uint16_t j = 0; j < rows; ++j) {
                mData[i][j] *= value;
            }
        }

        return *this;
    };

    Vector operator*(const Vector& value) {
        Vector res;
        for (uint16_t i = 0; i < rows; ++i) {
            for (uint16_t j = 0; j < cols; ++j) {
                res[i] += mData[i][j] * value[j];
            }
        }
        return res;
    };

    void InPlaceTranspose() {
        if (cols != rows) {
            return;
        }

        for (uint16_t i = 0; i < rows; ++i) {
            for (uint16_t j = 0; j < i; ++j) {
                std::swap(this->mData[i][j], this->mData[j][i]);
            }
        }
    }

    /**
     * @brief Ostream operator for printing Matrix
     * @param os stream output
     * @param matrix Matrix
     */
    friend std::ostream& operator<<(std::ostream& stream,
                                    const Matrix& matrix) {
        for (uint8_t i = 0; i < rows; ++i) {
            for (uint8_t j = 0; j < cols; ++j) {
                stream << matrix.mData[i][j] << " ";
            }
            stream << "\n";  // Add newline after each row
        }
        return stream;  // Return stream for chaining
    }
};

/**
 * @brief 3x3 Matrix of type float
 */
using Matrix3d = Matrix<float, 3, 3>;

}  // namespace math
}  // namespace solo

#endif  // SOLO_MATH_MATRIX_H
