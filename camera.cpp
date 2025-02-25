#include "camera.h"

Camera::Camera(glm::vec3 position, float zoom)
    : Position(position), WorldUp(glm::vec3(0.0f, 1.0f, 0.0f)), Yaw(-90.0f), Pitch(0.0f), Zoom(zoom) {
    Position += Front * -Zoom;  // Ensure initial position respects zoom level
    updateCameraVectors();
}

glm::mat4 Camera::GetViewMatrix() {
    return glm::lookAt(Position, Position + Front, Up);
}

void Camera::ProcessMouseMovement(float xoffset, float yoffset) {
    float sensitivity = 0.1f;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    Yaw += xoffset;
    Pitch += yoffset;

    if (Pitch > 89.0f) Pitch = 89.0f;
    if (Pitch < -89.0f) Pitch = -89.0f;

    updateCameraVectors();
}

void Camera::ProcessMouseScroll(float yoffset) {
    float prevZoom = Zoom;
    Zoom -= yoffset;
    if (Zoom < 1.0f) Zoom = 1.0f;
    if (Zoom > 1000.0f) Zoom = 1000.0f;

    // Adjust position smoothly only if zoom is changing
    if (prevZoom != Zoom) {
        Position += Front * (prevZoom - Zoom); // Prevents sudden jumps
    }
}

void Camera::ProcessPan(float xoffset, float yoffset) {
    float panSpeed = 0.005f; // Reduce panning speed to make it more manageable
    glm::vec3 right = glm::normalize(glm::cross(Front, WorldUp)); 
    glm::vec3 up = glm::normalize(WorldUp);

    Position -= right * xoffset * panSpeed;
    Position -= up * yoffset * panSpeed;
}

void Camera::updateCameraVectors() {
    glm::vec3 front;
    front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    front.y = sin(glm::radians(Pitch));
    front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    Front = glm::normalize(front);

    Right = glm::normalize(glm::cross(Front, WorldUp));
    Up = glm::normalize(glm::cross(Right, Front));
}
