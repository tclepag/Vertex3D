//
// Created by lepag on 1/5/2025.
//

#ifndef TEXTURE_H
#define TEXTURE_H

#include <glad/glad.h>
#include "../stb.h"
#include "../shaders/Shader.h"

namespace Vertex3D {

class Texture {
public:
    GLuint ID;
    GLenum type;
    Texture(const char* image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType);

    void texUnit(Shader &shader, const char* uniform, GLuint unit);
    void Bind();
    void Unbind();
    void Delete();
};

} // Vertex3D

#endif //TEXTURE_H
