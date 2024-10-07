#include "application.h"

namespace Eng {
bool fn(KeyDownEvent& ev)
{
	ENG_CORE_INFO("hieeu {}", ev);
	return true;
}

Application::Application()
{
	Log::init();

	m_Window = std::unique_ptr<Eng::WindowInterface>(Eng::GlfwWindow::Create(Eng::WindowInterface::WindowProperties()));
	m_Window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));

	auto layers = LayerStack();
	Layer mylayer = Layer("layer 1");

	layers.AddLayer(&mylayer);
	ENG_INFO("{}", layers);
}
void Application::Render()
{
	glClearColor(1., 1., 0., 1.);

	glClear(GL_COLOR_BUFFER_BIT);
	m_Window->Update();
}

} // namespace FauxPlanet