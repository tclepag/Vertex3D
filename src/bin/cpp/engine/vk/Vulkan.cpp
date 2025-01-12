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

    SDL_Window* Vulkan::GetWindow() {
        return this->_wnd;
    }

    int Vulkan::Window() {
        // Initialize SDL
        if (SDL_Init(SDL_INIT_VIDEO) < 0)
            return EXIT_FAILURE;

        // Create WindowFlags
        SDL_WindowFlags window_flags = (SDL_WindowFlags)(
            SDL_WINDOW_VULKAN |
            SDL_WINDOW_RESIZABLE
            );

        // Create Window
        SDL_Window* window = SDL_CreateWindow(
            "Vertex3D", // Window Title
            this->_width, // Window Width (Pixels)
            this->_height, // Window Height (Pixels)
            window_flags
            );

        if (!window) { // Did the window fail to create?
            std::cout << " SDL ERROR:" << SDL_GetError() << std::endl;
            return EXIT_FAILURE;
        }

        this->_wnd = window; // Set SDL Window to our reference

        SDL_Renderer* renderer = SDL_CreateRenderer(
            this->_wnd,
            nullptr
            ); // Setup Renderer
        if (!renderer) { // Did the renderer fail to create?
            std::cout << " SDL ERROR:" << SDL_GetError() << std::endl;
            return EXIT_FAILURE;
        }
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Set Window Background to Red
        SDL_RenderClear(renderer); // Clear Render so it applies this change

        SDL_RenderPresent(renderer); // Everything was drawn behind the scenes, now fully apply changes and make them visible

        this->_renderer = renderer; // Set SDL Renderer to our reference
        // Everything went fine
        this->_ready = true;
        this->Run(); // Begin polling events
        return EXIT_SUCCESS;
    }

    void Vulkan::HandleEvent(SDL_WindowEvent e) {
        switch ( e.type ) {
            case SDL_EVENT_WINDOW_RESIZED:
                this->_width = e.data1;
                this->_height = e.data2;
                this->_update = true;
            default: ;
        }
    }

    void Vulkan::createWindowSurface(VkInstance instance, VkSurfaceKHR *surface) {
        SDL_Surface* windowSurface = SDL_GetWindowSurface(this->_wnd);
        if (windowSurface == nullptr) {
            std::cout << " SDL ERROR:" << SDL_GetError() << std::endl;
        }
        this->_surface = windowSurface;
    }

    void Vulkan::Run() {
        SDL_Event event;
        bool running = true;

        while ( running ) {
            while (SDL_PollEvent(&event) != 0) {
                if (event.type == SDL_EVENT_QUIT) { // Is the user trying to quit the application? (X button, ALT-F4, Forced by developer)
                    running = false;
                    break;
                }

                this->Update(event); // Update the window
            }
        }
        this->~Vulkan(); // SDL No longer needs to update the window, destroy the application
    }

    // Runs every poll event
    void Vulkan::Update(const SDL_Event &event) {
        this->HandleEvent(event.window); // Handle events
        this->Viewport(event); // Update viewport
        this->Draw(event); // Draw screen
    }

    // Update the SDL Viewport every poll event
    void Vulkan::Viewport(const SDL_Event &event) {
        SDL_RenderClear(this->_renderer); // Clear window contents
        SDL_RenderPresent(this->_renderer); // Present changes applied
    }

    // Call the SDL Window to draw objects every poll event
    void Vulkan::Draw(const SDL_Event &event) {

    }

    // Destroy the current window
    void Vulkan::DestroyWindow() {
        if ( this->_ready && this->_wnd ) {
            SDL_DestroyWindow(this->_wnd);
            this->_wnd = nullptr;
            std::cout << "Window Destroyed" << std::endl;
        }
    }

    // Does the window exist?
    bool Vulkan::IsWindowValid() {
        return this->_wnd != nullptr;
    }

    Vulkan::~Vulkan() {
        std::cout << "Vulkan Class deconstructing" << std::endl;
        this->DestroyWindow();
    }

} // Vertex3D