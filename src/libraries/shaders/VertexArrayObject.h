//
// Created by lepag on 1/5/2025.
//

#ifndef VERTEXARRAYOBJECT_H
#define VERTEXARRAYOBJECT_H

#include <glad/glad.h>
#include "VertexBufferObject.h"

namespace Vertex3D {

class VertexArrayObject {
public:
    GLuint ID;

    VertexArrayObject();

    void Link(VertexBufferObject &vbo, GLuint layout);
    void Bind();
    void Unbind();
    void Delete();
};

} // Vertex3D

#endif //VERTEXARRAYOBJECT_H
