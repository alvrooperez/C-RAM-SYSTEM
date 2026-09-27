#pragma once
#include <cmath>
#include <numbers>

// Basic structure for 2D vectors
struct Vec2 {
    double x = 0.0;
    double y = 0.0;

    // Operators
    // Sum operator
    Vec2 operator+(const Vec2& other) const {
        return {x + other.x, y + other.y};
    }

    Vec2 operator-(const Vec2& other) const {
        return {x - other.x, y - other.y};
    }

    // Add and assign operator
    Vec2& operator+=(const Vec2& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    // Multiplier scalar operator
    Vec2 operator*(const double k) const {
        return {k * x, k * y};
    }

    double module() const {
        return std::sqrt(x * x + y * y);
    }

    double moduleSquared() const {
        return (x * x + y * y);
    }

    double angle() const {
        return std::atan2(y, x) * (180.0 / std::numbers::pi);
    }

    static Vec2 fromPolar(double angleDegrees, double length) {
        double rad = angleDegrees * (std::numbers::pi / 180.0);
        return { length * std::cos(rad), length * std::sin(rad) };
    }
};
