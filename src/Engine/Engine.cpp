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

#include "Engine/Engine.h"

#include <cstddef>
#include <vector>

#include "Particle/Particle.h"

namespace solo {
namespace engine {

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

}  // namespace engine
}  // namespace solo
