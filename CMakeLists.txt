cmake_minimum_required(VERSION 3.16)

project(SistemaCram LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Descargar e integrar raylib
include(FetchContent)
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.0
)
FetchContent_MakeAvailable(raylib)

# 2. Rutas de cabeceras (incluyendo subcarpetas modulares)
include_directories(
    include
    include/core
    include/entities
    include/systems
    include/graphics
)

# 3. Fuentes organizadas por modulos
set(SOURCES
    src/main.cpp
    src/entities/Entity.cpp
    src/entities/Threat.cpp
    src/entities/Bullet.cpp
    src/systems/Radar.cpp
    src/systems/Turret.cpp
    src/systems/World.cpp
    src/graphics/Renderer.cpp
)

add_executable(SistemaCram ${SOURCES})
target_link_libraries(SistemaCram PRIVATE raylib)