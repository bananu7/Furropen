#pragma once

#include <Furrovine++/RVector2.h>
#include <Furrovine++/RVector3.h>
#include <Furrovine++/RVector4.h>

namespace Furrovine {

	template <typename T> 
	struct TVector4 : public RVector4<T> {
	
		static const TVector4<T> UnitX;
		static const TVector4<T> UnitY;
		static const TVector4<T> UnitZ;
		static const TVector4<T> UnitW;
		static const TVector4<T> One;
		static const TVector4<T> Zero;

		TVector4 ( ) {
			x = 0;
			y = 0;
			z = 0;
			w = 0;
		}

		TVector4( T X, T Y, T Z ) {
			x = X;
			y = Y;
			z = Z;
			w = 0;
		}

		TVector4 ( T X, T Y, T Z, T W ) {
			x = X;
			y = Y;
			z = Z;
			w = W;
		}

		TVector4( T X, T Y, T Z, T W, T Homogenous ) {
			x = X / Homogenous;
			y = Y / Homogenous;
			z = Z / Homogenous;
			w = W / Homogenous;
		}

		template <typename Tv, typename Tva>
		TVector4( Tv&& res, Tva tva ) 
		: TVector4( static_cast<T>( res[ 0 ] ), static_cast<T>( res[ 1 ] ), static_cast<T>( res[ 2 ] ), tva ) {

		}

		template <typename Tv>
		TVector4( Tv&& res ) 
		: TVector4( static_cast<T>( res[ 0 ] ), static_cast<T>( res[ 1 ] ), static_cast<T>( res[ 2 ] ), static_cast<T>( res[ 3 ] ) ) {

		}

	};

	template <class T> 
	const TVector4<T> TVector4<T>::UnitX = { static_cast<T>( 1 ),static_cast<T>( 0 ),static_cast<T>( 0 ),static_cast<T>( 0 ) };
	template <class T> 
	const TVector4<T> TVector4<T>::UnitY = { static_cast<T>( 0 ),static_cast<T>( 1 ),static_cast<T>( 0 ),static_cast<T>( 0 ) };
	template <class T> 
	const TVector4<T> TVector4<T>::UnitZ = { static_cast<T>( 0 ),static_cast<T>( 0 ),static_cast<T>( 1 ),static_cast<T>( 0 ) };
	template <class T> 
	const TVector4<T> TVector4<T>::UnitW = { static_cast<T>( 0 ),static_cast<T>( 0 ),static_cast<T>( 0 ),static_cast<T>( 1 ) };
	template <class T> 
	const TVector4<T> TVector4<T>::One = { static_cast<T>( 1 ),static_cast<T>( 1 ),static_cast<T>( 1 ),static_cast<T>( 1 ) };
	template <class T> 
	const TVector4<T> TVector4<T>::Zero = { static_cast<T>( 0 ),static_cast<T>( 0 ),static_cast<T>( 0 ),static_cast<T>( 0 ) };

}
