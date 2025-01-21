//
// Created by lepag on 1/18/2025.
//

#ifndef DEBUG_H
#define DEBUG_H
#include <iostream>

#include "../signals/VSignal.h"

namespace Vertex3D::Debug {
    // Debug Variables

    // Debug Signals
    inline VSignal<std::string> console_logged;

    // Debug Functions

    // Prints a Message to the Console
    void log(const std::string& msg);
} // Vertex3D

#endif //DEBUG_H
