#pragma once

#include <Furrovine++/Declarations.h>
#include <Furrovine++/MemoryLayout.h>
#include <Furrovine++/Mathema.h>
#include <Furrovine++/Mem.h>
#include <Furrovine++/RVector4.h>
#include <Furrovine++/RQuaternion.h>
#include <Furrovine++/normalized_device_coordinates.h>

namespace Furrovine {
	
	template <typename T> 
	struct RMatrix4 {
		static const RMatrix4 Identity;
		static const RMatrix4 Zero;

#ifdef FURROVINEMATRIXROWMAJOR
		static const MemoryLayout Layout = MemoryLayout::RowMajor;

		enum {
			i11, i12, i13, i14,
			i21, i22, i23, i24,
			i31, i32, i33, i34,
			i41, i42, i43, i44,
			ScaleX = 0,
			ScaleY = 5,
			ScaleZ = 10,
			TranslationX = 12,
			TranslationY = 13,
			TranslationZ = 14,
			Diagonal0 = 0,
			Diagonal1 = 5,
			Diagonal2 = 10,
			Diagonal3 = 15,
			NextRow = 4,
			NextColumn = 1,
		};
#else
		static const MemoryLayout Layout = MemoryLayout::ColumnMajor;

		enum {
			i11, i21, i31, i41,
			i12, i22, i32, i42,
			i13, i23, i33, i43,
			i14, i24, i34, i44,
			ScaleX = 0,
			ScaleY = 5,
			ScaleZ = 10,
			TranslationX = 3,
			TranslationY = 7,
			TranslationZ = 11,
			Diagonal0 = 0, 
			Diagonal1 = 5,
			Diagonal2 = 10,
			Diagonal3 = 15, 
			NextRow = 1,
			NextColumn = 4,
		};
#endif

		union {

			struct {
#ifdef FURROVINEMATRIXROWMAJOR
				T	m11, m12, m13, m14,
					m21, m22, m23, m24,
					m31, m32, m33, m34,
					m41, m42, m43, m44;
#else
				T	m11, m21, m31, m41,
					m12, m22, m32, m42,
					m13, m23, m33, m43,
					m14, m24, m34, m44;
#endif // FURROVINEMATRIXROWMAJOR 
			};

			T cell[16];

			struct {
				RVector4<T> rows[4];
			};
		};

		RMatrix4& Set ( T x11 = T(1), T x21 = T(0), T x31 = T(0), T x41 = T(0),
		T x12 = T(0), T x22 = T(1), T x32 = T(0), T x42 = T(0),
		T x13 = T(0), T x23 = T(0), T x33 = T(1), T x43 = T(0),
		T x14 = T(0), T x24 = T(0), T x34 = T(0), T x44 = T(1) ) {
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
			return *this;
		}

		RMatrix4& Set ( bool,
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
			return *this;
		}

		void Identify () {
			m12 = m13 = m14 = m21 = m23 = m24 = m31 = m32 = m34 = m41 = m42 = m43 = 0;
			m11 = m22 = m33 = m44 = (T)1;
		}

		RMatrix4& Clone (const RMatrix4& obj) {
			memcpy(cell, obj.cell, sizeof(T) * 16);
			return *this;
		}

		RMatrix4& Transpose () {
			Mem::Swap<T>(m12, m21);
			Mem::Swap<T>(m13, m31);
			Mem::Swap<T>(m14, m41);

			Mem::Swap<T>(m32, m23);
			Mem::Swap<T>(m34, m43);

			Mem::Swap<T>(m42, m24);

			return *this;
		}

		RVector3<T> Left ( ) {
			RVector3<T> rout = { m11, m12, m13 };
			return rout;
		}
		
		void Left ( const RVector3<T>& value ) {
			m11 = -value[0];
			m12 = -value[1];
			m13 = -value[2];
		}


		RVector3<T> Right () {
			RVector3<T> rout = { m11, m12, m13 };
			return rout;
		}
		
		void Right ( const RVector3<T>& value ) {
			m11 = value[0];
			m12 = value[1];
			m13 = value[2];
		}

		RVector3<T> Translation () {
			RVector3<T> rout = { m41, m42, m43 };
			return rout;
		}
		
		void Translation ( const RVector3<T>& value ) {
			m41 = value[0];
			m42 = value[1];
			m43 = value[2];
		}

		RVector3<T> Up () {
			RVector3<T> rout = { m21, m22, m23 };
			return rout;
		}
			
		void Up ( const RVector3<T>& value ) {
			m21 = value[0];
			m22 = value[1];
			m23 = value[2];
		}

		void Transform (const RVector3<T>& source, RVector3<T>& value) const {
			Transform( *this, source, value );
		}

		void Transform (const RVector4<T>& source, RVector4<T>& value) const {
			Transform( *this, source, value );
		}

		void Transform (const RVector4<T>& source, RVector3<T>& value) const {
			Transform( *this, source, value );
		}

		void Transform ( const RMatrix4& source, RMatrix4& value ) const {
			Transform( *this, source, value );
		}

		RVector3<T> Transform (const RVector3<T>& source) const {
			RVector3<T> value;
			Transform( source, value );
			return value;
		}

		RVector4<T> Transform (const RVector4<T>& source) const {
			RVector4<T> value;
			Transform( source, value );
			return value;
		}

		RMatrix4 Transform (const RMatrix4& source) const {
			RMatrix4 value;
			Transform( source, value );
			return value;
		}

		T Determinant () {
			T a0 = cell[0] * cell[5] - cell[1] * cell[4];
			T a1 = cell[0] * cell[6] - cell[2] * cell[4];
			T a2 = cell[0] * cell[7] - cell[3] * cell[4];
			T a3 = cell[1] * cell[6] - cell[2] * cell[5];
			T a4 = cell[1] * cell[7] - cell[3] * cell[5];
			T a5 = cell[2] * cell[7] - cell[3] * cell[6];
			T b0 = cell[8] * cell[13] - cell[9] * cell[12];
			T b1 = cell[8] * cell[14] - cell[10] * cell[12];
			T b2 = cell[8] * cell[15] - cell[11] * cell[12];
			T b3 = cell[9] * cell[14] - cell[10] * cell[13];
			T b4 = cell[9] * cell[15] - cell[11] * cell[13];
			T b5 = cell[10] * cell[15] - cell[11] * cell[14];

			T det = a0 * b5 - a1*b4 + a2 * b3 + a3 * b2 - a4 * b1 + a5 * b0;

			return det;
		}

		RMatrix4 Inverse () {
			/* Alternate Method? 
			RMatrix4 t, value;
			T tx = -cell[3], 
			ty = -cell[7], 
			tz = -cell[11];

			for ( int h = 0; h < 3; h++ )  {
			for ( int v = 0; v < 3; v++ ) { 
			t.cell[h + v * 4] = cell[v + h * 4];
			}
			}

			for ( int i = 0; i < 11; i++ )  {
			value.cell[i] = t.cell[i];
			}

			value.cell[3] = tx * cell[0] + ty * cell[1] + tz * cell[2];
			value.cell[7] = tx * cell[4] + ty * cell[5] + tz * cell[6];
			value.cell[11] = tx * cell[8] + ty * cell[9] + tz * cell[10];

			value.cell[12] = cell[12];
			value.cell[13] = cell[13];
			value.cell[14] = cell[14];
			value.cell[15] = cell[15];

			return value;
			*/

			T a0 = cell[0] * cell[5] - cell[1] * cell[4];
			T a1 = cell[0] * cell[6] - cell[2] * cell[4];
			T a2 = cell[0] * cell[7] - cell[3] * cell[4];
			T a3 = cell[1] * cell[6] - cell[2] * cell[5];
			T a4 = cell[1] * cell[7] - cell[3] * cell[5];
			T a5 = cell[2] * cell[7] - cell[3] * cell[6];
			T b0 = cell[8] * cell[13] - cell[9] * cell[12];
			T b1 = cell[8] * cell[14] - cell[10] * cell[12];
			T b2 = cell[8] * cell[15] - cell[11] * cell[12];
			T b3 = cell[9] * cell[14] - cell[10] * cell[13];
			T b4 = cell[9] * cell[15] - cell[11] * cell[13];
			T b5 = cell[10] * cell[15] - cell[11] * cell[14];

			T det = a0 * b5 - a1 * b4 + a2 * b3 + a3 * b2 - a4 * b1 + a5 * b0;
			RMatrix4 inverse;
			if (Mathema<T>::Abs(det) > T(0)) {
				inverse.cell[0] = + cell[5] * b5 - cell[6] * b4 + cell[7] * b3;
				inverse.cell[4] = - cell[4] * b5 + cell[6] * b2 - cell[7] * b1;
				inverse.cell[8] = + cell[4] * b4 - cell[5] * b2 + cell[7] * b0;
				inverse.cell[12] = - cell[4] * b3 + cell[5] * b1 - cell[6] * b0;
				inverse.cell[1] = - cell[1] * b5 + cell[2] * b4 - cell[3] * b3;
				inverse.cell[5] = + cell[0] * b5 - cell[2] * b2 + cell[3] * b1;
				inverse.cell[9] = - cell[0] * b4 + cell[1] * b2 - cell[3] * b0;
				inverse.cell[13] = + cell[0] * b3 - cell[1] * b1 + cell[2] * b0;
				inverse.cell[2] = + cell[13] * a5 - cell[14] * a4 + cell[15] * a3;
				inverse.cell[6] = - cell[12] * a5 + cell[14] * a2 - cell[15] * a1;
				inverse.cell[10] = + cell[12] * a4 - cell[13] * a2 + cell[15] * a0;
				inverse.cell[14] = - cell[12] * a3 + cell[13] * a1 - cell[14] * a0;
				inverse.cell[3] = - cell[9] * a5 + cell[10] * a4 - cell[11] * a3;
				inverse.cell[7] = + cell[8] * a5 - cell[10] * a2 + cell[11] * a1;
				inverse.cell[11] = - cell[8] * a4 + cell[9] * a2 - cell[11] * a0;
				inverse.cell[15] = + cell[8] * a3 - cell[9] * a1 + cell[10] * a0;

				T invDet = (T(1)) / det;
				for (int i = 0; i < 16; ++i)
					inverse.cell[i]  *= invDet;
				
				return inverse;
			}

			inverse.Identify();
			
			return inverse;
		}

