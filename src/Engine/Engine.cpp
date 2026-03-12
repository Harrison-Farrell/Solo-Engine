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

#include <chrono>
#include <cstddef>
#include <thread>
#include <vector>

#include "Engine/Engine.h"
#include "Particle/Particle.h"

namespace solo {
namespace engine {

Engine::~Engine() { Stop(); }

void Engine::Start(double tick_rate_hz) {
    if (mRunning) {
        return;
    }

    mRunning = true;
    mLoopThread = std::thread(&Engine::SimulationLoop, this, tick_rate_hz);
}

void Engine::Stop() {
    mRunning = false;
    if (mLoopThread.joinable()) {
        mLoopThread.join();
    }
}

bool Engine::IsRunning() const { return mRunning; }

void Engine::AddParticle(const physics::Particle& particle) {
    mParticles.push_back(particle);
}

void Engine::UpdateParticles(double time_step) {
    const std::size_t particle_count = mParticles.size();
    for (std::size_t i = 0; i < particle_count; ++i) {
        mParticles[i].Update(time_step);
    }
}

std::size_t Engine::GetParticleCount() const { return mParticles.size(); }

std::vector<physics::Particle>& Engine::GetParticles() { return mParticles; }

void Engine::SimulationLoop(double tick_rate_hz) {
    const auto interval =
        std::chrono::duration<double>(1.0 / tick_rate_hz);
    const double time_step = 1.0 / tick_rate_hz;

    while (mRunning) {
        const auto start_time = std::chrono::steady_clock::now();

        UpdateParticles(time_step);

        const auto end_time = std::chrono::steady_clock::now();
        const auto elapsed = end_time - start_time;
        const auto sleep_time = interval - elapsed;

        if (sleep_time > std::chrono::nanoseconds(0)) {
            std::this_thread::sleep_for(sleep_time);
        }
    }
}

}  // namespace engine
}  // namespace solo
