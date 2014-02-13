#pragma once

#include <Furrovine++/static_cast_return.h>
#include <Furrovine++/remove_type.h>

namespace Furrovine {

	template <typename TFrom, typename TTo>
	struct ptrptr_static_cast {
		template <typename T>
		static auto to( T&& a )
		-> decltype( static_cast_return<TTo, TFrom>( std::forward<T>( a ) ) ) {
			return static_cast_return<TTo, TFrom>( std::forward<T>( a ) );
		}

		template <typename T>
		static auto from( T&& a )
		-> decltype( static_cast_return<TFrom, TTo>( std::forward<T>( a ) ) ) {
			return static_cast_return<TFrom, TTo>( std::forward<T>( a ) );
		}

	};

	template <typename TParent, typename TPtr = typename std::remove_pointer<typename TParent::pointer>::type, typename TCast = ptrptr_static_cast<typename TParent::pointer, TPtr*>, bool isvoid = std::is_void<TPtr>::value>
	class ptrptr_type;

	template <typename TParent, typename TPtr, typename TCast>
	class ptrptr_type<TParent, TPtr, TCast, false> {
	public:
		typedef TParent parent_type;
		typedef TPtr* pointer;
		typedef typename parent_type::pointer parent_pointer;
		typedef typename remove_type<pointer>::type erasure_pointer;

	private:
		TCast cast;
		parent_type* p;
		pointer a;
		ptrptr_type( const ptrptr_type& nocopy ) {};
		ptrptr_type& operator=( const ptrptr_type& nocopy ) { return *this; };

	public:
		ptrptr_type( parent_type& ptr ) : p( std::addressof( ptr ) ), a( cast.to( ptr.release( ) ) ) {}
		ptrptr_type( ptrptr_type&& mover ) { p = mover.p; a = mover.a; mover.p = nullptr; }
		ptrptr_type& operator=( ptrptr_type&& mover ) { p = mover.p; a = mover.a; mover.p = nullptr; return *this; }
		pointer& get( ) { return a; }
		pointer* indirect( ) { return std::addressof( a ); }
		operator pointer&( ) { return get(); }
		operator pointer*( ) { return indirect(); }
		explicit operator erasure_pointer ( ) { return reinterpret_cast<erasure_pointer>( a ); }
		explicit operator erasure_pointer* ( ) { return reinterpret_cast<erasure_pointer*>( std::addressof( a ) ); }
		~ptrptr_type( ) { if ( p ) p->reset( cast.from( a ) ); }
	};

	template <typename TParent, typename TPtr, typename TCast>
	class ptrptr_type<TParent, TPtr, TCast, true> {
	public:
		typedef TParent parent_type;
		typedef TPtr* pointer;
		typedef typename parent_type::pointer parent_pointer;

	private:
		TCast cast;
		parent_type* p;
		pointer a;
		ptrptr_type( const ptrptr_type& nocopy ) {};
		ptrptr_type& operator=( const ptrptr_type& nocopy ) { return *this; };

	public:
		ptrptr_type( parent_type& ptr ) : p( std::addressof( ptr ) ), a( cast.to( ptr.release( ) ) ) {}
		ptrptr_type( ptrptr_type&& mover ) { p = mover.p; a = mover.a; mover.p = nullptr; }
		ptrptr_type& operator=( ptrptr_type&& mover ) { p = mover.p; a = mover.a; mover.p = nullptr; return *this; }
		pointer& get( ) { return a; }
		pointer* indirect( ) { return std::addressof( a ); }
		operator pointer&( ) { return get(); }
		operator pointer*( ) { return indirect(); }
		~ptrptr_type( ) { if ( p ) p->reset( cast.from( a ) ); }
	};

}