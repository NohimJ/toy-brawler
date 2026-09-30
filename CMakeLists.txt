cmake_minimum_required(VERSION 3.24)
project(yakuza_toy LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # needed for clangd / editor tooling

# Default to a Release-ish build if nothing was specified, so profiling numbers
# aren't accidentally taken from an unoptimized Debug build.
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE RelWithDebInfo)
endif()

include(cmake/CompilerWarnings.cmake)

# ---------------------------------------------------------------------------
# Third-party dependencies via FetchContent (same pattern you already used
# for GoogleTest in the order book project) rather than vendoring source.
# ---------------------------------------------------------------------------
include(FetchContent)

FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG        3.4
)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
    glm
    GIT_REPOSITORY https://github.com/g-truc/glm.git
    GIT_TAG        1.0.1
)

FetchContent_MakeAvailable(glfw glm)

# ---------------------------------------------------------------------------
# Engine + game as separate targets. Keeping "engine" free of any
# Kiryu/enemy/wave-spawner specifics is what lets the same core (ECS, jobs,
# renderer, physics) plug into a completely different game later if you ever
# want to reuse it, and it forces a clean dependency boundary you'll actually
# be asked about in interviews.
# ---------------------------------------------------------------------------
add_subdirectory(src/engine)
add_subdirectory(src/game)

add_executable(yakuza_toy src/main.cpp)
target_link_libraries(yakuza_toy PRIVATE game)

# ---------------------------------------------------------------------------
# Tests are opt-in (BUILD_TESTING ON by default) so `cmake --build` for a
# normal dev loop doesn't pay the GoogleTest fetch/build cost every time.
# ---------------------------------------------------------------------------
option(BUILD_TESTING "Build unit tests" ON)
if(BUILD_TESTING)
    enable_testing()
    add_subdirectory(tests)
endif()
