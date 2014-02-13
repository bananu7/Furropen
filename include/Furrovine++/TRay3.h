#pragma once

#include <Furrovine++/Vector3.h>

namespace Furrovine { 
	
	template <typename T> 
	struct TRay3 {
	public:
		
		TVector3<T> origin;
		TVector3<T> direction;

		TRay3 () {

		}

		TRay3 (const TVector3<T>& direction) : direction(direction) {

		}

		TRay3 (const TVector3<T>& origin, const TVector3<T>& direction) : direction(direction), origin(origin) {

		}

		TRay3 (const TVector3<T>& origin, const TVector3<T>& from, const TVector3<T>& to) : direction(from - to), origin(origin) {

		}

		TVector3<T> at (const T& t) const {
			TVector3<T> value(direction);
			value *= t;
			value += origin;
			return value;
		}
	};

}
