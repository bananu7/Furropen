#pragma once

#include <Furrovine++/Graphics/DisplayMode.h>
#include <Furrovine++/Graphics/MultisampleDescription.h>

namespace Furrovine { namespace Graphics {

	struct GraphicsDeviceSettings {
		DisplayMode Display;
		bool VerticalSync, Windowed;
		MultisampleDescription Multisample;
	};

}}