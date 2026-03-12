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

#ifndef SOLO_ENGINE_ENGINE_H
#define SOLO_ENGINE_ENGINE_H

#include <atomic>
#include <chrono>
#include <cstddef>
#include <thread>
#include <vector>

#include "Particle/Particle.h"

namespace solo {
namespace engine {

/**
 * @brief Core engine class managing physical entities.
 */
class Engine {
   public:
    Engine() = default;

    /**
     * @brief Destructor ensures simulation loop is stopped.
     */
    virtual ~Engine();

    /**
     * @brief Starts the threaded simulation tick function.
     * @param tick_rate_hz Target frequency for updates.
     */
    void Start(double tick_rate_hz = 60.0);

    /**
     * @brief Stops the threaded simulation tick function.
     */
    void Stop();

    /**
     * @brief Checks if the simulation loop is currently running.
     * @return True if running.
     */
    bool IsRunning() const;

    /**
     * @brief Adds a particle to the engine's management.
     * @param particle The particle to add.
     */
    void AddParticle(const physics::Particle& particle);

    /**
     * @brief Calls update on a provided number of particles.
     * @param time_step Delta time for the physical update.
     */
    void UpdateParticles(double time_step);

    /**
     * @brief Returns the total number of particles currently in the engine.
     * @return Number of particles.
     */
    std::size_t GetParticleCount() const;

    /**
     * @brief Allows access to the underlying particle collection.
     * @return Reference to the vector of particles.
     */
    std::vector<physics::Particle>& GetParticles();

   private:
    /**
     * @brief Internal loop managed by the thread.
     * @param tick_rate_hz Frequency of updates.
     */
    void SimulationLoop(double tick_rate_hz);

    std::vector<physics::Particle> mParticles;
    std::atomic<bool> mRunning{false};
    std::thread mLoopThread;
};

}  // namespace engine
}  // namespace solo

#endif  // SOLO_ENGINE_ENGINE_H
