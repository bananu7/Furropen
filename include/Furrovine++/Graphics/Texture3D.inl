#include <Furrovine++/Graphics/Texture3D.h>
#include <Furrovine++/Graphics/GraphicsDevice.h>

namespace Furrovine { namespace Graphics {

	template <typename TPixel>
	void Texture3D::SetData( uint32 mipmap, const Boxu32& box, TPixel* pixels, ulword start, ulword count ) {
		typedef typename std::conditional<std::is_const<TPixel>::value, const void, void>::type pointer;
		TPixel* startpixel = pixels + start;
		ulword bytesize = sizeof( TPixel );
		SetData( mipmap, box, static_cast<pointer*>( startpixel ), bytesize, count );
	}

	template <typename TPixel>
	void Texture3D::SetData( uint32 mipmap, TPixel* pixels, ulword start, ulword count ) {
		SetData( mipmap, Boxu32::Empty, pixels, start, count );
	}

	template <typename TPixel>
	void Texture3D::SetData( TPixel* pixels, uint32 count ) {
		SetData( 0, Boxu32::Empty, pixels, 0, count );
	}

	template <typename TPixel>
	void Texture3D::SetData( uint32 mipmap, TPixel* pixels, ulword count ) {
		SetData( 0, Boxu32::Empty, pixels, 0, count );
	}

	template <typename TPixel, ulword n>
	void Texture3D::SetData( const TPixel (&pixels)[n] ) {
		SetData( 0, Boxu32::Empty, pixels, 0, n );
	}

	template <typename TPixel>
	void Texture3D::SetData( const std::vector<TPixel>& pixels ) {
		SetData( 0, Boxu32::Empty, pixels.data( ), 0, pixels.size( ) );
	}

}}
