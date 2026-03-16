cmake_minimum_required(VERSION 3.16)
project(GameEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(raylib REQUIRED)

add_library(GameEngine
    src/Engine.cpp
    src/Input.cpp
    src/MyRenderer2D.cpp
    src/MyCamera2D.cpp
    src/MyAssetManager.cpp
    src/ECS/Systems.cpp
    src/ECS/World.cpp
    src/Scene/SceneManager.cpp
    src/Scene/MenuScene.cpp
    src/Scene/GameScene.cpp
)

target_include_directories(GameEngine PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(GameEngine PUBLIC
    raylib
)

add_executable(engine_demo
    src/main.cpp
)

target_link_libraries(engine_demo PRIVATE
    GameEngine
)