cmake_minimum_required(VERSION 3.6)

add_subdirectory("../common/jaeger-client-cpp" "${CMAKE_CURRENT_BINARY_DIR}/jaeger-client-cpp_build")
add_subdirectory("../common/pistache" "${CMAKE_CURRENT_BINARY_DIR}/pistache_build")

# Project name and version
project(serviceB VERSION 1.0)

# Executable
add_executable(${PROJECT_NAME} main.cpp)

# Dependencies
target_include_directories(${PROJECT_NAME} PUBLIC jaegertracing)
target_link_libraries(${PROJECT_NAME} PUBLIC jaegertracing pistache)

