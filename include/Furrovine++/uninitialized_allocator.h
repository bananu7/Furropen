#pragma once

#include <type_traits>
#include <utility>

namespace Furrovine {

	template <typename T>
	class uninitialized_allocator {
	public:
		typedef T value_type;

		uninitialized_allocator( ) {}

		template <class U>
		uninitialized_allocator( const uninitialized_allocator<U>& ) {}

		T* allocate( std::size_t n ) {
			return static_cast<T*>( ::operator new( n * sizeof( T ) ) );
		}

		void deallocate( T* p, std::size_t ) {
			::operator delete( static_cast<void*>( p ) );
		}

		template <class U>
		void construct( U* ) {
			static_assert( std::is_trivially_default_constructible<U>::value,
				"This allocator can only be used with trivally default constructible types" );
		}

		template <class U, class A0, class... Args>
		void construct( U* up, A0&& a0, Args&&... args ) {
			::new(up)U( std::forward<A0>( a0 ), std::forward<Args>( args )... );
		}
	};

	template <typename T>
	class unsafe_uninitialized_allocator {
	public:
		typedef T value_type;

		unsafe_uninitialized_allocator( ) {}

		template <class U>
		unsafe_uninitialized_allocator( const unsafe_uninitialized_allocator<U>& ) {}

		T* allocate( std::size_t n ) {
			return static_cast<T*>( ::operator new( n * sizeof( T ) ) );
		}

		void deallocate( T* p, std::size_t ) {
			::operator delete( static_cast<void*>( p ) );
		}

		template <class U>
		void construct( U* ) {
			
		}

		template <class U, class A0, class... Args>
		void construct( U* up, A0&& a0, Args&&... args ) {
			::new(up)U( std::forward<A0>( a0 ), std::forward<Args>( args )... );
		}
	};

}
