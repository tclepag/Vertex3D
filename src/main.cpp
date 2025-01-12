// Base
#include "../src/bin/cpp/engine/vk/Vulkan.h"

// ImGui
#include "bin/include/imgui/imgui.h"
#include "bin/include/imgui/imgui_impl_vulkan.h"
#include "bin/include/imgui/imgui_impl_sdl2.h"

int main() {
    // Setup Window
    auto* vulkan = new Vertex3D::Vulkan();
    vulkan->Window();

    SDL_Delay(100);

    return 0;
}
