#pragma once

#include <Furrovine++/handle.h>
#include <Furrovine++/Graphics/graphics_handle.h>
#include <Furrovine++/Graphics/ShaderResourceViewDimension.h>
#include <Furrovine++/Graphics/GraphicsResource.h>

namespace Furrovine { namespace Graphics {

	class ShaderResourceView : public GraphicsResource {
	protected:
		struct deleter {
			furrovineapi void operator() ( graphics_handle p );
		};
		ShaderResourceViewDimension dimension;
		handle<graphics_handle, deleter> shaderresourceview;

	public:

		furrovineapi ShaderResourceView( );
		furrovineapi ShaderResourceView( GraphicsDevice& graphicsdevice );
		furrovineapi ShaderResourceView ( GraphicsDevice& graphicsdevice, graphics_handle originalview );

		furrovineapi ShaderResourceView ( ShaderResourceView&& mov );
		furrovineapi ShaderResourceView& operator= ( ShaderResourceView&& mov );

		furrovineapi graphics_handle ShaderResourceViewResource () const;

		furrovineapi ShaderResourceViewDimension ResourceViewDimension () const;

	};

}}
