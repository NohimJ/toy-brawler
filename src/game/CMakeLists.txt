add_library(game STATIC
    Kiryu.cpp
    Enemy.cpp
    WaveSpawner.cpp
    CombatSystem.cpp
)

target_include_directories(game PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_link_libraries(game PUBLIC engine PRIVATE project_warnings)
