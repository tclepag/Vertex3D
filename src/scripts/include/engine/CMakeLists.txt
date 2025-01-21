cmake_minimum_required(VERSION 3.30)

add_library(ENGINE_INCLUDE INTERFACE)
target_include_directories(ENGINE_INCLUDE INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/buffers
        ${CMAKE_CURRENT_SOURCE_DIR}/common
        ${CMAKE_CURRENT_SOURCE_DIR}/core
        ${CMAKE_CURRENT_SOURCE_DIR}/rendering
)