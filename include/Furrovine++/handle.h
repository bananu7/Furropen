#pragma once

#include <Furrovine++/handle_typedef_enable_if.h>
#include <Furrovine++/handle_get_null_enable_if.h>
#include <Furrovine++/default_handle_deleter.h>
#include <Furrovine++/ptrptr.h>
#include <utility>

namespace Furrovine {
	
	template <typename T,
		typename TDx = default_handle_deleter<T>,
		typename TNull = typename default_handle_get_null <T, TDx >::type,
		bool same_deleter_null = std::is_same<TDx, TNull>::value>
	class handle { };

	template <typename T, typename TDx, typename TNull>
	class handle<T, TDx, TNull, true> {
	public:
		typedef typename get_handle_type<T, TDx>::type pointer;
		typedef typename get_handle_type<T, TDx>::type handle_type;
		typedef TDx deleter_type;
		typedef TNull nil_type;
		typedef ptrptr_type<handle> ptrptr_t;

	private:
		TDx deleter;
		handle_type res;

	public:

		handle( const handle& nocopy ) = delete;

		handle( ) : res( get_null( ) ) {
		}

		handle( handle_type h )
			: res( h ) {
		}

		handle( std::nullptr_t )
			: res( get_null( ) ) {
		}

		handle( handle_type h, deleter_type d )
			: deleter( std::move( d ) ), res( h ) {
		}

		handle( std::nullptr_t, deleter_type d )
			: deleter( std::move( d ) ), res( get_null( ) ) {
		}

		template <typename ...Dx>
		handle( handle_type h, Dx&&... dx )
			: deleter( std::forward<Dx>( dx )... ), res( h ) {
		}

		template <typename ...Dx>
		handle( std::nullptr_t, Dx&&... dx )
			: deleter( std::forward<Dx>( dx )... ), res( get_null( ) ) {
		}

		handle( handle&& mov )
			: res( std::move( mov.res ) ),
			deleter( std::move( mov.deleter ) ) {
			mov.reset( mov.get_null( ) );
		}

		handle_type get_null( ) const {
			return deleter.get_null( );
		}

		handle_type get( ) const {
			return res;
		}

		void reset( handle_type h ) {
			if ( res != get_null( ) )
				deleter( res );
			res = h;
		}

		void reset( std::nullptr_t ) {
			if ( res != get_null( ) )
				deleter( res );
			res = get_null( );
		}

		handle_type release( ) {
			handle_type rel = std::move( res );
			res = get_null( );
			return rel;
		}

		void swap( handle& handler ) {
			std::swap( handler.res, res );
			std::swap( handler.deleter, deleter );
		}

		deleter_type& get_deleter( ) {
			return deleter;
		}

		const deleter_type& get_deleter( ) const {
			return deleter;
		}

		nil_type& get_nil( ) {
			return deleter;
		}

		const nil_type& get_nil( ) const {
			return deleter;
		}

		handle_type operator* ( ) {
			return get( );
		}

		handle_type operator-> ( ) {
			return get( );
		}

		explicit operator bool( ) const { return get( ) != get_null( ); }
		handle& operator= ( handle&& right ) { reset( right.release( ) ); return *this; }
		handle& operator= ( handle_type right ) { reset( right ); return *this; }
		handle& operator= ( std::nullptr_t ) { reset( nullptr ); return *this; }

		operator handle_type ( ) { return get( ); }
		operator const handle_type( ) const { return get( ); }
		ptrptr_t operator& ( ) { return get_ptrptr( ); }
		ptrptr_t get_ptrptr( ) { return ptrptr( *this ); }

		~handle( ) {
			if ( res != get_null( ) )
				deleter( res );
			res = get_null( );
		}
	};

	template <typename T, typename TDx, typename TNull>
	class handle<T, TDx, TNull, false> {
	public:
		typedef typename get_handle_type<T, TDx>::type pointer;
		typedef typename get_handle_type<T, TDx>::type handle_type;
		typedef TDx deleter_type;
		typedef TNull nil_type;
		typedef ptrptr_type<handle> ptrptr_t;

	private:
		TDx deleter;
		TNull nil;
		handle_type res;
		
	public:

		handle( const handle& nocopy ) = delete;

		handle( handle_type h )
			: res( h ) {
		}

		handle( )
			: res( get_null( ) ) {
		}

		handle( std::nullptr_t )
			: res( get_null( ) ) {
		}