		bool Invert () {
			T a0 = cell[0] * cell[5] - cell[1] * cell[4];
			T a1 = cell[0] * cell[6] - cell[2] * cell[4];
			T a2 = cell[0] * cell[7] - cell[3] * cell[4];
			T a3 = cell[1] * cell[6] - cell[2] * cell[5];
			T a4 = cell[1] * cell[7] - cell[3] * cell[5];
			T a5 = cell[2] * cell[7] - cell[3] * cell[6];
			T b0 = cell[8] * cell[13] - cell[9] * cell[12];
			T b1 = cell[8] * cell[14] - cell[10] * cell[12];
			T b2 = cell[8] * cell[15] - cell[11] * cell[12];
			T b3 = cell[9] * cell[14] - cell[10] * cell[13];
			T b4 = cell[9] * cell[15] - cell[11] * cell[13];
			T b5 = cell[10] * cell[15] - cell[11] * cell[14];

			T det = a0 * b5 - a1 * b4 + a2 * b3 + a3 * b2 - a4 * b1 + a5 * b0;
			if ( Mathema<T>::Abs(det) > T(0) ) {
				RMatrix4 inverse;
				inverse.cell[0] = + cell[5] * b5 - cell[6] * b4 + cell[7] * b3;
				inverse.cell[4] = - cell[4] * b5 + cell[6] * b2 - cell[7] * b1;
				inverse.cell[8] = + cell[4] * b4 - cell[5] * b2 + cell[7] * b0;
				inverse.cell[12] = - cell[4] * b3 + cell[5] * b1 - cell[6] * b0;
				inverse.cell[1] = - cell[1] * b5 + cell[2] * b4 - cell[3] * b3;
				inverse.cell[5] = + cell[0] * b5 - cell[2] * b2 + cell[3] * b1;
				inverse.cell[9] = - cell[0] * b4 + cell[1] * b2 - cell[3] * b0;
				inverse.cell[13] = + cell[0] * b3 - cell[1] * b1 + cell[2] * b0;
				inverse.cell[2] = + cell[13] * a5 - cell[14] * a4 + cell[15] * a3;
				inverse.cell[6] = - cell[12] * a5 + cell[14] * a2 - cell[15] * a1;
				inverse.cell[10] = + cell[12] * a4 - cell[13] * a2 + cell[15] * a0;
				inverse.cell[14] = - cell[12] * a3 + cell[13] * a1 - cell[14] * a0;
				inverse.cell[3] = - cell[9] * a5 + cell[10] * a4 - cell[11] * a3;
				inverse.cell[7] = + cell[8] * a5 - cell[10] * a2 + cell[11] * a1;
				inverse.cell[11] = - cell[8] * a4 + cell[9] * a2 - cell[11] * a0;
				inverse.cell[15] = + cell[8] * a3 - cell[9] * a1 + cell[10] * a0;

				T invDet = (T(1)) / det;
				for (int i = 0; i < 16; ++i)
					cell[i] = inverse.cell[i]  * invDet;
				

				return true;
			}

			return false;
		}

		void Decompose (RVector3<T>& valuescale, RQuaternion<T>& valuerotate, RVector3<T>& valuetranslation) {
			T mdiag = Mathema<T>::Sqrt(cell[0] + cell[5] + cell[10] + cell[15]);
			T mdiag2 = 2 * mdiag;
#ifdef FURROVINEMATRIXROWMAJOR
			valuescale[0] = Mathema<T>::Sqrt(m11 * m11 + m21 * m21 * m31 * m31);
			valuescale[1] = Mathema<T>::Sqrt(m12 * m12 + m22 * m22 * m32 * m32);
			valuescale[2] = Mathema<T>::Sqrt(m13 * m13 + m23 * m23 * m33 * m33);
			valuetranslation[0] = m14;
			valuetranslation[1] = m24;
			valuetranslation[2] = m34;
			valuerotate[0] = (cell[6] - cell[9]) / mdiag2;
			valuerotate[1] = (cell[8] - cell[2]) / mdiag2;
			valuerotate[2] = (cell[1] - cell[4]) / mdiag2;
			valuerotate[3] = mdiag / 2;
#else
			valuetranslation[0] = cell[3];
			valuetranslation[1] = cell[7];
			valuetranslation[2] = cell[11];
			valuescale[0] = Mathema<T>::Sqrt(cell[0] * cell[0] + cell[1] * cell[1] + cell[2] * cell[2]);
			valuescale[1] = Mathema<T>::Sqrt(cell[4] * cell[4] + cell[5] * cell[5] + cell[6] * cell[6]);
			valuescale[2] = Mathema<T>::Sqrt(cell[8] * cell[8] + cell[9] * cell[9] + cell[10] * cell[10]);
			valuerotate[0] = (cell[6] - cell[9]) / mdiag2;
			valuerotate[1] = (cell[8] - cell[2]) / mdiag2;
			valuerotate[2] = (cell[1] - cell[4]) / mdiag2;
			valuerotate[3] = mdiag / 2;
#endif
		}

		void Decompose (RVector3<T>& valuescale, RVector3<T>& valuerotate, RVector3<T>& valueranslate) {
			T mdiag = Mathema<T>::Sqrt(cell[0] + cell[5] + cell[10] + cell[15]);
			T mdiag2 = 2 * mdiag;
			T vrot4;
#ifdef FURROVINEMATRIXROWMAJOR
			valuescale[0] = Mathema<T>::Sqrt(m11 * m11 + m21 * m21 * m31 * m31);
			valuescale[1] = Mathema<T>::Sqrt(m12 * m12 + m22 * m22 * m32 * m32);
			valuescale[2] = Mathema<T>::Sqrt(m13 * m13 + m23 * m23 * m33 * m33);
			valueranslate[0] = m14;
			valueranslate[1] = m24;
			valueranslate[2] = m34;
			valuerotate[0] = (cell[6] - cell[9]) / mdiag2;
			valuerotate[1] = (cell[8] - cell[2]) / mdiag2;
			valuerotate[2] = (cell[1] - cell[4]) / mdiag2;
			vrot4 = mdiag / 2;
#else
			valueranslate[0] = cell[3];
			valueranslate[1] = cell[7];
			valueranslate[2] = cell[11];
			valuescale[0] = Mathema<T>::Sqrt(cell[0] * cell[0] + cell[1] * cell[1] + cell[2] * cell[2]);
			valuescale[1] = Mathema<T>::Sqrt(cell[4] * cell[4] + cell[5] * cell[5] + cell[6] * cell[6]);
			valuescale[2] = Mathema<T>::Sqrt(cell[8] * cell[8] + cell[9] * cell[9] + cell[10] * cell[10]);
			valuerotate[1] = Mathema<T>::Asin(-cell[8]);
			T theta = Mathema<T>::Cos(valuerotate[1]);
			valuerotate[0] = Mathema<T>::Asin(Mathema<T>::Mod(cell[9] / theta, T(1)) );
			valuerotate[2] = Mathema<T>::Asin(Mathema<T>::Mod(cell[4] / theta, T(1)) );
#endif
		}

		bool Equals ( const RMatrix4& right ) const {
			return cell[0] == right.cell[0] &&
				cell[1] == right.cell[1] &&
				cell[2] == right.cell[2] &&
				cell[3] == right.cell[3] &&
				cell[4] == right.cell[4] &&
				cell[5] == right.cell[5] &&
				cell[6] == right.cell[6] &&
				cell[7] == right.cell[7] &&
				cell[8] == right.cell[8] &&
				cell[9] == right.cell[9] &&
				cell[10] == right.cell[10] &&
				cell[11] == right.cell[11] &&
				cell[12] == right.cell[12] &&
				cell[13] == right.cell[13] &&
				cell[14] == right.cell[14] &&
				cell[15] == right.cell[15];
		}

