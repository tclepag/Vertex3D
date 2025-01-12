#include "../src/bin/cpp/engine/vk/Vulkan.h"

int main() {
    auto* vulkan = new Vertex3D::Vulkan();
    vulkan->CreateWindow();
    return 0;
}
