#pragma once

#include <Furrovine++/Declarations.h>
#include <Furrovine++/Mathema.h>
#include <Furrovine++/RVector3.h>
#include <Furrovine++/RQuaternion.h>

namespace Furrovine {

	template <typename T> struct RMatrix3 {
	public:
		union {
			struct {
#ifdef FURROVINEMATRIXROWMAJOR
				T	m11, m12, m13,
					m21, m22, m23,
					m31, m32, m33;
#else
				T	m11, m21, m31,
					m12, m22, m32,
					m13, m23, m33;
#endif // FURROVINEMATRIXROWMAJOR 
			};

			T m[9];

			struct {
				RVector3<T> rows[3];
			};
		};
		
	};
	
}