		RMatrix4 operator+ (const RMatrix4& right) const {
			RMatrix4 r = {
				cell[0] + right.cell[0],
				cell[1] + right.cell[1],
				cell[2] + right.cell[2],
				cell[3] + right.cell[3],
				cell[4] + right.cell[4],
				cell[5] + right.cell[5],
				cell[6] + right.cell[6],
				cell[7] + right.cell[7],
				cell[8] + right.cell[8],
				cell[9] + right.cell[9],
				cell[10] + right.cell[10],
				cell[11] + right.cell[11],
				cell[12] + right.cell[12],
				cell[13] + right.cell[13],
				cell[14] + right.cell[14],
				cell[15] + right.cell[15]
			};
			return r;
		}

		RMatrix4 operator- (const RMatrix4& right) const {
			RMatrix4 r = {
				cell[0] - right.cell[0],
				cell[1] - right.cell[1],
				cell[2] - right.cell[2],
				cell[3] - right.cell[3],
				cell[4] - right.cell[4],
				cell[5] - right.cell[5],
				cell[6] - right.cell[6],
				cell[7] - right.cell[7],
				cell[8] - right.cell[8],
				cell[9] - right.cell[9],
				cell[10] - right.cell[10],
				cell[11] - right.cell[11],
				cell[12] - right.cell[12],
				cell[13] - right.cell[13],
				cell[14] - right.cell[14],
				cell[15] - right.cell[15]
			};
			return r;
		}

		RMatrix4 operator* (const T& right) const {
			RMatrix4 r = {
				cell[0] * right,
				cell[1] * right,
				cell[2] * right,
				cell[3] * right,
				cell[4] * right,
				cell[5] * right,
				cell[6] * right,
				cell[7] * right,
				cell[8] * right,
				cell[9] * right,
				cell[10] * right,
				cell[11] * right,
				cell[12] * right,
				cell[13] * right,
				cell[14] * right,
				cell[15] * right
			};
			return r;
		}

		RMatrix4 operator/ (const T& right) const {
			if (right == T(0)) {
				RMatrix4 z = { 0 };
				return z;
			}
			T invright = (T(1)) / right;
			RMatrix4 r = { 
				cell[0] * invright,
				cell[1] * invright,
				cell[2] * invright,
				cell[3] * invright,
				cell[4] * invright,
				cell[5] * invright,
				cell[6] * invright,
				cell[7] * invright,
				cell[8] * invright,
				cell[9] * invright,
				cell[10] * invright,
				cell[11] * invright,
				cell[12] * invright,
				cell[13] * invright,
				cell[14] * invright,
				cell[15] * invright };

			return r;
		}

		RMatrix4& operator+= (const RMatrix4& right) {
			for (int i = 0; i < 16; ++i)
				cell[i] += right.cell[i];

			return *this;
		}

		RMatrix4& operator-= (const RMatrix4& right) {
			for (int i = 0; i < 16; ++i)
				cell[i] += right.cell[i];

			return *this;
		}

		RMatrix4& operator*= ( const T& right ) {
			for (int i = 0; i < 16; ++i)
				cell[i] *= right;

			return *this;
		}

		RMatrix4& operator/= (const T& right) {
			if (right == T(0))
				return *this;

			T invright = (T(1)) / right;
			for (int i = 0; i < 16; ++i)
				cell[i] *= invright;
			
			return *this;
		}

		RMatrix4 operator* ( const RMatrix4& right ) const {
			return Transform( right );
		}

		RMatrix4& operator*= ( const RMatrix4& right ) {
			T value[16] = {
				right.cell[1 * 1 - 1] * cell[1 * 1 - 1] + right.cell[1 * 2 - 1] * cell[2 * 1 - 1] + right.cell[1 * 3 - 1] * cell[3 * 1 - 1] + right.cell[1 * 4 - 1] * cell[4 * 1 - 1],
				right.cell[1 * 1 - 1] * cell[1 * 2 - 1] + right.cell[1 * 2 - 1] * cell[2 * 2 - 1] + right.cell[1 * 3 - 1] * cell[3 * 2 - 1] + right.cell[1 * 4 - 1] * cell[4 * 2 - 1],
				right.cell[1 * 1 - 1] * cell[1 * 3 - 1] + right.cell[1 * 2 - 1] * cell[2 * 3 - 1] + right.cell[1 * 3 - 1] * cell[3 * 3 - 1] + right.cell[1 * 4 - 1] * cell[4 * 3 - 1],
				right.cell[1 * 1 - 1] * cell[1 * 4 - 1] + right.cell[1 * 2 - 1] * cell[2 * 4 - 1] + right.cell[1 * 3 - 1] * cell[3 * 4 - 1] + right.cell[1 * 4 - 1] * cell[4 * 4 - 1],
				right.cell[2 * 1 - 1] * cell[1 * 1 - 1] + right.cell[2 * 2 - 1] * cell[2 * 1 - 1] + right.cell[2 * 3 - 1] * cell[3 * 1 - 1] + right.cell[2 * 4 - 1] * cell[4 * 1 - 1],
				right.cell[2 * 1 - 1] * cell[1 * 2 - 1] + right.cell[2 * 2 - 1] * cell[2 * 2 - 1] + right.cell[2 * 3 - 1] * cell[3 * 2 - 1] + right.cell[2 * 4 - 1] * cell[4 * 2 - 1],
				right.cell[2 * 1 - 1] * cell[1 * 3 - 1] + right.cell[2 * 2 - 1] * cell[2 * 3 - 1] + right.cell[2 * 3 - 1] * cell[3 * 3 - 1] + right.cell[2 * 4 - 1] * cell[4 * 3 - 1],
				right.cell[2 * 1 - 1] * cell[1 * 4 - 1] + right.cell[2 * 2 - 1] * cell[2 * 4 - 1] + right.cell[2 * 3 - 1] * cell[3 * 4 - 1] + right.cell[2 * 4 - 1] * cell[4 * 4 - 1],
				right.cell[3 * 1 - 1] * cell[1 * 1 - 1] + right.cell[3 * 2 - 1] * cell[2 * 1 - 1] + right.cell[3 * 3 - 1] * cell[3 * 1 - 1] + right.cell[3 * 4 - 1] * cell[4 * 1 - 1],
				right.cell[3 * 1 - 1] * cell[1 * 2 - 1] + right.cell[3 * 2 - 1] * cell[2 * 2 - 1] + right.cell[3 * 3 - 1] * cell[3 * 2 - 1] + right.cell[3 * 4 - 1] * cell[4 * 2 - 1],
				right.cell[3 * 1 - 1] * cell[1 * 3 - 1] + right.cell[3 * 2 - 1] * cell[2 * 3 - 1] + right.cell[3 * 3 - 1] * cell[3 * 3 - 1] + right.cell[3 * 4 - 1] * cell[4 * 3 - 1],
				right.cell[3 * 1 - 1] * cell[1 * 4 - 1] + right.cell[3 * 2 - 1] * cell[2 * 4 - 1] + right.cell[3 * 3 - 1] * cell[3 * 4 - 1] + right.cell[3 * 4 - 1] * cell[4 * 4 - 1],
				right.cell[4 * 1 - 1] * cell[1 * 1 - 1] + right.cell[4 * 2 - 1] * cell[2 * 1 - 1] + right.cell[4 * 3 - 1] * cell[3 * 1 - 1] + right.cell[4 * 4 - 1] * cell[4 * 1 - 1],
				right.cell[4 * 1 - 1] * cell[1 * 2 - 1] + right.cell[4 * 2 - 1] * cell[2 * 2 - 1] + right.cell[4 * 3 - 1] * cell[3 * 2 - 1] + right.cell[4 * 4 - 1] * cell[4 * 2 - 1],
				right.cell[4 * 1 - 1] * cell[1 * 3 - 1] + right.cell[4 * 2 - 1] * cell[2 * 3 - 1] + right.cell[4 * 3 - 1] * cell[3 * 3 - 1] + right.cell[4 * 4 - 1] * cell[4 * 3 - 1],
				right.cell[4 * 1 - 1] * cell[1 * 4 - 1] + right.cell[4 * 2 - 1] * cell[2 * 4 - 1] + right.cell[4 * 3 - 1] * cell[3 * 4 - 1] + right.cell[4 * 4 - 1] * cell[4 * 4 - 1]
			};

			memcpy(cell, value, sizeof(T) * 16);

			return *this;
		}

		bool operator== ( const RMatrix4& right ) const {
			return memcmp(cell, right.cell, sizeof(T) * 16) == 0;
		}

		bool operator!= ( const RMatrix4& right ) const {
			return memcmp(cell, right.cell, sizeof(T) * 16) != 0;
		}

		bool operator== ( T* right ) const {
			return memcmp(cell, right, sizeof(T) * 16) == 0;
		}

		bool operator!= ( T* right ) const {
			return memcmp(cell, right, sizeof(T) * 16) != 0;
		}

		explicit operator const T* () const {
			return cell;
		}

		explicit operator T* () {
			return cell;
		}

		T& operator[] (int index) {
			return cell[index];
		}

		const T& operator[] (int index) const {
			return cell[index];
		}

		T& operator() (int column, int row) {
			return cell[row * 4 + column];
		}

		const T& operator() (int column, int row) const {
			return cell[row * 4 + column];
		}

