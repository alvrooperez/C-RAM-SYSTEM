#pragma once
#include "World.hpp"
#include "raylib.h"

class Renderer {
    int screenWidth;
    int screenHeight;

public:
    Renderer(int width = 900, int height = 900);
    ~Renderer();

    bool shouldClose() const;
    void render(const World& world);
    ::Vector2 toScreen(Vec2 worldPos) const;
};