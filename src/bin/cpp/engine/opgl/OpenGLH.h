//
// Created by lepag on 1/12/2025.
//

#ifndef OPENGLH_H
#define OPENGLH_H
#include <iostream>
#include <SDL3/SDL.h>
#include "../sdl/SDLWindow.h"

namespace Vertex3D {
    class SDLWindow;
class OpenGLH {
public:
    // Public Variables
    bool _active = false;
    SDLWindow* window;

    // Public Signals
    // TODO: CREATE A SIGNAL CLASS!!!

    // Constructor
    OpenGLH();

    // Public Functions
    void Setup();
    void SetupWindow();
    void Update(SDL_Event* event);


    // Deconstructor
    ~OpenGLH();
};

} // Vertex3D

#endif //OPENGLH_H
