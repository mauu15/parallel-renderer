#include <iostream>
#include <algorithm>
#include <omp.h>
#include "../include/types.h"
#include "../include/renderer.h"
#include "../include/utils.h"

int main() {
    const int WIDTH = 1024;
    const int HEIGHT = 1024;
    const int NUM_CIRCLES = 10000;

    std::cout << "Generazione di " << NUM_CIRCLES << " cerchi..." << std::endl;
    auto circles = generate_circles(NUM_CIRCLES, WIDTH, HEIGHT);

    std::sort(circles.begin(), circles.end(), [](const Circle& a, const Circle& b) {
        return a.z < b.z;
    });

    Image img;
    img.width = WIDTH;
    img.height = HEIGHT;
    img.pixels.resize(WIDTH * HEIGHT, {0, 0, 0, 1.0f});

    std::cout << "Avvio rendering sequenziale..." << std::endl;
    
    double start_time = omp_get_wtime();
    render_seq(img, circles);
    double end_time = omp_get_wtime();

    std::cout << "Tempo di rendering (sequenziale): " << (end_time - start_time) << " secondi" << std::endl;

    std::cout << "Salvataggio immagine..." << std::endl;
    save_ppm(img, "output_seq.ppm");
    
    std::cout << "Fatto!" << std::endl;

    return 0;
}