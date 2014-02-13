#pragma once

#include <Furrovine++/std_defines.h>
#include <Furrovine++/ptrptr.h>
#include <memory>
#include <utility>

namespace Furrovine {

	template <typename T, typename TDx = std::default_delete<T>, bool isarray = std::is_array<T>::value>
	class ptr;

	template <typename T, typename TDx>
	class ptr<T, TDx, false> : private std::unique_ptr<T, TDx> {
	public:
		typedef std::unique_ptr<T, TDx> parent_type;
		typedef typename parent_type::pointer pointer;
		typedef typename parent_type::element_type element_type;
		typedef typename parent_type::deleter_type deleter_type;
		typedef ptrptr_type<ptr> ptrptr_t;

	public:
		ptr( const ptr& nocopy ) = delete;
		ptr& operator=( const ptr& nocopy ) = delete;
		ptr( ) : parent_type( ) {}
		ptr( pointer p ) : parent_type( p ) {}
		ptr( parent_type p ) : parent_type( std::move( p ) ) {}
		ptr( pointer p, const deleter_type& d ) : parent_type( p, d ) {}
		ptr (pointer p, deleter_type&& d) : parent_type(p, std::move( d )) {}
		ptr (std::nullptr_t p) : parent_type(p) {}
		ptr (ptr&& rhs) : parent_type( std::move(rhs) ) { }
		template <typename Tp>
		ptr( ptr<Tp, TDx>&& rhs ) : parent_type( std::move( rhs ) ) {}
		ptr& operator= ( ptr&& right ) { parent_type::operator=( std::move( right ) ); return *this; }
		template <typename Tp>
		ptr& operator= ( ptr<Tp, TDx>&& right ) { parent_type::operator=( std::move( right ) ); return *this; }
		using parent_type::get;
		using parent_type::reset;
		using parent_type::release;
		using parent_type::swap;
		using parent_type::get_deleter;
		using parent_type::operator*;
		using parent_type::operator->;

		explicit operator bool ( ) const { return get() != nullptr; }
		ptr& operator= ( pointer right ) { reset( right ); return *this; }
		ptr& operator= ( std::nullptr_t right ) { reset( right ); return *this; }
		operator pointer () { return get(); };
		operator const pointer () const { return get(); };
		ptrptr_t operator& () { return get_ptrptr(); }
		ptrptr_t get_ptrptr( ) { return ptrptr( *this ); }

	};

	template <typename T, typename TDx>
	class ptr<T, TDx, true> : private std::unique_ptr<T, TDx> {
	private:
		ptr ( const ptr& nocopy ) { }
		ptr& operator=(const ptr& nocopy) { return *this; }

	public:
		typedef std::unique_ptr<T, TDx> parent_type;
		typedef typename parent_type::pointer pointer;
		typedef typename parent_type::element_type element_type;
		typedef typename parent_type::deleter_type deleter_type;
		typedef ptrptr_type<ptr> ptrptr_type;

	public:
		ptr () : parent_type() {}
		ptr( parent_type p ) : parent_type( std::move( p ) ) {}
		ptr( pointer p ) : parent_type( p ) {}
		ptr (pointer p, const deleter_type& d) : parent_type(p, d ) {}
		ptr (pointer p, deleter_type&& d) : parent_type(p, std::move( d )) {}
		ptr (std::nullptr_t p) : parent_type(p) {}
		ptr (ptr&& rhs) : parent_type( std::move(rhs) ) { }
		template <typename Tp>
		ptr( ptr<Tp, TDx>&& rhs ) : parent_type( std::move( rhs ) ) {}
		ptr& operator= ( ptr&& right ) { parent_type::operator=( std::move( right ) ); return *this; }
		template <typename Tp>
		ptr& operator= ( ptr<Tp, TDx>&& right ) { parent_type::operator=( std::move( right ) ); return *this; }
		using parent_type::get;
		using parent_type::release;
		using parent_type::swap;
		using parent_type::get_deleter;
		using parent_type::operator[];
		using parent_type::operator*;

		operator bool ( ) const { return get() != nullptr; }
		ptr& operator= ( pointer right ) { reset( right ); return *this; }
		ptr& operator= ( std::nullptr_t right ) { reset( right ); return *this; }
		operator pointer () { return get(); };
		operator const pointer () const { return get(); };
		ptrptr_type operator& () { return get_ptrptr(); }
		ptrptr_type get_ptrptr( ) { return ptrptr( *this ); }
		
	};

	template<typename T, typename TDx>
	static bool operator== ( typename ptr<T, TDx>::pointer right, const ptr<T, TDx>& left ) { return left.get() == right; }
	template<typename T, typename TDx>
	static bool operator== ( std::nullptr_t right, const ptr<T, TDx>& left ) { return left.get() == right; }
	template<typename T, typename TDx>
	static bool operator== ( const ptr<T, TDx>& left, const ptr<T, TDx>& right ) { return left.get() == right.get(); }
	template<typename T, typename TDx>
	static bool operator== ( const ptr<T, TDx>& left, const typename ptr<T, TDx>::parent_type& right ) { return left.get() == right.get(); }
	template<typename T, typename TDx>
	static bool operator== ( const typename ptr<T, TDx>::parent_type& right, const ptr<T, TDx>& left ) { return left.get() == right.get(); }
	template<typename T, typename TDx>
	static bool operator== ( const ptr<T, TDx>& left, typename ptr<T, TDx>::pointer right ) { return left.get() == right; }
	template<typename T, typename TDx>
	static bool operator== ( const ptr<T, TDx>& left, std::nullptr_t right ) { return left.get() == right; }
	
	template<typename T, typename TDx>
	static bool operator!= ( typename ptr<T, TDx>::pointer right, const ptr<T, TDx>& left ) { return left.get() != right; }
	template<typename T, typename TDx>
	static bool operator!= ( const ptr<T, TDx>& left, const typename ptr<T, TDx>::parent_type& right ) { return left.get() != right.get(); }
	template<typename T, typename TDx>
	static bool operator!= ( const typename ptr<T, TDx>::parent_type& right, const ptr<T, TDx>& left ) { return left.get() != right.get(); }
	template<typename T, typename TDx>
	static bool operator!= ( std::nullptr_t right, const ptr<T, TDx>& left ) { return left.get() != right; }
	template<typename T, typename TDx>
	static bool operator!= ( const ptr<T, TDx>& left, const ptr<T, TDx>& right ) { return left.get() != right.get(); }
	template<typename T, typename TDx>
	static bool operator!= ( const ptr<T, TDx>& left, typename ptr<T, TDx>::pointer right ) { return left.get() != right; }
	template<typename T, typename TDx>
	static bool operator!= ( const ptr<T, TDx>& left, std::nullptr_t right ) { return left.get() != right; }

}
