#pragma once

#include <Furrovine++/RRgba.h>

namespace Furrovine {

	template <typename T>
	struct TRgba : public RRgba<T> {

		TRgba( ) {
			r = static_cast<T>( 0 );
			g = static_cast<T>( 0 );
			b = static_cast<T>( 0 );
			a = static_cast<T>( 0 );
		}

		template <typename Tc>
		TRgba( Tc cr, Tc cg, Tc cb, Tc ca = color_limits<Tc>::max( ) ) {
			r = color_normalize<T>( cr );
			g = color_normalize<T>( cg );
			b = color_normalize<T>( cb );
			a = color_normalize<T>( ca );
		}

		template <typename Tc, typename Tca>
		TRgba( Tc&& res, Tca a ) : TRgba( res[0], res[1], res[2], a ) {
			
		}

		template <typename Tc>
		TRgba( Tc&& res ) : TRgba( res, res[3] ) {
			
		}

	};

}