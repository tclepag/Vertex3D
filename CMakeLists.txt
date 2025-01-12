## For simplicity, and avoiding the manual process of installing packages
## Packages will be automatically downloaded from git and made available for this cmake project
cmake_minimum_required(VERSION 3.30)
project(Vertex3D)

set(CMAKE_GENERATOR_PLATFORM "x86")

# ImGui Source
set(IMGUI_SRC
        src/bin/include/imgui/imgui_impl_vulkan.h
        src/bin/include/imgui/imgui_impl_vulkan.cpp
        src/bin/include/imgui/imgui.h
        src/bin/include/imgui/imgui.cpp
        src/bin/include/imgui/imgui_draw.cpp
        src/bin/include/imgui/imgui_tables.cpp
        src/bin/include/imgui/imgui_widgets.cpp
        src/bin/include/imgui/imgui_demo.cpp
)

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
find_package( Vulkan REQUIRED )

if ( Vulkan_FOUND )
    message( STATUS "Found Vulkan: ${Vulkan_LIBRARIES}" )
    # Add Vulkan include directories and libraries to your target
    include_directories( ${Vulkan_INCLUDE_DIRS} )
    link_directories( ${Vulkan_LIBRARIES} )

else ()
    message( FATAL_ERROR "Could not find Vulkan SDK" )
endif ()


add_executable( Vertex3D src/main.cpp
        ${IMGUI_SRC}
        src/bin/cpp/engine/vk/Vulkan.cpp
        src/bin/cpp/engine/vk/Vulkan.h
        src/bin/cpp/engine/sdl/SDLWindow.cpp
        src/bin/cpp/engine/sdl/SDLWindow.h
        src/bin/cpp/engine/vk/vkObjects/VulkanInstance.cpp
        src/bin/cpp/engine/vk/vkObjects/VulkanInstance.h
)
target_link_libraries(
        Vertex3D
        Vulkan::Vulkan
        SDL::SDL
        ${VULKAN_LIBRARIES}
        ${SDL_LIBRARY}
        ${SDL_LIBRARIES}
        ${IMGUI_LIBRARIES}
)