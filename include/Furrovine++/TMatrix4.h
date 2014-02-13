#pragma once

#include <Furrovine++/RMatrix4.h>

namespace Furrovine {

	template <typename T> 
	struct TMatrix4 : public RMatrix4<T> {
		static const TMatrix4 Identity;
		static const TMatrix4 Zero;

		TMatrix4 ( const RMatrix4<T>& obj ) {
			cell[0] = obj[0];
			cell[1] = obj[1];
			cell[2] = obj[2];
			cell[3] = obj[3];
			cell[4] = obj[4];
			cell[5] = obj[5];
			cell[6] = obj[6];
			cell[7] = obj[7];
			cell[8] = obj[8];
			cell[9] = obj[9];
			cell[10] = obj[10];
			cell[11] = obj[11];
			cell[12] = obj[12];
			cell[13] = obj[13];
			cell[14] = obj[14];
			cell[15] = obj[15];
		}

		TMatrix4 (T diagonal = T(1)) {
			const T zero(T(0));
			cell[0] = diagonal;
			cell[1] = zero;
			cell[2] = zero;
			cell[3] = zero;
			cell[4] = zero;
			cell[5] = diagonal;
			cell[6] = zero;
			cell[7] = zero;
			cell[8] = zero;
			cell[9] = zero;
			cell[10] = diagonal;
			cell[11] = zero;
			cell[12] = zero;
			cell[13] = zero;
			cell[14] = zero;
			cell[15] = diagonal;
		}

#ifdef FURROVINEMATRIXROWMAJOR
		TMatrix4 ( T x11, T x12, T x13, T x14,
			T x21, T x22, T x23, T x24,
			T x31, T x32, T x33, T x34,
			T x41, T x42, T x43, T x44 ) {
#else
		TMatrix4 ( T x11, T x21, T x31, T x41,
			T x12, T x22, T x32, T x42,
			T x13, T x23, T x33, T x43,
			T x14, T x24, T x34, T x44 ) {
#endif			
			m11 = x11;
			m12 = x12;
			m13 = x13;
			m14 = x14;
			m21 = x21;
			m22 = x22;
			m23 = x23;
			m24 = x24;
			m31 = x31;
			m32 = x32;
			m33 = x33;
			m34 = x34;
			m41 = x41;
			m42 = x42;
			m43 = x43;
			m44 = x44;
		}

		TMatrix4 ( bool memorder,
			T x01, T x02, T x03, T x04,
			T x05, T x06, T x07, T x08,
			T x09, T x10, T x11, T x12,
			T x13, T x14, T x15, T x16 ) {
				cell[0] = x01;
				cell[1] = x02;
				cell[2] = x03;
				cell[3] = x04;
				cell[4] = x05;
				cell[5] = x06;
				cell[6] = x07;
				cell[7] = x08;
				cell[8] = x09;
				cell[9] = x10;
				cell[10] = x11;
				cell[11] = x12;
				cell[12] = x13;
				cell[13] = x14;
				cell[14] = x15;
				cell[15] = x16;
		}

		TMatrix4 (const std::array<T, 16>& matrix, bool rowmajor = 
#ifdef FURROVINEMATRIXROWMAJOR
			true
#else
			false
#endif // FURROVINEMATRIXROWMAJOR
			) : TMatrix4( matrix.data(), rowmajor ) {

		}



		TMatrix4 (const T* matrix, bool rowmajor =
#ifdef FURROVINEMATRIXROWMAJOR
			true
#else
			false
#endif // FURROVINEMATRIXROWMAJOR
			) {
#ifdef FURROVINEMATRIXROWMAJOR
				if (rowmajor) {
					cell[0] = matrix[0];
					cell[1] = matrix[1];
					cell[2] = matrix[2];
					cell[3] = matrix[3];
					cell[4] = matrix[4];
					cell[5] = matrix[5];
					cell[6] = matrix[6];
					cell[7] = matrix[7];
					cell[8] = matrix[8];
					cell[9] = matrix[9];
					cell[10] = matrix[10];
					cell[11] = matrix[11];
					cell[12] = matrix[12];
					cell[13] = matrix[13];
					cell[14] = matrix[14];
					cell[15] = matrix[15];
				}
				else {
					cell[0] = matrix[0];
					cell[1] = matrix[4];
					cell[2] = matrix[8];
					cell[3] = matrix[12];
					cell[4] = matrix[1];
					cell[5] = matrix[5];
					cell[6] = matrix[9];
					cell[7] = matrix[13];
					cell[8] = matrix[2];
					cell[9] = matrix[6];
					cell[10] = matrix[10];
					cell[11] = matrix[14];
					cell[12] = matrix[3];
					cell[13] = matrix[7];
					cell[14] = matrix[11];
					cell[15] = matrix[15];
				}
#else
				if (rowmajor) {
					cell[0] = matrix[0];
					cell[1] = matrix[4];
					cell[2] = matrix[8];
					cell[3] = matrix[12];
					cell[4] = matrix[1];
					cell[5] = matrix[5];
					cell[6] = matrix[9];
					cell[7] = matrix[13];
					cell[8] = matrix[2];
					cell[9] = matrix[6];
					cell[10] = matrix[10];
					cell[11] = matrix[14];
					cell[12] = matrix[3];
					cell[13] = matrix[7];
					cell[14] = matrix[11];
					cell[15] = matrix[15];
				}
				else {
					cell[0] = matrix[0];
					cell[1] = matrix[1];
					cell[2] = matrix[2];
					cell[3] = matrix[3];
					cell[4] = matrix[4];
					cell[5] = matrix[5];
					cell[6] = matrix[6];
					cell[7] = matrix[7];
					cell[8] = matrix[8];
					cell[9] = matrix[9];
					cell[10] = matrix[10];
					cell[11] = matrix[11];
					cell[12] = matrix[12];
					cell[13] = matrix[13];
					cell[14] = matrix[14];
					cell[15] = matrix[15];
				}
#endif
		}

		TMatrix4 (const T (&matrix)[16], bool rowmajor =
#ifdef FURROVINEMATRIXROWMAJOR
		true
#else
		false
#endif // FURROVINEMATRIXROWMAJOR
		) {
#ifdef FURROVINEMATRIXROWMAJOR
			if (rowmajor) {
				cell[0] = matrix[0];
				cell[1] = matrix[1];
				cell[2] = matrix[2];
				cell[3] = matrix[3];
				cell[4] = matrix[4];
				cell[5] = matrix[5];
				cell[6] = matrix[6];
				cell[7] = matrix[7];
				cell[8] = matrix[8];
				cell[9] = matrix[9];
				cell[10] = matrix[10];
				cell[11] = matrix[11];
				cell[12] = matrix[12];
				cell[13] = matrix[13];
				cell[14] = matrix[14];
				cell[15] = matrix[15];
			}
			else {
				cell[0] = matrix[0];
				cell[1] = matrix[4];
				cell[2] = matrix[8];
				cell[3] = matrix[12];
				cell[4] = matrix[1];
				cell[5] = matrix[5];
				cell[6] = matrix[9];
				cell[7] = matrix[13];
				cell[8] = matrix[2];
				cell[9] = matrix[6];
				cell[10] = matrix[10];
				cell[11] = matrix[14];
				cell[12] = matrix[3];
				cell[13] = matrix[7];
				cell[14] = matrix[11];
				cell[15] = matrix[15];
			}
#else
			if (rowmajor) {
				cell[0] = matrix[0];
				cell[1] = matrix[4];
				cell[2] = matrix[8];
				cell[3] = matrix[12];
				cell[4] = matrix[1];
				cell[5] = matrix[5];
				cell[6] = matrix[9];
				cell[7] = matrix[13];
				cell[8] = matrix[2];
				cell[9] = matrix[6];
				cell[10] = matrix[10];
				cell[11] = matrix[14];
				cell[12] = matrix[3];
				cell[13] = matrix[7];
				cell[14] = matrix[11];
				cell[15] = matrix[15];
			}
			else {
				cell[0] = matrix[0];
				cell[1] = matrix[1];
				cell[2] = matrix[2];
				cell[3] = matrix[3];
				cell[4] = matrix[4];
				cell[5] = matrix[5];
				cell[6] = matrix[6];
				cell[7] = matrix[7];
				cell[8] = matrix[8];
				cell[9] = matrix[9];
				cell[10] = matrix[10];
				cell[11] = matrix[11];
				cell[12] = matrix[12];
				cell[13] = matrix[13];
				cell[14] = matrix[14];
				cell[15] = matrix[15];
			}
#endif
		}

		TMatrix4<T>& operator= (const std::array<T, 16>&right ) {
			cell[0] = right[0];
			cell[1] = right[1];
			cell[2] = right[2];
			cell[3] = right[3];
			cell[4] = right[4];
			cell[5] = right[5];
			cell[6] = right[6];
			cell[7] = right[7];
			cell[8] = right[8];
			cell[9] = right[9];
			cell[10] = right[10];
			cell[11] = right[11];
			cell[12] = right[12];
			cell[13] = right[13];
			cell[14] = right[14];
			cell[15] = right[15];
			return *this;
		}

		TMatrix4<T>& operator= (const T (&right)[16]) {
			cell[0] = right[0];
			cell[1] = right[1];
			cell[2] = right[2];
			cell[3] = right[3];
			cell[4] = right[4];
			cell[5] = right[5];
			cell[6] = right[6];
			cell[7] = right[7];
			cell[8] = right[8];
			cell[9] = right[9];
			cell[10] = right[10];
			cell[11] = right[11];
			cell[12] = right[12];
			cell[13] = right[13];
			cell[14] = right[14];
			cell[15] = right[15];
			return *this;
		}

		TMatrix4<T>& operator= ( const RMatrix4<T>&right ) {
			cell[0] = right[0];
			cell[1] = right[1];
			cell[2] = right[2];
			cell[3] = right[3];
			cell[4] = right[4];
			cell[5] = right[5];
			cell[6] = right[6];
			cell[7] = right[7];
			cell[8] = right[8];
			cell[9] = right[9];
			cell[10] = right[10];
			cell[11] = right[11];
			cell[12] = right[12];
			cell[13] = right[13];
			cell[14] = right[14];
			cell[15] = right[15];
			return *this;
		}

	};

	template <typename T> 
	const TMatrix4<T> TMatrix4<T>::Identity = {
		T(1), T(0), T(0), T(0), 
		T(0), T(1), T(0), T(0), 
		T(0), T(0), T(1), T(0), 
		T(0), T(0), T(0), T(1)
	};

	template <typename T> 
	const TMatrix4<T> TMatrix4<T>::Zero = {
		T(0), T(0), T(0), T(0), 
		T(0), T(0), T(0), T(0), 
		T(0), T(0), T(0), T(0), 
		T(0), T(0), T(0), T(0)
	};

}
