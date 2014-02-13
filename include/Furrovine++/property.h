#ifndef FURROVINEPROPERTY_H
#define FURROVINEPROPERTY_H

#include <utility>
#include <type_traits>
#include <tuple>
#include <Furrovine++/default_set.h>
#include <Furrovine++/default_get.h>

namespace Furrovine {

	template <typename T, 
		typename TGetter = default_get<T>, 
		typename TLValueSetter = default_set<T>, 
		typename TRValueSetter = default_set<T>>
	struct property {
	private:
		typedef std::tuple<T, TGetter, TLValueSetter, TRValueSetter> getset;
		getset p;

	public:

		property ( const T& value, const TGetter& valuegetter = TGetter(), const TLValueSetter& lvaluesetter = TLValueSetter(), const TRValueSetter& rvaluesetter = TRValueSetter() )
			: p( value, valuegetter, lvaluesetter, rvaluesetter ) {
				set( value );
		}

		T& data () {
			return std::get<0>( p );
		}

		const T& data () const {
			return std::get<0>( p );
		}

		TGetter& get_getter () const {
			return std::get<1>( p );
		}

		TRValueSetter& get_setter_rvalue () const {
			return std::get<3>( p );
		}

		TLValueSetter& get_setter_lvalue () const {
			return std::get<2>( p );
		}

		T get () {
			return std::get<1>( p )( std::get<0>( p ) );
		}

		void set ( const T& right ) {
			std::get<2>( p )( std::get<0>( p ), right );
		}

		void set ( T&& right ) {
			std::get<3>( p )( std::get<0>( p ), std::move( right ) );
		}

		property& operator= ( const T& right ) {
			set( right );
			return p;
		}

		property& operator= ( T&& right ) {
			set( std::move( right ) );
			return p;
		}

		operator T () {
			return get();
		}
	};

}

#endif // FURROVINEPROPERTY_H 