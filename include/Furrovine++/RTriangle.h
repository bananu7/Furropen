#pragma once

namespace Furrovine {
	
	template <typename T>
	struct RTriangle {
		RVector3<T> a, b, c;

		RVector3<T> normal( ) const {
			return cross( b - a, c - a );
		}

		RVector3<T> minimum( ) const {
			RVector3<T> min( a );
			return min.min( b ).min( c );
		}

		RVector3<T> maximum( ) const {
			RVector3<T> max( a );
			return max.max( b ).max( c );
		}

		RVector3<T> center( ) const {
			RVector3<T> c( a );
			c += b;
			c += c;
			c /= 3;
			return c;
		}

	};

}