#pragma once

#include <Furrovine++/RVector2.h>

namespace Furrovine {
	
	template <typename T> 
	struct TVector2 : public RVector2<T> {

		static const TVector2<T> UnitX;
		static const TVector2<T> UnitY;
		static const TVector2<T> Up;
		static const TVector2<T> Left;
		static const TVector2<T> Down;
		static const TVector2<T> Right;
		static const TVector2<T> One;
		static const TVector2<T> Zero;

		TVector2 ( ) {
			x = 0;
			y = 0;
		}

		TVector2 (const T& X, const T& Y, const T& Homogenous) {
			x = X / Homogenous ;
			y = Y / Homogenous ;
		}

		TVector2 ( const T& X, const T& Y ) {
			x = X ;
			y = Y ;
		}

		template <typename Tv>
		TVector2( Tv&& res )
			: TVector2(
			static_cast<T>( res[ 0 ] ),
			static_cast<T>( res[ 1 ] ) ) {
		}
	
	};

	template <class T> 
	const TVector2<T> TVector2<T>::Zero = { static_cast<T>( 0 ), static_cast<T>( 0 ) };
	template <class T> 
	const TVector2<T> TVector2<T>::One = { static_cast<T>( 1 ), static_cast<T>( 1 ) };
	template <class T> 
	const TVector2<T> TVector2<T>::Right = { static_cast<T>( 1 ), 0 };
	template <class T> 
	const TVector2<T> TVector2<T>::Up = { static_cast<T>( 0 ), static_cast<T>( 1 ) };
	template <class T> 
	const TVector2<T> TVector2<T>::Left = { (T)-1, static_cast<T>( 0 ) };
	template <class T> 
	const TVector2<T> TVector2<T>::Down = { static_cast<T>( 0 ), (T)-1 };
	template <class T> 
	const TVector2<T> TVector2<T>::UnitX = { static_cast<T>( 1 ), static_cast<T>( 0 ) };
	template <class T> 
	const TVector2<T> TVector2<T>::UnitY = { static_cast<T>( 0 ), static_cast<T>( 1 ) };

}
