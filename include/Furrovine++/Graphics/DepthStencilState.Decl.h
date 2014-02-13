#pragma once

#include <Furrovine++/handle.h>
#include <Furrovine++/Graphics/graphics_handle.h>
#include <Furrovine++/Graphics/GraphicsResource.h>
#include <Furrovine++/Graphics/DepthStencilStateDescription.h>

namespace Furrovine { namespace Graphics {

	class DepthStencilState : public GraphicsResource {
	public:
		furrovineapi static const DepthStencilStateDescription None;
		furrovineapi static const DepthStencilStateDescription DepthRead;
		furrovineapi static const DepthStencilStateDescription Default;
		furrovineapi static const DepthStencilStateDescription DefaultStencil;

	protected:
		struct deleter {
			furrovineapi void operator() ( void* p );
		};
		bool applied;
		handle<graphics_handle, deleter>  stateres;
		DepthStencilStateDescription statedesc;

	public:

		furrovineapi DepthStencilState( GraphicsDevice& graphicsdevice );

		furrovineapi DepthStencilState( GraphicsDevice& graphicsdevice, const DepthStencilStateDescription& statedesc );

		furrovineapi DepthStencilState (GraphicsDevice& graphicsdevice, void* depthstencilstate );

		furrovineapi DepthStencilState( const DepthStencilState& copy );

		furrovineapi DepthStencilState( DepthStencilState&& mov );

		furrovineapi const DepthStencilStateDescription& Description( ) const;

		furrovineapi graphics_handle StateResource( ) const;

		furrovineapi void Apply( );

		furrovineapi ulword HashCode () const;

		furrovineapi bool operator== ( const DepthStencilState& blend ) const;

		furrovineapi bool operator!= ( const DepthStencilState& blend ) const;

		furrovineapi DepthStencilState& operator= ( const DepthStencilState& copy );

		furrovineapi DepthStencilState& operator= ( DepthStencilState&& mov );

		furrovineapi ~DepthStencilState ();

	};

}}
