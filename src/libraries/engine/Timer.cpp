//
// Created by lepag on 1/5/2025.
//

#include "Timer.h"
#include "GLFW/glfw3.h"

namespace Vertex3D {
    void Timer::Update() {
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrameTime;
        lastFrameTime = currentFrame;
    }


} // Vertex3D