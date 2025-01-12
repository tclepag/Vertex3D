## For simplicity, and avoiding the manual process of installing packages
## Packages will be automatically downloaded from git and made available for this cmake project
cmake_minimum_required(VERSION 3.30)
project(Vertex3D)

include(FetchContent)

# Vulkan Packages
find_package( Vulkan REQUIRED )

if ( Vulkan_FOUND )
    message( STATUS "Found Vulkan: ${Vulkan_LIBRARIES}" )
    # Add Vulkan include directories and libraries to your target
    include_directories( ${Vulkan_INCLUDE_DIRS} )
    link_directories( ${Vulkan_LIBRARIES} )

    # Add SDL
    set(SDL_INCLUDE_DIR "C:/VulkanSDK/1.3.296.0/Include/SDL2")
    set(SDL_LIBRARY "C:/VulkanSDK/1.3.296.0/Lib/SDL2/SDL2.lib")  # or .so/.dll depending on your platform

    include_directories(${SDL_INCLUDE_DIR})
    link_directories(${SDL_LIBRARY})

    # Find SDL
    find_package( SDL REQUIRED )

else ()
    message( FATAL_ERROR "Could not find Vulkan SDK" )
endif ()

add_executable( Vertex3D src/main.cpp
        src/bin/cpp/engine/vk/Vulkan.cpp
        src/bin/cpp/engine/vk/Vulkan.h
)
target_link_libraries(
        Vertex3D
        Vulkan::Vulkan
        ${VULKAN_LIBRARIES}
        ${SDL_LIBRARY}
)