#pragma once

#include <Furrovine++/TVector2.h>

namespace Furrovine {

	template <typename T>
	struct TNormal2 : public TVector2<T> {

		TNormal2( ) : TVector2( ) {

		}

		TNormal2( const RVector2<T>& v ) : TVector2( Furrovine::normalize( v ) ) {

		}

	};

}