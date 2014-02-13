#pragma once

#include <Furrovine++/RSize2.h>

namespace Furrovine {

	template <typename T>
	struct TSize2 : RSize2<T> {
		TSize2 ( ) {
			x = 0 ;
			y = 0 ;
		}

		TSize2 ( const RVector2<T>& obj ) {
			x = obj.x ;
			y = obj.y ;
		}

		TSize2 ( const RSize2<T>& obj ) {
			x = obj.x ;
			y = obj.y ;
		}

		TSize2 ( const T(&varr)[2] ) {
			x = varr[0];
			y = varr[1];
		}

		TSize2 ( const std::array<T, 2>& varr ) {
			x = varr[0];
			y = varr[1];
		}

		TSize2 ( const T* varr ) {
			x = varr[0];
			y = varr[1];
		}

		TSize2 (const T& X, const T& Y, const T& Homogenous) {
			x = X / Homogenous ;
			y = Y / Homogenous ;
		}

		TSize2 ( const T& X, const T& Y ) {
			x = X ;
			y = Y ;
		}

		TSize2 ( const T& XY ) {
			x = XY ;
			y = XY ;
		}

		template <typename TCast> 
		TSize2 (const RVector2<TCast>& vec) {
			x = (T)vec.x ;
			y = (T)vec.y ;
		}
	};

}
 