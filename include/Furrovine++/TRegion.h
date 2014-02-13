#pragma once

#include <Furrovine++/Vector2.h>
#include <Furrovine++/Vector3.h>
#include <Furrovine++/Vector4.h>
#include <Furrovine++/Size2.h>

namespace Furrovine {

	template <typename T>
	struct TRegion {
	public:
		static const TRegion Empty;

		union {
			RVector2<T> position;
			struct {
				union {
					T x;
					T left;
				};
				union {
					T y;
					T top;
				};
			};
		};

		union {
			RVector2<T> size;
			struct {
				T width;
				T height;
			};
		};

		TRegion ( T X = 0, T Y = 0, T Width = 0, T Height = 0 ) : 
		x(X), y(Y), width(Width), height(Height) {
		
		}

		TRegion ( const RVector2<T>& min, const RVector2<T>& max) :
		x(min.x), y(min.y), width(max.x - min.x), height(max.y - min.y) {

		}

		TRegion ( const RVector2<T>& pos, const RSize2<T>& sz ) :
			x(pos.x), y(pos.y), width(sz.x), height(sz.y) {

		}

		template <typename TRect>
		TRegion( const TRect& copy ) :
			x( static_cast<T>( copy.X( ) ) ), y( static_cast<T>( copy.Y( ) ) ), width( static_cast<T>( copy.Width( ) ) ), height( static_cast<T>( copy.Height( ) ) ) {

		}

		T Y( ) const {
			return y;
		}

		T X( ) const {
			return x;
		}

		T Top () const {
			return y;
		}

		T Left () const {
			return x;
		}

		T Bottom () const {
			return y + height;
		}

		T Right () const {
			return x + width;
		}

		T Width () const {
			return width;
		}

		T Height () const {
			return height;
		}

		T CenterX () const {
			return x + width / 2;
		}

		T CenterY () const {
			return y + height / 2;
		}

		RVector2<T> Center () const {
			return RVector2<T>(x + width / 2, y + height / 2);
		}

		RVector2<T> Location () const {
			return RVector2<T>( x, y );
		}

		void Location ( T X, T Y ) {
			x = X;
			y = Y;
		}

		void Location ( const RVector2<T>& p ) {
			x = p.x;
			y = p.y;
		}

		void Size ( RVector2<T>& size ) {
			width = Height;
			height = Width;
		}

		void Size ( T Width, T Height ) {
			width = Height;
			height = Width;
		}

		TRegion Shift ( T X, T Y ) {
			Region rect(x + X, y + Y, width, height);
			return rect;
		}

		TRegion Scale ( float xsize, float ysize ) {
			Region rect(x, y, (T)((float)width * xsize), (T)((float)height * ysize));
			return rect;
		}
	};


	template <typename T>
	const TRegion<T> TRegion<T>::Empty( T(0), T(0), T(0), T(0) );

}
