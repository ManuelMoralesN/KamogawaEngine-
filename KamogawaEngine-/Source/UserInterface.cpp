#include "UserInterface.h"

void 
UserInterface::init(void* window, 
			        ID3D11Device* device, 
			        ID3D11DeviceContext* deviceContext) {
    // Inicialización básica de ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Habilitar navegación con teclado

    // Inicialización de backends
    ImGui_ImplWin32_Init(window);
    ImGui_ImplDX11_Init(device, deviceContext);

    // Estilo negro
    ImGui::StyleColorsDark();
}

void 
UserInterface::update(){

}

void 
UserInterface::render(XMFLOAT3& position, XMFLOAT3& rotation, XMFLOAT3& scale, XMMATRIX& modelMatrix, XMMATRIX& viewMatrix, XMMATRIX& projectionMatrix){
    ImGui_ImplDX11_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();

    ImGui::Begin("Inspector", nullptr, ImGuiWindowFlags_NoCollapse);
    ImGui::Text("Muevele pa:");

    ImGui::Separator();
    vec3Control("Position", &position.x, 0.0f);
    ImGui::Separator();
    vec3Control("Rotation", &rotation.x, 0.0f);
    ImGui::Separator();
    vec3Control("Scale", &scale.x, 1.0f);
    ImGui::Separator();

    ImGui::End();

    ImGui::Render();
    ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
}

void 
UserInterface::destroy(){
    ImGui_ImplDX11_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();
}

void 
UserInterface::vec3Control(std::string label, 
				   float* values, 
				   float resetValues, 
				   float columnWidth){
    ImGui::PushID(label.c_str());

    ImGui::Columns(2);
    ImGui::SetColumnWidth(0, columnWidth);
    ImGui::Text("%s", label.c_str());
    ImGui::NextColumn();

    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2{ 0, 0 });

    float widthEach = (ImGui::GetContentRegionAvail().x - 2.0f) / 3.0f;

    ImGui::PushItemWidth(widthEach);
    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{ 0.8f, 0.1f, 0.1f, 1.0f }); // Rojo
    if (ImGui::Button("X")) values[0] = resetValues;
    ImGui::SameLine();
    ImGui::DragFloat("##X", &values[0], 0.1f, -10.0f, 10.0f, "%.3f");
    ImGui::PopStyleColor();
    ImGui::PopItemWidth();

    ImGui::SameLine();

    ImGui::PushItemWidth(widthEach);
    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{ 0.2f, 0.8f, 0.2f, 1.0f }); // Verde
    if (ImGui::Button("Y")) values[1] = resetValues;
    ImGui::SameLine();
    ImGui::DragFloat("##Y", &values[1], 0.1f, -10.0f, 10.0f, "%.3f");
    ImGui::PopStyleColor();
    ImGui::PopItemWidth();

    ImGui::SameLine();

    ImGui::PushItemWidth(widthEach);
    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{ 0.1f, 0.3f, 0.8f, 1.0f }); // Azul
    if (ImGui::Button("Z")) values[2] = resetValues;
    ImGui::SameLine();
    ImGui::DragFloat("##Z", &values[2], 0.1f, -10.0f, 10.0f, "%.3f");
    ImGui::PopStyleColor();
    ImGui::PopItemWidth();

    ImGui::PopStyleVar();
    ImGui::Columns(1);
    ImGui::PopID();
}