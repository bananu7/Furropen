#pragma once

#include <Furrovine++/std_defines.h>
#include <memory>
#include <type_traits>
#include <cstddef>
#include <Furrovine++/default_construct.h>
#include <Furrovine++/deleter_arg.h>
#include <Furrovine++/deleters.h>

namespace Furrovine {

	namespace detail {
		template <typename T, typename... Tn>
		std::unique_ptr<T> make_unique( std::false_type, Tn&&... argn ) {
			return std::unique_ptr<T>( new T( std::forward<Tn>( argn )... ) );
		}

		template <typename T, typename... Tn>
		std::unique_ptr<T> make_unique( std::true_type, Tn&&... argn ) {
			static_assert( std::extent<T>::value == 0,
				"make_unique<T[N]>() is forbidden, please use make_unique<T[]>()." );

			typedef typename std::remove_extent<T>::type U;
			return std::unique_ptr<T>( new U[ sizeof...( Tn ) ]( std::forward<Tn>( argn )... ) );
		}

		template <typename T, typename TDx, typename... Tn>
		std::unique_ptr<T, TDx> make_unique_deleter( std::false_type, Tn&&... argn ) {
			return std::unique_ptr<T, TDx>( new T( std::forward<Tn>( argn )... ) );
		}

		template <typename T, typename TDx, typename... Tn>
		std::unique_ptr<T, TDx> make_unique_deleter( std::true_type, Tn&&... argn ) {
			static_assert( std::extent<T>::value == 0,
				"make_unique<T[N]>() is forbidden, please use make_unique<T[]>()" );

			typedef typename std::remove_extent<T>::type U;
			return std::unique_ptr<T, TDx>( new U[ sizeof...( Tn ) ]( std::forward<Tn>( argn )... ) );
		}

		template <typename T, typename TAlloc, typename... Tn>
		std::unique_ptr<T, allocator_deleter<TAlloc>> make_unique_allocator( std::false_type, TAlloc&& alloc, Tn&&... argn ) {
			U* p = alloc.allocate( 1 );
			alloc.construct( p, std::forward<Tn>( argn )... );
			return p<T, allocator_deleter<TAlloc>>( p, allocator_deleter<TAlloc>( std::forward<TAlloc>( alloc ), 1 ) );
		}

		template <typename T, typename TAlloc, typename... Tn>
		std::unique_ptr<T, allocator_deleter<TAlloc>> make_unique_allocator( std::true_type, TAlloc&& alloc, Tn&&... argn ) {
			static_assert( std::extent<T>::value == 0,
				"make_unique<T[N]>() is forbidden, please use make_unique<T[]>()" );

			typedef typename std::remove_extent<T>::type U;
			U* p = alloc.allocate( sizeof...( Tn ) );
			cascading_construct( p, alloc, std::forward<Tn>( argn )... );
			return p<T, allocator_deleter<TAlloc>>( p, allocator_deleter<TAlloc>( std::forward<TAlloc>( alloc ), sizeof...( Tn ) ) );
		}
	}

	template <typename T, typename... Tn>
	std::unique_ptr<T> make_unique( Tn&&... argn ) {
		return detail::make_unique<T>( std::is_array<T>( ), std::forward<Tn>( argn )... );
	}

	template <typename T, typename TAlloc, typename... Tn>
	std::unique_ptr<T, allocator_deleter<TAlloc>> make_unique( std::allocator_arg_t, TAlloc&& al, Tn&&... argn ) {
		return detail::make_unique_allocator<T, TAlloc>( std::is_array<T>( ), std::forward<TAlloc>( al ), std::forward<Tn>( argn )... );
	}

	template <typename T, typename TDx, typename... Tn>
	std::unique_ptr<T, TDx> make_unique( deleter_arg_t, TDx&& dx, Tn&&... argn ) {
		return detail::make_unique_deleter<T, TDx>( std::is_array<T>( ), std::forward<TDx>( dx ), std::forward<Tn>( argn )... );
	}

	template <typename T, typename TDx, typename... Tn>
	void unique_reset( std::unique_ptr<T, TDx>& p, Tn&&... argn ) {
		p = make_unique<T>( std::forward<Tn>( argn )... );
	}

}