		static RMatrix4 CreateColumnMajor ( T x11, T x21, T x31, T x41,
			T x12, T x22, T x32, T x42,
			T x13, T x23, T x33, T x43,
			T x14, T x24, T x34, T x44 ) {
				RMatrix4 r = {
#ifdef FURROVINEMATRIXROWMAJOR
					x11, x12, x13, x14,
					x21, x22, x23, x24,
					x31, x32, x33, x34,
					x41, x42, x43, x44
#else
					x11, x21, x31, x41,
					x12, x22, x32, x42,
					x13, x23, x33, x43,
					x14, x24, x34, x44
#endif
				};
				return r;
		}

		static RMatrix4 CreateRowMajor ( T x11, T x12, T x13, T x14,
			T x21, T x22, T x23, T x24,
			T x31, T x32, T x33, T x34,
			T x41, T x42, T x43, T x44 ) {
			RMatrix4 r = {
#ifdef FURROVINEMATRIXROWMAJOR
				x11, x12, x13, x14,
				x21, x22, x23, x24,
				x31, x32, x33, x34,
				x41, x42, x43, x44
#else
				x11, x21, x31, x41,
				x12, x22, x32, x42,
				x13, x23, x33, x43,
				x14, x24, x34, x44
#endif
			};
			return r;
		}

		static RVector2<T> Transform( const RMatrix4& matrix, const RVector2<T>& source ) {
			RVector2<T> val;
			matrix.Transform( matrix, source, val );
			return val;
		}

		static RVector3<T> Transform( const RMatrix4& matrix, const RVector3<T>& source ) {
			RVector3<T> val;
			matrix.Transform( matrix, source, val );
			return val;
		}

		static RVector4<T> Transform (const RMatrix4& matrix, const RVector4<T>& source) {
			RVector4<T> val;
			matrix.Transform( matrix, source, val );
			return val;
		}

		static RMatrix4 Transform (const RMatrix4& matrix, const RMatrix4& source) {
			RMatrix4 val;
			Transform( matrix, source, val );
			return val;
		}

		static void Transform( const RMatrix4& matrix, const RVector2<T>& source, RVector2<T>& value ) {
			T w =
				( matrix.cell[ 3 * NextColumn + 0 * NextRow ] * source[ 0 ] ) +
				( matrix.cell[ 3 * NextColumn + 1 * NextRow ] * source[ 1 ] ) +
				0/*( matrix.cell[ 3 * NextColumn + 2 * NextRow ] * source[ 2 ] )*/ +
				matrix.cell[ 3 * NextColumn + 3 * NextRow ];

			for ( ulword c = 0; c < 2; c++ ) {
				value[ c ] =
					( matrix.cell[ c * NextColumn + 0 * NextRow ] * source[ 0 ] ) +
					( matrix.cell[ c * NextColumn + 1 * NextRow ] * source[ 1 ] ) +
					0/*( matrix.cell[ c * NextColumn + 2 * NextRow ] * source[ 2 ] )*/ +
					matrix.cell[ c * NextColumn + 3 * NextRow ];
			}

			value /= w;
		}

		static void Transform (const RMatrix4& matrix, const RVector3<T>& source, RVector3<T>& value) {
			T w = 
				( matrix.cell[3 * NextColumn + 0 * NextRow] * source[ 0 ] ) + 
				( matrix.cell[3 * NextColumn + 1 * NextRow] * source[ 1 ] ) + 
				( matrix.cell[3 * NextColumn + 2 * NextRow] * source[ 2 ] ) + 
				matrix.cell[3 * NextColumn + 3 * NextRow];

			int c;
			
			for ( c = 0; c < 3; c++ ) {
				value[ c ] = 
					( matrix.cell[c * NextColumn + 0 * NextRow] * source[ 0 ] ) + 
					( matrix.cell[c * NextColumn + 1 * NextRow] * source[ 1 ] ) + 
					( matrix.cell[c * NextColumn + 2 * NextRow] * source[ 2 ] ) + 
					matrix.cell[c * NextColumn + 3 * NextRow];
			}

			value /= w;
		}

		static void Transform (const RMatrix4& matrix, const RVector4<T>& source, RVector4<T>& value) {
			int y;

			for (  y = 0; y < 4; y++ ) {
				value[ y ] = 
					( matrix.cell[y * NextRow + 0] * source[ 0 ] ) + 
					( matrix.cell[y * NextRow + 1] * source[ 1 ] ) + 
					( matrix.cell[y * NextRow + 2] * source[ 2 ] ) + 
					matrix.cell[y * NextRow + 3];
			}
		}

		static void Transform (const RMatrix4& matrix, const RVector4<T>& source, RVector3<T>& value) {
			T w = matrix.cell[3 * NextRow + 0] * source[ 0 ] +
				matrix.cell[3 * NextRow + 1] * source[ 1 ] +
				matrix.cell[3 * NextRow + 2] * source[ 2 ] +
				matrix.cell[3 * NextRow + 3];

			int y;

			for (  y = 0; y < 3; y++ ) {
				value[ y ] = 
					( matrix.cell[y * NextRow + 0] * source[ 0 ] ) + 
					( matrix.cell[y * NextRow + 1] * source[ 1 ] ) + 
					( matrix.cell[y * NextRow + 2] * source[ 2 ] ) + 
					matrix.cell[y * NextRow + 3];
			}

			value /= w;
		}

		static void Multiply (const RMatrix4& matrix, const RMatrix4& source, RMatrix4& value) {
			Transform( matrix, source, value );
		}

		static void Transform (const RMatrix4& matrix, const RMatrix4& source, RMatrix4& value) {
			RMatrix4 result;
			int c, r;
			for ( c = 0; c < 4; c++ ) {
				for ( r = 0; r < 4; r++ ) {
					result.cell[ r * 4 + c ] =
						matrix.cell[r * NextRow] * source[ c ] +
						matrix.cell[r * NextRow + 1] * source[c + NextRow * 1] +
						matrix.cell[r * NextRow + 2] * source[c + NextRow * 2] +
						matrix.cell[r * NextRow + 3] * source[c + NextRow * 3];
				}
			}
			value = result;
		}

		static RMatrix4 Transpose (const RMatrix4& matrix) {
			RMatrix4 r = {
				matrix.cell[0],
				matrix.cell[4],
				matrix.cell[8],
				matrix.cell[12],
				matrix.cell[1],
				matrix.cell[5],
				matrix.cell[9],
				matrix.cell[13],
				matrix.cell[2],
				matrix.cell[6],
				matrix.cell[10],
				matrix.cell[14],
				matrix.cell[3],
				matrix.cell[7],
				matrix.cell[11],
				matrix.cell[15]
			};
			return r;
		}

		static RMatrix4 Adjoint (const RMatrix4& matrix) {
			T a0 = matrix.cell[0] * matrix.cell[5] - matrix.cell[1] * matrix.cell[4];
			T a1 = matrix.cell[0] * matrix.cell[6] - matrix.cell[2] * matrix.cell[4];
			T a2 = matrix.cell[0] * matrix.cell[7] - matrix.cell[3] * matrix.cell[4];
			T a3 = matrix.cell[1] * matrix.cell[6] - matrix.cell[2] * matrix.cell[5];
			T a4 = matrix.cell[1] * matrix.cell[7] - matrix.cell[3] * matrix.cell[5];
			T a5 = matrix.cell[2] * matrix.cell[7] - matrix.cell[3] * matrix.cell[6];
			T b0 = matrix.cell[8] * matrix.cell[13] - matrix.cell[9] * matrix.cell[12];
			T b1 = matrix.cell[8] * matrix.cell[14] - matrix.cell[10] * matrix.cell[12];
			T b2 = matrix.cell[8] * matrix.cell[15] - matrix.cell[11] * matrix.cell[12];
			T b3 = matrix.cell[9] * matrix.cell[14] - matrix.cell[10] * matrix.cell[13];
			T b4 = matrix.cell[9] * matrix.cell[15] - matrix.cell[11] * matrix.cell[13];
			T b5 = matrix.cell[10] * matrix.cell[15] - matrix.cell[11] * matrix.cell[14];

			RMatrix4 r = {
				+ matrix.cell[5] * b5 - matrix.cell[6] * b4 + matrix.cell[7] * b3,
				- matrix.cell[1] * b5 + matrix.cell[2] * b4 - matrix.cell[3] * b3,
				+ matrix.cell[13] * a5 - matrix.cell[14] * a4 + matrix.cell[15] * a3,
				- matrix.cell[9] * a5 + matrix.cell[10] * a4 - matrix.cell[11] * a3,
				- matrix.cell[4] * b5 + matrix.cell[6] * b2 - matrix.cell[7] * b1,
				+ matrix.cell[0] * b5 - matrix.cell[2] * b2 + matrix.cell[3] * b1,
				- matrix.cell[12] * a5 + matrix.cell[14] * a2 - matrix.cell[15] * a1,
				+ matrix.cell[8] * a5 - matrix.cell[10] * a2 + matrix.cell[11] * a1,
				+ matrix.cell[4] * b4 - matrix.cell[5] * b2 + matrix.cell[7] * b0,
				- matrix.cell[0] * b4 + matrix.cell[1] * b2 - matrix.cell[3] * b0,
				+ matrix.cell[12] * a4 - matrix.cell[13] * a2 + matrix.cell[15] * a0,
				- matrix.cell[8] * a4 + matrix.cell[9] * a2 - matrix.cell[11] * a0,
				- matrix.cell[4] * b3 + matrix.cell[5] * b1 - matrix.cell[6] * b0,
				+ matrix.cell[0] * b3 - matrix.cell[1] * b1 + matrix.cell[2] * b0,
				- matrix.cell[12] * a3 + matrix.cell[13] * a1 - matrix.cell[14] * a0,
				+ matrix.cell[8] * a3 - matrix.cell[9] * a1 + matrix.cell[10] * a0
			};
			return r;
		}

