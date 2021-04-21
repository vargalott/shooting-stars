cmake_minimum_required(VERSION 3.20)

project(shooting-stars)

add_subdirectory(extern/sfml)

add_executable(shooting-stars)

target_include_directories(shooting-stars PRIVATE ${CMAKE_CURRENT_LIST_DIR}/extern/sfml/include)
target_sources(shooting-stars PRIVATE 
    ${CMAKE_CURRENT_LIST_DIR}/src/main.cpp 
    ${CMAKE_CURRENT_LIST_DIR}/src/shooting-stars.cpp
)
target_link_libraries(shooting-stars sfml-graphics)