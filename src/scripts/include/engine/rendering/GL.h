//
// Created by lepag on 1/12/2025.
//

#ifndef GL_H
#define GL_H

#include <glad/glad.h>
#include <iostream>
#include <SDL3/SDL.h>

namespace Vertex3D {
    class SDLWindow;
class GL {
public:
    // Public Variables
    bool _active = false;
    SDLWindow* window;

    // Public Signals

    // Constructor
    GL();

    // Public Functions
    void Update(SDL_Event* event);

    // Deconstructor
    ~GL();
};

} // Vertex3D

#endif //GL_H
