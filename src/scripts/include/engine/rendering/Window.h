//
// Created by lepag on 1/12/2025.
//

#ifndef SDLWINDOW_H
#define SDLWINDOW_H


#include <SDL3/SDL.h>
#include <SDL3/SDL_image.h>
#include <iostream>

#include "../main/EngineCore.h"

namespace Vertex3D {
    class EngineCore;
    class Window {
public:
    int width = 800;
    int height = 600;
    EngineCore* handler;
    SDL_GLContext context;
    SDL_Window* window;
    SDL_Renderer* renderer;

    Window();
    void SetupWindow(const char* title, const char* iconPath, int w, int h, SDL_WindowFlags flags);

    void Run(); // Starts the process
    void CallDraw(); // Call Draw to screen
    void CallResize(int w, int h); // Call resize
    void Cleanup(); // Clean the window
    bool RequestQuit(); // Is the window trying to close?
private:
    bool _ready = false;
    bool _running = true;
    bool _update = false;
    void Update(SDL_Event event);
    void Draw();
};

} // Vertex3D

#endif //SDLWINDOW_H
