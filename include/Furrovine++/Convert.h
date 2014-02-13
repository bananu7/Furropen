#pragma once

#include <Furrovine++/unqualified.h>
#include <Furrovine++/Strings.h>
#include <string>

namespace Furrovine {

	namespace detail {
		template <typename T>
		struct stringifier {
			String operator() ( T item ) {
				return String( std::to_string( std::forward<T>( item ) ) );
			}
		};

		template <typename TEnco, typename TChar, typename TTraits, typename TAlloc>
		struct stringifier<string_base<TEnco, TChar, TTraits, TAlloc>> {
			template <typename U>
			string_base<TEnco, TChar, TTraits, TAlloc> operator() ( U&& item ) {
				return string_base<TEnco, TChar, TTraits, TAlloc>( std::forward<U>( item ) );
			}
		};

		template <typename TChar, std::size_t n>
		struct stringifier<TChar[ n ]> {
			template <typename U>
			String operator() ( U&& item ) {
				return String( std::forward<U>( item ) );
			}
		};

		template <typename TChar>
		struct stringifier<TChar*> {
			template <typename U>
			String operator() ( U&& item ) {
				return String( std::forward<U>( item ) );
			}
		};
	}

	struct Convert {
		template <typename T>
		static bool TryParse( const String& string, T& value ) {
			const charutf8* d = string.data( );
			lword count = 0;
			value = 0;
			while ( *d >= '0' && *d <= '9' ) {
				value = ( value * 10 ) + ( *d - '0' );
				++d;
				++count;
			}

			return count == string.length( );
		}

		template <typename T>
		static String FromInteger( T integer, ulword newbase = 10 ) {
			String out;
			if ( input == 0 ) {
				out.Append( '0' );
				return out;
			}

			if ( newbase < 2 ) {
				newbase = 2;
			}
			bool neg = false;
			if ( input < 0 ) {
				neg = true;
				input *= -1;
			}

			uint16 idx( 0 );
			while ( input > 0 ) {
				idx = input % newbase;
				out.Insert( 0, '0' + idx );
				input /= newbase;
			}
			if ( neg )
				out.Insert( 0, '-' );

			return out;
		}

		template <typename T>
		static String ToString( T&& item ) {
			typedef typename unqualified<T>::type value_t;
			detail::stringifier<value_t> fx;
			return fx( std::forward<T>( item ) );
		}

	};

}
