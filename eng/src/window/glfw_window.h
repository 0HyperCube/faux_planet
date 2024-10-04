#include "engpch.h"
#include "window_interface.h"

namespace Eng {
class GlfwWindow : public WindowInterface {
public:
	GlfwWindow(WindowProperties properties);
	static WindowInterface* Create(WindowProperties properties);
	void SetEventCallback(EventCallback callback);
	void Update() override
	{
		glfwSwapBuffers(m_Window);
		glfwPollEvents();
	}
	~GlfwWindow();

private:
	struct WindowData {
		EventCallback callback;
	};

	GLFWwindow* m_Window;
	WindowData m_Data;
	static void ErrorCallback(int error, const char* description);
};
}