		handle( handle_type h, deleter_type d )
			: deleter( std::move( d ) ), res( h ) {
		}

		handle( std::nullptr_t, deleter_type d )
			: deleter( std::move( d ) ), res( get_null( ) ) {
		}

		handle( handle_type h, deleter_type d, nil_type n )
			: deleter( std::move( d ) ), nil( std::move( n ) ), res( h ) {
		}

		handle( std::nullptr_t h, deleter_type d, nil_type n )
			: deleter( std::move( d ) ), nil( std::move( n ) ), res( get_null() ) {
		}

		handle( handle&& mov )
		: res( std::move( mov.release() ) ),
		nil( std::move( mov.nil ) ),
		deleter( std::move( mov.deleter ) ) {
		
		}

		handle_type get_null( ) const {
			return nil.get_null( );
		}

		handle_type get( ) const {
			return res;
		}

		void reset( handle_type h ) {
			if ( res != get_null( ) )
				deleter( res );
			res = h;
		}

		void reset( std::nullptr_t ) {
			if ( res != get_null( ) )
				deleter( res );
			res = get_null( );
		}

		handle_type release( ) {
			handle_type rel = std::move( res );
			res = get_null( );
			return rel;
		}

		void swap( handle& handler ) {
			std::swap( handler.res, res );
			std::swap( handler.deleter, deleter );
		}

		deleter_type& get_deleter( ) {
			return deleter;
		}

		const deleter_type& get_deleter( ) const {
			return deleter;
		}

		nil_type& get_nil( ) {
			return nil;
		}

		const nil_type& get_nil( ) const {
			return nil;
		}

		handle_type operator* ( ) {
			return get( );
		}

		handle_type operator-> ( ) {
			return get( );
		}

		explicit operator bool( ) const { return get( ) != get_null( ); }
		handle& operator= ( handle&& right ) { reset( right.release( ) ); return *this; }
		handle& operator= ( handle_type right ) { reset( right ); return *this; }
		handle& operator= ( std::nullptr_t ) { reset( nullptr ); return *this; }

		operator handle_type ( ) { return get( ); }
		operator const handle_type( ) const { return get( ); }
		ptrptr_t operator& ( ) { return get_ptrptr( ); }
		ptrptr_t get_ptrptr( ) { return ptrptr( *this ); }

		~handle( ) {
			if ( res != get_null( ) )
				deleter( res );
			res = get_null( );
		}
	};

	template <typename T, typename TDx, typename TNull>
	static bool operator== ( const handle<T, TDx, TNull>& left, const handle<T, TDx, TNull>& right ) { return left.get( ) == right.get( ); }
	
	template <typename T, typename TDx, typename TNull>
	static bool operator== ( std::nullptr_t right, const handle<T, TDx, TNull>& left ) { return left.get( ) == left.get_null(); }
	template <typename T, typename TDx, typename TNull>
	static bool operator== ( const handle<T, TDx, TNull>& left, std::nullptr_t right ) { return left.get( ) == right; }
	template <typename T, typename TDx, typename TNull>
	static bool operator== ( typename handle<T, TDx, TNull>::handle_type right, const handle<T, TDx, TNull>& left ) { return left.get() == right; }
	template <typename T, typename TDx, typename TNull>
	static bool operator== ( const handle<T, TDx, TNull>& left, typename handle<T, TDx, TNull>::handle_type right ) { return left.get() == right; }
	

	template <typename T, typename TDx, typename TNull>
	static bool operator!= ( const handle<T, TDx, TNull>& left, const handle<T, TDx, TNull>& right ) { return left.get( ) != right.get( ); }
	
	template <typename T, typename TDx, typename TNull>
	static bool operator!= ( std::nullptr_t right, const handle<T, TDx, TNull>& left ) { return left.get( ) != left.get_null(); }
	template <typename T, typename TDx, typename TNull>
	static bool operator!= ( const handle<T, TDx, TNull>& left, std::nullptr_t right ) { return left.get( ) != left.get_null(); }
	template <typename T, typename TDx, typename TNull>
	static bool operator!= ( typename handle<T, TDx, TNull>::handle_type right, const handle<T, TDx, TNull>& left ) { return left.get() != right; }
	template <typename T, typename TDx, typename TNull>
	static bool operator!= ( const handle<T, TDx, TNull>& left, typename handle<T, TDx, TNull>::handle_type right ) { return left.get() != right; }
	
}
