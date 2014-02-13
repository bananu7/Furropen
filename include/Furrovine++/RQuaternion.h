#pragma once

#include <Furrovine++/RVector4.h>

namespace Furrovine {
	
	template <typename T> 
	struct RQuaternion {
		union {
			struct {
				T x, y, z, w;
			};
			RVector4<T> axisangle;
			struct {
				RVector3<T> axis;
				T angle;
			};
			T q[4];
		};

		typedef T TElement;

		T Length () {
			return Mathema<T>::Sqrt(w * w + x * x + y * y + z * z);
		}

		T length_squared () {
			return w * w + x * x + y * y + z * z;
		}

		void Normalize () {
			T len = length_squared();
			if (len != T(0.0) && len != T(1.0)) {
				len = Mathema<T>::Sqrt(len);
				x /= len;
				y /= len;
				z /= len;
				w /= len;
			}
		}

		RQuaternion normalize () {
			T len = length_squared();
			RQuaternion r = {x, y, z, w};
			if (len != 0 && len != 1) {
				len = Mathema<T>::Sqrt(len);
				r.x /= len, r.y /= len, r.z /= len, r.w /= len;
			}
			return r;
		}

		void invert () {
			conjugate();
			T len = length_squared();
			if (len != 0.0f && len != 1.0f) {
				x /= len;
				y /= len;
				z /= len;
				w /= len;
			}
		}

		RQuaternion inverse () {
			RQuaternion result(*this);
			result.invert();
			return result;
		}

		void conjugate () {
			x = -x;
			y = -y;
			z = -z;
		}

		RQuaternion conjugation () {
			RQuaternion r = {-x, -y, -z, w};
			return r;
		}

		void axis_angle (T& angleout, RVector3<T>& axisout) {
			angleout = Mathema<T>::Acos(w);
			T angleinv = 1 / Mathema<T>::Sin(angleout);

			axisout.x = x * angleinv;
			axisout.y = y * angleinv;
			axisout.z = z * angleinv;

			angleout *= (T)2;
		}

		RVector3<T> Rotate (const RVector3<T>& point) {
			RQuaternion V = { point.x, point.y, point.z, T(0) };
			RQuaternion conjugate = conjugation();
			conjugate = (*this * V * conjugate);
			return conjugate.axis;
		}

		void Euler (const RVector3<T>& euler) {
			Euler(euler.x, euler.y, euler.z);
		}

		void Euler (T eulerx, T eulery, T eulerz) {
			T cosx, cosy, cosz, sinx, siny, sinz, cosycosz, sinysinz, cosysinz, sinycosz;
			eulerx /= T(2);
			eulery /= T(2);
			eulerz /= T(2);

			cosx = Mathema<T>::Cos(eulerx);
			cosy = Mathema<T>::Cos(eulery);
			cosz = Mathema<T>::Cos(eulerz);

			sinx = Mathema<T>::Sin(eulerx);
			siny = Mathema<T>::Sin(eulery);
			sinz = Mathema<T>::Sin(eulerz);

			cosycosz = cosy * cosz;
			cosysinz = cosy * sinz;
			sinysinz = siny * sinz;
			sinycosz = siny * cosz;

			w = cosx * cosycosz + sinx * sinysinz;
			x = sinx * cosycosz - cosx * sinysinz;
			y = cosx * sinycosz + sinx * cosysinz;
			z = cosx * cosysinz - sinx * sinycosz;
		}

		RVector3<T> Euler (bool homogeneity = true) const {
			T sqw = w * w;
			T sqx = x * x;
			T sqy = y * y;
			T sqz = z * z;

			RVector3<T> euler;
			if (homogeneity) {
				euler.x = Mathema<T>::Atan2(2 * (x * y + z * w), sqx - sqy - sqz + sqw);
				euler.y = Mathema<T>::Asin(-2 * (x * z - y * w));
				euler.z = Mathema<T>::Atan2(2 * (y * z + x * w), -sqx - sqy + sqz + sqw);
			}
			else {
				euler.x = Mathema<T>::Atan2(2 * (z * y + x * w), 1 - 2 * (sqx + sqy));
				euler.y = Mathema<T>::Asin(-2 * (x * z - y * w));
				euler.z = Mathema<T>::Atan2(2 * (x * y + z * w), 1 - 2 * (sqy + sqz));
			}
			return euler;
		}

