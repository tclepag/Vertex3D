// Base
#include "../src/bin/cpp/engine/vk/Vulkan.h"

// ImGui
#include "bin/include/imgui/imgui.h"
#include "bin/include/imgui/imgui_impl_vulkan.h"
#include "bin/include/imgui/imgui_impl_sdl2.h"

int main() {
    // Setup Window
    auto* vulkan = new Vertex3D::Vulkan();
    vulkan->InitSDL();

    SDL_Delay(900);

    return 0;
}
