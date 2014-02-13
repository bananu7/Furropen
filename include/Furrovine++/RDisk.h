#pragma once

namespace Furrovine {

	template <typename T>
	struct RDisk {
		RPlane<T> plane;
		T radius;
		RVector3<T> origin;
	};

}