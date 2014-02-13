#pragma once

#include <Furrovine++/Vector2.h>

namespace Furrovine { 
	
	template <typename T> 
	struct TRay2 {
	
		TVector2<T> origin;
		TVector2<T> direction;

		TRay2 () {

		}

		TRay2 (const RVector2<T>& direction) : direction(direction) {
		}

		TRay2 (const RVector2<T>& origin, const RVector2<T>& direction) : direction(direction), origin(origin) {
		}

		TRay2 (const RVector2<T>& origin, const RVector2<T>& from, const RVector2<T>& to) : direction(from - to), origin(origin) {
		}

		RVector2<T> At (const T& t) {
			RVector2<T> value(direction);
			value *= t;
			value += origin;
			return value;
		}

		void At (const T& t, RVector2<T>& into) {
			into = direction;
			into *= t;
			into += origin;
		}
	};

}
