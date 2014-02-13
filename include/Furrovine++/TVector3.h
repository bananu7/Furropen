#pragma once

#include <Furrovine++/Platform.Conventions.h>
#include <Furrovine++/RVector3.h>

namespace Furrovine {

	template <typename T> 
	struct TVector3 : public RVector3<T> {

		static const TVector3<T> UnitX;
		static const TVector3<T> UnitY;
		static const TVector3<T> UnitZ;
		static const TVector3<T> Right;
		static const TVector3<T> Up;
		static const TVector3<T> Forward;
		static const TVector3<T> Left;
		static const TVector3<T> Down;
		static const TVector3<T> Backward;
		static const TVector3<T> One;
		static const TVector3<T> Zero;
		static const TVector3<T> MinValue;
		static const TVector3<T> MaxValue;

		TVector3 ( ) {
			x = 0;
			y = 0;
			z = 0;
		}

		TVector3 ( T X, T Y, T Z ) {
			x = X;
			y = Y;
			z = Z;
		}

		TVector3( T X, T Y, T Z, T Homogenous ) {
			x = X / Homogenous;
			y = Y / Homogenous;
			z = Z / Homogenous;
		}

		template <typename Tv>
		TVector3( Tv&& res )
			: TVector3( static_cast<T>( res[ 0 ] ),
			static_cast<T>( res[ 1 ] ),
			static_cast<T>( res[ 2 ] ) ) {
		}

		template <typename Tv, typename Tva>
		TVector3( Tv&& res, Tva tva3 )
			: TVector3( static_cast<T>( res[ 0 ] ),
			static_cast<T>( res[ 1 ] ),
			static_cast<T>( tva3 ) ) {
		}

	};

	template <class T> 
	const TVector3<T> TVector3<T>::MaxValue = { Mathema<T>::Maximum, Mathema<T>::Maximum, Mathema<T>::Maximum };
	template <class T> 
	const TVector3<T> TVector3<T>::MinValue = { Mathema<T>::Minimum, Mathema<T>::Minimum, Mathema<T>::Minimum };
	template <class T> 
	const TVector3<T> TVector3<T>::Zero = { 0, 0, 0 };
	template <class T> 
	const TVector3<T> TVector3<T>::UnitX = { 1, 0, 0 };
	template <class T> 
	const TVector3<T> TVector3<T>::UnitY = { 0, 1, 0 };
	template <class T> 
	const TVector3<T> TVector3<T>::UnitZ = { 0, 0, 1 };
	template <class T> 
	const TVector3<T> TVector3<T>::Right = { 1, 0, 0 };
	template <class T> 
	const TVector3<T> TVector3<T>::Up = { 0, 1, 0 };
#ifdef FURROVINECOORDINATESYSTEMLEFTHANDED
	template <class T> 
	const TVector3<T> TVector3<T>::Forward = { 0, 0, 1 };
	template <class T> 
	const TVector3<T> TVector3<T>::Backward = { 0, 0, -1 };
#else
	template <class T> 
	const TVector3<T> TVector3<T>::Forward = { 0, 0, -1 };
	template <class T> 
	const TVector3<T> TVector3<T>::Backward = { 0, 0, 1 };
#endif
	template <class T> 
	const TVector3<T> TVector3<T>::Left = { -1, 0, 0 };
	template <class T> 
	const TVector3<T> TVector3<T>::Down = { 0, -1, 0 };
	template <class T> 
	const TVector3<T> TVector3<T>::One = { 1, 1, 1 };


}
