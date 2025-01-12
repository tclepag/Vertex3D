//
// Created by lepag on 1/12/2025.
//

#include "Vulkan.h"

#include <iostream>
#include <ostream>

namespace Vertex3D {
    Vulkan::Vulkan() {
        VkApplicationInfo appInfo = {};
        appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        appInfo.pApplicationName = "Vertex3D";
        appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.pEngineName = "Vertex3DEngine";
        appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.apiVersion = VK_MAKE_VERSION(1, 0, 0);
        this->appInfo = appInfo;
    }

    void Vulkan::InitSDL() {
        auto *wnd = new SDLWindow();
        wnd->CreateWindow(
            "Vertex3D",
            "src/bin/materials/tex/app/app.png",
            800,
            600,
            SDL_WINDOW_VULKAN
            );
        wnd->Run();
        this->window = wnd;
    }

} // Vertex3D