//
// Created by lepag on 1/5/2025.
//

#include "VertexArrayObject.h"

namespace Vertex3D {
    VertexArrayObject::VertexArrayObject() {
        glGenVertexArrays(1, &ID);
    }

    void VertexArrayObject::Link(VertexBufferObject &vbo, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset) {
        vbo.Bind();
        glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
        glEnableVertexAttribArray(layout);
        vbo.Unbind();
    }

    void VertexArrayObject::Bind() {
        glBindVertexArray(ID);
    }

    void VertexArrayObject::Unbind() {
        glBindVertexArray(0);
    }

    void VertexArrayObject::Delete() {
        glDeleteVertexArrays(1, &ID);
    }
} // Vertex3D