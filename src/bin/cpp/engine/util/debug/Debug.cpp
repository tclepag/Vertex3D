//
// Created by lepag on 1/18/2025.
//

#include "Debug.h"
#include <iostream>

namespace Vertex3D::Debug {
    void log(const std::string& msg) {
        std::cout << msg << std::endl;
        console_logged.publish(msg);
    }

} // Vertex3D