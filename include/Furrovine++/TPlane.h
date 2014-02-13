#pragma once

#include <Furrovine++/RPlane.h>

namespace Furrovine {

	template <typename T>
	struct TPlane : public RPlane<T> {

		TPlane( ) {
			distance = 0;
			normal.x = 0;
			normal.y = 1;
			normal.z = 0;
		}

		TPlane( T dist, T normx, T normy, T normz ) {
			distance = dist;
			normal.x = normx;
			normal.y = normy;
			normal.z = normz;
			normalize( normal );
		}

		template <typename Tv>
		TPlane( T dist, Tv&& norm ) : TPlane( dist, norm[ 0 ], norm[ 1 ], norm[ 2 ] ) {
			
		}

	};

}