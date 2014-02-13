#pragma once

#include <Furrovine++/TVector3.h>

namespace Furrovine {

	template <typename T>
	struct TNormal3 : public TVector3<T> {

		TNormal3( ) : TVector3( ) {

		}

		TNormal3( const RVector3<T>& v ) : TVector3( Furrovine::normalize( v ) ) {

		}

	};

}
