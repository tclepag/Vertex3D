//
// Created by lepag on 1/12/2025.
//

#include "OpenGLH.h"

#include <glad/glad.h>
#include <GL/gl.h>

namespace Vertex3D {
    OpenGLH::OpenGLH() {
        this->_active = true;

        // Setup class stuff ...

        // Begin processing
        this->Setup();
    }

    void OpenGLH::Setup() {
        this->SetupWindow();
    }

    void OpenGLH::SetupWindow() {
        auto *wnd = new SDLWindow();
        wnd->SetupWindow("Vertex3D", "src/bin/materials/tex/app/app.png", 800, 600, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
        if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
        {
            throw std::runtime_error("Failed to load OpenGL functions");
        }
        wnd->Run();
        this->window = wnd;
    }

    void OpenGLH::Update(SDL_Event* event) {

    }

    OpenGLH::~OpenGLH() {
        this->window->Cleanup();
        this->_active = false;
    }
} // Vertex3D