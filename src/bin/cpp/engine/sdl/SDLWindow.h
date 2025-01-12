//
// Created by lepag on 1/12/2025.
//

#ifndef SDLWINDOW_H
#define SDLWINDOW_H
#include <SDL3/SDL.h>
#include <vulkan/vulkan_core.h>
#include <SDL3/SDL_image.h>

namespace Vertex3D {

class SDLWindow {
public:
    int width = 800;
    int height = 600;
    SDL_Window* window;
    SDL_Renderer* renderer;

    SDLWindow();
    void CreateWindow(const char* title, const char* iconPath, int w, int h, SDL_WindowFlags flags);

    void Run();
    void CallDraw();
    void CallResize(int w, int h);
    ~SDLWindow();
private:
    bool _ready = false;
    bool _running = false;
    bool _update = false;
    void Update(SDL_Event event);
    void Draw();
};

} // Vertex3D

#endif //SDLWINDOW_H
