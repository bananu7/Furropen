#pragma once

#include <Furrovine++/std_defines.h>
#include <type_traits>
#include <cstddef>
#include <Furrovine++/ptr.h>
#include <Furrovine++/allocator_deleter.h>
#include <Furrovine++/deleter_arg.h>
#include <Furrovine++/in_place.h>
#include <Furrovine++/default_construct.h>

namespace Furrovine {

	namespace detail {
		template <typename T, typename TPtr, typename... Tn>
		ptr<T> make_ptr( std::false_type, Tn&&... argn ) {
			return ptr<T>( new TPtr(std::forward<Tn>(argn)...) );
		}

		template <typename T, typename TPtr, typename... Tn>
		ptr<T> make_ptr( std::true_type, Tn&&... argn ) {
			static_assert(std::extent<TPtr>::value == 0,
				"make_ptr<T[N]>() is forbidden, please use make_ptr<T[]>().");

			typedef typename std::remove_extent<TPtr>::type U;
			return ptr<T>( new U[sizeof...(Tn)]{std::forward<Tn>(argn)...} );
		}

		template <typename T, typename TPtr, typename TDx, typename... Tn>
		ptr<T, TDx> make_ptr_deleter( std::false_type, TDx&& dx, Tn&&... argn ) {
			return ptr<T, TDx>( new TPtr(std::forward<Tn>(argn)...), std::forward<TDx>( dx ) );
		}

		template <typename T, typename TPtr, typename TDx, typename... Tn>
		ptr<T, TDx> make_ptr_deleter( std::true_type, TDx&& dx, Tn&&... argn ) {
			static_assert(std::extent<T>::value == 0,
				"make_ptr<T[N]>() is forbidden, please use make_ptr<T[]>().");

			typedef typename std::remove_extent<TPtr>::type U;
			return ptr<T, TDx>( new U[sizeof...(Tn)]{ std::forward<Tn>(argn)... }, std::forward<TDx>( dx ) );
		}

		template <typename T, typename TPtr, typename TAlloc, typename... Tn>
		ptr<T, allocator_deleter<TAlloc>> make_ptr_allocator( std::false_type, TAlloc&& alloc, Tn&&... argn ) {
			TPtr* p = alloc.allocate( 1 );
			alloc.construct( p, std::forward<Tn>(argn)... );
			return ptr<T, allocator_deleter<TAlloc>>( p, allocator_deleter<TAlloc>( alloc, 1 ) );
		}

		template <typename T, typename TPtr, typename TAlloc, typename... Tn>
		ptr<T, allocator_deleter<TAlloc>> make_ptr_allocator( std::true_type, TAlloc&& alloc, Tn&&... argn ) {
			static_assert(std::extent<T>::value == 0,
				"make_ptr<T[n]>() is forbidden, please use make_ptr<T[]>().");

			typedef typename std::remove_extent<T>::type U;
			U* p = alloc.allocate( sizeof...( Tn ) );
			cascading_construct( p, alloc, std::forward<Tn>( argn )... );
			return ptr<T, allocator_deleter<TAlloc>>( ptr, allocator_deleter<TAlloc>( std::forward<TAlloc>( alloc ), sizeof...( Tn ) ) );
		}
	}

	template <typename T, typename... Tn>
	ptr<T> make_ptr( Tn&&... argn ) {
		return detail::make_ptr<T, T>( std::is_array<T>( ), std::forward<Tn>( argn )... );
	}

	template <typename T, typename TDx, typename... Tn>
	ptr<T, TDx> make_ptr( deleter_arg_t, TDx&& dx, Tn&&... argn ) {
		return detail::make_ptr_deleter<T, T, TDx>( std::is_array<T>( ), std::forward<TDx>( dx ), std::forward<Tn>( argn )... );
	}

	template <typename T, typename TAlloc, typename... Tn>
	ptr<T, allocator_deleter<TAlloc>> make_ptr( std::allocator_arg_t, TAlloc&& alloc, Tn&&... argn ) {
		return detail::make_ptr_allocator<T, T, TAlloc>( std::is_array<T>(), std::forward<TAlloc>( alloc ), std::forward<Tn>(argn)... );
	}

	template <typename T, typename TPtr, typename... Tn>
	ptr<T> make_derived_ptr( Tn&&... argn ) {
		return detail::make_ptr<T, TPtr>( std::is_array<T>( ), std::forward<Tn>( argn )... );
	}

	template <typename T, typename TDx, typename... Tn>
	void reset_ptr( ptr<T, TDx>& p, Tn&&... argn ) {
		p = make_ptr<T>( std::forward<Tn>( argn )... );
	}

}
