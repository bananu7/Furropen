#ifndef FURROVINEFORWARD_BYTE_ITERATOR_H
#define FURROVINEFORWARD_BYTE_ITERATOR_H

#include <Furrovine++/std_defines.h>
#include <array>
#include <Furrovine++/PrimitiveTypes.h>
#include <Furrovine++/forward_iterator.h>
#include <Furrovine++/expanded_iterator_traits.h>

namespace Furrovine {

	template <typename TIter>
	struct forward_byte_iterator : public forward_iterator<forward_byte_iterator<TIter>, byte> {
	public:
		typedef TIter iterator_type;
	
	private:
		typedef typename expanded_iterator_traits<TIter>::value_type internal_value_type;
		iterator_type i;
		lword current;
		static const ulword iteratorsize = sizeof( internal_value_type );
		std::array<byte, sizeof( internal_value_type )> buffer;

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

		forward_byte_iterator( iterator_type it, ulword start = 0 ) : i( it ), current( start ) {
			fill( );
		}

		iterator_type internal_iterator( ) {
			return i;
		}

		void next( ) {
			++current;
			if ( current >= iteratorsize ) {
				++i;
				fill( );
				current = 0;
			}
		}

		reference dereference( ) {
			return buffer[ current ];
		}

		const reference dereference( ) const {
			return buffer[ current ];
		}

		bool equals( const forward_byte_iterator& right ) const {
			return i == right.i && current == right.current;
		}
	};

}

#endif // FURROVINEFORWARD_BYTE_ITERATOR_H 