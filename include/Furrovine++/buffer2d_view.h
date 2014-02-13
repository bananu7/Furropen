#pragma once

#include <cstddef>
#include <memory>
#include <initializer_list>
#include <Furrovine++/buffer_view.h>

namespace Furrovine {

	template <typename T>
	class buffer2d_view : public buffer_view<T> {
	private:
		std::size_t width;
		std::size_t height;

	public:

		buffer2d_view( ) : buffer_view( ), width( 0 ), height( 0 ) {

		}

		buffer2d_view( T* buffer, std::size_t w, std::size_t h )
		: buffer_view( buffer, w * h ), width( w ), height( w ) {

		}

		template<std::size_t n>
		buffer2d_view( T( &array )[ n ], std::size_t w, std::size_t h ) : buffer2d_view( std::addressof( array[ 0 ] ), w, h ) {

		}

		template <typename TContainer>
		buffer2d_view( TContainer&& container, std::size_t w, std::size_t h ) : buffer2d_view( detail::get_data( container ), w, h ) {

		}

		T& operator()( std::size_t x, std::size_t y ) {
			return operator[]( y * height + x );
		}

		const T& operator()( std::size_t x, std::size_t y ) const {
			return operator[]( y * height + x );
		}
	};

	template <typename T>
	buffer2d_view<T> make_buffer2d_view( T* buffer, std::size_t n, std::size_t w, std::size_t h ) {
		return buffer2d_view<T>( buffer, n, w, h );
	}

	template <typename T>
	buffer2d_view<T> make_buffer2d_view( const T* buffer, std::size_t w, std::size_t h ) {
		return buffer2d_view<T>( const_cast<T*>( buffer ), w, h );
	}

	template <typename T, std::size_t n>
	buffer2d_view<T> make_buffer2d_view( T( &container )[ n ], std::size_t w, std::size_t h ) {
		return make_buffer2d_view( container, n, w, h );
	}

	template <typename TContainer>
	auto make_buffer2d_view( TContainer& container, std::size_t w, std::size_t h ) -> decltype( make_buffer2d_view( container.data( ), container.size( ) ) ) {
		return make_buffer2d_view( container.data( ), container.size( ), w, h );
	}

	template <typename TAs, typename T>
	buffer2d_view<TAs> make_buffer2d_view_as( T* buffer, std::size_t w, std::size_t h ) {
		void* addr = buffer;
		return buffer2d_view<TAs>( static_cast<TAs*>( addr ), w, h );
	}

	template <typename TAs, typename T, std::size_t n>
	auto make_buffer2d_view_as( T( &container )[ n ], std::size_t w, std::size_t h ) -> decltype( make_buffer2d_view_as<TAs>( container, n ) ) {
		return make_buffer2d_view_as<TAs>( container, w, h );
	}

	template <typename TAs, typename TContainer>
	buffer2d_view<TAs> make_buffer2d_view_as( TContainer& container, std::size_t w, std::size_t h ) {
		return make_buffer2d_view_as<TAs>( container.data( ), w, h );
	}

	template <typename TAs, typename TContainer>
	buffer2d_view<TAs> make_buffer2d_view_as( TContainer& container ) {
		return make_buffer2d_view_as<TAs>( container.data( ), container.width( ), container.height( ) );
	}

}
