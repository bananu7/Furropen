#pragma once

#include <Furrovine++/std_defines.h>
#include <array>
#include <Furrovine++/PrimitiveTypes.h>
#include <Furrovine++/bidirectional_iterator.h>
#include <Furrovine++/expanded_iterator_traits.h>

namespace Furrovine {

	template <typename TIterator>
	struct bidirectional_byte_iterator : public bidirectional_iterator<bidirectional_byte_iterator<TIterator>, byte> {
	private:
		typedef typename expanded_iterator_traits<TIterator>::value_type internal_value_type;
		TIterator i;
		lword current;
		static const ulword iteratorsize = sizeof( internal_value_type );
		std::array<byte, iteratorsize> buffer;

		internal_value_type* ptr( ) {
			return static_cast<internal_value_type*>( static_cast<void*>( buffer.data( ) ) );
		}

		const internal_value_type* ptr( ) const {
			return static_cast<const internal_value_type*>( static_cast<const void*>( buffer.data( ) ) );
		}

		void fill( ) {
			internal_value_type* p = ptr( );
			*p = *i;
		}

	public:

		bidirectional_byte_iterator( TIterator it, lword start = 0 ) : i( it ), current( start ) {
			fill( );
		}

		TIterator internal_iterator( ) {
			return i;
		}

		void next( ) {
			++current;
			if ( current == iteratorsize ) {
				++i;
				fill( );
				current = 0;
			}
		}

		void prev( ) {
			--current;
			if ( current < 0 ) {
				--i;
				fill( );
				current = iteratorsize - 1;
			}
		}

		reference dereference( ) {
			return buffer[ current ];
		}

		const reference dereference( ) const {
			return buffer[ current ];
		}

		bool equals( const bidirectional_byte_iterator& right ) const {
			return i == right.i && current == right.current;
		}
	};

}
