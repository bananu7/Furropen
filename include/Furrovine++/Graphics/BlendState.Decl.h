#pragma once

#include <Furrovine++/Vector4.h>
#include <Furrovine++/Graphics/graphics_handle.h>
#include <Furrovine++/Graphics/BlendFactor.h>
#include <Furrovine++/Graphics/BlendOperation.h>
#include <Furrovine++/Graphics/ColorWriteChannels.h>
#include <Furrovine++/Graphics/GraphicsResource.h>
#include <Furrovine++/Graphics/BlendStateDescription.h>

namespace Furrovine { namespace Graphics {

	class BlendStateCollection;

	class BlendState {
	public:
		furrovineapi static const BlendStateDescription Default;
		furrovineapi static const BlendStateDescription AlphaBlend;
		furrovineapi static const BlendStateDescription NonPremultiplied;
		furrovineapi static const BlendStateDescription Additive;
		furrovineapi static const BlendStateDescription Opaque;
		furrovineapi static const BlendStateDescription None;
	
	protected:
		friend class BlendStateCollection;
		BlendStateDescription statedesc;

	public:

		furrovineapi BlendState( const BlendStateDescription& desc );
		furrovineapi BlendState( GraphicsDevice& graphicsdevice, ulword rendertarget );
		furrovineapi BlendState( GraphicsDevice& graphicsdevice, ulword rendertarget, graphics_handle blendstate );

		furrovineapi BlendState( const BlendState& copy );
		furrovineapi BlendState& operator=( const BlendState& copy );

		furrovineapi const BlendStateDescription& Description( ) const;

		furrovineapi ulword HashCode( ) const;

		furrovineapi bool operator== ( const BlendState& blend ) const;
		furrovineapi bool operator!= ( const BlendState& blend ) const;

		furrovineapi ~BlendState( );

	};

}}
