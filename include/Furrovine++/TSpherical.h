#pragma once

#include <Furrovine++/RVector3.h>

namespace Furrovine {

	/// <summary>
	/// TSpherical coordinate system. Angles are in radians.
	/// </summary>
	template <typename T>
	struct TSpherical {
	public:
		/// <summary>
		/// The distance from the origin
		/// </summary>
		T Radius;
		/// <summary>
		/// The angle from the x/z plane
		/// </summary>
		T Elevation;
		/// <summary>
		/// The angle around the y axis
		/// </summary>
		T Azimuth;

		TSpherical ( T radius = 1.0f, T elevation = 1.0f, T azimuth = 1.0f ) {
			Radius = radius;
			Elevation = elevation;
			Azimuth = azimuth;
		}

		/// <summary>
		/// Converts the spherical coordinates to Cartesian coordinates.
		/// Assumes that Elevation means the angle from the x/z plane and the Azimuth is the rotation about the Y axis.
		/// </summary>
		RVector3<T> Cartesian () const {
			RVector3<T> result;
			result.x = Radius * sin( Elevation ) * cos( Azimuth );
			result.y = Radius * cos( Elevation );
			result.z = Radius * sin( Elevation ) * sin( Azimuth );
			return result;
		}

		void Cartesian ( const RVector3<T>& cartesian ) {
			Radius = sqrt( ( cartesian.x * cartesian.x ) + ( cartesian.y * cartesian.y ) + ( cartesian.z * cartesian.z ) );
			Elevation = acos( cartesian.y / Radius );
			Azimuth = atan2( cartesian.z, cartesian.x );
		}

		bool IsUnit () const {
			return Radius == 1.0f;
		}

		TSpherical FromCartesian ( const RVector3<T>& cartesian ) {
			T radius = sqrt( ( cartesian.x * cartesian.x ) + ( cartesian.y * cartesian.y ) + ( cartesian.z * cartesian.z ) );
			return TSpherical(
				radius,
				acos( cartesian.y / radius ),
				atan2( cartesian.z, cartesian.x ) );
		}

	};
}
