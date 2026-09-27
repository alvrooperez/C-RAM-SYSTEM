#include "Renderer.hpp"
#include "raylib.h"

Renderer::Renderer(int width, int height)
    : screenWidth(width), screenHeight(height) {
    InitWindow(screenWidth, screenHeight, "C-RAM Defense System - Tactical Radar");
    SetTargetFPS(60);
}

Renderer::~Renderer() {
    CloseWindow();
}

bool Renderer::shouldClose() const {
    return WindowShouldClose();
}

void Renderer::render(const World& world) {
    BeginDrawing();
    ClearBackground(BLACK);

    // TODO: Tu turno para implementar el dibujado aquí

    EndDrawing();
}