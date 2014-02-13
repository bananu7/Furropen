#ifndef FURROVINETSIZE3_H
#define FURROVINETSIZE3_H

#include <Furrovine++/RSize3.h>

namespace Furrovine {

	template <typename T>
	struct TSize3 : RSize3<T> {
		TSize3 ( ) {
			x = 0 ;
			y = 0 ;
		}

		TSize3 ( const RVector3<T>& obj ) {
			x = obj.x ;
			y = obj.y ;
		}

		TSize3 ( const RSize3<T>& obj ) {
			x = obj.x ;
			y = obj.y ;
		}

		TSize3 ( const T(&varr)[3] ) {
			x = varr[0];
			y = varr[1];
		}

		TSize3 ( const std::array<T, 3>& varr ) {
			x = varr[0];
			y = varr[1];
		}

		TSize3 ( const T* varr ) {
			x = varr[0];
			y = varr[1];
		}

		TSize3 (const T& X, const T& Y, const T& Homogenous) {
			x = X / Homogenous ;
			y = Y / Homogenous ;
		}

		TSize3 ( const T& X, const T& Y ) {
			x = X ;
			y = Y ;
		}

		TSize3 ( const T& XY ) {
			x = XY ;
			y = XY ;
		}

		template <typename TCast> 
		TSize3 (const RVector3<TCast>& vec) {
			x = (T)vec.x ;
			y = (T)vec.y ;
		}
	};

}

#endif // FURROVINETSIZE3_H 