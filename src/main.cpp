// ImGui
#include "bin/cpp/engine/opgl/OpenGLH.h"
#include "bin/include/imgui/imgui.h"
#include "bin/include/imgui/imgui_impl_opengl3.h"
#include "bin/include/imgui/imgui_impl_sdl2.h"

using Vertex3D::OpenGLH;

int main() {
    auto* opGL = new OpenGLH();
    opGL->Setup();

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
