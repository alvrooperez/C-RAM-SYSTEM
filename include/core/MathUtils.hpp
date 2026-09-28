
#pragma once
#include <random>

namespace MathUtils {
    inline double getRandom(double min, double max) {
        static std::mt19937 gen(std::random_device{}());
        std::uniform_real_distribution<double> dist(min, max);
        return dist(gen);
    }

    inline int getRandomInt(int min, int max) {
        static std::mt19937 gen(std::random_device{}());
        std::uniform_int_distribution<int> dist(min, max);
        return dist(gen);
    }
}