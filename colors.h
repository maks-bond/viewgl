#ifndef COLORS_H
#define COLORS_H

#include <glm/glm.hpp>

namespace Colors {
    // Primary Colors
    const glm::vec3 Red        = glm::vec3(1.0f, 0.0f, 0.0f);
    const glm::vec3 Green      = glm::vec3(0.0f, 1.0f, 0.0f);
    const glm::vec3 Blue       = glm::vec3(0.0f, 0.0f, 1.0f);

    // Secondary Colors
    const glm::vec3 Yellow     = glm::vec3(1.0f, 1.0f, 0.0f);
    const glm::vec3 Cyan       = glm::vec3(0.0f, 1.0f, 1.0f);
    const glm::vec3 Magenta    = glm::vec3(1.0f, 0.0f, 1.0f);
    
    // Tertiary Colors
    const glm::vec3 Orange     = glm::vec3(1.0f, 0.5f, 0.0f);
    const glm::vec3 Lime       = glm::vec3(0.5f, 1.0f, 0.0f);
    const glm::vec3 Teal       = glm::vec3(0.0f, 0.5f, 0.5f);
    const glm::vec3 Violet     = glm::vec3(0.5f, 0.0f, 0.5f);
    const glm::vec3 Pink       = glm::vec3(1.0f, 0.6f, 0.8f);
    const glm::vec3 Brown      = glm::vec3(0.6f, 0.3f, 0.1f);

    // Grayscale Shades
    const glm::vec3 Black      = glm::vec3(0.0f, 0.0f, 0.0f);
    const glm::vec3 White      = glm::vec3(1.0f, 1.0f, 1.0f);
    const glm::vec3 Gray10     = glm::vec3(0.1f, 0.1f, 0.1f);
    const glm::vec3 Gray20     = glm::vec3(0.2f, 0.2f, 0.2f);
    const glm::vec3 Gray30     = glm::vec3(0.3f, 0.3f, 0.3f);
    const glm::vec3 Gray40     = glm::vec3(0.4f, 0.4f, 0.4f);
    const glm::vec3 Gray50     = glm::vec3(0.5f, 0.5f, 0.5f);
    const glm::vec3 Gray60     = glm::vec3(0.6f, 0.6f, 0.6f);
    const glm::vec3 Gray70     = glm::vec3(0.7f, 0.7f, 0.7f);
    const glm::vec3 Gray80     = glm::vec3(0.8f, 0.8f, 0.8f);
    const glm::vec3 Gray90     = glm::vec3(0.9f, 0.9f, 0.9f);

    // Pastel Colors
    const glm::vec3 PastelPink   = glm::vec3(1.0f, 0.7f, 0.8f);
    const glm::vec3 PastelBlue   = glm::vec3(0.7f, 0.8f, 1.0f);
    const glm::vec3 PastelGreen  = glm::vec3(0.7f, 1.0f, 0.7f);
    const glm::vec3 PastelYellow = glm::vec3(1.0f, 1.0f, 0.7f);
    const glm::vec3 PastelOrange = glm::vec3(1.0f, 0.8f, 0.6f);
    const glm::vec3 PastelPurple = glm::vec3(0.8f, 0.7f, 1.0f);
    
    // Neon Colors
    const glm::vec3 NeonRed      = glm::vec3(1.0f, 0.1f, 0.1f);
    const glm::vec3 NeonGreen    = glm::vec3(0.1f, 1.0f, 0.1f);
    const glm::vec3 NeonBlue     = glm::vec3(0.1f, 0.1f, 1.0f);
    const glm::vec3 NeonYellow   = glm::vec3(1.0f, 1.0f, 0.1f);
    const glm::vec3 NeonCyan     = glm::vec3(0.1f, 1.0f, 1.0f);
    const glm::vec3 NeonMagenta  = glm::vec3(1.0f, 0.1f, 1.0f);
    const glm::vec3 NeonOrange   = glm::vec3(1.0f, 0.5f, 0.0f);
    const glm::vec3 NeonPink     = glm::vec3(1.0f, 0.0f, 0.5f);

    // Earth Tones
    const glm::vec3 Sand         = glm::vec3(0.9f, 0.8f, 0.6f);
    const glm::vec3 Olive        = glm::vec3(0.5f, 0.5f, 0.2f);
    const glm::vec3 ForestGreen  = glm::vec3(0.1f, 0.4f, 0.1f);
    const glm::vec3 DeepBlue     = glm::vec3(0.0f, 0.0f, 0.5f);
    const glm::vec3 Maroon       = glm::vec3(0.5f, 0.0f, 0.0f);
    const glm::vec3 Tan          = glm::vec3(0.8f, 0.7f, 0.5f);
    const glm::vec3 Charcoal     = glm::vec3(0.2f, 0.2f, 0.2f);

    // Special Colors
    const glm::vec3 Gold         = glm::vec3(1.0f, 0.84f, 0.0f);
    const glm::vec3 Silver       = glm::vec3(0.75f, 0.75f, 0.75f);
    const glm::vec3 Bronze       = glm::vec3(0.8f, 0.5f, 0.2f);

    // Custom Unique Shades
    const glm::vec3 MidnightBlue = glm::vec3(0.1f, 0.1f, 0.44f);
    const glm::vec3 SkyBlue      = glm::vec3(0.53f, 0.81f, 0.92f);
    const glm::vec3 Coral        = glm::vec3(1.0f, 0.5f, 0.31f);
    const glm::vec3 Crimson      = glm::vec3(0.86f, 0.08f, 0.24f);
    const glm::vec3 Salmon       = glm::vec3(0.98f, 0.5f, 0.45f);
    const glm::vec3 DarkSlate    = glm::vec3(0.18f, 0.31f, 0.31f);
    const glm::vec3 Lavender     = glm::vec3(0.9f, 0.7f, 1.0f);
    const glm::vec3 Indigo       = glm::vec3(0.29f, 0.0f, 0.51f);
}
#endif
