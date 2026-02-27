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

add_library(Math)
add_library(solo_engine::Math ALIAS Math)

target_sources(Math
    PRIVATE
        Kinematics.cpp
        Vector.cpp
)

target_include_directories(Math
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include
)
