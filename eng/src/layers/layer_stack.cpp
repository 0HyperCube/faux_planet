#include "layer_stack.h"

namespace Eng {
void LayerStack::AddLayer(Element layer)
{
	m_Layers[0].push_back(std::move(layer));
}
void LayerStack::AddOverlayLayer(Element layer)
{
	// m_Layers[1].push_back(layer);
}
void LayerStack::RemoveLayer(Layer* layer)
{
	// m_Layers[0].erase(std::remove(m_Layers[0].begin(), m_Layers[0].end(), layer));
}
void LayerStack::RemoveOverlayLayer(Layer* layer)
{
	// m_Layers[1].erase(std::remove(m_Layers[1].begin(), m_Layers[1].end(), layer));
}
}