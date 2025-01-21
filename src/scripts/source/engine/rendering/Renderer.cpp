//
// Created by lepag on 1/16/2025.
//

#include "Renderer.h"

namespace Vertex3D {
    Renderer::Renderer() = default;

    void Renderer::UpdateScreenSize(int w, int h) {
        this->width = w;
        this->height = h;
    }

    void Renderer::Render(SDL_Event *event) {
        glViewport(0, 0, this->width, this->height);
        glClearColor(0.9, 0.4, 0.6, 1);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    Renderer::~Renderer() = default;


} // Vertex3D