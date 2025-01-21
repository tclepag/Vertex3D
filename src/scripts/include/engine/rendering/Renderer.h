//
// Created by lepag on 1/16/2025.
//

#ifndef RENDERER_H
#define RENDERER_H

#include <glad/glad.h>
#include <SDL3/SDL_events.h>

namespace Vertex3D {
    class Renderer {
public:
    int width;
    int height;

    Renderer();
    void UpdateScreenSize(int w, int h);
    void Render(SDL_Event* event);
    ~Renderer();
};

} // Vertex3D

#endif //RENDERER_H
