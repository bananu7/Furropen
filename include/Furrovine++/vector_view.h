#pragma once

#include <Furrovine++/buffer_view.h>
#include <Furrovine++/asserts.h>

namespace Furrovine {

	template <typename T>
	class vector_view : public buffer_view<T> {
	private:
		typedef buffer_view<T> parent_t;
		std::size_t cap;

	public:

		vector_view ( ) : parent_t( nullptr ), cap(0) {

		}

		vector_view ( T* buffer, std::size_t capacity, std::size_t n = 0 ) 
		: buffer_view<T>( buffer, n ), cap(capacity) {

		}

		template<std::size_t n>
		vector_view ( T(&array)[capacity], std::size_t n = 0 ) : vector_view(std::addressof(array[0]), capacity, n ) {

		}

		template <typename TContainer>
		vector_view ( TContainer& container, std::size_t n = 0 ) : vector_view(container.data(), container.size(), n ) {

		}

		bool full( ) const {
			return sz >= n;
		}

		void push_back( const T& item ) {
			new( res + sz ) T( item );
			++sz;
		}

		void push_back( T&& item ) {
			new( res + sz ) T( std::move( item ) );
			++sz;
		}

		template <typename ...Tn>
		void emplace_back( Tn&&... argn ) {
			new( res + sz ) T( std::forward<Tn>( argn )... );
			++sz;
		}

		void pop_back( ) {
			T& addr = refat( );
			addr.~T( );
			--sz;
		}

		void clear( ) {
			for ( ; len > 0; ) {
				pop_back( );
			}
		}

		void resize ( std::size_t maxlen ) {
			furrovinelazyassert( maxlen < cap );
			sz = std::min( cap, maxlen );
		}

		std::size_t capacity () const {
			return cap;
		}
	};

}
