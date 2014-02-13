#pragma once

#include <Furrovine++/Vector2.h>
#include <Furrovine++/RVector3.h>
#include <Furrovine++/Vector4.h>
#include <Furrovine++/Quaternion.h>
#include <Furrovine++/Matrix.h>

namespace Furrovine {

	struct Math {

		template <typename T>
		static void Fast2DMatrixZ ( T originX, T originY, T scaleX, T scaleY, T rotation, T translationX, T translationY, Matrix& matOut ) {
			// Identify

			//matOut.m11 = 1;
			//matOut.m22 = 1;
			matOut.m33 = 1;
			matOut.m44 = 1;
			matOut.m12 = 0;
			matOut.m13 = 0;
			matOut.m14 = 0;
			matOut.m21 = 0;
			matOut.m23 = 0;
			matOut.m24 = 0;
			matOut.m31 = 0;
			matOut.m32 = 0;
			matOut.m34 = 0;
			//matOut.m41 = 0;
			//matOut.m42 = 0;
			matOut.m34 = 0;

			// Origin

			matOut.m41 = -originX;
			matOut.m42 = -originY;

			// Scaling

			T sX = scaleX;
			T sY = scaleY;
			matOut.m11 = sX;
			matOut.m22 = sY;
			matOut.m41 *= sX;
			matOut.m42 *= sY;
			//matOut.m33 = 1;

			//Rotation

			T cos = (T)Mathema<T>::Cos( rotation );
			T sin = (T)Mathema<T>::Sin( rotation );

			//Z Axis
			T Om11 = matOut.m11;
			T Om12 = matOut.m12;
			T Om21 = matOut.m21;
			T Om22 = matOut.m22;
			T Om31 = matOut.m31;
			T Om32 = matOut.m32;
			T Om41 = matOut.m41;
			T Om42 = matOut.m42;

			matOut.m11 = ( cos * Om11 ) + ( -sin * Om12 );
			matOut.m12 = ( sin * Om11 ) + ( cos * Om12 );

			matOut.m21 = ( cos * Om21 ) + ( -sin * Om22 );
			matOut.m22 = ( sin * Om21 ) + ( cos * Om22 );

			matOut.m41 = ( cos * Om41 ) + ( -sin * Om42 );
			matOut.m42 = ( sin * Om41 ) + ( cos * Om42 );

			// Translation

			matOut.m41 += translationX;
			matOut.m42 += translationY;
		}

		template <typename T>
		static void ToEulerAngles ( const RQuaternion<T>& rotation, RVector3<T>& euler ) {
			RVector3<T> forward = RQuaternion<T>::Transform( RVector3<T>::Forward, rotation );
			RVector3<T> up = RQuaternion<T>::Transform( RVector3<T>::Up, rotation );

			euler = RVector3<T>::AngleTo( RVector3<T>::Zero, forward );

			if ( euler.X == Mathema<T>::HalfPi ) {
				euler.Y = Mathema<T>::Atan2( up.X, up.Z );
				euler.Z = 0;
			}
			else if ( euler.X == -Mathema<T>::HalfPi ) {
				euler.Y = Mathema<T>::Atan2( -up.X, -up.Z );
				euler.Z = 0;
			}
			else {
				up = RMatrix4<T>::Transform( up, Matrix.CreateRotation( -euler.x, -euler.Y, 0 ) );
				
				euler.Z = Mathema<T>::Atan2( -up.X, up.Y );
			}

		}

	};

}
