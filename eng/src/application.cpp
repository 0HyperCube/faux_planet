#include "application.h"
#include "layers/imgui_layer.h"

namespace Eng {
bool fn(KeyDownEvent& ev)
{
	ENG_CORE_INFO("hieeu {}", ev);
	return true;
}

void Application::OnEvent(Eng::BaseEvent& event)
{

	for (auto layer : m_Layers->GetLayers()) {
		layer->OnEvent(this, event);
	}
}

Application::Application()
{
	Log::init();

	m_Layers = std::make_unique<Eng::LayerStack>();
	m_Window = std::unique_ptr<Eng::WindowInterface>(Eng::GlfwWindow::Create(Eng::WindowInterface::WindowProperties()));
	m_Window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));

	Eng::Layer* mylayer = new Eng::Layer("layer 1");
	Eng::Layer* imgui = new Eng::ImguiLayer();

	m_Layers->AddLayer(mylayer);
	m_Layers->AddLayer(imgui);
	ENG_INFO("{}", *m_Layers);
}
void Application::Render()
{
	glClearColor(1., 1., 0., 1.);

	glClear(GL_COLOR_BUFFER_BIT);
	for (auto layer : m_Layers->GetLayers()) {
		layer->OnUpdate(this);
	}

	m_Window->Update();
}

} // namespace FauxPlanet