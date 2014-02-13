#pragma once

#include <Furrovine++/Rectangle.h>
#include <Furrovine++/Region.h>
#include <Furrovine++/Graphics/Texture2D.h>
#include <Furrovine++/Graphics/DepthStencilBufferDescription.h>

namespace Furrovine { namespace Graphics {

	class DepthStencilBuffer : public Texture2D {
	protected:
		struct deleter {
			furrovineapi void operator() ( void* p );
		};
		handle<graphics_handle, ShaderResourceView::deleter>  depthview;
		DepthStencilBufferDescription depthdesc;

		furrovineapi void Create ( );

	public:

		furrovineapi DepthStencilBuffer( GraphicsDevice& graphicsdevice, graphics_handle originaldepthtexture, DepthStencilViewFlags flags = DepthStencilViewFlags::None, bool create = true );
		furrovineapi DepthStencilBuffer( GraphicsDevice& graphicsdevice, uint32 width, uint32 height, DepthStencilFormat format, ResourceUsage usage = ResourceUsage::Default, CpuAccessFlags accessflags = CpuAccessFlags::Default, DepthStencilViewFlags flags = DepthStencilViewFlags::None, BindFlags binflags = BindFlags::DepthStencil | BindFlags::ShaderResource, bool create = true );
		furrovineapi DepthStencilBuffer( DepthStencilBuffer&& mov );
		furrovineapi DepthStencilBuffer& operator= ( DepthStencilBuffer&& mov );

		furrovineapi DepthStencilFormat Format( ) const;

		furrovineapi uint32 Width( ) const;

		furrovineapi uint32 Height( ) const;

		furrovineapi graphics_handle TexDepthResource( ) const;

		furrovineapi graphics_handle DepthStencilViewResource ( ) const;

		furrovineapi Rectangle BoundRectangle( ) const;

		furrovineapi Furrovine::Region BoundRegion( ) const;

		furrovineapi Furrovine::Region Bounds( ) const;

		furrovineapi void Clear( float depth );

		furrovineapi void Clear( byte stencil );

		furrovineapi void Clear( float depth, byte stencil );

		furrovineapi void Clear( ClearFlags clearflags, float depth, byte stencil );

		furrovineapi ~DepthStencilBuffer( );

	};

}}
