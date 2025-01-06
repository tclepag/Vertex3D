//
// Created by lepag on 1/5/2025.
//


#include <glm/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/vector_angle.hpp>

#include "../shaders/Shader.h"
#include "GLFW/glfw3.h"

#ifndef CAMERA_H
#define CAMERA_H

namespace Vertex3D {

class Camera {
public:
    // Stores the main vectors of the camera
    glm::vec3 Position;
    glm::vec3 Orientation = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);

    // Prevents the camera from jumping around when first clicking left click
    bool firstClick = true;

    // Stores the width and height of the window
    int width;
    int height;

    // Adjust the speed of the camera and it's sensitivity when looking around
    float speed = 0.1f;
    float sensitivity = 100.0f;

    // Camera constructor to set up initial values
    Camera(int width, int height, glm::vec3 position);

    // Updates and exports the camera matrix to the Vertex Shader
    void Matrix(float FOVdeg, float nearPlane, float farPlane, Shader& shader, const char* uniform);
    // Handles camera inputs
    void Inputs(GLFWwindow* window);
};

} // Vertex3D

#endif //CAMERA_H
