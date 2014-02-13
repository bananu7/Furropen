#pragma once

#include <array>
#include <memory>

namespace Furrovine {

	template <typename T, std::size_t n>
	class array_view {
	public:
		typedef T value_type;
		typedef T& reference;
		typedef const T& const_reference;
		typedef T* pointer_type;
		typedef std::size_t size_type;
		typedef std::ptrdiff_t difference_type;
		typedef pointer_type iterator;
		typedef const pointer_type const_iterator;

	private:
		T* res;

	public:

		array_view( T( &arr )[ n ] ) : res( std::addressof( arr[ 0 ] ) ) {

		}

		array_view( const T( &arr )[ n ] ) : res( const_cast<T*>( std::addressof( arr[ 0 ] ) ) ) {

		}

		array_view( std::array<T, n>& arr ) : res( arr.data( ) ) {

		}

		array_view( const std::array<T, n>& arr ) : res( const_cast<T*>( arr.data( ) ) ) {

		}

		T* begin( ) {
			return res;
		}

		T* end( ) {
			return res + n;
		}

		const T* begin( ) const {
			return res;
		}

		const T* end( ) const {
			return res + n;
		}

		const T* cbegin( ) {
			return res;
		}

		const T* cend( ) {
			return res + n;
		}

		const T* cbegin( ) const {
			return res;
		}

		const T* cend( ) const {
			return res + n;
		}

		T& operator[] ( std::size_t i ) {
			return res[ i ];
		}

		const T& operator[] ( std::size_t i ) const {
			return res[ i ];
		}

		T* data( ) {
			return res;
		}

		const T* data( ) const {
			return res;
		}

		reference front( ) {
			return *res;
		}

		reference back( ) {
			return *( res + n );
		}

		const_reference front( ) const {
			return *res;
		}

		const_reference back( ) const {
			return *( res + n );
		}

	};
}