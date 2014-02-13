#pragma once

#include <Furrovine++/RVector3.h>
#include <Furrovine++/Mathema.h>
#include <Furrovine++/TRay3.h>

namespace Furrovine {

	template <typename T>
	struct TBoundingBox {
	public:
		TVector3<T> min;
		TVector3<T> max;

		TBoundingBox () {

		}

		TBoundingBox (const RVector3<T>& min, const RVector3<T>& max) : min(min), max(max) {

		}

		TBoundingBox (const T& minx, const T& miny, const T& minz, const T& maxx, const T& maxy, const T& maxz) : min(minx, miny, minz), max(maxx, maxy, maxz) {

		}

		TBoundingBox (const RVector3<T>& location, const RVector3<T>& size, bool fromsize ) : min(location), max(location.x + size.x, location.y + size.y, location.z + size.z) {

		}

		TBoundingBox OctalSubdivide ( int octant) const {
			bool maxx = ((octant & 0x1) == 1);
			bool maxy = ((octant & 0x2) == 2);
			bool maxz = ((octant & 0x4) == 4);
			RVector3<T> center = Center();
			RVector3<T> min;
			RVector3<T> max;
			if (maxx) {
				min.x = center.x;
				max.x = max.x;
			}
			else {
				min.x = min.x;
				max.x = center.x;
			}
			if (maxy) {
				min.y = center.y;
				max.y = max.y;
			}
			else {
				min.y = min.y;
				max.y = center.y;
			}
			if ( maxz ) {
				min.z = center.z;
				max.z = max.z;
			}
			else {
				min.z = min.z;
				max.z = center.z;
			}
			return TBoundingBox( min, max );
		}

		T Width ()const  {
			return max.x - min.x;
		}

		T Height () const {
			return max.y - min.y;
		}

		T Depth () const {
			return max.z - min.z;
		}

		void Maximize ( const TBoundingBox& box ) {
			max.max( box.max );
			min.Minimize( box.min );
		}

		RVector3<T> Center () const {
			RVector3<T> r = { min.x + Width() * 0.5f, min.y + Height() * 0.5f, min.z + Depth() * 0.5f };
			return r;
		}

		T DiagonalLength () const {
			return (max - min).Length();
		}

		T HalfDiagonalLength () const {
			return DiagonalLength() * 0.5f;
		}

		bool Contains ( const RVector3<T>& point ) const {
			return point.x > min.x && point.y > min.y && point.z > min.z &&
				point.x < max.x && point.y < max.y && point.z < max.z;
		}

		bool Intersects ( const TRay3<T>& ray ) const {
			T tmin = numeric_limits<T>::lowest();
			T tmax = numeric_limits<T>::max();

			if (ray.direction.x != T(0)) {
				T tx1 = (min.x - ray.origin.x) / ray.direction.x;
				T tx2 = (max.x - ray.origin.x) / ray.direction.x;
				tmin = Mathema<T>::Min(tx1, tx2);
				tmax = Mathema<T>::Max(tx1, tx2);
			}

			if (ray.direction.y != T(0)) {
				T ty1 = (min.y - ray.origin.y) / ray.direction.y;
				T ty2 = (max.y - ray.origin.y) / ray.direction.y;
				tmin = Mathema<T>::Min(Mathema<T>::Min(ty1, ty2), tmin);
				tmax = Mathema<T>::Max(Mathema<T>::Max(ty1, ty2), tmax);
			}

			if (ray.direction.z != T(0)) {
				T tz1 = (min.z - ray.origin.z) / ray.direction.z;
				T tz2 = (max.z - ray.origin.z) / ray.direction.z;
				tmin = Mathema<T>::Min(Mathema<T>::Min(tz1, tz2), tmin);
				tmax = Mathema<T>::Max(Mathema<T>::Max(tz1, tz2), tmax);
			}

			return tmax >= tmin;
		}

		bool Intersects ( const TRay3<T>& ray, T& t ) const {
			const T ox = ray.origin.x, oy = ray.origin.y, oz = ray.origin.z;
			const T dx = ray.direction.x, dy = ray.direction.y, dz = ray.direction.z;

			T tx_min, ty_min, tz_min;
			T tx_max, ty_max, tz_max;

			// x
			T a = T(1.0)/dx;
			if(a >= 0) {
				tx_min = (min.x-ox)*a;
				tx_max = (max.x-ox)*a;
			}
			else {
				tx_min = (max.x-ox)*a;
				tx_max = (min.x-ox)*a;
			}

			// y
			T b = T(1)/dy;
			if(b >= 0) {
				ty_min = (min.y-oy)*b;
				ty_max = (max.y-oy)*b;
			}
			else {
				ty_min = (max.y-oy)*b;
				ty_max = (min.y-oy)*b;
			}

			// z
			T c = T(1)/dz;
			if(c >= 0) {
				tz_min = (min.z-oz)*c;
				tz_max = (max.z-oz)*c;
			}
			else {
				tz_min = (max.z-oz)*c;
				tz_max = (min.z-oz)*c;
			}

			T t0, t1;

			t0 = Mathema<T>::Max(tx_min, ty_min);
			t0 = Mathema<T>::Max(tz_min, t0);

			t1 = Mathema<T>::Min(tx_max, ty_max);
			t1 = Mathema<T>::Min(tz_max, t1);

			if (t0 < t1 && t1 > 0) {
				t = t0;
				return true;
			}
			return false;
		}

	};

}
