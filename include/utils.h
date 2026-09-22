#pragma once
#include "types.h"
#include <string>
#include <vector>

void save_ppm(const Image& img, const std::string& filename); // formato PPM (Portable PixMap) binario

// Genera un vettore di cerchi con parametri randomici controllati
std::vector<Circle> generate_circles(int num_circles, int width, int height);