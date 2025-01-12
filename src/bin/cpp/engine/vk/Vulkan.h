//
// Created by lepag on 1/11/2025.
//

#ifndef VULKAN_H
#define VULKAN_H

#define SDL_MAIN_HANDLED
#include <SDL3/SDL.h>
#include <SDL3/SDL_vulkan.h>
#include <SDL3/SDL_video.h>
#include <vulkan/vulkan.h>
#include <vulkan/vulkan_core.h>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include "Pipeline.h"

namespace Vertex3D {

class Vulkan {
public:
    // SDL Objects
    SDL_Window* _wnd;
    SDL_Renderer* _renderer;
    SDL_Surface* _surface;
    // Vulkan Objects
    VkApplicationInfo _info;
    VkInstance _inst;
    VkPhysicalDevice _physDevice;
    VkDevice _device;
    VkQueue _queue;

    // Class Public
    Vulkan();
    bool IsReady();
    int Window();
    void DestroyWindow();
    bool IsWindowValid();
    SDL_Window* GetWindow();
    void createWindowSurface(VkInstance instance, VkSurfaceKHR* surface);
    ~Vulkan();
private:
    // Vulkan Objects
    bool _ready = false;
    bool _update = false;

    // Vulkan Window Settings
    int _width = 800;
    int _height = 600;

    // Class Private
    Pipeline _pipeline{"src/bin/shaders/base/default.vert.spv", "src/bin/shaders/base/default.frag.spv"};
protected:
    // Class Protected
    void HandleEvent(SDL_WindowEvent e);
    void Run();
    void Draw(const SDL_Event &event);
    void Viewport(const SDL_Event &event);
    void Update(const SDL_Event &event);
};

} // Vertex3D

#endif //VULKAN_H
