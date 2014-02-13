#pragma once

#include <Furrovine++/Graphics/Texture2D.h>
#include <Furrovine++/Graphics/GraphicsDevice.h>

namespace Furrovine { namespace Graphics {

	template <typename TPixel>
	void Texture2D::SetData( uint32 mipmap, const Rectangleu32& source, TPixel* pixels, uint32 count ) {
		typedef typename std::conditional<std::is_const<TPixel>::value, const void, void>::type pointer;
		TPixel* startpixel = pixels + start;
		ulword bytesize = sizeof( TPixel );
		SetData( mipmap, source, static_cast<pointer*>( pixels + start ), bytesize, count );
	}

	template <typename TPixel>
	void Texture2D::SetData( TPixel* pixels, uint32 count ) {
		SetData( 0, Rectangleu32::Empty, pixels, count );
	}

	template <typename TPixel>
	void Texture2D::SetData( uint32 mipmap, TPixel* pixels, uint32 count ) {
		SetData( 0, Rectangleu32::Empty, pixels, count );
	}

	template <typename TPixel, ulword n>
	void Texture2D::SetData( const TPixel (&pixels)[n] ) {
		SetData( 0, Rectangleu32::Empty, pixels, static_cast<uint32>( n ) );
	}

	template <typename TPixel>
	void Texture2D::SetData( const buffer_view<TPixel>& pixels ) {
		SetData( 0, Rectangleu32::Empty, pixels.data( ), static_cast<uint32>( pixels.size( ) ) );
	}

	template <typename TPixel>
	void Texture2D::SetData( uint32 mipmap, const buffer_view<TPixel>& pixels ) {
		SetData( mipmap, Rectangleu32::Empty, pixels.data( ), (uint32)pixels.size( ) );
	}

	template <typename TPixel>
	void Texture2D::SetData( uint32 mipmap, const Rectangleu32& source, const buffer_view<TPixel>& pixels ) {
		SetData( mipmap, source, pixels.data(), static_cast<uint32>( pixels.size() ) );
	}

}}
