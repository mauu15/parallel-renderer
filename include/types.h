#pragma once
#include <vector>
#include <cstdint>

struct Color {
    uint8_t r, g, b;
    float a; // alpha channel [0.0, 1.0] per blending
};

struct Circle {
    float x, y, z; 
    float radius;
    Color color;
};

struct Image {
    int width;
    int height;
    std::vector<Color> pixels; 
};