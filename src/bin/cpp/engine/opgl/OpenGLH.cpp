//
// Created by lepag on 1/12/2025.
//

#include "OpenGLH.h"

#include <glad/glad.h>
#include <GL/gl.h>

#include "../util/debug/Debug.h"

namespace Vertex3D {
    OpenGLH::OpenGLH() {
        if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
        {
            throw std::runtime_error("Failed to load OpenGL functions");
        }
        this->_active = true;
    }

    void OpenGLH::Update(SDL_Event* event) {

    }

    OpenGLH::~OpenGLH() {
        this->window->Cleanup();
        this->_active = false;
    }
} // Vertex3D