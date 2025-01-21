## For simplicity, and avoiding the manual process of installing packages
## Packages will be automatically downloaded from git and made available for this cmake project
cmake_minimum_required(VERSION 3.30)
project(Vertex3D)

include(FetchContent)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

# Glad Packages
FetchContent_Declare(glad GIT_REPOSITORY https://github.com/Dav1dde/glad.git)
FetchContent_MakeAvailable(glad)

# GLM Packages
FetchContent_Declare(glm GIT_REPOSITORY https://github.com/g-truc/glm.git)
FetchContent_MakeAvailable(glm)

# SDL Packages
set(SDL_INCLUDE_DIR "C:/SDL/include")
set(SDL_LIBRARY "C:/SDL/lib/SDL3.lib" "C:/SDL/lib/SDL3_image.lib")

include_directories(${SDL_INCLUDE_DIR})
link_directories(${SDL_LIBRARY})

# Find SDL
find_package( SDL REQUIRED )

if ( SDL_FOUND )
    message( STATUS "FOUND SDL: ${SDL_LIBRARY}")
    message( STATUS "FOUND SDL LIBRARIES: ${SDL_LIBRARIES}")
else ()
    message( FATAL_ERROR "Could not find SDL" )
endif ()

# Vulkan Packages
find_package( OpenGL REQUIRED )

if ( OpenGL_FOUND )
    message( STATUS "Found OpenGL: ${OPENGL_LIBRARIES}" )
    # Add OpenGL include directories and libraries to your target
    include_directories( ${OPENGL_INCLUDE_DIRS} )
    link_directories( ${OPENGL_LIBRARIES} )

else ()
    message( FATAL_ERROR "Could not find OpenGL" )
endif ()


add_subdirectory(src/scripts/source/engine)
add_subdirectory(src/scripts/include/engine)

add_executable( Vertex3D src/main.cpp
        ${ENGINE_SRC}
        ${GFX_SRC}
        ${IMGUI_SRC}
)
target_link_libraries(
        Vertex3D
        opengl32
        glu32
        glad
        glm
        SDL::SDL
        ${SDL_LIBRARY}
        ${SDL_LIBRARIES}
        ${OPENGL_LIBRARIES}
        ${IMGUI_LIBRARIES}
)