		static RMatrix4 Inverse (const RMatrix4& matrix) {
			T a0 = matrix.cell[0] * matrix.cell[5] - matrix.cell[1] * matrix.cell[4];
			T a1 = matrix.cell[0] * matrix.cell[6] - matrix.cell[2] * matrix.cell[4];
			T a2 = matrix.cell[0] * matrix.cell[7] - matrix.cell[3] * matrix.cell[4];
			T a3 = matrix.cell[1] * matrix.cell[6] - matrix.cell[2] * matrix.cell[5];
			T a4 = matrix.cell[1] * matrix.cell[7] - matrix.cell[3] * matrix.cell[5];
			T a5 = matrix.cell[2] * matrix.cell[7] - matrix.cell[3] * matrix.cell[6];
			T b0 = matrix.cell[8] * matrix.cell[13] - matrix.cell[9] * matrix.cell[12];
			T b1 = matrix.cell[8] * matrix.cell[14] - matrix.cell[10] * matrix.cell[12];
			T b2 = matrix.cell[8] * matrix.cell[15] - matrix.cell[11] * matrix.cell[12];
			T b3 = matrix.cell[9] * matrix.cell[14] - matrix.cell[10] * matrix.cell[13];
			T b4 = matrix.cell[9] * matrix.cell[15] - matrix.cell[11] * matrix.cell[13];
			T b5 = matrix.cell[10] * matrix.cell[15] - matrix.cell[11] * matrix.cell[14];

			T det = a0 * b5 - a1 * b4 + a2 * b3 + a3 * b2 - a4 * b1 + a5 * b0;
			RMatrix4 inverse = { 0 };
			if (Mathema<T>::Abs(det) > T(0)) {
				inverse.cell[0] = + matrix.cell[5] * b5 - matrix.cell[6] * b4 + matrix.cell[7] * b3;
				inverse.cell[4] = - matrix.cell[4] * b5 + matrix.cell[6] * b2 - matrix.cell[7] * b1;
				inverse.cell[8] = + matrix.cell[4] * b4 - matrix.cell[5] * b2 + matrix.cell[7] * b0;
				inverse.cell[12] = - matrix.cell[4] * b3 + matrix.cell[5] * b1 - matrix.cell[6] * b0;
				inverse.cell[1] = - matrix.cell[1] * b5 + matrix.cell[2] * b4 - matrix.cell[3] * b3;
				inverse.cell[5] = + matrix.cell[0] * b5 - matrix.cell[2] * b2 + matrix.cell[3] * b1;
				inverse.cell[9] = - matrix.cell[0] * b4 + matrix.cell[1] * b2 - matrix.cell[3] * b0;
				inverse.cell[13] = + matrix.cell[0] * b3 - matrix.cell[1] * b1 + matrix.cell[2] * b0;
				inverse.cell[2] = + matrix.cell[13] * a5 - matrix.cell[14] * a4 + matrix.cell[15] * a3;
				inverse.cell[6] = - matrix.cell[12] * a5 + matrix.cell[14] * a2 - matrix.cell[15] * a1;
				inverse.cell[10] = + matrix.cell[12] * a4 - matrix.cell[13] * a2 + matrix.cell[15] * a0;
				inverse.cell[14] = - matrix.cell[12] * a3 + matrix.cell[13] * a1 - matrix.cell[14] * a0;
				inverse.cell[3] = - matrix.cell[9] * a5 + matrix.cell[10] * a4 - matrix.cell[11] * a3;
				inverse.cell[7] = + matrix.cell[8] * a5 - matrix.cell[10] * a2 + matrix.cell[11] * a1;
				inverse.cell[11] = - matrix.cell[8] * a4 + matrix.cell[9] * a2 - matrix.cell[11] * a0;
				inverse.cell[15] = + matrix.cell[8] * a3 - matrix.cell[9] * a1 + matrix.cell[10] * a0;

				T invDet = (T(1)) / det;
				for ( int i = 0; i < 16; ++i )
					inverse.cell[i]  *= invDet;
				
			}

			return inverse;
		}

		static bool Invert (const RMatrix4& matrix, RMatrix4& value) {
			T a0 = matrix.cell[0] * matrix.cell[5] - matrix.cell[1] * matrix.cell[4];
			T a1 = matrix.cell[0] * matrix.cell[6] - matrix.cell[2] * matrix.cell[4];
			T a2 = matrix.cell[0] * matrix.cell[7] - matrix.cell[3] * matrix.cell[4];
			T a3 = matrix.cell[1] * matrix.cell[6] - matrix.cell[2] * matrix.cell[5];
			T a4 = matrix.cell[1] * matrix.cell[7] - matrix.cell[3] * matrix.cell[5];
			T a5 = matrix.cell[2] * matrix.cell[7] - matrix.cell[3] * matrix.cell[6];
			T b0 = matrix.cell[8] * matrix.cell[13] - matrix.cell[9] * matrix.cell[12];
			T b1 = matrix.cell[8] * matrix.cell[14] - matrix.cell[10] * matrix.cell[12];
			T b2 = matrix.cell[8] * matrix.cell[15] - matrix.cell[11] * matrix.cell[12];
			T b3 = matrix.cell[9] * matrix.cell[14] - matrix.cell[10] * matrix.cell[13];
			T b4 = matrix.cell[9] * matrix.cell[15] - matrix.cell[11] * matrix.cell[13];
			T b5 = matrix.cell[10] * matrix.cell[15] - matrix.cell[11] * matrix.cell[14];

			T det = a0 * b5 - a1 * b4 + a2 * b3 + a3 * b2 - a4 * b1 + a5 * b0;
			if ( Mathema<T>::Abs(det) > T(0) ) {
				value.cell[0] = + matrix.cell[5] * b5 - matrix.cell[6] * b4 + matrix.cell[7] * b3;
				value.cell[4] = - matrix.cell[4] * b5 + matrix.cell[6] * b2 - matrix.cell[7] * b1;
				value.cell[8] = + matrix.cell[4] * b4 - matrix.cell[5] * b2 + matrix.cell[7] * b0;
				value.cell[12] = - matrix.cell[4] * b3 + matrix.cell[5] * b1 - matrix.cell[6] * b0;
				value.cell[1] = - matrix.cell[1] * b5 + matrix.cell[2] * b4 - matrix.cell[3] * b3;
				value.cell[5] = + matrix.cell[0] * b5 - matrix.cell[2] * b2 + matrix.cell[3] * b1;
				value.cell[9] = - matrix.cell[0] * b4 + matrix.cell[1] * b2 - matrix.cell[3] * b0;
				value.cell[13] = + matrix.cell[0] * b3 - matrix.cell[1] * b1 + matrix.cell[2] * b0;
				value.cell[2] = + matrix.cell[13] * a5 - matrix.cell[14] * a4 + matrix.cell[15] * a3;
				value.cell[6] = - matrix.cell[12] * a5 + matrix.cell[14] * a2 - matrix.cell[15] * a1;
				value.cell[10] = + matrix.cell[12] * a4 - matrix.cell[13] * a2 + matrix.cell[15] * a0;
				value.cell[14] = - matrix.cell[12] * a3 + matrix.cell[13] * a1 - matrix.cell[14] * a0;
				value.cell[3] = - matrix.cell[9] * a5 + matrix.cell[10] * a4 - matrix.cell[11] * a3;
				value.cell[7] = + matrix.cell[8] * a5 - matrix.cell[10] * a2 + matrix.cell[11] * a1;
				value.cell[11] = - matrix.cell[8] * a4 + matrix.cell[9] * a2 - matrix.cell[11] * a0;
				value.cell[15] = + matrix.cell[8] * a3 - matrix.cell[9] * a1 + matrix.cell[10] * a0;

				T invDet = (T(1)) / det;
				for (int i = 0; i < 16; ++i)
					value.cell[i]  *= invDet;
				
				return true;
			}

			return false;
		}

		static RMatrix4 CreateTranslation (T dx, T dy, T dz) {
			RMatrix4 r;
			CreateTranslation( dx, dy, dz, r );
			return r;
		}

		static void CreateTranslation ( T dx, T dy, T dz, RMatrix4& result ) {
			result = CreateRowMajor( 
				T(1), T(0), T(0), T(0),
				T(0), T(1), T(0), T(0),
				T(0), T(0), T(1), T(0),
				dx, dy, dz, T(1) );
		}

		static RMatrix4 CreateTranslation (const RVector3<T>& translation) {
			return CreateTranslation( translation[0], translation[1], translation[2] );
		}

		static void CreateTranslation ( const RVector3<T>& translation, RMatrix4& result ) {
			return CreateTranslation( translation[0], translation[1], translation[2], result );
		}

