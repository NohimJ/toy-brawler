# Shared warning flags. Applied via a function so each target opts in
# explicitly (target_link_libraries(mytarget PRIVATE project_warnings))
# instead of blasting them globally onto third-party targets pulled in
# via FetchContent, which would drown your own warnings in GLFW/GLM noise.

add_library(project_warnings INTERFACE)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    target_compile_options(project_warnings INTERFACE
        -Wall
        -Wextra
        -Wpedantic
        -Wshadow
        -Wcast-align
        -Wunused
        -Wconversion
        -Wsign-conversion
        -Wnull-dereference
        -Wdouble-promotion
    )
endif()
