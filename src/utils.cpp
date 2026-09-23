#include "../include/utils.h"
#include <fstream>
#include <iostream>
#include <random>

void save_ppm(const Image& img, const std::string& filename) {
    std::ofstream file(filename, std::ios::binary); // apertura in modalità binaria
    if (!file) {
        std::cerr << "Errore nell'apertura del file " << filename << std::endl;
        return;
    }
    
    // Header PPM (P6 = binario, larghezza altezza, max_color_value)
    file << "P6\n" << img.width << " " << img.height << "\n255\n";

    for (const auto& p : img.pixels) {
        file << p.r << p.g << p.b;
    }
    
    file.close();
}

std::vector<Circle> generate_circles(int num_circles, int width, int height) {
    std::vector<Circle> circles(num_circles);
    
    std::mt19937 gen(100); 
    
    std::uniform_real_distribution<float> x_dist(0.0f, static_cast<float>(width)); // da 0 a width
    std::uniform_real_distribution<float> y_dist(0.0f, static_cast<float>(height)); // da 0 a height
    std::uniform_real_distribution<float> z_dist(0.0f, 1000.0f); // profondità z da 0 a 1000
    std::uniform_real_distribution<float> r_dist(10.0f, std::min(width, height) / 10.0f); // raggio da 10 a 1/10 della dimensione minore dell'immagine
    std::uniform_int_distribution<int> c_dist(0, 255); // colore RGB da 0 a 255
    std::uniform_real_distribution<float> a_dist(0.3f, 0.8f); // trasparenza da 0.3 a 0.8

    for (int i = 0; i < num_circles; ++i) {
        circles[i] = {
            x_dist(gen), y_dist(gen), z_dist(gen), r_dist(gen),
            { static_cast<uint8_t>(c_dist(gen)), static_cast<uint8_t>(c_dist(gen)), static_cast<uint8_t>(c_dist(gen)), a_dist(gen) }
        };
    }
    
    return circles;
}