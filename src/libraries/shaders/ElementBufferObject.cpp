//
// Created by lepag on 1/5/2025.
//

#include "ElementBufferObject.h"

namespace Vertex3D {
    ElementBufferObject::ElementBufferObject(GLuint *indices, GLsizeiptr size) {
        glGenBuffers(1, &ID);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
    }

    void ElementBufferObject::Bind() {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
    }

    void ElementBufferObject::Unbind() {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    void ElementBufferObject::Delete() {
        glDeleteBuffers(1, &ID);
    }
} // Vertex3D
