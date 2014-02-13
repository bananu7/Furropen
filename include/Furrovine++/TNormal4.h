#pragma once

#include <Furrovine++/TVector4.h>

namespace Furrovine {

	template <typename T>
	struct TNormal4 : public TVector4<T> {

		TNormal4( ) : TVector4( ) {

		}

		TNormal4( const RVector4<T>& v ) : TVector4( normalize( v ) ) {

		}

	};

}
