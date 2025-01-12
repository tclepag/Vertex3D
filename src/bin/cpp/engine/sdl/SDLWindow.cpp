//
// Created by lepag on 1/12/2025.
//

#include "SDLWindow.h"

#include <iostream>

namespace Vertex3D {
    SDLWindow::SDLWindow() {
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
            exit(-1);
        }
        _ready = true;
    }

    void SDLWindow::CreateWindow(const char *title, const char* iconPath, int w, int h, SDL_WindowFlags flags) {
        if ( !_ready ) {
            std::cout << "SDLWindow::CreateWindow() Called but SDL isn't ready" << std::endl;
        }

        // Create Window
        SDL_Window *window = SDL_CreateWindow(title, w, h, flags);
        if ( !window ) { // Did we fail to create the window?
            std::cout << "SDL_CreateWindow() Error: " << SDL_GetError() << std::endl;
            exit(-1);
        }

        SDL_Surface *app_ico = IMG_Load(iconPath);
        SDL_SetWindowIcon(window, app_ico);

        // Create Renderer
        SDL_Renderer *renderer = SDL_CreateRenderer(window, nullptr);
        if ( !renderer ) { // Did we fail to create the renderer?
            std::cout << "SDL_CreateRenderer() Error: " << SDL_GetError() << std::endl;
        }

        this->window = window;
        this->renderer = renderer;
    }


    void SDLWindow::Run() {
        if ( !_ready ) {
            std::cout << "SDLWindow::Run() Called but SDL isn't ready" << std::endl;
        }
        if ( !window ) {
            std::cout << "SDLWindow::Run() Called but no SDL Window was found" << std::endl;
        }

        bool _quit = false;

        while ( !_quit ) {
            SDL_Event event;
            while ( SDL_PollEvent( &event ) != 0 ) { // (1 = events to process, 0 = no events to process)
                if ( event.type == SDL_EVENT_QUIT ) { // User is attempting to leave manually or by force
                    _quit = true;
                    break;
                }
            }

            this->Update(event);
        }

        // SDL No longer needs to process, exit the application
        this->~SDLWindow();
    }

    // Runs every poll event, handles window
    void SDLWindow::Update(SDL_Event event) {
        SDL_SetRenderDrawColor(this->renderer, 50, 50, 50, 255); // Change background color
        SDL_RenderClear(this->renderer); // Clear render to set applied changes, and wait for present to run
        SDL_RenderPresent(this->renderer); // All changes set will now be visible
    }

    SDLWindow::~SDLWindow() {
        SDL_DestroyRenderer(this->renderer);
        SDL_DestroyWindow(this->window);
        SDL_Quit();
    }


} // Vertex3D