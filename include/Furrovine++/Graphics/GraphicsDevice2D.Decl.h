#pragma once

#include <Furrovine++/Declarations.h>
#include <Furrovine++/Strings.h>
#include <Furrovine++/handle.h>
#include <Furrovine++/Graphics/graphics_handle.h>
#include <Furrovine++/Colors.h>
#include <Furrovine++/Graphics/GraphicsDevice.h>
#include <Furrovine++/Graphics/RenderBuffer2D.h>
#include <Furrovine++/Text/Font.h>

namespace Furrovine { namespace Graphics {

	class GraphicsDevice2D {
	private:
		struct render_target_deleter {
			furrovineapi void operator()( graphics_handle p );
		};
		struct brush_deleter {
			furrovineapi void operator()( graphics_handle p );
		};
		struct factory_deleter {
			furrovineapi void operator()( graphics_handle p );
		};
		struct device_deleter {
			furrovineapi void operator()( graphics_handle p );
		};
		struct device_context_deleter {
			furrovineapi void operator()( graphics_handle p );
		};
		GraphicsDevice* graphicsdevice;
		handle<graphics_handle, render_target_deleter> rendertargetresource;
		handle<graphics_handle, brush_deleter> basicbrushresource;
		handle<graphics_handle, factory_deleter> factoryresource;
		handle<graphics_handle, device_deleter> deviceresource;
		handle<graphics_handle, device_context_deleter> devicecontextresource;
		bool hasbegun;
		
		furrovineapi void Create( GraphicsDevice& graphics );

	public:

		furrovineapi GraphicsDevice2D( GraphicsDevice& graphics );
		
		furrovineapi bool Ready( ) const;

		furrovineapi graphics_handle DeviceContextResource( ) const;
		furrovineapi graphics_handle DeviceResource( ) const;
		furrovineapi graphics_handle FactoryResource( ) const;
		furrovineapi graphics_handle RenderTargetResource( ) const;
		furrovineapi graphics_handle BrushResource( ) const;

		furrovineapi void Begin( );

		furrovineapi void RenderText( Text::Font& font, String text );

		furrovineapi void End( );

		furrovineapi void Present( );

		furrovineapi void Clear( const Color& color = Colors::Transparent );

	};
}}
