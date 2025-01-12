//
// Created by lepag on 1/12/2025.
//

#ifndef VULKAN_H
#define VULKAN_H
#include <vulkan/vulkan_core.h>

#include "../sdl/SDLWindow.h"

namespace Vertex3D {

class Vulkan {
public:
    SDLWindow* window{};

    Vulkan();
    void InitSDL();
    ~Vulkan();
private:
    VkApplicationInfo appInfo{};
};

} // Vertex3D

#endif //VULKAN_H
