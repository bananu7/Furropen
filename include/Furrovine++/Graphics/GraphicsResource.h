#pragma once

#include <Furrovine++/Event.h>
#include <Furrovine++/Graphics/Declarations.Graphics.h>
#include <Furrovine++/null.h>

namespace Furrovine { namespace Graphics {
	
	class GraphicsResource {
	protected:
		GraphicsDevice* graphicsdevice;

	public:
		Event<GraphicsResource&> Disposing;

		furrovineapi GraphicsResource( );

		furrovineapi GraphicsResource( GraphicsDevice* graphicsdevice );

		furrovineapi GraphicsResource( GraphicsDevice& graphicsdevice );

		furrovineapi GraphicsResource( GraphicsResource&& resource );

		furrovineapi GraphicsResource( const GraphicsResource& resource );

		furrovineapi GraphicsResource& operator=( GraphicsResource&& resource );

		furrovineapi GraphicsResource& operator=( const GraphicsResource& resource );

		furrovineapi GraphicsDevice& Device( );

		furrovineapi bool HasDevice( ) const;

		furrovineapi ~GraphicsResource( );

	};


}}
