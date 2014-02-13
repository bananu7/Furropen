#pragma once

namespace Furrovine {

	template <typename T>
	struct allocator_deleter {
		typedef typename T::pointer pointer;
		T allocator;
		std::size_t count;

		allocator_deleter( const T& alloc, std::size_t allocated_count ) : allocator( alloc ), count( allocated_count ) {

		}

		allocator_deleter( T && alloc, std::size_t allocated_count ) : allocator( std::move( alloc ) ), count( allocated_count ) {

		}

		void operator ( ) ( pointer pointer ) {
			pointer pbegin = pointer;
			pointer p = pointer + count;
			for ( ; p-- != pbegin; ) {
				allocator.destroy( p );
			}
			allocator.deallocate( pointer, count );
		}

	};

}