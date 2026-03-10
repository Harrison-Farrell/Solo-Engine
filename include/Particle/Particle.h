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

#ifndef SOLO_PHYSICS_PARTICLE_H
#define SOLO_PHYSICS_PARTICLE_H

#include "Math/Matrix.h"
#include "Math/Vector.h"
#include "Coordinates/WorldCoordinates.h"

namespace solo {
namespace physics {

/// @brief Represents a physical particle in 3D space.
class Particle {
   public:
    /// @brief Constructs a new Particle object.
    /// @param mass The mass of the particle. Default is 1.0.
    Particle(double mass = 1.0);

    // Getters
    double GetMass() const;
    math::WorldCoordinates GetPosition() const;
    math::Vector GetVelocity() const;
    math::Vector GetAcceleration() const;
    math::Vector GetAngle() const;
    math::Vector GetAngularVelocity() const;
    math::Vector GetAngularAcceleration() const;
    // Setters
    void SetMass(double mass);
    void SetPosition(const math::WorldCoordinates& position);
    void SetVelocity(const math::Vector& velocity);
    void SetAcceleration(const math::Vector& acceleration);
    void SetAngle(const math::Vector& angle);
    void SetAngularVelocity(const math::Vector& angular_velocity);
    void SetAngularAcceleration(const math::Vector& angular_acceleration);

    /// @brief Update the particle's position based on its velocity and a time step.
    /// @param time_step Delta time for the physical update.
    void Update(double time_step);

   private:
    double mMass;

    // Position
    math::WorldCoordinates mPosition;
    math::Vector mVelocity;
    math::Vector mAcceleration;

    // Angle (Rotation)
    math::Vector mAngle;
    math::Vector mAngularVelocity;
    math::Vector mAngularAcceleration;
};

}  // namespace physics
}  // namespace solo

#endif  // SOLO_PHYSICS_PARTICLE_H