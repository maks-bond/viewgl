#ifndef CUBE_H
#define CUBE_H

#include "glad.h"
#include <glm/glm.hpp>
#include "shader.h"

class Cube {
public:
    unsigned int VAO, VBO, EBO, edgeEBO;

    Cube();  // Constructor initializes cube data
    void draw(Shader& shader, glm::vec3 position, glm::vec3 color);
    ~Cube(); // Destructor to clean up GPU memory
};

#endif
