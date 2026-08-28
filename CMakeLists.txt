cmake_minimum_required(VERSION 3.16)

project(HyperPlane
    VERSION 1.0.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Library sources
file(GLOB LIB_SOURCES
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

# Create library
add_library(HyperPlane STATIC
    ${LIB_SOURCES}
)

target_include_directories(HyperPlane
    PUBLIC
        ${PROJECT_SOURCE_DIR}/includes
)

# Example program
add_executable(hyper_plane
    main.cpp
)

target_link_libraries(hyper_plane
    PRIVATE HyperPlane
)

# Tests
add_executable(test_runner
    tests/main.cpp
)

target_link_libraries(test_runner
    PRIVATE HyperPlane
)

enable_testing()

add_test(
    NAME HyperPlaneTests
    COMMAND test_runner
)
