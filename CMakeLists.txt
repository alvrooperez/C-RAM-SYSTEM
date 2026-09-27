cmake_minimum_required(VERSION 3.16)

project(SistemaCram LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Descargar raylib
include(FetchContent)
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.0
)
FetchContent_MakeAvailable(raylib)

# 2. Rutas de cabeceras
include_directories(include)

# 3. Fuentes
set(SOURCES
    src/main.cpp
    src/Threat.cpp
    src/Entity.cpp
    src/Radar.cpp
    src/Turret.cpp
    src/Bullet.cpp
    src/World.cpp
    src/Renderer.cpp
)

add_executable(SistemaCram ${SOURCES})
target_link_libraries(SistemaCram PRIVATE raylib)