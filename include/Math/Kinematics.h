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

#ifndef SOLO_MATH_KINEMATICS_H
#define SOLO_MATH_KINEMATICS_H

#include "Matrix.h"
#include "Vector.h"

namespace solo {
namespace math {

/***
 * @brief Kinematics algorithms
 * X_Y_Z
 * X - Specifies rotation as either fixed(F) or rotating(R).
 * Y - Specifies Kinematic rates to be held constant as either
 *     rate of position (P) or rate of velocity (V).
 * Z - Specifies the coordinate system as either world coordinates (W)
 *     or body axis coordinates(B).
 */
enum KinematicAlgorithm {
    Other_DRA = 0,
    Static = 1,
    F_P_W = 2,
    R_P_W = 3,
    R_V_W = 4,
    F_V_W = 5,
    F_P_B = 6,
    R_P_B = 7,
    R_V_B = 8,
    F_V_B = 9
};

/**
 * @brief Kinematic class
 */
class Kinematic {
   public:
    /**
     * @brief Default constructor
     */
    Kinematic() : algorithm(Other_DRA) {};

    ~Kinematic() = default;

    /**
     * @brief Constructor with algorithm
     * @param algorithm The algorithm to use for Kinematic
     */
    Kinematic(KinematicAlgorithm algorithm) : algorithm(algorithm) {};

   private:
    Vector linear_acceleration;
    Vector angular_acceleration;

    KinematicAlgorithm algorithm;
};

}  // namespace math
}  // namespace solo
#endif  // SOLO_MATH_KINEMATICS_H
