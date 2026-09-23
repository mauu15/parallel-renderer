#include "../include/renderer.h"
#include <cmath>
#include <algorithm>

void render_seq(Image& img, const std::vector<Circle>& circles) {

    for (const auto& circle : circles) {

        // calcolo bounding box del cerchio limitata ai bordi dell'immagine
        int min_x = std::max(0, static_cast<int>(std::floor(circle.x - circle.radius)));
        int max_x = std::min(img.width - 1, static_cast<int>(std::ceil(circle.x + circle.radius)));

        int min_y = std::max(0, static_cast<int>(std::floor(circle.y - circle.radius)));
        int max_y = std::min(img.height - 1, static_cast<int>(std::ceil(circle.y + circle.radius)));

        float radius_sq = circle.radius * circle.radius;
        
        for (int y = min_y; y <= max_y; ++y) {
            for (int x = min_x; x <= max_x; ++x) {
                
                float dx = x - circle.x; // distanza orizzontale dal centro del cerchio
                float dy = y - circle.y; // distanza verticale dal centro del cerchio

                if (dx * dx + dy * dy <= radius_sq) {
                    int idx = y * img.width + x; // accesso al pixel corrispondente
                    Color& pixel = img.pixels[idx];
                    
                    // Alpha blending standard: out = src * alpha + dst * (1 - alpha)
                    float alpha = circle.color.a;
                    float inv_alpha = 1.0f - alpha;
                    
                    pixel.r = static_cast<uint8_t>(circle.color.r * alpha + pixel.r * inv_alpha);
                    pixel.g = static_cast<uint8_t>(circle.color.g * alpha + pixel.g * inv_alpha);
                    pixel.b = static_cast<uint8_t>(circle.color.b * alpha + pixel.b * inv_alpha);
                }
            }
        }
    }
}