#pragma once

#include <vector>
#include <Furrovine++/Graphics/Texture.h>
#include <Furrovine++/Graphics/Texture3DDescription.h>
#include <Furrovine++/Box.h>
#include <Furrovine++/Graphics/SurfaceFormat.h>
#include <Furrovine++/Graphics/DepthStencilFormat.h>
#include <Furrovine++/Graphics/ResourceOptionFlags.h>
#include <Furrovine++/Graphics/ResourceMapping.h>
#include <Furrovine++/Graphics/ResourceUsage.h>
#include <Furrovine++/Graphics/BindFlags.h>
#include <Furrovine++/Graphics/CpuAccessFlags.h>

namespace Furrovine { namespace Graphics {

	class Texture3D : public Texture {
	protected:
		struct deleter {
			furrovineapi void operator () ( graphics_handle p );
		};
		handle<graphics_handle, deleter> tex3tex;
		Texture3DDescription tex3desc;

		furrovineapi void Create ();

	public:

		furrovineapi Texture3D ( GraphicsDevice& graphicsdevice, void* textureresource, bool create = true );

		furrovineapi Texture3D ( GraphicsDevice& graphicsdevice, uint32 texturewidth, uint32 textureheight, uint32 texturedepth, uint32 mipmapcount, SurfaceFormat format, bool create = true );

		furrovineapi Texture3D ( GraphicsDevice& graphicsdevice, uint32 texturewidth, uint32 textureheight, uint32 texturedepth, SurfaceFormat format, BindFlags texturebinding = BindFlags::ShaderResource, bool create = true );

		furrovineapi Texture3D ( GraphicsDevice& graphicsdevice, uint32 texturewidth, uint32 textureheight, uint32 texturedepth, DepthStencilFormat format, BindFlags texturebinding = BindFlags::DepthStencil, bool create = true );

		furrovineapi Texture3D ( GraphicsDevice& graphicsdevice, uint32 texturewidth, uint32 textureheight, uint32 texturedepth, uint32 mipmapcount, 
			SurfaceFormat format, ResourceUsage textureusage, BindFlags texturebinding, CpuAccessFlags textureaccess, bool create = true );

		furrovineapi Texture3D ( GraphicsDevice& graphicsdevice, uint32 texturewidth, uint32 textureheight, uint32 texturedepth, uint32 mipmapcount, 
			uint32 format, ResourceUsage textureusage, BindFlags texturebinding, CpuAccessFlags textureaccess, bool create = true );

		furrovineapi Texture3D ( GraphicsDevice& graphicsdevice, uint32 texturewidth, uint32 textureheight, uint32 texturedepth, uint32 mipmapcount, 
			uint32 format, ResourceUsage textureusage, BindFlags texturebinding, CpuAccessFlags textureaccess, ResourceOptionFlags texturemiscflags = ResourceOptionFlags::None, bool create = true );

		furrovineapi Texture3D& operator=( Texture3D&& mov );

		furrovineapi Texture3D ( Texture3D&& mov );

		template <typename TPixel> 
		void SetData ( const std::vector<TPixel>& pixels );
		template <typename TPixel, ulword n> 
		void SetData ( const TPixel (&pixels)[n] );
		template <typename TPixel> 
		void SetData ( uint32 mipmap, TPixel* pixels, ulword count );
		template <typename TPixel> 
		void SetData ( TPixel* pixels, ulword count );
		template <typename TPixel> 
		void SetData ( uint32 mipmap, TPixel* pixels, ulword start, ulword count );
		template <typename TPixel> 
		void SetData ( uint32 mipmap, const Boxu32& box, TPixel* pixels, ulword start, ulword count );
		furrovineapi void SetData( uint32 mipmap, const Boxu32& box, const void* pixels, ulword pixelbytesize, ulword count );

		furrovineapi graphics_handle Tex3DResource( ) const;

		furrovineapi uint32 Width () const;

		furrovineapi uint32 Height () const;

		furrovineapi uint32 Depth( ) const;

		furrovineapi Box Bounds( ) const;

		furrovineapi ~Texture3D( );

	};

}}
