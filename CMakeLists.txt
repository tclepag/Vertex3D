## For simplicity, and avoiding the manual process of installing packages
## Packages will be automatically downloaded from git and made available for this cmake project
cmake_minimum_required(VERSION 3.30)
project(Vertex3D)

# GLFW Packages
include(FetchContent)
FETCHCONTENT_DECLARE(GLFW GIT_REPOSITORY https://github.com/glfw/glfw.git)
FETCHCONTENT_MAKEAVAILABLE(GLFW)

# Glad Packages
FETCHCONTENT_DECLARE(glad GIT_REPOSITORY https://github.com/Dav1dde/glad.git)
FETCHCONTENT_MAKEAVAILABLE(glad)

# OpenGL Packages
find_package(OpenGL REQUIRED)
if (OpenGL_FOUND)
    include_directories(${OpenGL_INCLUDE_DIRS})
    link_directories(${OpenGL_LIBRARY_DIRS})
endif ()

add_executable(Vertex3D src/main.cpp
        src/libraries/shaders/Shader.cpp
        src/libraries/shaders/Shader.h
        src/libraries/shaders/VertexBufferObject.cpp
        src/libraries/shaders/VertexBufferObject.h
        src/libraries/shaders/ElementBufferObject.cpp
        src/libraries/shaders/ElementBufferObject.h
        src/libraries/shaders/VertexArrayObject.cpp
        src/libraries/shaders/VertexArrayObject.h)
target_link_libraries(Vertex3D glfw glad opengl32 ${OPENGL_LIBRARIES})