add_library(engine STATIC
    core/Application.cpp
    core/Window.cpp
    ecs/EntityManager.cpp
    jobs/JobSystem.cpp
    physics/Collision.cpp
)

target_include_directories(engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_link_libraries(engine PUBLIC glfw glm::glm PRIVATE project_warnings)

# Threads for the job system's worker pool.
find_package(Threads REQUIRED)
target_link_libraries(engine PUBLIC Threads::Threads)
