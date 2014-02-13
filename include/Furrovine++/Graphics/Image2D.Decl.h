#pragma once

#include <Furrovine++/std_defines.h>
#include <vector>
#include <Furrovine++/PrimitiveTypes.h>
#include <Furrovine++/FurrovineApi.h>
#include <Furrovine++/buffer_view.h>
#include <Furrovine++/Rectangle.h>
#include <Furrovine++/Graphics/SurfaceFormat.h>

namespace Furrovine { namespace Graphics {

	class Image2D {
	private:
		ulword w, h, s;
		SurfaceFormat format;
		std::vector<byte> bytes;

	public:

		furrovineapi Image2D( SurfaceFormat format = SurfaceFormat::Red8Green8Blue8Alpha8Normalized );
		furrovineapi Image2D( ulword width, ulword height, SurfaceFormat format = SurfaceFormat::Red8Green8Blue8Alpha8Normalized );
		furrovineapi Image2D( ulword width, ulword height, SurfaceFormat format, ulword stride );
		furrovineapi Image2D( const Image2D& copy );
		furrovineapi Image2D ( Image2D&& mov );
		furrovineapi Image2D& operator= ( const Image2D& copy );
		furrovineapi Image2D& operator= ( Image2D&& mov );

		template <typename T>
		Image2D ( const T* data, ulword width, ulword height, SurfaceFormat format = SurfaceFormat::Red8Green8Blue8Alpha8Normalized );
		template <typename T>
		Image2D( const T* data, ulword width, ulword height, SurfaceFormat format, ulword stride );
		furrovineapi Image2D( const void* data, ulword width, ulword height, SurfaceFormat format = SurfaceFormat::Red8Green8Blue8Alpha8Normalized );
		furrovineapi Image2D( const void* data, ulword width, ulword height, SurfaceFormat format, ulword stride );

		template <typename T>
		const T* GetData ( ) const;

		template <typename T>
		T* GetData ( );

		template <typename T>
		T& Get( ulword x, ulword y );

		template <typename T>
		const T& Get( ulword x, ulword y ) const;

		template <typename T>
		ulword GetSize ( ) const;

		template <typename T>
		buffer_view<T> View ( );

		template <typename T>
		const buffer_view<T> View ( ) const;

		furrovineapi void Resize( ulword width, ulword height );
		furrovineapi void Resize( ulword width, ulword height, ulword stride );

		furrovineapi SurfaceFormat Format ( ) const;

		furrovineapi ulword Width ( ) const;

		furrovineapi ulword Height( ) const;

		furrovineapi ulword Stride( ) const;

		furrovineapi Rectangleu32 Bounds( ) const;

		furrovineapi ulword WidthStride( ) const;

		furrovineapi byte* data ( );

		furrovineapi const byte* data ( ) const;

		furrovineapi byte& operator [] ( ulword index );

		furrovineapi const byte& operator [] ( ulword index ) const;

		furrovineapi ulword width( ) const;

		furrovineapi ulword height( ) const;

		furrovineapi ulword size( ) const;

		furrovineapi std::vector<byte>& Buffer ( );

		furrovineapi const std::vector<byte>& Buffer ( ) const;

	};

}}
