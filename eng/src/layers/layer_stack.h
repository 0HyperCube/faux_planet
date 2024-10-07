#include "engpch.h"
#include "layer.h"

namespace Eng {
class LayerStack {
public:
	using Element = Layer*;
	LayerStack() { }
	void AddLayer(Element layer);
	void AddOverlayLayer(Element layer);

	void RemoveLayer(Layer* layer);
	void RemoveOverlayLayer(Layer* layer);

	auto GetLayers()
	{
		return std::ranges::join_view(m_Layers);
	}

private:
	std::array<std::vector<Element>, 2> m_Layers = { std::vector<Element>(), std::vector<Element>() };
};
}

template <>
struct fmt::formatter<Eng::LayerStack> : fmt::formatter<std::string> {
	auto format(Eng::LayerStack my, format_context& ctx) const -> decltype(ctx.out())
	{

		return format_to(ctx.out(), "LayerStack {{ Layers: [{}] }}", fmt::join(my.GetLayers(), ", "));
	}
};
