# --------------------------------------------------------------------------
# Author:      Harrison Farrell
# Project:     Solo-Engine Simulation Engine
# Copyright:   (c) 2026 Harrison Farrell. All Rights Reserved.
#
# Licensed under the GNU Affero General Public License v3.0 (AGPL-3.0).
# This program is distributed WITHOUT ANY WARRANTY; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See <https://www.gnu.org/licenses/agpl-3.0.html> for full details.
# --------------------------------------------------------------------------

add_library(Particle)
add_library(solo_engine::Particle ALIAS Particle)

target_sources(Particle
    PRIVATE
        Particle.cpp
)

target_include_directories(Particle
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(Particle
    PRIVATE
        solo_engine::Math
)
