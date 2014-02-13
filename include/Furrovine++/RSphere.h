#pragma once

#include <Furrovine++/Vector3.h>
#include <Furrovine++/Ray3.h>

namespace Furrovine {

	template <typename T>
	struct RSphere {
	public:
		T radius;
		RVector3<T> origin;
	};
}
