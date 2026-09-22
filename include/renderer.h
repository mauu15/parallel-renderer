#pragma once
#include "types.h"
#include <vector>

// Implementazione baseline
void render_seq(Image& img, const std::vector<Circle>& circles);

// Implementazioni OpenMP
void render_par_pixel(Image& img, const std::vector<Circle>& circles);
void render_par_tile(Image& img, const std::vector<Circle>& circles);