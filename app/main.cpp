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

#include <atomic>
#include <chrono>
#include <csignal>
#include <cstddef>
#include <iostream>
#include <thread>

#include "Coordinates/WorldCoordinates.h"
#include "Engine/Engine.h"
#include "Math/Vector.h"
#include "Particle/Particle.h"

namespace globals {
// Global flag to track if the application should keep running
// Using std::atomic flag ensures thread-safe reads and writes
std::atomic<bool> g_running{true};

// Signal handler for SIGINT (Ctrl+C)
void signal_handler(int signal) {
    if (signal == SIGINT) {
        std::cout << "\nReceived Ctrl+C (SIGINT). Stopping simulation..."
                  << "\n";
        g_running = false;
    }
}
}  // namespace globals

int main() {
    // Register the signal handler
    std::signal(SIGINT, globals::signal_handler);

    std::cout << "Starting Particle Engine Demo..." << "\n";

    constexpr int particle_count = 5;
    constexpr float x_location = 2.0;
    constexpr float y_location = 5.0;
    constexpr float x_speed = 1.0;
    constexpr float y_speed = 5.0;
    constexpr float z_speed = 2.0;
    constexpr float mass_modifier = 2.0;
    constexpr int sleep_time_ms = 1000;

    solo::engine::Engine engine;
    solo::math::WorldCoordinates position;
    solo::math::Vector velocity;

    // Create and add multiple particles
    for (int i = 0; i < particle_count; ++i) {
        position.Set(static_cast<double>(x_location) * i,
                     static_cast<double>(y_location), static_cast<double>(i));
        velocity.Set(x_speed + static_cast<float>(i), y_speed,
                     z_speed + static_cast<float>(i));
        solo::physics::Particle point(static_cast<double>(i) * mass_modifier);
        point.SetPosition(position);
        point.SetVelocity(velocity);  // Moving along X axis
        engine.AddParticle(point);
    }

    std::cout << "Added " << engine.GetParticleCount()
              << " particles to the engine." << "\n";

    // Setup signal handler loop
    std::cout << "Running simulation loop. Press Ctrl+C to stop..." << "\n";

    int step = 1;
    const double time_step = 0.1;

    while (globals::g_running) {
        std::cout << "\n--- Step " << step << " ---" << "\n";
        engine.UpdateParticles(time_step);

        // Print positions
        auto& particles = engine.GetParticles();
        for (std::size_t i = 0; i < particles.size(); ++i) {
            auto pos = particles.at(i).GetPosition();
            std::cout << "Particle " << i << " Position: (" << pos.GetX()
                      << ", " << pos.GetY() << ", " << pos.GetZ() << ")"
                      << "\n";
        }

        step++;
        std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time_ms));
    }

    std::cout << "\nSimulation stopped gracefully." << "\n";
    return 0;
}
