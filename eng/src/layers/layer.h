#include "engpch.h"
#include "events/base.h"

#ifndef ENG_LAYER_GUARD
#define ENG_LAYER_GUARD

namespace Eng {
struct Application;
class Layer {

public:
	Layer(const char* debugName)
		: m_DebugName(debugName)
	{
	}
	const char* GetDebugName() { return m_DebugName; }
	virtual ~Layer() { }
	virtual void OnUpdate(Application* application) { }
	virtual bool OnEvent(Application* application, BaseEvent& event) { return false; }

private:
	const char* m_DebugName;
};
}

template <>
struct fmt::formatter<Eng::Layer> : fmt::formatter<std::string> {
	auto format(Eng::Layer my, format_context& ctx) const -> decltype(ctx.out())
	{
		return format_to(ctx.out(), "Layer {{ DebugName: \"{}\" }}", my.GetDebugName());
	}
};

template <>
struct fmt::formatter<Eng::Layer*> : fmt::formatter<std::string> {
	auto format(Eng::Layer* my, format_context& ctx) const -> decltype(ctx.out())
	{
		return format_to(ctx.out(), "Layer {{ DebugName: \"{}\" }}", my->GetDebugName());
	}
};
#endif