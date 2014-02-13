#pragma once

#include <Furrovine++/Graphics/Texture2D.h>
#include <Furrovine++/Graphics/RenderBuffer2DDescription.h>
#include <Furrovine++/Graphics/ClearFlags.h>

namespace Furrovine { namespace Graphics {

	class RenderBuffer2D : public Texture2D {
	private:
		struct render_target_view_deleter {
			furrovineapi void operator() ( graphics_handle p );
		};
		handle<graphics_handle, render_target_view_deleter> renderbufferview;
		RenderBuffer2DDescription rendertargetdesc;
		
		furrovineapi void Create ();

	public:

		furrovineapi RenderBuffer2D( );
		furrovineapi RenderBuffer2D( GraphicsDevice& graphicsdevice, graphics_handle rendertargeresource, bool create = true );
		furrovineapi RenderBuffer2D( GraphicsDevice& graphicsdevice, const RenderBuffer2DDescription& desc, bool create = true );
		furrovineapi RenderBuffer2D( GraphicsDevice& graphicsdevice, uint32 width, uint32 height, SurfaceFormat surfaceformat, bool create = true );

		furrovineapi void Clear (  );
		furrovineapi void Clear ( const Color& color );
		furrovineapi void Clear ( float depth );
		furrovineapi void Clear ( byte stencil );
		furrovineapi void Clear ( float depth, byte stencil );
		furrovineapi void Clear ( ClearFlags clearflags, const Color& color, float depth, byte stencil );
		furrovineapi void ClearColor ( const Color& color );
		furrovineapi void ClearDepth ( float depth );
		furrovineapi void ClearStencil ( byte stencil );

		furrovineapi const RenderBuffer2DDescription& RenderTargetDescription( ) const;

		furrovineapi graphics_handle RenderBufferViewResource( ) const;

	};

}}
 