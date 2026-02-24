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

# Document the source code
if(BUILD_DOXYGEN)
    include(Doxygen)
    Doxygen(src "${CMAKE_CURRENT_SOURCE_DIR}")
endif()

add_subdirectory(Math)
add_subdirectory(Particle)
add_subdirectory(Engine)
