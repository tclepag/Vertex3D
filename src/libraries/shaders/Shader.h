//
// Created by lepag on 1/5/2025.
//

#ifndef SHADERS_H
#define SHADERS_H

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>

namespace Vertex3D {
    std::string get_file_contents(const std::string& filename);
class Shader {
public:
    GLuint ID;
    Shader(const char* vertex_file_path, const char* fragment_file_path);
    void Activate();
    void Delete();
    void compileErrors(unsigned int shader, const char* type);
};

} // Vertex3D

#endif //SHADERS_H
