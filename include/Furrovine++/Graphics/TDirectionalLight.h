#pragma once

#include <Furrovine++/Graphics/RDirectionalLight.h>

namespace Furrovine { namespace Graphics {

	template <typename T>
	struct TDirectionalLight : public RDirectionalLight<T> {

		TDirectionalLight( ) {
			direction = TVector3<T>::Down;
		}

		TDirectionalLight( const RVector3<T>& dir ) {
			direction = dir;
		}

	};

}}
