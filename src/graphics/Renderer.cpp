#include "Renderer.hpp"
#include "raylib.h"
#include "Constants.hpp"
#include <cmath>
#include <numbers>

using namespace Constants;

Renderer::Renderer(int width, int height)
    : screenWidth(width), screenHeight(height) {
    SetTraceLogLevel(LOG_WARNING);
    InitWindow(screenWidth, screenHeight, "C-RAM Defense System - Tactical Radar");
    SetTargetFPS(60);
}

Renderer::~Renderer() {
    CloseWindow();
}

bool Renderer::shouldClose() const {
    return WindowShouldClose() || IsKeyPressed(KEY_Q);;
}

void Renderer::render(const WorldSnapshot& snapshot) {
    BeginDrawing();
    ClearBackground(BLACK);
    ::Vector2 baseZone = toScreen(BASE_POSITION);
    float baseZonePixelRadius = (BASE_RADIUS / (X_MAX - X_MIN)) * screenWidth;
    DrawCircle(baseZone.x, baseZone.y, baseZonePixelRadius, Fade(BLUE, 0.15f));
    DrawCircleLines(baseZone.x, baseZone.y, baseZonePixelRadius, DARKBLUE);
    ::Vector2 baseScreen = toScreen(snapshot.turretPos);
    DrawCircle(baseScreen.x, baseScreen.y, 8, BLUE);
    double angleRad = snapshot.turretAngle * (std::numbers::pi / 180.0);
    float barrelLength = 25.0f;

    ::Vector2 barrelEnd = {
        baseScreen.x + static_cast<float>(barrelLength * std::cos(angleRad)),
        baseScreen.y - static_cast<float>(barrelLength * std::sin(angleRad))
    };

    DrawLineEx(baseScreen, barrelEnd, 3.0f, SKYBLUE);

    for (const auto& pos : snapshot.threatPositions) {
        ::Vector2 threatScreen = toScreen(pos);
        DrawCircle(threatScreen.x, threatScreen.y, 6, RED);
    }

    for (const auto& pos : snapshot.bulletPositions) {
        ::Vector2 bulletScreen = toScreen(pos);
        DrawCircle(bulletScreen.x, bulletScreen.y, 3, YELLOW);
    }

    //Radar
    float maxRadarPixelRadius = (RADAR_RANGE / (X_MAX-X_MIN)) * screenWidth;

    DrawCircleLines(baseScreen.x, baseScreen.y,maxRadarPixelRadius* 0.25f, DARKGREEN);
    DrawCircleLines(baseScreen.x, baseScreen.y,maxRadarPixelRadius* 0.50f, DARKGREEN);
    DrawCircleLines(baseScreen.x, baseScreen.y,maxRadarPixelRadius* 0.75f, DARKGREEN);
    DrawCircleLines(baseScreen.x, baseScreen.y,maxRadarPixelRadius,GREEN);

    EndDrawing();
}

::Vector2 Renderer::toScreen(Vec2 worldPos) const{
    float sx = static_cast<float>((worldPos.x / (X_MAX - X_MIN)) * screenWidth);
    float sy = static_cast<float>(screenHeight - (worldPos.y / (Y_MAX - Y_MIN)) * screenHeight);
    return ::Vector2{sx,sy};
}