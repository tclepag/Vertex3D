//
// Created by lepag on 1/19/2025.
//

#ifndef ENGINECORE_H
#define ENGINECORE_H

#include "../opgl/OpenGLH.h"
#include "../sdl/SDLWindow.h"
#include "../gfx/Renderer.h"

namespace Vertex3D {
    // Forward Directives
    class SDLWindow;
    class OpenGLH;

    class EngineCore {
    public:
      SDLWindow* window{};
      OpenGLH* gl{};
      Renderer* renderer{};

      EngineCore();

        void SetupWindow();
        void SetupOpenGL();
        void SetupRenderer();
        void Update(SDL_Event* event) const;

      ~EngineCore();
};

} // Vertex3D

#endif //ENGINECORE_H
