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
    math::Vector3 getPosition() const;
    math::Vector3 getVelocity() const;
    math::Vector3 getAcceleration() const;

    math::Vector3 getAngle() const;
    math::Vector3 getAngularVelocity() const;
    math::Vector3 getAngularAcceleration() const;

    // Setters
    void setMass(double mass);
    void setPosition(const math::Vector3& position);
    void setVelocity(const math::Vector3& velocity);
    void setAcceleration(const math::Vector3& acceleration);

    void setAngle(const math::Vector3& angle);
    void setAngularVelocity(const math::Vector3& angularVelocity);
    void setAngularAcceleration(const math::Vector3& angularAcceleration);

    /**
     * @brief Update the particle's position based on its velocity and a time step.
     * @param dt Delta time for the physical update.
     */
    void update(double dt);

private:
    double mass_;
    
    // Position
    math::Vector3 position_;
    math::Vector3 velocity_;
    math::Vector3 acceleration_;

    // Angle (Rotation)
    math::Vector3 angle_;
    math::Vector3 angularVelocity_;
    math::Vector3 angularAcceleration_;
};

} // namespace physics
} // namespace solo

#endif // SOLO_PHYSICS_PARTICLE_H