		static RMatrix4 CreateRotationX (T radians) {
			T cosa = Mathema<T>::Cos(radians);
			T sina = Mathema<T>::Sin(radians);
			RMatrix4 r = CreateRowMajor(
				T(1), T(0), T(0), T(0),
				T(0), cosa, -sina, T(0),
				T(0), sina, cosa, T(0),
				T(0), T(0), T(0), T(1) );
			return r;
		}

		static RMatrix4 CreateRotationY (T radians) {
			T cosa = Mathema<T>::Cos(radians);
			T sina = Mathema<T>::Sin(radians);
			RMatrix4 r = CreateRowMajor( 
				cosa, T(0), sina, T(0),
				T(0), T(1), T(0), T(0),
				-sina, T(0), cosa, T(0),
				T(0), T(0), T(0), T(1) );
			return r;
		}

		static RMatrix4 CreateRotationZ( T radians ) {
			RMatrix4 r;
			CreateRotationZ( radians, r );
			return r;
		}

		static void CreateRotationZ( T radians, RMatrix4& r ) {
			T cosa = Mathema<T>::Cos(radians);
			T sina = Mathema<T>::Sin(radians);
			r = CreateRowMajor(
				cosa, -sina, T(0), T(0),
				sina, cosa, T(0), T(0),
				T(0), T(0), T(1), T(0),
				T(0), T(0), T(0), T(1) );
		}

		static RMatrix4 CreateRotation (T xradians, T yradians, T zradians) {
			RMatrix4 r;
			CreateRotation( xradians, yradians, xradians, r );
			return r;
		}

		static void CreateRotation ( T xradians, T yradians, T zradians, RMatrix4& result ) {
			T xcos = Mathema<T>::Cos(xradians);
			T xsin = Mathema<T>::Sin(xradians);
			T zcos = Mathema<T>::Cos(zradians);
			T zsin = Mathema<T>::Sin(zradians);
			T ycos = Mathema<T>::Cos(yradians);
			T ysin = Mathema<T>::Sin(yradians);
			
			result = CreateRowMajor(
				ycos * zcos, -xcos * zsin + xsin * ysin * zcos, xsin * zsin + xcos * ysin * zcos, T(0),
				ycos * zsin, xcos * zcos + xsin * ysin * zsin, -xsin * zcos + xcos * ysin * zsin, T(0),
				ysin, xsin * ycos, xcos * ycos, T(0),
				T(0), T(0), T(0), T(1) );
		}

		static RMatrix4 CreateFromYawPitchRoll (const RVector3<T>& yawpitchroll) {
			return CreateRotation(yawpitchroll[1], yawpitchroll[0], yawpitchroll[2]);
		}

		static RMatrix4 CreateFromYawPitchRoll ( T yaw, T pitch, T roll ) {
			return CreateRotation( pitch, yaw, roll );
		}

		static void CreateFromYawPitchRoll ( T yaw, T pitch, T roll, RMatrix4& result ) {
			CreateRotation( pitch, yaw, roll, result );
		}

		static RMatrix4 CreateRotation (const RVector3<T>& yawpitchroll) {
			return CreateRotation(yawpitchroll[0], yawpitchroll[1], yawpitchroll[2]);
		}

		static RMatrix4 CreateRotationAxis (RVector3<T> axis, T radians) {
			axis.Normalize();
			T cosa = Mathema<T>::Cos(radians);
			T sina = Mathema<T>::Sin(radians);
			T affcosa = T(1) - cosa;
			RMatrix4 r = CreateRowMajor(
				(axis[0] * axis[0]) * affcosa + cosa, (axis[0] * axis[1]) * affcosa - (axis[2] * sina), (axis[0] * axis[2]) * affcosa + (axis[1] * sina), T(0),
				(axis[1] * axis[0]) * affcosa + (axis[2] * sina), (axis[1] * axis[1]) * affcosa + cosa, (axis[1] * axis[2]) * affcosa - (axis[0] * sina), T(0),
				(axis[2] * axis[0]) * affcosa - (axis[1] * sina), (axis[2] * axis[1]) * affcosa + (axis[0] * sina), (axis[2] * axis[2]) * affcosa + cosa, T(0),
				T(0), T(0), T(0), T(1) );
			return r;
		}

		static RMatrix4 CreateRotationQuaternion ( T x, T y, T z, T w ) {
			RQuaternion<T> q = { x, y, z, w };
			return CreateRotationQuaternion( q );
		}

		static RMatrix4 CreateRotationQuaternion (const RQuaternion<T>& quaternion) {
			T w2 = T( quaternion[3] * quaternion[3] );
			T x2 = T( quaternion[0] * quaternion[0] );
			T y2 = T( quaternion[1] * quaternion[1] );
			T z2 = T( quaternion[2] * quaternion[2] );
			T dx = T( 2 * quaternion[0] );
			T dy = T( 2 * quaternion[1] );
			T dw = T( 2 * quaternion[3] );
			RMatrix4 r = CreateRowMajor(
				w2 + x2 - y2 - z2, dx * quaternion[1] - dw * quaternion[2], dx * quaternion[2] + dw * quaternion[1], T(0),
				dx * quaternion[1] + dw * quaternion[2], w2 - x2 + y2 - z2, dy * quaternion[2] + dw * quaternion[0], T(0),
				dx * quaternion[2] - dw * quaternion[1], dy * quaternion[2] - dw * quaternion[0], w2 - x2 - y2 + z2, T(0),
				T(0), T(0), T(0), T(1) );
			return r;
		}

		static RMatrix4 CreateScale (T sx, T sy, T sz) {
			RMatrix4 r;
			CreateScale( sx, sy, sz, r );
			return r;
		}

		static void CreateScale ( T sx, T sy, T sz, RMatrix4& result ) {
			result = CreateRowMajor(
				sx, T(0), T(0), T(0),
				T(0), sy, T(0), T(0),
				T(0), T(0), sz, T(0),
				T(0), T(0), T(0), T(1) );
		}

		static RMatrix4 CreateScale (T s) {
			return CreateScale(s, s, s);
		}

		static RMatrix4 CreateScale (const RVector3<T>& s) {
			return CreateScale(s[0], s[1], s[2]);
		}

		static RMatrix4 CreateScale (T sx, T sy, T sz, const RVector3<T>& origin) {
			RMatrix4 r;
			CreateScale( sx, sy, sz, origin, r );
			return r;
		}

		static void CreateScale (T sx, T sy, T sz, const RVector3<T>& origin, RMatrix4& result ) {
			result = CreateRowMajor( 
				sx, T(0), T(0), origin[0] * (T(1) - sx),
				T(0), sy, T(0), origin[1] * (T(1) - sy),
				T(0), T(0), sz, origin[2] * (T(1) - sz),
				T(0), T(0), T(0), T(1) );
		}

		static RMatrix4 CreateScale (T s, const RVector3<T>& origin) {
			return CreateScale(s, s, s, origin);
		}

		static RMatrix4 CreateScale (const RVector3<T>& s, const RVector3<T>& origin) {
			return CreateScale(s[0], s[1], s[2], origin);
		}

		static RMatrix4 CreateReflectionX () {
			RMatrix4 r = CreateRowMajor( 
				-T(1), T(0), T(0), T(0),
				T(0), T(1), T(0), T(0),
				T(0), T(0), T(1), T(0),
				T(0), T(0), T(0), T(1) );
			return r;
		}

		static RMatrix4 CreateReflectionY () {
			RMatrix4 r = CreateRowMajor( 
				T(1), T(0), T(0), T(0),
				T(0), -T(1), T(0), T(0),
				T(0), T(0), T(1), T(0),
				T(0), T(0), T(0), T(1) );
			return r;
		}

		static RMatrix4 CreateReflectionZ () {
			RMatrix4 r = CreateRowMajor( 
				T(1), T(0), T(0), T(0),
				T(0), T(1), T(0), T(0),
				T(0), T(0), -T(1), T(0),
				T(0), T(0), T(0), T(1) );
			return r;
		}

		static RMatrix4 CreateReflection (const RVector3<T>& normal, const RVector3<T>& origin) {
			T doubledotnormorigin = ((T)2) * (normal.dot(origin));
			RMatrix4 r = CreateColumnMajor( 
				T(1) - ((T)2) * normal[0] * normal[0],
				-((T)2) * normal[0] * normal[1],
				-((T)2) * normal[0] * normal[2],
				doubledotnormorigin * normal[0],
				-((T)2) * normal[1] * normal[0],
				T(1) - ((T)2) * normal[1] * normal[1],
				-((T)2) * normal[1] * normal[2],
				doubledotnormorigin * normal[1],
				-((T)2) * normal[2] * normal[0],
				-((T)2) * normal[2] * normal[1],
				T(1) - ((T)2) * normal[2] * normal[2],
				doubledotnormorigin * normal[2],
				T(0),
				T(0),
				T(0),
				T(1)
			);
			return r;
		}

