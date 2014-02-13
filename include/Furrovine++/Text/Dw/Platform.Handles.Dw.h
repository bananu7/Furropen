#pragma once

#include <Furrovine++/Export.h>
#include <Furrovine++/Platform.Text.h>
#include <Furrovine++/Text/Declarations.Text.h>

namespace Furrovine { namespace Text { namespace Dw {

#ifdef FURROVINEDIRECTWRITE

	struct text_factory_t { };
	const auto text_factory = text_factory_t{ };

	namespace detail {
		furrovineapi IDWriteFactory1* native_handle( const TextResources&, void* target, text_factory_t hint = text_factory );
		furrovineapi IDWriteFactory1* native_handle( const TextResources& target, text_factory_t hint = text_factory );
		furrovineapi IDWriteTextFormat* native_handle( const Font&, void* target );
		furrovineapi IDWriteTextFormat* native_handle( const Font& target );

		template <typename TR, typename T, typename... Tn>
		inline TR native_handle( T* target, Tn&&... argn ) {
			return target == null ? null : detail::native_handle( *target, std::forward<Tn>( argn )... );
		}
	}

	template <typename T, typename... Tn>
	inline auto native_handle( T& target, Tn&&... argn )
		-> decltype( detail::native_handle( target, std::forward<Tn>( argn )... ) ) {
		return detail::native_handle( target, std::forward<Tn>( argn )... );
	}

	template <typename T, typename... Tn>
	inline auto native_handle( T* target, Tn&&... argn )
		-> decltype( detail::native_handle( *target, std::forward<Tn>( argn )... ) ) {
		typedef decltype( detail::native_handle( *target, std::forward<Tn>( argn )... ) ) TR;
		return detail::native_handle<TR>( target, std::forward<Tn>( argn )... );
	}

	template <typename T, typename... Tn>
	inline auto native_handle( void* target, Tn&&... argn )
		-> decltype( detail::native_handle( null_ref<T>::value, target, std::forward<Tn>( argn )... ) ) {
		return detail::native_handle( null_ref<T>::value, target, std::forward<Tn>( argn )... );
	}

	template <typename... Tn>
	inline auto rnative_handle( Tn&&... argn )
		-> decltype( *native_handle( std::forward<Tn>( argn )... ) ) {
		return *native_handle( std::forward<Tn>( argn )... );
	}

	template <typename T, typename... Tn>
	inline auto rnative_handle( Tn&&... argn )
		-> decltype( *native_handle<T>( std::forward<Tn>( argn )... ) ) {
		return *native_handle<T>( std::forward<Tn>( argn )... );
	}

#endif // DIRECTWRITE

}}}
