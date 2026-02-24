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

#include <iostream>
#include "Engine/Engine.h"

int main() {
    std::cout << "Starting Particle Engine Demo..." << std::endl;

    solo::engine::Engine engine;

    // Create and add multiple particles
    for (int i = 0; i < 5; ++i) {
        solo::physics::Particle p(1.0 + i * 0.5); // Varying masses
        p.setPosition(solo::math::Vector3(i * 1.5, i * 2.0, 0.0));
        p.setVelocity(solo::math::Vector3(1.0, 0.0, 0.0)); // Moving along X axis
        engine.addParticle(p);
    }

    std::cout << "Added " << engine.getParticleCount() << " particles to the engine." << std::endl;

    // Simulate for a few steps
    double dt = 0.1;
    for (int step = 1; step <= 3; ++step) {
        std::cout << "\n--- Step " << step << " ---" << std::endl;
        engine.updateParticles(dt, engine.getParticleCount());
        
        // Print positions
        auto& particles = engine.getParticles();
        for (std::size_t i = 0; i < particles.size(); ++i) {
            auto pos = particles[i].getPosition();
            std::cout << "Particle " << i << " Position: ("
                      << pos.x << ", "
                      << pos.y << ", "
                      << pos.z << ")" << std::endl;
        }
    }

    return 0;
}
