#include <iostream>
#include <omp.h>

int main() {
    std::cout << "Test Ambiente OpenMP..." << std::endl;

    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        
        // Stampa solo il master thread per evitare output accavallati
        if (thread_id == 0) {
            std::cout << "OpenMP configurato con successo." << std::endl;
            std::cout << "Thread totali disponibili: " << omp_get_num_threads() << std::endl;
        }
    }

    return 0;
}