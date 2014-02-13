#pragma once

#include <Furrovine++/Graphics/GraphicsResource.h>
#include <Furrovine++/handle.h>
#include <Furrovine++/Graphics/graphics_handle.h>
#include <Furrovine++/Graphics/TextureFilter.h>
#include <Furrovine++/Graphics/TextureAddress.h>
#include <Furrovine++/Graphics/ShaderStage.h>
#include <Furrovine++/Graphics/SamplerStateDescription.h>

namespace Furrovine { namespace Graphics {

	class SamplerState : public GraphicsResource {
	public:
		furrovineapi static const SamplerStateDescription Default;
		furrovineapi static const SamplerStateDescription LinearClamp;
		furrovineapi static const SamplerStateDescription LinearWrap;
		furrovineapi static const SamplerStateDescription PointClamp;
		furrovineapi static const SamplerStateDescription PointWrap;
		furrovineapi static const SamplerStateDescription AnisotropicClamp;
		furrovineapi static const SamplerStateDescription AnisotropicWrap;
		furrovineapi static const SamplerStateDescription LinearMirrorWrap;

	protected:
		struct deleter {
			furrovineapi void operator() ( graphics_handle p );
		};
		friend class SamplerStateCollection;
		handle<graphics_handle, deleter>  stateres;
		SamplerStateCollection* collection;
		ShaderStage shadermethod;
		ulword samplerindex;
		bool applied;
		SamplerStateDescription statedesc;

	public:

		furrovineapi SamplerState( GraphicsDevice& graphicsdevice, SamplerStateCollection& samplercollection, ShaderStage method, ulword index );

		furrovineapi SamplerState( GraphicsDevice& graphicsdevice, SamplerStateCollection& samplercollection, ShaderStage method, ulword index, void* samplerstate );

		furrovineapi SamplerState( GraphicsDevice& graphicsdevice, SamplerStateCollection& samplercollection, ShaderStage method, ulword index, const SamplerStateDescription& statedesc );

		furrovineapi SamplerState( const SamplerState& copy );

		furrovineapi SamplerState& operator= ( const SamplerState& copy );

		furrovineapi SamplerState& operator= ( SamplerState&& copy );

		furrovineapi const SamplerStateDescription& Description( ) const;

		furrovineapi graphics_handle StateResource( ) const;

		furrovineapi ulword HashCode () const;

		furrovineapi bool operator== ( const SamplerState& blend ) const;

		furrovineapi bool operator!= ( const SamplerState& blend ) const;

		furrovineapi void Apply ( );

		furrovineapi ~SamplerState();

	};

}}
