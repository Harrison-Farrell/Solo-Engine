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

#include <cstddef>
#include <iostream>

#include "Engine/Engine.h"
#include "Math/Vector.h"
#include "Particle/Particle.h"

int main() {
    std::cout << "Starting Particle Engine Demo..." << std::endl;

    constexpr int particle_count = 5;
    constexpr float x_location = 2.0;
    constexpr float y_location = 5.0;
    constexpr float x_speed = 1.0;
    constexpr float y_speed = 5.0;
    constexpr float z_speed = 2.0;
    constexpr float mass_modifier = 2.0;

    solo::engine::Engine engine;
    solo::math::Vector position;
    solo::math::Vector velocity;

    // Create and add multiple particles
    for (float i = 0; i < particle_count; ++i) {
        position.Set(x_location * i, y_location, i);
        velocity.Set(x_speed + i, y_speed, z_speed + i);
        solo::physics::Particle point(i * mass_modifier);
        point.SetPosition(position);
        point.SetVelocity(velocity);  // Moving along X axis
        engine.AddParticle(point);
    }

    std::cout << "Added " << engine.GetParticleCount()
              << " particles to the engine." << std::endl;

    // Simulate for a few steps
    const double time_step = 0.1;
    for (int step = 1; step <= 3; ++step) {
        std::cout << "\n--- Step " << step << " ---" << std::endl;
        engine.UpdateParticles(time_step);

        // Print positions
        auto& particles = engine.GetParticles();
        for (std::size_t i = 0; i < particles.size(); ++i) {
            auto pos = particles[i].GetPosition();
            std::cout << "Particle " << i << " Position: (" << pos.GetX()
                      << ", " << pos.GetY() << ", " << pos.GetZ() << ")"
                      << std::endl;
        }
    }

    return 0;
}
