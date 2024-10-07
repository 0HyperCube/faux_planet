#ifndef ENG_APPLICATION_HEADER_GUARD
#define ENG_APPLICATION_HEADER_GUARD

#include "engpch.h"
#include "events/events.h"
#include "layers/layer_stack.h"
#include "window/glfw_window.h"

namespace Eng {
class Application {
public:
	Application();
	void Render();
	const Eng::WindowInterface* GetWindow() { return &*m_Window; }
	Eng::LayerStack* GetLayers() { return &*m_Layers; }

private:
	void OnEvent(BaseEvent& event);
	std::unique_ptr<Eng::WindowInterface> m_Window;
	std::unique_ptr<LayerStack> m_Layers;
};
} // namespace Eng

#endif