		T Dot (const RQuaternion& right) const {
			return w * right.w + x * right.x + y * right.y + z * right.z;
		}

		RQuaternion Log () const {
			T a = Mathema<T>::Acos(w);
			T sina = Mathema<T>::Sin(a);
			RQuaternion result;

			result.w = 0;
			if (sina > 0) {
				result.x = a * x / sina;
				result.y = a * y / sina;
				result.z = a * z / sina;
			}
			else {
				result.x = result.y = result.z = 0;
			}
			return result;
		}

		RQuaternion Exp () const {
			T a = Mathema<T>::Sqrt(x * x + y * y + z * z);
			T sina = Mathema<T>::Sin(a);
			T cosa = Mathema<T>::Cos(a);
			RQuaternion result;

			result.w = cosa;
			if (a > 0) {
				result.x = sina * x / a;
				result.y = sina * y / a;
				result.z = sina * z / a;
			}
			else {
				result.x = result.y = result.z = 0;
			}
			return result;
		}

		RQuaternion operator- () const {
			RQuaternion r = {-x, -y, -z,-w};
			return r;
		}

		const RQuaternion operator+ (const RQuaternion& right) const {
			RQuaternion r = {x + right.x, y + right.y, z + right.z, w + right.w};
			return r;
		}

		const RQuaternion operator- (const RQuaternion& right) const {
			RQuaternion r = {x - right.x, y - right.y, z - right.z, w - right.w};
			return r;
		}

		RQuaternion operator* (const RQuaternion& right) const {
			RQuaternion result;
			result.w = w * right.w - x * right.x - y * right.y - z * right.z;
			result.x = w * right.x + x * right.w + y * right.z - z * right.y;
			result.y = w * right.y + x * right.w + y * right.x - z * right.z;
			result.z = w * right.z + x * right.w + y * right.y - z * right.x;
			return result;
		}

		RQuaternion operator* (T scale) const {
			RQuaternion result;
			result.x = x * scale;
			result.y = y * scale;
			result.z = z * scale;
			result.w = w * scale;
			return result;
		}

		RQuaternion operator/ (T scale) const {
			RQuaternion result;
			result.x = x / scale;
			result.y = y / scale;
			result.z = z / scale;
			result.w = w / scale;
			return result;
		}

		RQuaternion& operator*= (const RQuaternion& right) {
			T nx, ny, nz, nw;
			nw = w * right.w - x * right.x - y * right.y - z * right.z;
			nx = w * right.x + x * right.w + y * right.z - z * right.y;
			ny = w * right.y + x * right.w + y * right.x - z * right.z;
			nz = w * right.z + x * right.w + y * right.y - z * right.x;
			w = nw;
			x = nx;
			y = ny;
			z = nz;
			return *this;
		}

		RQuaternion& operator+= (const RQuaternion& right) {
			x += right.x;
			y += right.y;
			z += right.z;
			w += right.w;
			return *this;
		}

		RQuaternion& operator-= (const RQuaternion& right) {
			x -= right.x;
			y -= right.y;
			z -= right.z;
			w -= right.w;
			return *this;
		}

		RQuaternion& operator*= (T scale) {
			x *= scale;
			y *= scale;
			z *= scale;
			w *= scale;
			return *this;
		}

		RQuaternion& operator/= (T scale) {
			x /= scale;
			y /= scale;
			z /= scale;
			w /= scale;
			return *this;
		}

		explicit operator T* ( ) {
			return ( T* )this;
		}

		explicit operator const T* ( ) const {
			return ( T* )this;
		}

