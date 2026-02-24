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

#ifndef SOLO_ENGINE_ENGINE_H
#define SOLO_ENGINE_ENGINE_H

#include <vector>
#include <cstddef>
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
     * @brief Adds a particle to the engine's management.
     * @param particle The particle to add.
     */
    void addParticle(const physics::Particle& particle);

    /**
     * @brief Calls update on a provided number of particles.
     * @param dt Delta time for the physical update.
     * @param count The maximum number of particles to update.
     */
    void updateParticles(double dt, std::size_t count);

    /**
     * @brief Returns the total number of particles currently in the engine.
     * @return Number of particles.
     */
    std::size_t getParticleCount() const;

    /**
     * @brief Allows access to the underlying particle collection.
     * @return Reference to the vector of particles.
     */
    std::vector<physics::Particle>& getParticles();

private:
    std::vector<physics::Particle> particles_;
};

} // namespace engine
} // namespace solo

#endif // SOLO_ENGINE_ENGINE_H
