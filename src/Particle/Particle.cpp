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

#include "Particle/Particle.h"

#include "Math/Vector.h"
#include "Coordinates/WorldCoordinates.h"

namespace solo {
namespace physics {

Particle::Particle(double mass) : mMass(mass) {}

double Particle::GetMass() const { return mMass; }

math::WorldCoordinates Particle::GetPosition() const { return mPosition; }
math::Vector Particle::GetVelocity() const { return mVelocity; }
math::Vector Particle::GetAcceleration() const { return mAcceleration; }

math::Vector Particle::GetAngle() const { return mAngle; }
math::Vector Particle::GetAngularVelocity() const { return mAngularVelocity; }
math::Vector Particle::GetAngularAcceleration() const {
    return mAngularAcceleration;
}

void Particle::SetPosition(const math::WorldCoordinates& position) {
    mPosition = position;
}
void Particle::SetVelocity(const math::Vector& velocity) {
    mVelocity = velocity;
}
void Particle::SetAcceleration(const math::Vector& acceleration) {
    mAcceleration = acceleration;
}

void Particle::SetAngle(const math::Vector& angle) { mAngle = angle; }

void Particle::SetAngularVelocity(const math::Vector& angular_velocity) {
    mAngularVelocity = angular_velocity;
}
void Particle::SetAngularAcceleration(
    const math::Vector& angular_acceleration) {
    mAngularAcceleration = angular_acceleration;
}

void Particle::SetMass(double mass) { mMass = mass; }

void Particle::Update(double time_step) {
    // Integrate linear motion
    mVelocity += mAcceleration * time_step;
    mPosition += mVelocity * time_step;

    // Integrate angular motion
    mAngularVelocity += mAngularVelocity * time_step;
    mAngle += mAngularVelocity * time_step;
}

}  // namespace physics
}  // namespace solo
