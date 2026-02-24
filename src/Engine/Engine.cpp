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

#include "Engine/Engine.h"
#include <algorithm>

namespace solo {
namespace engine {

void Engine::addParticle(const physics::Particle& particle) {
    particles_.push_back(particle);
}

void Engine::updateParticles(double dt, std::size_t count) {
    std::size_t updateCount = std::min(count, particles_.size());
    for (std::size_t i = 0; i < updateCount; ++i) {
        particles_[i].update(dt);
    }
}

std::size_t Engine::getParticleCount() const {
    return particles_.size();
}

std::vector<physics::Particle>& Engine::getParticles() {
    return particles_;
}

} // namespace engine
} // namespace solo
