#include "application.h"
#include "engpch.h"
#include "layer.h"

namespace Eng {
class ImguiLayer : public Layer {
public:
	ImguiLayer()
		: Layer("IMGui Layer")
	{
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		ImGui_ImplOpenGL3_Init();
	}

	void OnUpdate(Application* application) override
	{
		ImGuiIO& io = ImGui::GetIO();
		auto window = application->GetWindow();
		auto size = window->GetSize();
		io.DisplaySize = ImVec2((float)size[0], (float)size[1]);
		io.DeltaTime = 1. / 50.;

		ENG_CORE_INFO("Update {}", size);
		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		static bool x = true;
		ImGui::ShowDemoWindow(&x);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}
};
}