#pragma once

#include <Furrovine++/Graphics/GraphicsDevice.h>
#include <Furrovine++/Graphics/GraphicsResource.h>
#include <Furrovine++/Graphics/RasterizerStateDescription.h>

namespace Furrovine { namespace Graphics {

	class RasterizerState : public GraphicsResource {
	public:
		furrovineapi static const RasterizerStateDescription Default;
		furrovineapi static const RasterizerStateDescription DefaultWireframe;
		furrovineapi static const RasterizerStateDescription CullCounterClockwise;
		furrovineapi static const RasterizerStateDescription CullClockwise;
		furrovineapi static const RasterizerStateDescription CullNone;
		furrovineapi static const RasterizerStateDescription CullCounterClockwiseWireframe;
		furrovineapi static const RasterizerStateDescription CullClockwiseWireframe;
		furrovineapi static const RasterizerStateDescription CullNoneWireframe;

	private:
		struct deleter {
			furrovineapi void operator() ( graphics_handle p );
		};
		handle<graphics_handle, deleter>  stateres;
		RasterizerStateDescription statedesc;
		bool applied;
		
	public:

		furrovineapi RasterizerState( GraphicsDevice& graphicsdevice );

		furrovineapi RasterizerState( GraphicsDevice& graphicsdevice, const RasterizerStateDescription& desc );

		furrovineapi RasterizerState( GraphicsDevice& graphicsdevice, graphics_handle rasterizerstate );

		furrovineapi RasterizerState ( const RasterizerState& copy );

		furrovineapi const RasterizerStateDescription& Description( ) const;

		furrovineapi graphics_handle StateResource( ) const;

		furrovineapi ulword HashCode( ) const;

		furrovineapi bool operator== ( const RasterizerState& rasterizer ) const;

		furrovineapi bool operator!= ( const RasterizerState& rasterizer ) const;

		furrovineapi void Apply ( );

		furrovineapi RasterizerState& operator= ( const RasterizerState& copy );

		furrovineapi RasterizerState& operator= ( RasterizerState&& mov );

		furrovineapi ~RasterizerState ();

	};

}}
