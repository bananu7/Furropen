#pragma once

#include <Furrovine++/Graphics/Texture1D.h>

namespace Furrovine { namespace Graphics {

	template <typename TPixel>
	void Texture1D::SetData( uint32 mipmap, const Spanu32& span, TPixel* pixels, ulword start, ulword count ) {
		typedef typename std::conditional<std::is_const<TPixel>::value, const void, void>::type pointer;
		TPixel* startpixel = pixels + start;
		ulword bytesize = sizeof( TPixel );
		SetData( mipmap, span, static_cast<pointer*>( startpixel ), bytesize, count );
	}

	template <typename TPixel>
	void Texture1D::SetData( uint32 mipmap, TPixel* pixels, ulword start, ulword count ) {
		SetData( mipmap, Spanu32::Empty, pixels, start, count );
	}

	template <typename TPixel>
	void Texture1D::SetData( uint32 mipmap, TPixel* pixels, ulword count ) {
		SetData( 0, Spanu32::Empty, pixels, 0, count );
	}

	template <typename TPixel>
	void Texture1D::SetData( TPixel* pixels, ulword count ) {
		SetData( 0, Spanu32::Empty, pixels, 0, count );
	}

	template <typename TPixel, ulword n>
	void Texture1D::SetData( const TPixel (&pixels)[n] ) {
		SetData( 0, Spanu32::Empty, pixels, 0, n );
	}

	template <typename TPixel>
	void Texture1D::SetData( const std::vector<TPixel>& pixels ) {
		SetData( 0, Spanu32::Empty, pixels.data( ), 0, pixels.size( ) );
	}

}}
