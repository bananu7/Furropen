#pragma once

#include <cstddef>
#include <cassert>

namespace Furrovine {

	template <std::size_t N, std::size_t a = 16>
	class arena {
		static const std::size_t alignment = a;
		alignas( alignment ) char buf_[ N ];
		char* ptr_;

		bool pointer_in_buffer( char* p ) noexcept { 
			return buf_ <= p && p <= buf_ + N; 
		}

	public:
		arena( ) noexcept : ptr_( buf_ ) {
		
		}

		~arena( ) { 
			ptr_ = nullptr; 
		}

		arena( const arena& ) = delete;

		arena& operator=( const arena& ) = delete;

		char* allocate( std::size_t n ) {
			assert( pointer_in_buffer( ptr_ ) && "short_alloc has outlived arena" );
			if ( buf_ + N - ptr_ >= n ) {
				char* r = ptr_;
				ptr_ += n;
				return r;
			}
			return static_cast<char*>( ::operator new( n ) );
		}

		void deallocate( char* p, std::size_t n ) noexcept {
			assert( pointer_in_buffer( ptr_ ) && "short_alloc has outlived arena" );
			if ( pointer_in_buffer( p ) ) {
				if ( p + n == ptr_ )
					ptr_ = p;
			}
			else
				::operator delete( p );
		}

		static constexpr std::size_t size( ) { 
			return N; 
		}

		std::size_t used( ) const { 
			return static_cast<std::size_t>( ptr_ - buf_ ); 
		}
		
		void reset( ) { 
			ptr_ = buf_; 
		}
	};

	template <class T, std::size_t N>
	class arena_allocator {
		template <class U, std::size_t M> friend class arena_allocator;

		arena<N>& a_;
	public:
		typedef T value_type;

	public:
		template <class _Up> struct rebind { typedef arena_allocator<_Up, N> other; };

		arena_allocator( arena<N>& a ) noexcept : a_( a ) {}
		template <class U>
		arena_allocator( const arena_allocator<U, N>& a ) noexcept
			: a_( a.a_ ) {}
		arena_allocator( const arena_allocator& ) = default;
		arena_allocator& operator=( const arena_allocator& ) = delete;

		T* allocate( std::size_t n ) {
			return reinterpret_cast<T*>( a_.allocate( n*sizeof( T ) ) );
		}
		
		void deallocate( T* p, std::size_t n ) noexcept {
			a_.deallocate( reinterpret_cast<char*>( p ), n*sizeof( T ) );
		}

		template <class T1, std::size_t N1, class U, std::size_t M>
		friend bool operator==( const arena_allocator<T1, N1>& x, const arena_allocator<U, M>& y ) noexcept;
	};

	template <class T, std::size_t N, class U, std::size_t M>
	inline bool operator==( const arena_allocator<T, N>& x, const arena_allocator<U, M>& y ) noexcept {
		return N == M && &x.a_ == &y.a_;
	}

	template <class T, std::size_t N, class U, std::size_t M>
	inline bool operator!=( const arena_allocator<T, N>& x, const arena_allocator<U, M>& y ) noexcept {
		return !( x == y );
	}
}