//
// Created by lepag on 1/12/2025.
//

#include "VulkanInstance.h"

namespace Vertex3D {
    VulkanInstance::VulkanInstance(VkApplicationInfo *info) {
        this->application_info = info;
    }

    void VulkanInstance::createInstance() {
        VkInstanceCreateInfo create_info = {};
    }

} // Vertex3D