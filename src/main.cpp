// ImGui
#include <functional>
#include <variant>

#include "bin/cpp/engine/main/EngineCore.h"

using namespace Vertex3D;

int main() {
    auto* engine = new EngineCore();

    // Setup ImGui Context
    //IMGUI_CHECKVERSION();
    //ImGui::CreateContext();
    //ImGuiIO& io = ImGui::GetIO();
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Allow keyboard input

    //ImGui::StyleColorsDark(); // Set ImGui Style to Dark Mode

    //ImGui_ImplSDL3_InitForOpenGL(engine->window->window, engine->window->context);
    //ImGui_ImplOpenGL3_Init("#version 330");

    // Keep main process alive until it is not needed
    while (engine->running) {}
    std::cout << "bye bye";
    return 0;
}
