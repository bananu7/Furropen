#pragma once

#include <Furrovine++/handle.h>
#include <Furrovine++/Graphics/graphics_handle.h>
#include <Furrovine++/Graphics/Constants.h>
#include <Furrovine++/Graphics/BlendState.h>
#include <Furrovine++/Graphics/BlendStateCollectionDescription.h>
#include <Furrovine++/uninitialized.h>
#include <bitset>

namespace Furrovine { namespace Graphics {
	
	class BlendStateCollection : GraphicsResource {
	protected:
		struct deleter {
			furrovineapi void operator() ( graphics_handle p );
		};
		bool applied;
		handle<graphics_handle, deleter>  stateres;
		std::array<uninitialized<BlendState>, detail::SimultaneousRenderTargets> rendertargetstates;
		std::bitset<detail::SimultaneousRenderTargets> dirty;
		BlendStateCollectionDescription statedesc;
		ulword manualblendfactorindex;
		bool statedescdirty;

	public:

		furrovineapi BlendStateCollection( GraphicsDevice& graphicsdevice, bool a2cmultisampling = false, bool independentrendertargetblending = false );
		
		furrovineapi const BlendStateCollectionDescription& Description( ) const;
		furrovineapi graphics_handle StateResource( ) const;

		furrovineapi void Apply( );
		furrovineapi void SetMultisampleMask( uint32 multisamplemask );
		furrovineapi void SetBlend( ulword index, const BlendState& blendstate );
		furrovineapi const BlendState& GetBlend( ulword index ) const;
		furrovineapi const BlendState& operator[] ( ulword index ) const;

		furrovineapi ~BlendStateCollection( );
	};
	
}}
