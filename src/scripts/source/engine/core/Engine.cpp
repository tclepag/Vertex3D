//
// Created by lepag on 1/19/2025.
//

#include "../src/scripts/include/engine/core/Engine.h"

namespace Vertex3D {
    Engine::EngineCore() {
        this->SetupWindow();
        this->SetupRenderer();
    }

    void Engine::SetupRenderer() {
        auto* renderer = new Renderer();
        this->renderer = renderer;
    }

    void Engine::SetupWindow() {
        auto *wnd = new SDLWindow();
        wnd->handler = this;

        wnd->SetupWindow("Vertex3D", "src/bin/materials/textures/app/app.png", 800, 600, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
        wnd->Run();
        this->window = wnd;
    }

    void Engine::Update(SDL_Event* event) {
        if (!this->update) {
            return;
        }
        this->gl->Update(event);
        if (this->renderer) {
            int renderer_ratio = this->renderer->width / this->renderer->height;
            int window_ratio = this->window->width / this->window->height;

            // Is the renderer's ratio dissimilar to ours?
            if (renderer_ratio != window_ratio) {
                // Update the renderer's glViewport
                this->renderer->UpdateScreenSize(this->window->width, this->window->height);
            }

            this->renderer->Render(event);
        }

        if (this->window->RequestQuit()) {
            this->update = false;
            this->~EngineCore();
        }
    }

    Engine::~Engine() {
        this->gl->~OpenGLH();
        this->window->~SDLWindow();
        this->running = false;
    }

} // Vertex3D