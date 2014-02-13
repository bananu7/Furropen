#pragma once

#include <Furrovine++/Vector2.h>
#include <Furrovine++/Size2.h>

namespace Furrovine {

	template <typename T>
	struct TRegion;

	template <typename T>
	struct TRectangle {
	public:
		static const TRectangle Empty;

		union {
			RVector2<T> min;
			struct {
				union {
					T minx;
					T x;
					T left;
				};
				union {
					T miny;
					T y;
					T top;
				};
			};
		};

		union {
			RVector2<T> max;
			struct {
				union {
					T maxx;
					T right;
				};
				union {
					T maxy;
					T bottom;
				};
			};
		};
		
		TRectangle ( T X = 0, T Y = 0, T Width = 0, T Height = 0 ) : 
		x(X), y(Y), maxx(X + Width), maxy(Y + Height) {

		}

		TRectangle ( const RVector2<T>& min, const RVector2<T>& max ) :
		x(min.x), y(min.y), maxx(max.x), maxy(max.y) {

		}

		TRectangle ( const RVector2<T>& pos, const RSize2<T>& sz ) :
		x(pos.x), y(pos.y), maxx(pos.x + sz.x), maxy(pos.y + sz.y) {

		}

		TRectangle ( const TRectangle& copy ) :
		x(copy.x), y(copy.y), maxx(copy.maxx), maxy(copy.maxy) {

		}

		template <typename U>
		TRectangle( const TRectangle<U>& copy ) :
		x( static_cast<T>( copy.x ) ), y( static_cast<T>( copy.y ) ), maxx( static_cast<T>( copy.maxx ) ), maxy( static_cast<T>( copy.maxy) ) {

		}

		template <typename TRect>
		TRectangle ( const TRect& copy ) :
		x( static_cast<T>( copy.X( ) ) ), y( static_cast<T>( copy.Y( ) ) ), maxx( static_cast<T>( copy.Width( ) + x ) ), maxy( static_cast<T>( copy.Height() + y ) ) {

		}

		T Y( ) const {
			return min.y;
		}

		T X( ) const {
			return min.x;
		}

		T Top () const {
			return min.y;
		}

		T Left () const {
			return min.x;
		}

		T Right () const {
			return max.x;
		}

		T Bottom () const {
			return max.y;
		}

		T Width () const {
			return max.x - min.x;
		}

		T Height () const {
			return max.y - min.y;
		}

		T WidthOverHeight () const {
			return Width() / Height();
		}

		T HeightOverWidth () const {
			return Height() / Width();
		}

		T CenterX () const {
			return min.x + ( ( max.x - min.x ) / 2 );
		}

		T CenterY () const {
			return min.y + ( ( max.y - min.y ) / 2 );
		}

		RVector2<T> Center () const {
			return RVector2<T>( min + ( ( max - min ) / 2 ) );
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

		void Size ( T Width, T Height ) {
			width = Mathema<T>::Abs(Width);
			height = Mathema<T>::Abs(Height);
			if (Width < 0) {
				x = x - width;
			}
			if (Height < 0) {
				y = y - height;
			}
		}

		bool IsEmpty( ) const {
			return top == bottom && left == right;
		}

		TRectangle Shift ( T X, T Y ) {
			Rectangle rect(x + X, y + Y, width, height);
			return rect;
		}

		TRectangle Scale ( float xsize, float ysize ) {
			Rectangle rect(x, y, (T)((float)width * xsize), (T)((float)height * ysize));
			return rect;
		}

		template <typename TNumeric>
		bool Contains ( const RVector2<TNumeric>& p ) const {
			return p.x > min.x && p.y > min.y && p.x < max.x && p.y < max.y; 
		}

		template <typename TNumeric>
		bool Contains ( TNumeric X, TNumeric Y ) const {
			return X > min.x && Y > min.y && X < max.x && Y < max.y;
		}
	};

	template <typename T>
	const TRectangle<T> TRectangle<T>::Empty( T(0), T(0), T(0), T(0) );

}
