#pragma once

#include <Furrovine++/RVector3.h>

namespace Furrovine {
	
	template <typename T>
	struct TCylindrical {
	public:
		T Radius;
		T Azimuth;
		T Z;

		TCylindrical (T radius = T(1), T azimuth = T(0), T z = T(0)) {
			Radius = radius;
			Azimuth = azimuth;
			Z = z;
		}

		TCylindrical FromCartesian( const RVector3<T>& cartesian ) {
			return TCylindrical(sqrt( ( cartesian.x * cartesian.x ) + ( cartesian.y * cartesian.y ) ),
				atan2( cartesian.y, cartesian.x ),
				cartesian.z);
		}

		void Set( const RVector3<T>& cartesian ) {
			Radius = sqrt( ( cartesian.x * cartesian.x ) + ( cartesian.y * cartesian.y ) );
			Azimuth = atan2( cartesian.y, cartesian.x );
			/* Case Analysis - Not Necessary with atan2
			if ( cartesian.x == 0 && cartesian.y == 0 )
			Azimuth.Radians = 0;
			else if (cartesian.x >= 0 )
			Azimuth.Radians = (float)Math.Asin( cartesian.y / Radius );
			else if ( cartesian.x < 0 )
			Azimuth.Radians = (float)(-Math.Asin( cartesian.y / Radius ) + Math.PI); */
			Z = cartesian.z;
		}

		RVector3<T> Cartesian( const RVector3<T>& origin ) {
			return Cartesian() + origin;
		}

		RVector3<T> Cartesian( ) const {
			return RVector3<T>( Radius * cos( Azimuth ),
				Radius * sin( Azimuth ),
				Z );
		}

	};

}
