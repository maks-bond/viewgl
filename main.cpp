#include <iostream>
#include "glad.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "cube.h"
#include "shader.h"
#include "camera.h"
#include "colors.h"

// Window dimensions
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;

// Timing
float deltaTime = 0.0f;
float lastFrame = 0.0f;

Camera camera(glm::vec3(0.0f, 60.0f, 0.0f), 100.0);

// Callback functions
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos) {
    if (firstMouse) {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }
    
    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos;
    lastX = xpos;
    lastY = ypos;

    int leftState = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);
    int rightState = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT);
    if (leftState == GLFW_PRESS) {
        camera.ProcessMouseMovement(xoffset, yoffset);
    }
    if (rightState == GLFW_PRESS) {
        camera.ProcessPan(xoffset, yoffset);
    }
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
    camera.ProcessMouseScroll(yoffset * 2.5);
    std::cout<<"New zoom is: "<<camera.Zoom<<std::endl;
}

void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void drawWalls(Cube& cube, Shader& shader) {
    glm::vec3 wallColor = Colors::Orange;
    
    // Wall Scale: width = 1.0, height = 5.0, length = 100.0
    glm::vec3 verticalWallScale = glm::vec3(1.0f, 100.0f, 5.0f);  // X as thickness
    glm::vec3 horizontalWallScale = glm::vec3(100.0f, 1.0f, 5.0f); // Z as thickness

    // Left Wall
    cube.draw(shader, glm::vec3(-50.5f, 2.5f, 0.0f), wallColor, verticalWallScale);
    
    // Right Wall
    cube.draw(shader, glm::vec3(50.5f, 2.5f, 0.0f), wallColor, verticalWallScale);

    // Top Wall
    cube.draw(shader, glm::vec3(0.0f, 2.5f, -50.5f), wallColor, horizontalWallScale);

    // Bottom Wall
    cube.draw(shader, glm::vec3(0.0f, 2.5f, 50.5f), wallColor, horizontalWallScale);
}

void drawFloor(Cube &cube, Shader &shader) {
    glm::vec3 floorPosition = glm::vec3(0.0f, 0.0f, -0.05f); // Adjusted Z to lie flat
    glm::vec3 floorColor = Colors::Gray50;
    glm::vec3 floorScale = glm::vec3(100.0f, 100.0f, 0.1f); // Z is now the thin axis

    cube.draw(shader, floorPosition, floorColor, floorScale);
}

int main() {
    // Initialize GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create window
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Cube with Camera", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Camera setup
    camera.Yaw = -90.0f;
    camera.Pitch = -89.9f;
    camera.Zoom = 100.0f;
    camera.updateCameraVectors();

    glfwMakeContextCurrent(window);

    // Load OpenGL functions using GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // Set viewport and callbacks
    glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

    // Configure global OpenGL state
    glEnable(GL_DEPTH_TEST);

    // Shader setup
    Shader shader("vertex_shader.glsl", "fragment_shader.glsl");

    Cube cube;

    // Capture mouse
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);

    shader.use();
    shader.setMat4("projection", glm::perspective(glm::radians(camera.Zoom), 
                    (float)SCR_WIDTH / SCR_HEIGHT, 0.01f, 5000.0f));

    // Render loop
    while (!glfwWindowShouldClose(window)) {
        // Per-frame time logic
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        processInput(window);

        // Rendering commands
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        shader.use();
        // View matrix tells how we view the world. Camera is considered to be at [0, 0, 0].
        // When we rotate we change yaw and pitch which then affect camera's Front vector which defines its orientation.
        // Camera's Position vector tells where in 3d world the camera is.
        // Camera's Up vector is fixed. Chat GPT says that y usually represents height. I can consider changing that as it might be creating problems for me as in my 3d representation z is height vector.
        shader.setMat4("view", camera.GetViewMatrix());
        // This defines 3d to 2d screen projections. glm::perspective returns such a matrix.
        // First two values are straightforward. It is really interesting to understand what near and far clipping planes define.
        shader.setMat4("projection", glm::perspective(glm::radians(camera.Zoom), 
                        (float)SCR_WIDTH / SCR_HEIGHT, 0.01f, 5000.0f));

        drawFloor(cube, shader);
        drawWalls(cube, shader); // Draw the walls

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Cleanup
    glfwTerminate();
    return 0;
}
