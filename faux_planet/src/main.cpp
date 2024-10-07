#include "eng.h"

class MyApplication : public Eng::Application {
public:
	MyApplication();

	bool Close(Eng::WindowCloseEvent& event);

	void Run();

private:
	bool m_Running = true;
};

class StandardLayer : public Eng::Layer {
public:
	StandardLayer()
		: Layer("Standard Layer")
	{
	}
	bool OnEvent(Eng::Application* application, Eng::BaseEvent& event) override
	{
		auto bound = std::bind(&MyApplication::Close, (MyApplication*)application, std::placeholders::_1);
		return Eng::Dispatch<Eng::WindowCloseEvent>(bound, event);
	}
};

MyApplication::MyApplication()
{
	GetLayers()->AddLayer(new StandardLayer());
}

bool MyApplication::Close(Eng::WindowCloseEvent& event)
{
	m_Running = false;
	return true;
}

void MyApplication::Run()
{
	while (m_Running) {
		Render();
	}
}

int main()
{
	auto application = MyApplication();
	application.Run();

	return 0;
}
