#pragma once

#include <Furrovine++/SurfaceIntersection.h>
#include <Furrovine++/RVector3.h>
#include <Furrovine++/TRay3.h>

namespace Furrovine {

	template <typename T>
	struct RPlane {
		T distance;
		RVector3<T> normal;

		bool Intersects( const TRay3<T>& ray, T& t ) const {
			T denom = ray.direction.Dot( normal );
			if (denom <= 0)
				return false;

			t = (normal.Dot( ray.origin ) + distance) / denom;
			return true;
		}

		bool Intersects( const TRay3<T>& ray ) const {
			T denom = normal.Dot( ray.direction );

			return denom > 0;
		}

		SurfaceIntersection Intersects( const RVector3<T>& point ) const {
			T p =  normal.Dot( point ) + distance;

			if( p > T(0.0) )
				return SurfaceIntersection::Front;
			else if ( p < T(0.0) )
				return SurfaceIntersection::Back;

			return SurfaceIntersection::Coincides;
		}

		bool Contains( const RVector3<T>& point ) const {
			T p = normal.Dot( point ) + distance;

			return p == static_cast<T>(0);
		}

		T DistanceTo( const RVector3<T>& point ) const {
			return Mathema<T>::Abs( normal.Dot( point ) + distance) /
				normal.LengthSquared();
		}
	};

}
