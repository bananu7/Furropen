#pragma once

#include <Furrovine++/std_defines.h>
#include <type_traits>
#include <typeinfo>
#include <typeindex>
#include <utility>
#include <memory>
#include <Furrovine++/Export.h>
#include <Furrovine++/null.h>
#include <Furrovine++/allocator_deleter.h>
#include <Furrovine++/in_place.h>
#include <Furrovine++/runtime_type.h>

namespace Furrovine {

	class any {
	private:
		struct any_storage {
			virtual void* data( ) = 0;
			virtual const void* data( ) const = 0;

			virtual void cast( ) = 0;
			virtual void cast( ) const = 0;

			virtual any_storage* copy( ) = 0;

			virtual ~any_storage( ) { }
		};

		template <typename T>
		struct typed_any_storage : public any_storage {
			T item;

			template <typename ...Tn>
			explicit typed_any_storage( Tn&&... argn );

			virtual void* data( ) override;
			virtual const void* data( ) const override;

			virtual void cast( ) override;
			virtual void cast( ) const override;

			virtual any_storage* copy( ) override;
			
			~typed_any_storage( );
		};

		template <typename T, typename TAlloc>
		struct typed_allocated_any_storage : public any_storage{
			TAlloc allocator;
			std::unique_ptr<T, allocator_deleter<TAlloc>> item;

			template <typename ...Tn>
			typed_allocated_any_storage( Tn&&... argn );

			template <typename TAl, typename ...Tn>
			typed_allocated_any_storage( std::allocator_arg_t, TAl&& alloc, Tn&&... argn );

			virtual void* data( ) override;
			virtual const void* data( ) const override;

			virtual void cast( ) override;
			virtual void cast( ) const override;

			virtual any_storage* copy( ) override;
			
			~typed_allocated_any_storage( );
		};

		template <typename T, typename... Tn>
		void place( Tn&&... argn );
		template <typename T, typename TAl, typename... Tn>
		void place( std::allocator_arg_t allocarg, TAl&& alloc, Tn&&... argn );
		furrovineapi void destroy( );

		runtime_type rtt;
		std::unique_ptr<any_storage> storage;

	public:

		furrovineapi any ();

		template <typename T, typename TConcept = typename std::enable_if<!std::is_same<typename std::decay<T>::type, any>::value, T>::type>
		explicit any ( T&& value );

		template <typename T, typename TAl>
		any( std::allocator_arg_t, TAl&& alloc, T&& value );

		template <typename T, typename ...Tn>
		any( in_place_of<T>, Tn&&... argn );

		template <typename T, typename TAl, typename ...Tn>
		any( in_place_of<T>, std::allocator_arg_t allocarg, TAl&& alloc, Tn&&... argn );

		furrovineapi any ( any&& mov );

		furrovineapi any( const any& copy );

		furrovineapi any& operator= ( any&& mov );

		furrovineapi any& operator= ( const any& copy );

		template <typename T>
		any& operator= ( T&& value );

		furrovineapi ~any ();

		furrovineapi explicit operator bool () const;

		furrovineapi const runtime_type& type () const;

		template <typename T, typename ...Tn>
		void set ( Tn&&... argn );

		template <typename T, typename TAlloc, typename ...Tn>
		void set ( std::allocator_arg_t allocarg, TAlloc&& alloc, Tn&&... argn );

		furrovineapi bool is_anything () const;

		furrovineapi bool is_nothing () const;

		template <typename T>
		bool is () const;

		template <typename T>
		typename std::decay<T>::type& as();

		template <typename T>
		const typename std::decay<T>::type& as() const;

		template <typename T>
		typename std::decay<T>::type& unsafe_as();

		template <typename T>
		const typename std::decay<T>::type& unsafe_as() const;

	};

	template <typename T, typename... Tn>
	any make_any( Tn&&... argn ) {
		typedef in_place_of<T> identity;
		return any( identity(), std::forward<Tn>( argn )... );
	}

	template<typename T>
	auto any_cast ( const any& a ) -> decltype( a.as<T>() ) {
		return a.as<T>();
	}

	template<typename T>
	auto any_cast ( any& a ) -> decltype( a.as<T>() ) {
		return a.as<T>();
	}

	template<typename T>
	auto any_cast ( const any* a ) -> decltype( std::addressof( a->as<T>() ) ) {
		if ( a == null )
			return null;
		return std::addressof( a->as<T>() );
	}

	template<typename T>
	auto any_cast ( any* a ) -> decltype( std::addressof( a->as<T>() ) ) {
		if ( a == null )
			return null;
		return std::addressof( a->as<T>( ) );
	}

}
