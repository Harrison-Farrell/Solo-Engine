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

#include "Particle/Particle.h"

namespace solo {
namespace physics {

Particle::Particle(double mass)
    : mass_(mass),
      position_(),
      velocity_(),
      acceleration_(),
      angle_(),
      angularVelocity_(),
      angularAcceleration_() {}

double Particle::getMass() const { return mass_; }

math::Vector Particle::getPosition() const { return position_; }
math::Vector Particle::getVelocity() const { return velocity_; }
math::Vector Particle::getAcceleration() const { return acceleration_; }

math::Vector Particle::getAngle() const { return angle_; }
math::Vector Particle::getAngularVelocity() const { return angularVelocity_; }
math::Vector Particle::getAngularAcceleration() const {
    return angularAcceleration_;
}

void Particle::setPosition(const math::Vector& position) {
    position_ = position;
}
void Particle::setVelocity(const math::Vector& velocity) {
    velocity_ = velocity;
}
void Particle::setAcceleration(const math::Vector& acceleration) {
    acceleration_ = acceleration;
}

void Particle::setAngle(const math::Vector& angle) { angle_ = angle; }

void Particle::setAngularVelocity(const math::Vector& angularVelocity) {
    angularVelocity_ = angularVelocity;
}
void Particle::setAngularAcceleration(const math::Vector& angularAcceleration) {
    angularAcceleration_ = angularAcceleration;
}

void Particle::setMass(double mass) { mass_ = mass; }

void Particle::update(double dt) {
    // Integrate linear motion
    velocity_ += acceleration_ * dt;
    position_ += velocity_ * dt;

    // Integrate angular motion
    angularVelocity_ += angularAcceleration_ * dt;
    angle_ += angularVelocity_ * dt;
}

}  // namespace physics
}  // namespace solo
