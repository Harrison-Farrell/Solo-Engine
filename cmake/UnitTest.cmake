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

include(FetchContent)
FetchContent_Declare(
	googletest
	GIT_REPOSITORY https://github.com/google/googletest.git
	GIT_TAG v1.17.0
	GIT_SHALLOW 1
)

# Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

option(INSTALL_GMOCK OFF)
option(INSTALL_GTEST OFF)

FetchContent_MakeAvailable(googletest)

include(GoogleTest)

macro(AddTests target)
	add_executable(${target} ${target}.cpp)

	target_include_directories(${target} PRIVATE ${CMAKE_SOURCE_DIR}/include)
	
	target_link_libraries(${target} PRIVATE
    solo_engine::Math
    gtest
    gtest_main
	)

	set_target_properties(${target} PROPERTIES
		ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/test"
		LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/test"
		RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/test"
	)

	gtest_discover_tests(${target})

endmacro()
