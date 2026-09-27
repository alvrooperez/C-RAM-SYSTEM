#include <iostream>
#include "World.hpp"
#include "Renderer.hpp"

int main() {
    std::cout << "Starting C-RAM Simulation..." << std::endl;

    World world;
    Renderer renderer(900, 900);

    const double dt = 0.016; // 60 Hz aprox. para coincidir con la pantalla
    const double timeScale = 4.0;
    while (!renderer.shouldClose()) {
        // Si el objetivo sigue vivo, avanzamos la física
        if (world.isRunning()) {
            world.update(dt*timeScale);
        }

        // Renderizamos siempre el estado actual a 60 FPS
        renderer.render(world);
    }

    std::cout << "Simulation closed." << std::endl;
    return 0;
}