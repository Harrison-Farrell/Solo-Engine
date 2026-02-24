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

add_library(Engine)
add_library(solo_engine::Engine ALIAS Engine)

target_sources(Engine
    PRIVATE
        Engine.cpp
)

target_link_libraries(Engine
    PRIVATE
        solo_engine::Particle
)

target_include_directories(Engine
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include
)
