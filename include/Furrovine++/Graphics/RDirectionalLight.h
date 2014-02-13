#pragma once

#include <Furrovine++/Vector3.h>
#include <Furrovine++/Vector4.h>

namespace Furrovine { namespace Graphics {

	template <typename T>
	struct RDirectionalLight {
		RVector3<T> direction;
	};

}}
