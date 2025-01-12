//
// Created by lepag on 1/11/2025.
//

#include "Vulkan.h"

using std::cout;

namespace Vertex3D {
    Vulkan::Vulkan() {
        this->_info = {
            .sType = VK_STRUCTURE_TYPE_APPLICATION_INFO,
            .pNext = nullptr,
            .pApplicationName = "V3D",
            .applicationVersion = 0,
            .pEngineName = "Vertex3D",
            .engineVersion = 0,
            .apiVersion = VK_API_VERSION_1_0,
        };
    }

    bool Vulkan::IsReady() {
        return this->_ready;
    }

    int Vulkan::CreateWindow() {
        // Initialize SDL
        SDL_Init( SDL_INIT_VIDEO );

        // Create WindowFlags
        SDL_WindowFlags window_flags = (SDL_WindowFlags)(
            SDL_WINDOW_VULKAN |
            SDL_WINDOW_SHOWN |
            SDL_WINDOW_RESIZABLE
            );

        // Create Window
        SDL_Window* window = SDL_CreateWindow(
            "Vertex3D", // Window Title
            SDL_WINDOWPOS_UNDEFINED, // Window Position X
            SDL_WINDOWPOS_UNDEFINED, // Window Position Y
            this->_width, // Window Width (Pixels)
            this->_height, // Window Height (Pixels)
            window_flags
            );

        if (!window) {
            std::cout << " SDL ERROR:" << SDL_GetError() << std::endl;
            return EXIT_FAILURE;
        }

        this->_wnd = window;
        // Everything went fine
        this->_ready = true;
        this->Run();
        return EXIT_SUCCESS;
    }

    void Vulkan::HandleEvent(SDL_WindowEvent e) {
        switch ( e.event ) {
            case SDL_WINDOWEVENT_RESIZED:
                this->_width = e.data1;
                this->_height = e.data2;
                this->_update = true;
            default: ;
        }
    }


    void Vulkan::Run() {
        SDL_Event event;
        bool quit = false;

        while (!quit) {
            while (SDL_PollEvent(&event) != 0) {
                if (event.type == SDL_QUIT) {
                    quit = true; // If the user clicks the X or alt-f4s this'll be true
                }
            }

            this->Update(event); // Update the window
        }
    }

    void Vulkan::Update(const SDL_Event &event) {
        this->HandleEvent(event.window); // Handle events
        this->Viewport(); // Update viewport
        this->Draw(); // Draw screen
    }

    void Vulkan::Viewport() {

    }

    void Vulkan::Draw() {

    }

    void Vulkan::DestroyWindow() {
        if ( this->_ready && this->_wnd ) {
            SDL_DestroyWindow(this->_wnd);
            this->_wnd = nullptr;
        }
    }

    bool Vulkan::IsWindowValid() {
        return this->_wnd != nullptr;
    }

    Vulkan::~Vulkan() {
        this->DestroyWindow();
    }

} // Vertex3D