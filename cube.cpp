#include "cube.h"
#include <glm/gtc/matrix_transform.hpp>

float cubeVertices[] = {
    -0.5f, -0.5f, -0.5f,  
     0.5f, -0.5f, -0.5f,  
     0.5f,  0.5f, -0.5f,  
    -0.5f,  0.5f, -0.5f,  
    -0.5f, -0.5f,  0.5f,  
     0.5f, -0.5f,  0.5f,  
     0.5f,  0.5f,  0.5f,  
    -0.5f,  0.5f,  0.5f   
};

unsigned int cubeIndices[] = {
    0, 1, 2, 2, 3, 0,  // Front
    4, 5, 6, 6, 7, 4,  // Back
    0, 1, 5, 5, 4, 0,  // Bottom
    2, 3, 7, 7, 6, 2,  // Top
    1, 2, 6, 6, 5, 1,  // Right
    3, 0, 4, 4, 7, 3   // Left
};

unsigned int edgeIndices[] = {
    0, 1, 1, 2, 2, 3, 3, 0, // Front edges
    4, 5, 5, 6, 6, 7, 7, 4, // Back edges
    0, 4, 1, 5, 2, 6, 3, 7  // Connecting edges
};

Cube::Cube() {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glGenBuffers(1, &edgeEBO);

    glBindVertexArray(VAO);

    // Setup VBO
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeVertices, GL_STATIC_DRAW);

    // Setup EBO for solid cube
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(cubeIndices), cubeIndices, GL_STATIC_DRAW);

    // Setup edge EBO
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, edgeEBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(edgeIndices), edgeIndices, GL_STATIC_DRAW);

    // Vertex attributes
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);
}

void Cube::draw(Shader& shader, glm::vec3 position, glm::vec3 color, glm::vec3 scale) {
    shader.use();

    glm::mat4 model = glm::translate(glm::mat4(1.0f), position);
    model = glm::rotate(model, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f)); // Rotate to align with X-Y
    model = glm::scale(model, scale);  

    shader.setMat4("model", model);

    // Draw solid cube
    shader.setVec3("color", color);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    // Draw edges
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glEnable(GL_LINE_SMOOTH);
    glLineWidth(2.0f);
    shader.setVec3("color", glm::vec3(1.0f, 1.0f, 1.0f)); // White edges
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, edgeEBO);
    glDrawElements(GL_LINES, 24, GL_UNSIGNED_INT, 0);

    // Reset to normal rendering
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBindVertexArray(0);
}

Cube::~Cube() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glDeleteBuffers(1, &edgeEBO);
}
