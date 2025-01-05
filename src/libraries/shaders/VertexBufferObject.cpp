//
// Created by lepag on 1/5/2025.
//

#include "VertexBufferObject.h"

namespace Vertex3D {
    VertexBufferObject::VertexBufferObject(GLfloat *vertices, GLsizeiptr size) {
        glGenBuffers(1, &ID);
        glBindBuffer(GL_ARRAY_BUFFER, ID);
        glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
    }

    void VertexBufferObject::Bind() {
        glBindBuffer(GL_ARRAY_BUFFER, ID);
    }

    void VertexBufferObject::Unbind() {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void VertexBufferObject::Delete() {
        glDeleteBuffers(1, &ID);
    }
} // Vertex3D
