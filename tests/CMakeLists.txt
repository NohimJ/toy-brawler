include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.15.2
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(engine_tests
    ecs_tests.cpp
    jobs_tests.cpp
)

target_link_libraries(engine_tests PRIVATE engine GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(engine_tests)