		operator RVector4<T> () const {
			RVector4<T> r = {x, y, z, w};
			return r;
		}

		static T Dot (const RQuaternion& left, const RQuaternion& right) {
			return left.x * right.x + left.y * right.y + left.z * right.z + left.w * right.w;
		}

		static void Lerp ( const RQuaternion& q1, const RQuaternion& q2, T t, RQuaternion& result ) {
			result = Lerp( q1, q2, t );
		}

		static RQuaternion Lerp (const RQuaternion& q1, const RQuaternion& q2, T t) {
			RQuaternion lerped = (q1 * ( T(1) - t ) + (q2 * t));
			lerped.Normalize();
			return lerped;
		}

		static RQuaternion Slerp (const RQuaternion& q1, const RQuaternion& q2, T t) {
			RQuaternion q3;
			T dot = Dot(q1, q2);

			/*	dot = Mathema<T>::Cos(theta)
				if (dot < 0), q1 and q2 are more than 90 degrees apart,
				so we can invert one to reduce spinning	*/
			if (dot < 0) {
				dot = -dot;
				q3 = -q2;
			}
			else
				q3 = q2;

			if (dot < 0.95f) {
				T angle = Mathema<T>::Acos(dot);
				return (q1 * Mathema<T>::Sin(angle*(1-t)) + q3 * Mathema<T>::Sin(angle*t))/Mathema<T>::Sin(angle);
			}
			else // if the angle is small, use linear interpolation
				return Lerp(q1,q3,t);
		}

		static RQuaternion CreateFromAxisAngle ( T angle, const RVector3<T>& axis ) {
			axis *= Mathema<T>::Sin(angle * T(0.5));
			RQuaternion r = { axis.x, axis.y, axis.z, Mathema<T>::Cos(angle * T(0.5)) };
			return r;
		}

		static RQuaternion CreateFromYawPitchRoll ( T yaw, T pitch, T roll ) {
			T rollOver2 = roll * T(0.5);
			T sinRollOver2 = Mathema<T>::Sin(rollOver2);
			T cosRollOver2 = Mathema<T>::Cos(rollOver2);
			T pitchOver2 = pitch * T(0.5);
			T sinPitchOver2 = Mathema<T>::Sin(pitchOver2);
			T cosPitchOver2 = Mathema<T>::Cos(pitchOver2);
			T yawOver2 = yaw * T(0.5);
			T sinYawOver2 = Mathema<T>::Sin(yawOver2);
			T cosYawOver2 = Mathema<T>::Cos(yawOver2);

			// Heading = Yaw
			// Attitude = Pitch
			// Bank = Roll

			RQuaternion result = { };
			
			result.w = cosYawOver2 * cosPitchOver2 * cosRollOver2 - sinYawOver2 * sinPitchOver2 * sinRollOver2;
			result.x = sinYawOver2 * sinPitchOver2 * cosRollOver2 + cosYawOver2 * cosPitchOver2 * sinRollOver2;
			result.y = sinYawOver2 * cosPitchOver2 * cosRollOver2 + cosYawOver2 * sinPitchOver2 * sinRollOver2;
			result.z = cosYawOver2 * sinPitchOver2 * cosRollOver2 - sinYawOver2 * cosPitchOver2 * sinRollOver2;

			return result;
		}

		static RQuaternion CreateFromLookAtRotation ( const RVector3<T>& lookat, const RVector3<T>& updirection ) {
			RQuaternion look = { };
			T invw;
			RVector3<T> forward = lookat, up = updirection, right;
			RVector3<T>::OrthoNormalize( forward, up );
			right = RVector3<T>::Cross( up, forward );

			look.w = Mathema<T>::Sqrt( T(1) + right.x + up.y + forward.z ) * T(0.5);
			invw = T(1) / ( T(4) * look.w );

			look.x = ( up.z - forward.y ) * invw;
			look.y = ( forward.x - right.z ) * invw;
			look.z = ( right.y - up.x ) * invw;
			return look;
		}
	};
	
}
