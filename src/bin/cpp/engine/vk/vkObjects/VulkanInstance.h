//
// Created by lepag on 1/12/2025.
//

#ifndef VULKANINSTANCE_H
#define VULKANINSTANCE_H
#include <vulkan/vulkan_core.h>

namespace Vertex3D {

class VulkanInstance {
public:
    VulkanInstance(VkApplicationInfo* info);
    VkApplicationInfo* application_info;
    VkInstance instance;
    void createInstance();
    ~VulkanInstance();
};

} // Vertex3D

#endif //VULKANINSTANCE_H
