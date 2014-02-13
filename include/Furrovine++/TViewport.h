#pragma once

#include <Furrovine++/RVector2.h>

namespace Furrovine { 
	
	template <typename T>
	struct TViewport {
		union {
			struct {
				RVector2<T> position;
				RVector2<T> size;
				RVector2<T> depth;
			};
			struct {
				T x;
				T y;
				T width;
				T height;
				T mindepth;
				T maxdepth;
			};
		};

		T aspect_ratio( ) const {
			return width / height;
		}

		RVector2<T> center( ) const {
			return position + ( size / static_cast<T>( 2 ) );
		}

	};

}
