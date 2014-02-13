#pragma once

#include <Furrovine++/RVector2.h>

namespace Furrovine {

	template <typename T>
	struct TSpan {
		static const TSpan Empty;

		union {
			RVector2<T> v;
			struct {
				T left;
				T right;
			};
		};

		TSpan () {

		}

		TSpan ( T Left, T Right ) : left(Left), right(Right) {

		}

		TSpan ( T Width ) : left(0), right( Width ) {

		}

		T Width () const {
			return right - left;
		}

		bool IsEmpty( ) const {
			return right == left;
		}

	};

	template <typename T>
	const TSpan<T> TSpan<T>::Empty{ 0, 0 };

}