		static RMatrix4 CreateObliqueProjection (const RVector3<T>& normal, const RVector3<T>& origin, const RVector3<T>& direction) {
			T normaldotdir = normal.dot(direction);
			T normaldotorigin = normal.dot(origin);

			RMatrix4 r = CreateColumnMajor(
				direction[0] * normal[0] - normaldotdir,
				direction[0] * normal[1],
#ifdef FURROVINECOORDINATESYSTEMLEFTHANDED
				direction[0] * normal[2],
#else
				-direction[0] * normal[2],
#endif
				-normaldotorigin * direction[0],

				direction[1] * normal[0],
				direction[1] * normal[1] - normaldotdir,
#ifdef FURROVINECOORDINATESYSTEMLEFTHANDED
				direction[1] * normal[2],
#else
				-direction[1] * normal[2],
#endif
				-normaldotorigin * direction[1],
				
				direction[2] * normal[0],
				direction[2] * normal[1],
#ifdef FURROVINECOORDINATESYSTEMLEFTHANDED
				normaldotdir - ( direction[2] * normal[2]),
#else
				direction[2] * normal[2] - normaldotdir,
#endif
				-normaldotorigin * direction[2],
				
				T(0),
				T(0),
				T(0),
				-normaldotdir
			);

			return r;
		}

		static RMatrix4 CreateOrthographicProjection ( T width,  T height ) {
			return CreateOrthographicProjection( width, height, (T)-1, (T)1 );
		}

		static RMatrix4 CreateOrthographicProjection ( T width, T height, T nearplane, T farplane ) {
			T farrange = 
#ifdef FURROVINECOORDINATESYSTEMLEFTHANDED
			T(normalizedevicecoordinatesrange) / ( farplane - nearplane );
#else
			T(normalizedevicecoordinatesrange) / ( nearplane - farplane );
#endif
			RMatrix4 r = CreateRowMajor( 
				T(2.0) / width, 
				T(0), 
				T(0), 
				T(0),

				T(0), 
				T(2.0) / height, 
				T(0), 
				T(0),

				T(0), 
				T(0),
				farrange,
				T(0),

				T(0), 
				T(0), 
				farrange * nearplane,
				T(1)
			);
			return r;
		}

		static void CreateOrthographicProjectionOffCenter ( T left, T right, T bottom, T top, T nearplane, T farplane, RMatrix4& r ) {
			r = CreateOrthographicProjectionOffCenter( left, right, bottom, top, nearplane, farplane );
		}

		static RMatrix4 CreateOrthographicProjectionOffCenter ( T right,  T bottom ) {
			return CreateOrthographicProjectionOffCenter(0, right, bottom, 0, (T)-1, (T)1 );
		}

		static RMatrix4 CreateOrthographicProjectionOffCenter ( T left, T right,  T bottom,  T top ) {
			return CreateOrthographicProjectionOffCenter(left, right, bottom, top, (T)-1, (T)1 );
		}

		static RMatrix4 CreateOrthographicProjectionOffCenter ( T left, T right,  T bottom,  T top, T nearplane, T farplane ) {
			T inversewidth = T(1) / ( right - left );
			T inverseheight = T(1) / ( top - bottom );
			T farrange = 
#ifdef FURROVINECOORDINATESYSTEMLEFTHANDED
				T(normalizedevicecoordinatesrange) / ( farplane - nearplane );
#else
				T(normalizedevicecoordinatesrange) / ( nearplane - farplane );
#endif // FURROVINECOORDINATESYSTEMLEFTHANDED || RIGHTHANDED 
			RMatrix4 r = CreateRowMajor( 
				inversewidth + inversewidth, 
				T(0), 
				T(0), 
				T(0),

				T(0), 
				inverseheight + inverseheight, 
				T(0), 
				T(0),

				T(0), 
				T(0),
				farrange,
				T(0),

				-(left + right) * inversewidth, 
				-(top + bottom) * inverseheight,
#ifdef FURROVINECOORDINATESYSTEMLEFTHANDED
				-farrange * nearplane,
#else
				farrange * nearplane,
#endif // FURROVINECOORDINATESYSTEMLEFTHANDED || RIGHTHANDED 
				T(1)
			);
			return r;
		}

		static RMatrix4 CreatePerspectiveProjection ( T width, T height, T nearplane, T farplane ) {
			T doublenear = nearplane + nearplane;
			T farrange = ( T(normalizedevicecoordinatesrange) * farplane ) / 
#ifdef FURROVINECOORDINATESYSTEMLEFTHANDED
				(farplane - nearplane);
#else
				(nearplane - farplane);
#endif // FURROVINECOORDINATESYSTEMLEFTHANDED || RIGHTHANDED 

			RMatrix4 r = CreateRowMajor( 
				doublenear / width, 
				T(0), 
				T(0), 
				T(0),

				T(0), 
				doublenear / height, 
				T(0), 
				T(0),

				T(0), 
				T(0), 
				doublenear * farrange,
				T(1),

				T(0), 
				T(0), 
				T(-farrange * nearplane), 
				T(0)
			);
			return r;
		}

		static RMatrix4 CreatePerspectiveProjectionOffCenter ( T left, T right, T bottom, T top ) {
			return CreatePerspectiveProjectionOffCenter( left, right, bottom, top, -1, 1 );	
		}

		static RMatrix4 CreatePerspectiveProjectionOffCenter ( T left, T right, T bottom, T top, T nearplane, T farplane ) {
			T doublenear = nearplane + nearplane;
			T inversewidth = T(1) / (right - left);
			T inverseheight = T(1) / (top - bottom);
			T invfocalrange = T(1) / 
#ifdef FURROVINECOORDINATESYSTEMLEFTHANDED
				(farplane - nearplane);
#else
				(nearplane - farplane);
#endif // FURROVINECOORDINATESYSTEMLEFTHANDED || RIGHTHANDED 
			T farrange = 
			( T(normalizedevicecoordinatesrange) * farplane ) * invfocalrange;
			
			RMatrix4 r = CreateRowMajor( 
				doublenear * inversewidth, 
				T(0), 
				T(0), 
				T(0),

				T(0), 
				doublenear * inverseheight, 
				T(0),
				T(0),

				(right + left) * inversewidth, 
				(top + bottom) * inverseheight, 
				farrange,
				T(-1),

				T(0), 
				T(0), 
				farrange * nearplane, 
				T(0)
			);

			return r;
		}

		static RMatrix4 CreatePerspectiveFoV ( T fovy, T width, T height, T nearplane, T farplane) {
			return CreatePerspectiveFoV( fovy, width / height, nearplane, farplane );
		}

		static void CreatePerspectiveFoV ( T fovy, T width, T height, T nearplane, T farplane, RMatrix4& result ) {
			return CreatePerspectiveFoV( fovy, width / height, nearplane, farplane, result );
		}

		static RMatrix4 CreatePerspectiveFoV ( T fovy, T aspect, T nearplane, T farplane ) {
			RMatrix4 r;
			CreatePerspectiveFoV( fovy, aspect, nearplane, farplane, r );
			return r;
		}

		static void CreatePerspectiveFoV ( T fovy, T aspect, T nearplane, T farplane, RMatrix4& result ) {
			T halffovy = T(0.5) * fovy;
			T fovysin = Mathema<T>::Sin(halffovy);
			T fovycos = Mathema<T>::Cos(halffovy);
			T h = fovycos / fovysin;
			T w = h / aspect;
			T farrange =
#ifdef FURROVINECOORDINATESYSTEMLEFTHANDED
				farplane / (farplane - nearplane);
#else
				farplane / (nearplane - farplane);
#endif // FURROVINECOORDINATESYSTEMLEFTHANDED || RIGHTHANDED 

			result = CreateRowMajor( 
				w, T(0), T(0), T(0),

				T(0), h, T(0), T(0),

				T(0), T(0), farrange, 
#ifdef FURROVINECOORDINATESYSTEMLEFTHANDED
				T(1),
#else
				T(-1),
#endif // FURROVINECOORDINATESYSTEMLEFTHANDED || RIGHTHANDED 

				T(0), T(0),
#ifdef FURROVINECOORDINATESYSTEMLEFTHANDED
				farrange * -nearplane,
#else
				farrange * nearplane,
#endif // FURROVINECOORDINATESYSTEMLEFTHANDED || RIGHTHANDED 
				T(0)
			);
		}

		static RMatrix4 CreateLookTo ( const RVector3<T>& eye, const RVector3<T>& direction, const RVector3<T>& up) {
			RMatrix4 r;
			CreateLookTo(eye, direction, up, r);
			return r;
		}

		static void CreateLookTo ( const RVector3<T>& eye, const RVector3<T>& direction, const RVector3<T>& up, RMatrix4& result ) {
#ifdef FURROVINECOORDINATESYSTEMLEFTHANDED
			CreateLookToAgnostic( eye, -direction, up, result );
#else
			CreateLookToAgnostic( eye, direction, up, result );
#endif // FURROVINECOORDINATESYSTEMLEFTHANDED || RIGHTHANDED 
		}

		static RMatrix4 CreateLookToAgnostic ( const RVector3<T>& eye, const RVector3<T>& direction, const RVector3<T>& up) {
			RMatrix4 r;
			CreateLookToAgnostic ( eye, direction, up, r );
			return r;
		}

