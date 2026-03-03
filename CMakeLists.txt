cmake_minimum_required(VERSION 3.16)
project(2D-Game-Engine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(raylib REQUIRED)

add_executable(engine_demo
    src/main.cpp
    src/Engine.cpp
    src/Input.cpp
)

target_include_directories(engine_demo PRIVATE src)
target_link_libraries(engine_demo PRIVATE raylib)