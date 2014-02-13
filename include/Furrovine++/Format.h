#pragma once

#include <Furrovine++/Strings.h>
#include <Furrovine++/Convert.h>

namespace Furrovine {

	namespace detail {
		template <typename TString, typename ...Tn>
		inline typename unqualified<TString>::type Format( TString&& format, Tn&&... argn ) {
			typedef typename unqualified<TString>::type string_t;
			const static ulword arg_count = sizeof...( Tn );
			if ( arg_count < 1 ) {
				return std::forward<TString>( format );
			}

			std::array<string_t, sizeof...( Tn )> convertedvalues = {
				Convert::ToString( std::forward<Tn>( argn ) )...
			};
			string_t value;
			
			codepoint c = 0;
			ulword index = 0;
			ulword start = 0;

			value.Reserve( format.Length( ) * 3 );
			auto i = format.cbegin( );

			while ( i != format.cend( ) ) {
				c = *i;

				if ( c != '{' ) {
					value.Append( c );
					++i;
					continue;
				}

				auto cbegin = i;

				++i;

				index = 0;
				c = *i;
				while ( i != format.cend( ) && c >= '0' && c <= '9' ) {
					index *= 10;
					index += c - '0';
					++i;
					c = *i;
				}


				auto cend = i;
				if ( c != '}' ) {
					while ( cbegin != cend ) {
						value.Append( *cbegin );
						++cbegin;
					}
					continue;
				}

				++i;

				value.Append( convertedvalues[ index ] );
			}
			return value;
		}

	}

	template <typename TEnco, typename TChar, typename TTraits, typename TAlloc, typename ...Tn>
	inline string_base<TEnco, TChar, TTraits, TAlloc> Format( const string_base<TEnco, TChar, TTraits, TAlloc>& format, Tn&&... argn ) {
		return detail::Format( format, std::forward<Tn>( argn )... );
	}

	template <typename TEnco, typename TChar, typename TTraits, typename TAlloc, typename ...Tn>
	inline string_base<TEnco, TChar, TTraits, TAlloc> Format( string_base<TEnco, TChar, TTraits, TAlloc>&& format, Tn&&... argn ) {
		return detail::Format( std::move( format ), std::forward<Tn>( argn )... );
	}

	template <typename T, typename ...Tn>
	inline auto Format( T&& format, Tn&&... argn )
	-> decltype( Format( String( std::forward<T>( format ) ), std::forward<Tn>( argn )... ) ) {
		return Format( String( std::forward<T>( format ) ), std::forward<Tn>( argn )... );
	}

}