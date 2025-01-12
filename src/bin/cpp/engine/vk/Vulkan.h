//
// Created by lepag on 1/11/2025.
//

#ifndef VULKAN_H
#define VULKAN_H

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_vulkan.h>
#include <SDL2/SDL_video.h>
#include <vulkan/vulkan.h>
#include <vulkan/vulkan_core.h>
#include <iostream>
#include <stdexcept>
#include <cstdlib>

namespace Vertex3D {

class Vulkan {
public:
    // Class Public
    Vulkan();
    bool IsReady();
    int CreateWindow();
    void DestroyWindow();
    bool IsWindowValid();
    ~Vulkan();
private:
    // SDL Objects
    SDL_Window* _wnd;
    SDL_Surface* _surface;
    // Vulkan Objects
    VkApplicationInfo _info;
    VkInstance _inst;
    VkPhysicalDevice _physDevice;
    VkDevice _device;
    VkQueue _queue;

    // Vulkan Objects
    bool _ready = false;
    bool _update = false;

    // Vulkan Window Settings
    int _width = 800;
    int _height = 600;
protected:
    void HandleEvent(SDL_WindowEvent e);
    void Run();
    void Draw();
    void Viewport();
    void Update(const SDL_Event &event);
};

} // Vertex3D

#endif //VULKAN_H
