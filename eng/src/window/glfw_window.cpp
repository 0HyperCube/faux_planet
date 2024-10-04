#include "glfw_window.h"

namespace Eng {
static bool s_InitGlfw = false;
WindowInterface* GlfwWindow::Create(WindowProperties properties)
{
	return new GlfwWindow(properties);
}

void GlfwWindow::ErrorCallback(int error, const char* description)
{
	ENG_CORE_ERROR("GFLW error: {}", description);
}

GlfwWindow::GlfwWindow(WindowProperties properties)
{
	ENG_CORE_INFO("Creating window with {}", properties);

	if (!s_InitGlfw) {
		s_InitGlfw = true;
		int success = glfwInit();
		ENG_CORE_ASSERT(success, "Cannot init glfw");
		glfwSetErrorCallback(GlfwWindow::ErrorCallback);
	}

	m_Window = glfwCreateWindow(properties.Width, properties.Height, properties.Title, NULL, NULL);
	ENG_CORE_ASSERT(m_Window, "No window");

	glfwMakeContextCurrent(m_Window);
	glfwSetWindowUserPointer(m_Window, &m_Data);
}

void GlfwWindow::SetEventCallback(EventCallback callback)
{
	m_Data.callback = callback;
}

GlfwWindow::~GlfwWindow()
{
	ENG_CORE_INFO("Destroying window");
	glfwDestroyWindow(m_Window);
	glfwTerminate();
	s_InitGlfw = false;
}
}