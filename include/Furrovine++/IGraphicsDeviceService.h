#pragma once

#include <Furrovine++/IService.h>
#include <Furrovine++/Graphics/GraphicsDevice.h>
#include <Furrovine++/Graphics/GraphicsDevice2D.h>

namespace Furrovine {

	typedef IService<Graphics::GraphicsDevice> IGraphicsDeviceService;
	typedef IService<Graphics::GraphicsDevice2D> IGraphicsDevice2DService;
	
}
