set(ENGINE_MAIN
        core/Engine.cpp
)

set(ENGINE_GL
        rendering/GL.cpp
        rendering/Renderer.cpp
        rendering/Shader.cpp
)

set(ENGINE_SDL
        rendering/Window.cpp
)

set(ENGINE_UTIL

)

cmake_minimum_required(VERSION 3.30)

add_library(ENGINE_SRC
    ${ENGINE_MAIN}
    ${ENGINE_GL}
    ${ENGINE_SDL}
    ${ENGINE_UTIL}
)