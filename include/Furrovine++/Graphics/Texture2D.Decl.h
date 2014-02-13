#pragma once

#include <Furrovine++/Rectangle.h>
#include <Furrovine++/Region.h>
#include <Furrovine++/Graphics/Texture.h>
#include <Furrovine++/Graphics/Texture2DDescription.h>

namespace Furrovine { namespace Graphics {

	class Texture2D : public Texture {
	protected:
		struct deleter {
			furrovineapi void operator () ( graphics_handle p );
		};
		handle<graphics_handle, deleter> tex2tex;
		Texture2DDescription tex2desc;

		furrovineapi void Create ();

	public:

		furrovineapi Texture2D ( );
		furrovineapi Texture2D ( GraphicsDevice& graphicsdevice, graphics_handle originaltexture, bool create = true );
		furrovineapi Texture2D ( GraphicsDevice& graphicsdevice, uint32 texturewidth, uint32 textureheight, uint32 mipmapcount, SurfaceFormat format, bool create = true );
		furrovineapi Texture2D ( GraphicsDevice& graphicsdevice, uint32 texturewidth, uint32 textureheight, SurfaceFormat format, BindFlags texturebinding = BindFlags::ShaderResource, bool create = true );
		furrovineapi Texture2D ( GraphicsDevice& graphicsdevice, uint32 texturewidth, uint32 textureheight, uint32 mipmapcount, 
			SurfaceFormat format, ResourceUsage textureusage, BindFlags texturebinding, CpuAccessFlags textureaccess, bool create = true );
		furrovineapi Texture2D( GraphicsDevice& graphicsdevice, uint32 texturewidth, uint32 textureheight, uint32 mipmapcount,
			SurfaceFormat format, ResourceUsage textureusage, BindFlags texturebinding, CpuAccessFlags textureaccess, ResourceOptionFlags texturemiscflags = ResourceOptionFlags::None, bool create = true );
		furrovineapi Texture2D( GraphicsDevice& graphicsdevice, const Texture2DDescription& texturedesc, bool create = true );
		furrovineapi Texture2D( GraphicsDevice& graphicsdevice, const Image2D& image, ResourceUsage textureusage = ResourceUsage::Default, BindFlags texturebinding = BindFlags::ShaderResource, CpuAccessFlags textureaccess = CpuAccessFlags::Default, ResourceOptionFlags texturemiscflags = ResourceOptionFlags::None );
		furrovineapi Texture2D( GraphicsDevice& graphicsdevice, const Texture2DDescription& texturedesc, const Image2D& image );
		furrovineapi Texture2D( GraphicsDevice& graphicsdevice, const Texture2DDescription& texturedesc, const buffer_view<Image2D>& image );

		furrovineapi Texture2D( Texture2D&& mov );
		furrovineapi Texture2D& operator= ( Texture2D&& mov );

		template <typename TPixel>
		void SetData( const buffer_view<TPixel>& pixels );
		template <typename TPixel>
		void SetData( uint32 mipmap, const buffer_view<TPixel>& pixels );
		template <typename TPixel>
		void SetData( uint32 mipmap, const Rectangleu32& source, const buffer_view<TPixel>& pixels );
		template <typename TPixel, ulword n> 
		void SetData ( const TPixel (&pixels)[n] );
		template <typename TPixel>
		void SetData( TPixel* pixels, uint32 count );
		template <typename TPixel>
		void SetData ( uint32 mipmap, TPixel* pixels, uint32 count );
		template <typename TPixel> 
		void SetData ( uint32 mipmap, const Rectangleu32& source, TPixel* pixels, uint32 count );
		furrovineapi void SetData( const Image2D& image );
		furrovineapi void SetData( uint32 mipmap, const Image2D& image );
		furrovineapi void SetData( const Image2D& image, const Rectangleu32& source );
		furrovineapi void SetData( uint32 mipmap, const Image2D& image, const Rectangleu32& source );
		furrovineapi void SetData( uint32 mipmap, const Rectangleu32& source, const void* pixels, uint32 pixelbytesize, uint32 count );
		
		furrovineapi graphics_handle Tex2DResource( ) const;

		furrovineapi const Texture2DDescription& Tex2DDescription( ) const;

		furrovineapi SurfaceFormat Format() const;

		furrovineapi uint32 Width () const;

		furrovineapi uint32 Height () const;

		furrovineapi Rectangle BoundRectangle () const;

		furrovineapi Furrovine::Region BoundRegion () const;

		furrovineapi Furrovine::Region Bounds () const;

		furrovineapi ~Texture2D ();

	};

}}
