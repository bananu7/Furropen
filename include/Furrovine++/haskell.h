#ifndef FURROVINEHASKELL_H
#define FURROVINEHASKELL_H

#include <Furrovine++/std_defines.h>
#include <vector>

namespace Furrovine {

	struct until_t { };
	const auto until = until_t();

	template <typename T>
	struct haskell_range {
		std::vector<T> items;

		haskell_range () {

		}

		haskell_range ( std::vector<T> build ) : items(std::move(build)) {

		}

		typename std::vector<T>::iterator begin () {
			return std::begin( items );
		}

		typename std::vector<T>::iterator end () {
			return std::end( items );
		}

		typename std::vector<T>::const_iterator begin () const {
			return std::begin( items );
		}

		typename std::vector<T>::const_iterator end () const {
			return std::end( items );
		}

		template <typename TFx>
		haskell_range<T> operator% ( TFx&& fx ) {
			std::vector<T> filtered;
			filtered.reserve( items.size() );
			for ( auto&& item : items ) {
				if ( fx( item ) )
					filtered.emplace_back( item );
			}
			items = std::move( filtered );
			return *this;
		}

	};

	template <typename TFx, typename T>
	haskell_range<T> operator| ( TFx&& fx, const haskell_range<T>& set ) {
		std::vector<T> comprehension;
		comprehension.reserve( set.items.size() );
		for ( auto& item : set ) {
			comprehension.emplace_back( fx( item ) );
		}
		return haskell_range<T>( std::move( comprehension ) );
	}

	template <typename T, typename T0, typename T1 = T0, typename TDiff = decltype( std::declval<T1>() - std::declval<T0>() )>
	haskell_range<T> make_specific ( T0&& n0, const until_t&, T1&& n1, TDiff&& ndiff = static_cast<TDiff>(1) ) {
		std::vector<T> items;
		if ( n0 == n1 || ndiff == static_cast<TDiff>( 0 ) )
			return haskell_range<T>( std::move( items ) );

		T c0 = n0;

		if ( n0 < n1 ) {
			if ( ndiff < static_cast<TDiff>( 0 ) )
				return haskell_range<T>( std::move( items ) );

			while ( c0 <= n1 ) {
				items.emplace_back( c0 );
				c0 += ndiff;
			}
		}
		else {
			if ( ndiff > static_cast<TDiff>( 0 ) )
				return haskell_range<T>( std::move( items ) );

			while ( c0 >= n1 ) {
				items.emplace_back( c0 );
				c0 += ndiff;
			}
		}

		return haskell_range<T>( std::move( items ) );
	}

	template <typename T0, typename T1 = T0>
	haskell_range<T0> make ( T0&& n0, T1&& n1 ) {
		return make_specific<T0, T0, T1>( std::forward<T0>( n0 ), until, std::forward<T1>( n1 ) ); 
	}

	template <typename T0, typename T1 = T0, typename TDiff = decltype( std::declval<T1>() - std::declval<T0>() )>
	haskell_range<T0> make ( T0&& n0, const until_t&, T1&& n1, TDiff&& ndiff = static_cast<TDiff>(1) ) {
		return make_specific<T0, T0, T1, TDiff>( std::forward<T0>( n0 ), until, std::forward<T1>( n1 ), std::forward<TDiff>( ndiff ) ); 
	}

	template <typename T, typename T0, typename T1 = T0, typename TLim = T0>
	haskell_range<T> make_specific ( T0&& n0, T1&& n1, const until_t&, TLim&& nlim ) {
		typedef decltype( std::declval<T1>() - std::declval<T0>() ) TDiff;
		TDiff ndiff = n1 - n0;
		return make_specific<T, T0, TLim, TDiff>( std::forward<T0>( n0 ), until, std::forward<TLim>( nlim ), std::forward<TDiff>( ndiff ) );
	}

	template <typename T0, typename T1 = T0, typename TLim = T0>
	haskell_range<T0> make ( T0&& n0, T1&& n1, const until_t&, TLim&& nlim ) {
		return make_specific<T0, T0, T1, TLim>( std::forward<T0>( n0 ), std::forward<T1>( n1 ), until, std::forward<TLim>( nlim ) ); 
	}

	template <typename T0, typename T1 = T0, typename TLim = T0>
	haskell_range<T0> make ( T0&& n0, T1&& n1, TLim&& nlim ) {
		return make_specific<T0, T0, T1, TLim>( std::forward<T0>( n0 ), std::forward<T1>( n1 ), until, std::forward<TLim>( nlim ) ); 
	}

}

#endif // FURROVINEHASKELL_H 