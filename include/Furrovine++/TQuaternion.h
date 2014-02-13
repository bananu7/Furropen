#pragma once

#include <Furrovine++/RQuaternion.h>

namespace Furrovine {

	template <typename T> 
	struct TQuaternion : public RQuaternion<T> {
	public:
		static const TQuaternion<T> Identity;
		static const TQuaternion<T> Zero;

		TQuaternion () {
			x = T(0);
			y = T(0);
			z = T(0);
			w = T(1);
		}

		TQuaternion (T EulerX, T EulerY, T EulerZ) {
			Euler(EulerX, EulerY, EulerZ);
		}

		TQuaternion (const TVector3<T>& v, T W) {
			x = v.x;
			y = v.y;
			z = v.z;
			w = W;
		}

		TQuaternion (T X, T Y, T Z, T W) {
			x = X;
			y = Y;
			z = Z;
			w = W;
		}
	};

	template <typename T> const TQuaternion<T> TQuaternion<T>::Identity = TQuaternion(0, 0, 0, 1);
	template <typename T> const TQuaternion<T> TQuaternion<T>::Zero = TQuaternion(0, 0, 0, 0);

}
