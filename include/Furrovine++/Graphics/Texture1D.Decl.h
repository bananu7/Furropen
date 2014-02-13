#pragma once

#include <vector>
#include <Furrovine++/Span.h>
#include <Furrovine++/Graphics/Texture.h>
#include <Furrovine++/Graphics/Texture1DDescription.h>

namespace Furrovine { namespace Graphics {

	class Texture1D : public Texture {
	protected:
		struct deleter {
			furrovineapi void operator () ( graphics_handle p );
		}; 
		handle<graphics_handle, deleter>  tex1tex;
		Texture1DDescription tex1desc;

		furrovineapi void Create ();

	public:

		furrovineapi Texture1D ( GraphicsDevice& graphicsdevice, graphics_handle originaltexture, bool create = true );

		furrovineapi Texture1D ( GraphicsDevice& graphicsdevice, uint32 texturewidth, uint32 mipmapcount, SurfaceFormat format, bool create = true );

		furrovineapi Texture1D ( GraphicsDevice& graphicsdevice, uint32 texturewidth, SurfaceFormat format, BindFlags texturebinding = BindFlags::ShaderResource, bool create = true );

		furrovineapi Texture1D ( GraphicsDevice& graphicsdevice, uint32 texturewidth, DepthStencilFormat format, BindFlags texturebinding = BindFlags::DepthStencil, bool create = true );

		furrovineapi Texture1D ( GraphicsDevice& graphicsdevice, uint32 texturewidth, uint32 mipmapcount, 
			SurfaceFormat format, ResourceUsage textureusage, BindFlags texturebinding, CpuAccessFlags textureaccess, bool create = true );

		furrovineapi Texture1D ( GraphicsDevice& graphicsdevice, uint32 texturewidth, uint32 mipmapcount, 
			uint32 format, ResourceUsage textureusage, BindFlags texturebinding, CpuAccessFlags textureaccess, bool create = true );

		furrovineapi Texture1D ( GraphicsDevice& graphicsdevice, uint32 texturewidth, uint32 mipmapcount, 
			uint32 format, ResourceUsage textureusage, BindFlags texturebinding, CpuAccessFlags textureaccess, ResourceOptionFlags texturemiscflags = ResourceOptionFlags::None, bool create = true );

		furrovineapi Texture1D( Texture1D&& mov );

		furrovineapi Texture1D& operator=( Texture1D&& mov );

		template <typename TPixel> 
		void SetData ( const std::vector<TPixel>& pixels );
		template <typename TPixel, ulword n> 
		void SetData ( const TPixel (&pixels)[n] );
		template <typename TPixel> 
		void SetData ( TPixel* pixels, ulword count );
		template <typename TPixel> 
		void SetData ( uint32 mipmap, TPixel* pixels, ulword count );
		template <typename TPixel> 
		void SetData ( uint32 mipmap, TPixel* pixels, ulword start, ulword count );
		template <typename TPixel> 
		void SetData ( uint32 mipmap, const Spanu32& span, TPixel* pixels, ulword start, ulword count );
		furrovineapi void SetData( uint32 mipmap, const Spanu32& span, const void* pixels, ulword pixelbytesize, ulword count );

		furrovineapi graphics_handle Tex1DResource( ) const;

		furrovineapi uint32 Width () const;

		furrovineapi Spanu32 Bounds () const;

		furrovineapi ~Texture1D ();

	};

}}
