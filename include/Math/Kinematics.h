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

#ifndef SOLO_MATH_KINEMATICS_H
#define SOLO_MATH_KINEMATICS_H

#include <vector>

#include "EulerAngles.h"
#include "Matrix.h"
#include "Vector.h"
#include "WorldCoordinates.h"

namespace solo {
namespace math {

/// @brief Kinematics algorithms
/// X_Y_Z
/// X - Specifies rotation as either fixed(F) or rotating(R).
/// Y - Specifies Kinematic rates to be held constant as either
///     rate of position (P) or rate of velocity (V).
/// Z - Specifies the coordinate system as either world coordinates (W)
///     or body axis coordinates(B).

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

/// @brief Kinematic class
class Kinematic {
   public:
    /// @brief Default constructor
    Kinematic() : algorithm(Other_DRA) {};

    /// @brief Default destructor
    ~Kinematic() = default;

    /// @brief Constructor with algorithm
    /// @param algorithm The algorithm to use for Kinematic
    Kinematic(KinematicAlgorithm algorithm) : algorithm(algorithm) {};

   protected:
    solo::math::WorldCoordinates m_initPosition;
    solo::math::Vector m_initLinearVelocity;

    solo::math::Vector m_initLinearAcceleration;
    solo::math::Vector m_Ab;
    bool m_bQuaxAxisSet{false};
    solo::math::Vector m_quatAxis;

    // Some algorithms are implemented as an integral form for rotation,
    // thus using the time since t0
    float m_f64Magnitude{0};

    // Orientation cache
    solo::math::EulerAngles m_initOrientation, m_initEulerAngularVelocity;
    Matrix3d m_initOrientationMatrix, m_initOrientationMatrixTranspose;

    // Angular velocity cache
    solo::math::Vector m_initAngularVelocity;
    Matrix3d m_wwMatrix;
    Matrix3d m_SkewOmegaMatrix;

    KinematicAlgorithm m_DRA{KinematicAlgorithm::Other_DRA};

    void positionReset(const solo::math::WorldCoordinates& Position);
    void orientationReset(const solo::math::EulerAngles& Orientation);
    void angularVelocityReset(const solo::math::Vector& AngularVelocity);
    void velocityReset(const solo::math::Vector& LinearVelocity);
    void accelerationReset(const solo::math::Vector& LinearAcceleration);
    void quatAxisReset(const solo::math::Vector& QuatAxis);

    solo::math::EulerAngles toEulerAngularVelocity(
        const solo::math::Vector& angVel,
        const solo::math::EulerAngles& Orientation);

    void calcOrientation_simplified(solo::math::EulerAngles& OrientationOut,
                                    const float DeltaTime);
    void calcOrientation(solo::math::EulerAngles& OrientationOut,
                         const float totalTimeSinceReset);

    void computeRotationAxis(const Matrix3d& curOrientationMatrix);
    void computeDRMatrix(Matrix3d& res, const float totalTimeSinceReset);
    void computeDRMatrix_asQuat(Matrix3d& res, const float totalTimeSinceReset);

    /************************************************************************/
    /* Dead Reckoning Algorithm Implementations */
    /************************************************************************/

    // FPW //
    void calcDeadReckoningFPW(solo::math::WorldCoordinates& PositionOut,
                              const float totalTimeSinceReset);

    // RPW //
    void calcDeadReckoningRPW(solo::math::WorldCoordinates& PositionOut,
                              solo::math::EulerAngles& OrientationOut,
                              const float totalTimeSinceReset);

    // RVW //
    void calcDeadReckoningRVW(solo::math::WorldCoordinates& PositionOut,
                              solo::math::EulerAngles& OrientationOut,
                              const float totalTimeSinceReset);

    // FVW //
    void calcDeadReckoningFVW(solo::math::WorldCoordinates& PositionOut,
                              const float totalTimeSinceReset);

    // FPB //
    void calcDeadReckoningFPB(solo::math::WorldCoordinates& PositionOut,
                              const float totalTimeSinceReset);

    // RPB //
    void calcDeadReckoningRPB(solo::math::WorldCoordinates& PositionOut,
                              solo::math::EulerAngles& OrientationOut,
                              const float totalTimeSinceReset);

    // RVB //
    void calcDeadReckoningRVB(solo::math::WorldCoordinates& PositionOut,
                              solo::math::EulerAngles& OrientationOut,
                              const float totalTimeSinceReset);

    // FVB //
    void calcDeadReckoningFVB(solo::math::WorldCoordinates& PositionOut,
                              const float totalTimeSinceReset);

   public:
    DeadReckoningCalculator() = default;
    ~DeadReckoningCalculator() = default;

    /// @brief Resets this object
    /// @param LinearVelocity
    /// @param LinearAcceleration
    /// @param AngularVelocity
    /// @param Position
    /// @param Orientation
    /// @param QuatAxis
    /// @param DRA
    void Reset(const solo::math::Vector& LinearVelocity,
               const solo::math::Vector& LinearAcceleration,
               const solo::math::Vector& AngularVelocity,
               const solo::math::WorldCoordinates& Position,
               const solo::math::EulerAngles& Orientation,
               const solo::math::Vector& QuatAxis,
               solo::math::ENUMS::DeadReckoningAlgorithm DRA);

    /// @brief Steps algorithm for a time step, computing the position and
    /// orientation
    /// @param TotalTimeSinceReset
    /// @param PositionOut
    /// @param OrientationOut
    void RunAlgorithm(const float TotalTimeSinceReset,
                      solo::math::WorldCoordinates& PositionOut,
                      solo::math::EulerAngles& OrientationOut);

    /// @brief Generates smoothing points between to locations
    /// @param StartPosition
    /// @param EndPosition
    /// @param NumberOfPoints
    /// @return
    std::vector<solo::math::WorldCoordinates> GenerateSmoothingPoints(
        const solo::math::WorldCoordinates& StartPosition,
        const solo::math::WorldCoordinates& EndPosition,
        uint32_t NumberOfPoints);

    /// @brief Generates smoothing points between to locations
    /// @param StartPosition const WorldCoordinates
    /// @param EndPosition const WorldCoordinates
    /// @param NumberOfPoints const WorldCoordinates
    /// @param v resultant vector of points
    void GenerateSmoothingPoints(
        const solo::math::WorldCoordinates& StartPosition,
        const solo::math::WorldCoordinates& EndPosition,
        uint32_t NumberOfPoints, std::vector<solo::math::WorldCoordinates>& v);
};

}  // namespace math
}  // namespace solo
#endif  // SOLO_MATH_KINEMATICS_H
