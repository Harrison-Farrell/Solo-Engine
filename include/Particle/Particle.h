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

#ifndef SOLO_PHYSICS_PARTICLE_H
#define SOLO_PHYSICS_PARTICLE_H

#include "Math/Matrix.h"
#include "Math/Vector.h"

namespace solo {
namespace physics {

/**
 * @brief Represents a physical particle in 3D space.
 */
class Particle {
   public:
    /**
     * @brief Constructs a new Particle object.
     * @param mass The mass of the particle. Default is 1.0.
     */
    Particle(double mass = 1.0);

    // Getters
    double getMass() const;
    math::Vector getPosition() const;
    math::Vector getVelocity() const;
    math::Vector getAcceleration() const;
    math::Vector getAngle() const;
    math::Vector getAngularVelocity() const;
    math::Vector getAngularAcceleration() const;
    // Setters
    void setMass(double mass);
    void setPosition(const math::Vector& position);
    void setVelocity(const math::Vector& velocity);
    void setAcceleration(const math::Vector& acceleration);
    void setAngle(const math::Vector& angle);
    void setAngularVelocity(const math::Vector& angularVelocity);
    void setAngularAcceleration(const math::Vector& angularAcceleration);

    /**
     * @brief Update the particle's position based on its velocity and a time
     * step.
     * @param dt Delta time for the physical update.
     */
    void update(double dt);

   private:
    double mass_;

    // Position
    math::Vector position_;
    math::Vector velocity_;
    math::Vector acceleration_;

    // Angle (Rotation)
    math::Vector angle_;
    math::Vector angularVelocity_;
    math::Vector angularAcceleration_;
};

}  // namespace physics
}  // namespace solo

#endif  // SOLO_PHYSICS_PARTICLE_H