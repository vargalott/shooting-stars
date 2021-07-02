cmake_minimum_required(VERSION 3.20)

project(shooting-stars)
set(BUILD_SHARED_LIBS FALSE)

add_subdirectory(extern/sfml)

add_executable(shooting-stars)

target_include_directories(shooting-stars PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/extern/sfml/include
    ${CMAKE_CURRENT_LIST_DIR}/include
)
target_sources(shooting-stars PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/src/main.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/core.cpp
)
target_link_libraries(shooting-stars PRIVATE sfml-graphics)
