// ImGui
#include <functional>
#include <variant>

#include "bin/cpp/engine/opgl/OpenGLH.h"
#include "bin/cpp/engine/util/debug/Debug.h"
#include "bin/cpp/engine/util/Signals/VSignal.h"
#include "bin/include/imgui/imgui.h"
#include "bin/include/imgui/imgui_impl_opengl3.h"
#include "bin/include/imgui/imgui_impl_sdl2.h"
#include "bin/cpp/engine/util/debug/Debug.h"

using namespace Vertex3D;

int main() {
    auto* app = new EngineCore();

    // Setup ImGui Context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Allow keyboard input

    ImGui::StyleColorsDark(); // Set ImGui Style to Dark Mode

    //ImGui_ImplSDL2_InitForOpenGL(opGL->window->window, opGL->window->context);
    //ImGui_ImplOpenGL3_Init("#version 330");

    //opGL->engine_updated.subscribe([](SDL_Event* event) {
        //std::cout << event->type << std::endl;
    //});

    app->~EngineCore();

    return 0;
}
