#pragma once

#include <Furrovine++/Graphics/Image2D.h>

namespace Furrovine { namespace Graphics {

	template <typename T>
	buffer_view<T> Image2D::View( ) {
		return buffer_view<T>( GetData<T>(), GetSize<T>( ) );
	}

	template <typename T>
	const buffer_view<T> Image2D::View( ) const {
		return buffer_view<T>( GetData<T>(), GetSize<T>( ) );
	}

	template <typename T>
	ulword Image2D::GetSize( ) const {
		return size() / sizeof( T );
	}

	template <typename T>
	T& Image2D::Get( ulword x, ulword y ) {
		byte* target = data( );
		target += y * ( Stride( ) * Width( ) );
		target += x * Stride( );
		return *reinterpret_cast<T*>( target );
	}

	template <typename T>
	const T& Image2D::Get( ulword x, ulword y ) const {
		const byte* target = data( );
		target += y * ( Stride( ) * Width( ) );
		target += x * Stride( );
		return *reinterpret_cast<const T*>( target );
	}

	template <typename T>
	T* Image2D::GetData( ) {
		return reinterpret_cast<T*>( bytes.data() );
	}

	template <typename T>
	const T* Image2D::GetData( ) const {
		return reinterpret_cast<T*>( bytes.data() );
	}

	template <typename T>
	Image2D::Image2D( const T* data, ulword width, ulword height, SurfaceFormat format ) 
	: Image2D( data, width, height, format, sizeof( T ) ) {

	}

	template <typename T>
	Image2D::Image2D( const T* data, ulword width, ulword height, SurfaceFormat format, ulword stride )
	: Image2D( static_cast<const void*>( data ), width, height, format, stride ) {
		
	}

}}
