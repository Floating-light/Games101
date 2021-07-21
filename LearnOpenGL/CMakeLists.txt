include(CMakeDependentOption)
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(RealEngine LANGUAGES CXX)
include_directories(../../ThridLib/include/ ./)
LINK_DIRECTORIES(../../ThridLib/lib/)
# CONFIGURE_DEPENDS automatically check and reset the file lists any time the build is invoked.
# avoid manually re-running cmake every time a file is added
file(GLOB_RECURSE allSource CONFIGURE_DEPENDS "utility/*.h" "utility/*.hpp" "utility/*.cpp" "utility/*.c" "Shaders/*.h" "Shaders/*.cpp" )
list(APPEND allSource main.cpp)
message(STATUS "${allSource}")

add_executable(RealEngine ${allSource} )
target_link_libraries(RealEngine assimp-vc142-mtd.lib freetype.lib glfw3.lib opencv_world451d.lib opengl32.lib)

# set_target_properties(RealEngine
#     PROPERTIES
#       CXX_STANDARD 11
# )

# target_link_directories(RealEngine -L../../ThridLib/lib/)