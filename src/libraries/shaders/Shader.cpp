//
// Created by lepag on 1/5/2025.
//

#include "Shader.h"

namespace Vertex3D {
    // Reads a text file and outputs as string
    std::string get_file_contents(const char *filename)
    {
        if (std::ifstream in(filename, std::ios::in | std::ios::binary); in)
        {
            std::ostringstream contents;
            contents << in.rdbuf();
            in.close();
            return(contents.str());
        }
        throw(errno);
    }

    Shader::Shader(const char *vertex_file_path, const char *fragment_file_path) {
        std::string vertex_source = get_file_contents(vertex_file_path);
        std::string fragment_source = get_file_contents(fragment_file_path);

        const char* vertexSource = vertex_source.c_str();
        const char* fragmentSource = fragment_source.c_str();

        // Create Vertex Shader Object and get its reference
        GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
        // Attach Vertex Shader source to the Vertex Shader Object
        glShaderSource(vertexShader, 1, &vertexSource, NULL);
        // Compile the Vertex Shader into machine code
        glCompileShader(vertexShader);

        // Create Fragment Shader Object and get its reference
        GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        // Attach Fragment Shader source to the Fragment Shader Object
        glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
        // Compile the Vertex Shader into machine code
        glCompileShader(fragmentShader);

        // Create Shader Program Object and get its reference
        ID = glCreateProgram();
        // Attach the Vertex and Fragment Shaders to the Shader Program
        glAttachShader(ID, vertexShader);
        glAttachShader(ID, fragmentShader);
        // Wrap-up/Link all the shaders together into the Shader Program
        glLinkProgram(ID);

        // Delete the now useless Vertex and Fragment Shader objects
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    }

    void Shader::Activate() {
        glUseProgram(ID);
    }

    void Shader::Delete() {
        glDeleteProgram(ID);
    }


} // Vertex3D