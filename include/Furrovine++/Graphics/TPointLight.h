#pragma once

#include <Furrovine++/Graphics/RPointLight.h>

namespace Furrovine { namespace Graphics {

	template <typename T>
	struct TPointLight : public RPointLight<T> { 
		
		TPointLight( ) {
			position = TVector3<T>::Zero;
		}

		TPointLight( const RVector3<T>& pos ) {
			position = pos;
		}

	};

}}
