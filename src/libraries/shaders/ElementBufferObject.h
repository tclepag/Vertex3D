//
// Created by lepag on 1/5/2025.
//

#ifndef ELEMENTBUFFEROBJECT_H
#define ELEMENTBUFFEROBJECT_H

#include <glad/glad.h>

namespace Vertex3D {
    class ElementBufferObject {
    public:
        GLuint ID;

        ElementBufferObject(GLuint *indices, GLsizeiptr size);

        void Bind();

        void Unbind();

        void Delete();
    };
} // Vertex3D

#endif //ELEMENTBUFFEROBJECT_H
