#pragma once
#include "World.hpp"

class Renderer {
    int screenWidth;
    int screenHeight;

public:
    Renderer(int width = 900, int height = 900);
    ~Renderer();

    bool shouldClose() const;
    void render(const World& world);
};