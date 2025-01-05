//
// Created by lepag on 1/5/2025.
//

#ifndef VERTEXBUFFEROBJECT_H
#define VERTEXBUFFEROBJECT_H

#include <glad/glad.h>

namespace Vertex3D {
    class VertexBufferObject {
    public:
        GLuint ID;

        VertexBufferObject(GLfloat *vertices, GLsizeiptr size);

        void Bind();

        void Unbind();

        void Delete();
    };
} // Vertex3D

#endif //VERTEXBUFFEROBJECT_H
