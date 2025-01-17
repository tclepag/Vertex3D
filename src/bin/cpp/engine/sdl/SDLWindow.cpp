//
// Created by lepag on 1/12/2025.
//

#include "SDLWindow.h"
#include <GL/gl.h>

namespace Vertex3D {
    SDLWindow::SDLWindow() {
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
            exit(-1);
        }
        _ready = true;
    }

    void SDLWindow::SetupWindow(const char *title, const char* iconPath, int w, int h, SDL_WindowFlags flags) {
        if ( !_ready ) {
            std::cout << "SDLWindow::CreateWindow() Called but SDL isn't ready" << std::endl;
        }

        // Create Window
        SDL_Window *wnd = SDL_CreateWindow(title, w, h, flags);
        if ( !wnd ) { // Did we fail to create the window?
            std::cout << "SDL_CreateWindow() Error: " << SDL_GetError() << std::endl;
            exit(-1);
        }

        SDL_Surface *app_ico = IMG_Load(iconPath);
        SDL_SetWindowIcon(wnd, app_ico);
        SDL_GLContext glcontext = SDL_GL_CreateContext(wnd);

        this->context = glcontext;
        this->window = wnd;
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
                }
            }

            this->Update(event);
        }

        // SDL No longer needs to process, exit the application
        this->handler->~OpenGLH();
    }

    // Runs every poll event, handles window
    void SDLWindow::Update(SDL_Event event) {
        if (event.type == SDL_EVENT_WINDOW_RESIZED) {
            SDL_GetWindowSize(this->window, &this->width, &this->height);
        }
        glViewport(0, 0, this->width, this->height);
        glClearColor(0.9, 0.4, 0.6, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        SDL_GL_SwapWindow(this->window);

        this->handler->Update(&event);
    }

    void SDLWindow::Cleanup() {
        SDL_DestroyWindow(this->window);
        SDL_PumpEvents();
        SDL_Quit();
    }


} // Vertex3D