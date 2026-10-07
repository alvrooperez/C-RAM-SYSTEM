#include <iostream>
#include <thread>
#include <chrono>
#include "World.hpp"
#include "Renderer.hpp"
#include "Constants.hpp"
#include <iomanip>

int main() {

    std::cout << "Starting Concurrent C-RAM Simulation..." << std::endl;

    World world;
    Renderer renderer(900, 900);

    // First Threat
    std::jthread simThread([&world](std::stop_token stopToken) {
        using namespace std::chrono_literals;
        const double dt = 0.008; 
        const double timeScale = Constants::TIME_SCALE;

        while (!stopToken.stop_requested() && world.isRunning()) {
            world.update(dt * timeScale);
            std::this_thread::sleep_for(8ms); 
        }
    });

    // Main threat
    while (!renderer.shouldClose()) {
        WorldSnapshot snapshot = world.getSnapshot();
        renderer.render(snapshot); 
    }

    // 3. APAGADO LIMPIO
    simThread.request_stop();

    std::cout << "\n--- MISSION REPORT ---" << std::endl;
    std::cout << "Threats: " << world.getTotalDestroyed() << " / " << world.getTotalDestroyed()+ world.getHits() << " Neutralized " <<  "Base Hits : " <<world.getHits()<< std::endl;
    std::cout << "Interception Rate: " << std::fixed << std::setprecision(1)
              << (world.getTotalSpawned() > 0 ? (100.0 * world.getTotalDestroyed() / world.getTotalSpawned()) : 0.0)
              << "%" << std::endl;
    return 0;
}