		static void CreateLookToAgnostic ( const RVector3<T>& eye, const RVector3<T>& direction, const RVector3<T>& up, RMatrix4& result ) {
			RVector3<T> f = normalize(direction);			
			RVector3<T> u = normalize(up);
			RVector3<T> s = normalize(u.cross(f));
			u = f.cross( s );
			RVector3<T> negeye = TVector3<T>::Zero - eye;
			RVector3<T> dots;
			dots[ 0 ] = s.dot( negeye );
			dots[ 1 ] = u.dot( negeye );
			dots[ 2 ] = f.dot( negeye );
			
			result = CreateRowMajor(
				s[0], u[0], f[0], T(0),
				s[1], u[1], f[1], T(0),
				s[2], u[2], f[2], T(0),
				dots[0], dots[1], dots[2], T(1)
				);
		}

		static void CreateLookAt ( const RVector3<T>& eye, const RVector3<T>& target, const RVector3<T>& up, RMatrix4& result ) {
			RVector3<T> direction = eye - target;
			CreateLookTo( eye, direction, up, result );
		}

		static RMatrix4 CreateLookAt ( const RVector3<T>& eye, const RVector3<T>& target, const RVector3<T>& up) {
			RMatrix4 r;
			CreateLookAt( eye, target, up, r );
			return r;
		}

		static RMatrix4 CreateShearX (T dyradians, T dzradians) {
			dyradians = Mathema<T>::Tan(dyradians);
			dzradians = Mathema<T>::Tan(dzradians);
			RMatrix4 r = CreateColumnMajor( 
				T(1), dyradians, dzradians, T(0),
				T(0), T(1), T(0), T(0),
				T(0), T(0), T(1), T(0),
				T(0), T(0), T(0), T(1) );
			return r;
		}

		static RMatrix4 CreateShearX (T radians) {
			radians = Mathema<T>::Tan(radians);
			RMatrix4 r = CreateColumnMajor(
				T(1), radians, radians, T(0),
				T(0), T(1), T(0), T(0),
				T(0), T(0), T(1), T(0),
				T(0), T(0), T(0), T(1) );
			return r;
		}

		static RMatrix4 CreateShearY (T radians) {
			radians = Mathema<T>::Tan(radians);
			RMatrix4 r = CreateColumnMajor(
				T(1), T(0), T(0), T(0),
				radians, T(1), radians, T(0),
				T(0), T(0), T(1), T(0),
				T(0), T(0), T(0), T(1) );
			return r;
		}

		static RMatrix4 CreateShearY (T dxradians, T dzradians) {
			dxradians = Mathema<T>::Tan(dxradians);
			dzradians = Mathema<T>::Tan(dzradians);
			RMatrix4 r = CreateColumnMajor(
				T(1), T(0), T(0), T(0),
				dxradians, T(1), dzradians, T(0),
				T(0), T(0), T(1), T(0),
				T(0), T(0), T(0), T(1) );
			return r;
		}

		static RMatrix4 CreateShearZ (T radians) {
			radians = Mathema<T>::Tan(radians);
			RMatrix4 r = CreateColumnMajor(
				T(1), T(0), T(0), T(0),
				T(0), T(1), T(0), T(0),
				radians, radians, T(1), T(0),
				T(0), T(0), T(0), T(1) );
			return r;
		}

		static RMatrix4 CreateShearZ (T dxradians, T dyradians) {
			dxradians = Mathema<T>::Tan(dxradians);
			dyradians = Mathema<T>::Tan(dyradians);
			RMatrix4 r = CreateColumnMajor(
				T(1), T(0), T(0), T(0),
				T(0), T(1), T(0), T(0),
				dxradians, dyradians, T(1), T(0),
				T(0), T(0), T(0), T(1) );
			return r;
		}

		static RMatrix4 CreateShear (T xradians = T(0), T yradians = T(0), T zradians = T(0)) {
			xradians = Mathema<T>::Tan(xradians);
			yradians = Mathema<T>::Tan(yradians);
			zradians = Mathema<T>::Tan(zradians);
			RMatrix4 r = CreateColumnMajor(
				T(1), xradians, xradians, T(0),
				yradians, T(1), yradians, T(0),
				zradians, zradians, T(1), T(0),
				T(0), T(0), T(0), T(1) );
			return r;
		}

		static RMatrix4 CreateShear (const RVector3<T>& radians) {
			return CreateShear(radians[0], radians[1], radians[2]);
		}

	};

	template <typename T>
	RVector3<T> operator* ( const RVector3<T>& left, const RMatrix4<T>& right ) {
#ifdef FURROVINEMATRIXROWMAJOR
		return right.Transform( left );
#else
		RMatrix4<T> rhs = right;
		rhs.Transpose();
		return rhs.Transform( left );
#endif
	}

	template <typename T>
	RVector4<T> operator* ( const RVector4<T>& left, const RMatrix4<T>& right ) {
#ifdef FURROVINEMATRIXROWMAJOR
		return right.Transform( left );
#else
		RMatrix4<T> rhs = right;
		rhs.Transpose();
		return rhs.Transform( left );
#endif
	}

	template <typename T>
	RVector3<T> operator* ( const RMatrix4<T>& left, const RVector3<T>& right ) {
#ifdef FURROVINEMATRIXROWMAJOR
		RMatrix4<T> rhs = right;
		rhs.Transpose();
		return rhs.Transform( left );
#else
		return right.Transform( left );
#endif
	}

	template <typename T>
	RVector4<T> operator* ( const RMatrix4<T>& left, const RVector4<T>& right ) {
#ifdef FURROVINEMATRIXROWMAJOR
		RMatrix4<T> rhs = right;
		rhs.Transpose();
		return rhs.Transform( left );
#else
		return right.Transform( left );
#endif
	}

	template <typename T>
	void Shaderize ( RMatrix4<T>& matrix ) {
#ifdef FURROVINEMATRIXROWMAJOR
#ifdef FURROVINESHADERMATRIXROWMAJOR

#else
		matrix.Transpose( );
#endif

#else
#ifdef FURROVINESHADERMATRIXCOLUMNMAJOR

#else
		matrix.Transpose( );
#endif
#endif
	}

	template <typename T>
	void UnShaderize ( RMatrix4<T>& matrix ) {
#ifdef FURROVINEMATRIXROWMAJOR
#ifdef FURROVINESHADERMATRIXROWMAJOR
#else
		matrix.Transpose( );
#endif

#else
#ifdef FURROVINESHADERMATRIXCOLUMNMAJOR

#else
		matrix.Transpose( );
#endif
#endif
	}

	template <typename T>
	RMatrix4<T> ToShader ( const RMatrix4<T>& matrix ) {
		RMatrix4<T> s = matrix;
		Shaderize( s );
		return s;
	}

	template <typename T>
	RMatrix4<T> FromShader ( const RMatrix4<T>& matrix ) {
		RMatrix4<T> s = matrix;
		UnShaderize( s );
		return s;
	}

	template <typename T>
	void Shaderize ( RMatrix4<T>& matrix, MemoryLayout layout ) {
		switch (RMatrix4<T>::Layout) {
		case MemoryLayout::ColumnMajor:
			switch ( layout ) {
			case MemoryLayout::RowMajor:
				matrix.Transpose( );
				break;
			default:
			case MemoryLayout::ColumnMajor:
				break;
			}
			break;
		case MemoryLayout::RowMajor:
			switch ( layout ) {
			case MemoryLayout::ColumnMajor:
				matrix.Transpose( );
				break;
			default:
			case MemoryLayout::RowMajor:
				break;
			}
			break;
		}
	}

	template <typename T>
	void UnShaderize ( RMatrix4<T>& matrix, MemoryLayout layout ) {
		switch (layout) {
		case MemoryLayout::ColumnMajor:
			switch ( RMatrix4<T>::Layout ) {
			case MemoryLayout::RowMajor:
				matrix.Transpose( );
				break;
			case MemoryLayout::ColumnMajor:
			default:
				break;
			}
			break;
		case MemoryLayout::RowMajor:
			switch ( RMatrix4<T>::Layout ) {
			case MemoryLayout::ColumnMajor:
				matrix.Transpose( );
				break;
			case MemoryLayout::RowMajor:
			default:
				break;
			}
			break;
		}
	}

	template <typename T>
	RMatrix4<T> ToShader ( const RMatrix4<T>& matrix, MemoryLayout layout ) {
		RMatrix4<T> s = matrix;
		Shaderize( s, layout );
		return s;
	}

	template <typename T>
	RMatrix4<T> FromShader ( const RMatrix4<T>& matrix, MemoryLayout layout ) {
		RMatrix4<T> s = matrix;
		UnShaderize( s, layout );
		return s;
	}

	template <typename T> 
	const RMatrix4<T> RMatrix4<T>::Identity = {
		T(1), T(0), T(0), T(0), 
		T(0), T(1), T(0), T(0), 
		T(0), T(0), T(1), T(0), 
		T(0), T(0), T(0), T(1)
	};

	template <typename T> 
	const RMatrix4<T> RMatrix4<T>::Zero = {
		T(0), T(0), T(0), T(0), 
		T(0), T(0), T(0), T(0), 
		T(0), T(0), T(0), T(0), 
		T(0), T(0), T(0), T(0)
	};

}
