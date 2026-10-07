#include <iostream>
#include "World.hpp"
#include "Renderer.hpp"
#include "Constants.hpp"
#include <iomanip>

int main() {
    std::cout << "Starting C-RAM Simulation..." << std::endl;

    World world;
    Renderer renderer(900, 900);

    const double dt = 0.016; // 60 Hz aprox. para coincidir con la pantalla
    const double timeScale = Constants::TIME_SCALE;
    while (!renderer.shouldClose()) {
        // Si el objetivo sigue vivo, avanzamos la física
        
        if (world.isRunning()) {
            
            world.update(dt*timeScale);
            
        }

        // Renderizamos siempre el estado actual a 60 FPS
        renderer.render(world);
    }

    std::cout << "\n--- MISSION REPORT ---" << std::endl;
    std::cout << "Threats: " << world.getTotalDestroyed() << " / " << world.getTotalDestroyed()+ world.getHits() << " Neutralized " <<  "Base Hits : " <<world.getHits()<< std::endl;
    std::cout << "Interception Rate: " << std::fixed << std::setprecision(1)
              << (world.getTotalSpawned() > 0 ? (100.0 * world.getTotalDestroyed() / world.getTotalSpawned()) : 0.0)
              << "%" << std::endl;
    return 0;
}