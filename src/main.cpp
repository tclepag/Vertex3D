// ImGui
#include <functional>
#include <variant>

#include "bin/cpp/engine/opgl/OpenGLH.h"
#include "bin/cpp/engine/util/Signals/ISignal.h"
#include "bin/include/imgui/imgui.h"
#include "bin/include/imgui/imgui_impl_opengl3.h"
#include "bin/include/imgui/imgui_impl_sdl2.h"

using Vertex3D::OpenGLH;
using Vertex3D::ISignal;

int main() {

    ISignal< std::variant< bool, std::nullptr_t > > signal;

    signal.subscribe([](const std::variant<bool, std::nullptr_t> arg) {
        if (std::holds_alternative<std::nullptr_t>(arg)) {
            std::cout << "Variant is empty (like nullptr)" << std::endl;
        } else {
            std::cout << std::get<bool>(arg) << std::endl;
        }
    });

    signal.publish(true);
    signal.publish(nullptr);

    auto* opGL = new OpenGLH();
    opGL->Setup();

    return 0;

    // Setup ImGui Context
    //IMGUI_CHECKVERSION();
    //ImGui::CreateContext();
    //ImGuiIO& io = ImGui::GetIO();
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Allow keyboard input

    //ImGui::StyleColorsDark(); // Set ImGui Style to Dark Mode

    //ImGui_ImplSDL2_InitForOpenGL(opGL->window->window, opGL->window->context);
    //ImGui_ImplOpenGL3_Init("#version 330");

    // TODO: CREATE A SIGNAL CLASS!!!
    return 0;
}
