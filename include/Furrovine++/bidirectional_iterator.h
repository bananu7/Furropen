#ifndef FURROVINEBIDIRECTIONAL_ITERATOR_H
#define FURROVINEBIDIRECTIONAL_ITERATOR_H

#include <Furrovine++/std_defines.h>
#include <iterator>

namespace Furrovine {

	template <typename Impl, typename T, typename TDiff = std::ptrdiff_t, typename TPointer = T*, typename TReference = T&>
	struct bidirectional_iterator : public std::iterator<std::bidirectional_iterator_tag, T, TDiff, TPointer, TReference> {

		Impl operator++ (int){
			Impl& impl = *static_cast<Impl*>( this );
			Impl old( impl );
			impl.next( );
			return old;
		}

		Impl& operator++ ( ) {
			Impl& impl = *static_cast<Impl*>( this );
			impl.next( );
			return impl;
		}

		Impl operator-- (int){
			Impl& impl = *static_cast<Impl*>( this );
			Impl old( impl );
			impl.prev( );
			return old;
		}

		Impl& operator-- ( ) {
			Impl& impl = *static_cast<Impl*>( this );
			impl.prev( );
			return impl;
		}

		const reference operator* ( ) const {
			const Impl& impl = *static_cast<const Impl*>( this );
			return impl.dereference( );
		}

		reference operator* ( ) {
			Impl& impl = *static_cast<Impl*>( this );
			return impl.dereference( );
		}

		const reference operator-> ( ) const {
			const Impl& impl = *static_cast<const Impl*>( this );
			return impl.dereference( );
		}

		reference operator-> ( ) {
			Impl& impl = *static_cast<Impl*>( this );
			return impl.dereference( );
		}

		bool operator== ( const Impl& right ) const {
			const Impl& left = *static_cast<const Impl*>( this );
			return left.equals( right );
		}

		bool operator!= ( const Impl& right ) const {
			const Impl& left = *static_cast<const Impl*>( this );
			return !left.equals( right );
		}

	};

}

#endif // FURROVINEBIDIRECTIONAL_ITERATOR_H 