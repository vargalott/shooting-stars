cmake_minimum_required(VERSION 3.8)

enable_language(CXX)
set(CMAKE_CXX_STANDARD 17)
set(DEBUG_OPTIONS -m64 -Wall -Wextra -pedantic -Werror)
set(RELEASE_OPTIONS -m64 -O2)

project(ShootingStars)
add_subdirectory(3rd_party/sfml)

add_executable(ShootingStars)

target_sources(ShootingStars PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)
target_sources(ShootingStars PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/ShootingStars.cpp)

target_link_libraries(ShootingStars sfml-graphics)
target_link_libraries(ShootingStars sfml-audio)

add_compile_options("$<$<CONFIG:DEBUG>:${DEBUG_OPTIONS}>")
add_compile_options("$<$<CONFIG:RELEASE>:${RELEASE_OPTIONS}>")