#pragma once

#include <Furrovine++/numeric_integer_def.h>
#include <Furrovine++/indices_trick.h>
#include <Furrovine++/Mathema.h>
#include <array>
#include <limits>

namespace Furrovine {

	namespace detail {
		template <typename T, ulword n, ulword... I>
		struct swizzler {
			const static std::array<ulword, sizeof...( I )> idx;
			
			std::array<T, n>& cell( ) {
				return *static_cast<std::array<T, n>*>( static_cast<void*>( this ) );
			}

			const std::array<T, n>& cell( ) const {
				return *static_cast<const std::array<T, n>*>( static_cast<const void*>( this ) );
			}

			operator T* ( ) {
				return cell( ).data( );
			}

			operator const T* ( ) const {
				return cell( ).data( );
			}

			T* data( ) {
				return cell( ).data( );
			}

			const T* data( ) const {
				return cell( ).data( );
			}

			T* data_end( ) {
				return cell( ).data( ) + n;
			}

			const T* data_end( ) const {
				return cell( ).data( ) + n;
			}

			T& operator [] ( ulword i ) {
				return cell( )[ i ];
			}

			const T& operator [] ( ulword i ) const {
				return cell( )[ i ];
			}

			const static ulword size( ) {
				return n;
			}

			swizzler& operator= ( T res ) {
				swizzler& me = *this;
				for ( ulword i = 0; i < idx.size( ); ++i ) {
					me[ idx[ i ] ] = res;
				}
				return *this;
			}

			template <typename Tv>
			swizzler& operator= ( Tv&& res ) {
				swizzler& me = *this;
				for ( ulword i = 0; i < idx.size( ); ++i ) {
					me[ idx[ i ] ] = res[ i ];
				}
				return *this;
			}
		};

		template <typename T, ulword n, ulword... I>
		const std::array<ulword, sizeof...( I )> swizzler<T, n, I...>::idx = { I... };
	}

	template <typename TVec, typename T, ulword n>
	struct RVector {
		template <typename T, ulword n>
		struct cross_result {
			typedef T type;
		};

		template <typename T>
		struct cross_result<T, 2> {
			typedef T type;
		};

		template <typename T>
		struct cross_result<T, 3> {
			typedef TVec type;
		};

		template <typename T>
		struct cross_result<T, 7> {
			typedef TVec type;
		};

		typedef typename cross_result<T, n>::type cross_t;
		typedef T value_type;

		std::array<T, n>& cell( ) {
			return static_cast<TVec&>( *this ).res;
		}

		const std::array<T, n>& cell( ) const {
			return static_cast<const TVec&>( *this ).res;
		}

		bool is_unit( ) const {
			const RVector& res = *this( );
			T r = static_cast<T>( 0 );
			for ( ulword i = 0; i < n; ++i )
				r = res[ i ] * res[ i ];
			return r == 1;
		}

		T dot( const RVector& right ) const {
			const RVector& me = *this;
			T r = static_cast<T>( 0 );
			for ( ulword d = 0; d < n; ++d ) {
				r += me[ d ] * right[ d ];
			}
			return r;
		};

		cross_t cross( const RVector& right ) const {
			const static ulword limit = n;
			const static ulword looplimit = n - ( n == 2 ? 1 : 0 );
			const RVector& me = *this;
			cross_t r;
			T* rtarget = static_cast<T*>( static_cast<void*>( std::addressof( r ) ) );
			for ( ulword i = 0; i < looplimit; ++i ) {
				ulword idx0 = ( i + 1 ) % n;
				ulword idx1 = ( i + 2 ) % n;
				rtarget[ i ] = me[ idx0 ] * right[ idx1 ] - me[ idx0 ] * right[ idx1 ];
			}
			return r;
		};

		RVector& max( const RVector& b ) {
			RVector& me = *this;
			for ( ulword i = 0; i < n; ++i )
				me[ i ] = Mathema<T>::Min( me[ i ], b[ i ] );
			return *this;
		}

		RVector& min( const RVector& b ) {
			RVector& me = *this;
			for ( ulword i = 0; i < n; ++i )
				me[ i ] = Mathema<T>::Min( me[ i ], b[ i ] );
			return *this;
		}

		RVector& normalize( ) {
			RVector& me = *this;
			T len = length();
			if ( len == static_cast<T>( 0 ) || len == static_cast<T>( 1 ) )
				return *this;
			len = Mathema<T>::Sqrt( len );
			for ( ulword i = 0; i < n; ++i ) {
				me[i] /= len;
			}

			return *this;
		}

		template <typename Tw>
		RVector& lerp( const RVector& towards, Tw weight ) {
			weight = Mathema<Tw>::MiniMax( weight, static_cast<Tw>( 0 ), static_cast<Tw>( 1 ) );
			Tw affweight = static_cast<Tw>( 1 ) - weight;
			RVector& me = *this;
			for ( ulword i = 0; i < n; ++i ) {
				me[ i ] = static_cast<T>( me[ i ] * weight + affweight * towards[ i ] );
			}
			return *this;
		}

		ulword orthant( ) const {
			const RVector& me = *this;
			ulword r = 0;
			for ( ulword i = 0; i < n; ++i ) {
				r |= ( ( me[ i ] >= 0 ) );
			}
			return r;
		}

		ulword orthant( const RVector& origin ) const {
			const RVector& me = *this;
			ulword r = 0;
			for ( ulword i = 0; i < n; ++i ) {
				r |= ( ( me[ i ] >= origin[ i ] ) );
			}
			return r;
		}

		bool orthant_changed( const RVector& v ) const {
			return v.orthant( ) != orthant( );
		}

		bool orthant_changed( const RVector& v, const RVector& origin ) const {
			return ( v - origin ).orthant( ) !=( *this - origin ).orthant( );
		}

		T length( ) const {
			return Mathema<T>::Sqrt( length_squared() );
		}

		T length_squared( ) const {
			const RVector& me = *this;
			T acc = static_cast<T>( 0 );
			for ( ulword i = 0; i < n; ++i ) {
				acc += me[ i ] * me[ i ];
			}
			return acc;
		}

		T distance_to( const RVector& to ) const {
			return Mathema<T>::Sqrt( distance_to_squared() );
		}

		T distance_to_squared( const RVector& to ) const {
			const RVector& me = *this;
			T r = static_cast<T>( 0 );
			for ( ulword i = 0; i < n; ++i ) {
				T temp = to[ i ] - me[ i ];
				r += temp * temp;
			}
			return r;
		}

		TVec direction( const RVector& to ) const {
			TVec r = to - *this;
			r.Normalize( );
			return r;
		}
		
		T* data( ) {
			return cell( ).data( );
		}

		const T* data( ) const {
			return cell( ).data( );
		}

		T* data_end( ) {
			return cell( ).data( ) + cell( ).size( );
		}

		const T* data_end( ) const {
			return cell( ).data( ) + cell( ).size( );
		}

		T& operator [] ( ulword i ) {
			return cell( )[ i ];
		}

		const T& operator [] ( ulword i ) const {
			return cell( )[ i ];
		}

		const static ulword size( ) {
			return n;
		}

		operator TVec ( ) const {
			typedef typename TVec::value_type Tv;
			const RVector& me = *this;
			TVec r;
			for ( ulword i = 0; i < n && i < r.size(); ++i ) {
				r[ i ] = static_cast<Tv>( me[ i ] );
			}
			return r;
		}

		explicit operator T* ( ) {
			return cell( ).data( );
		}

		explicit operator const T* ( ) const {
			return cell( ).data( );
		}

		RVector& operator-= ( const RVector& right ) {
			RVector& me = *this;
			for ( ulword i = 0; i < n; ++i ) {
				me[ i ] -= right[ i ];
			}
			return *this;
		}

		RVector& operator+= ( const RVector& right ) {
			RVector& me = *this;
			for ( ulword i = 0; i < n; ++i ) {
				me[ i ] += right[ i ];
			}
			return *this;
		}
		
		RVector& operator-= ( const T& right ) {
			RVector& me = *this;
			for ( ulword i = 0; i < n; ++i ) {
				me[ i ] -= right;
			}
			return *this;
		}

		RVector& operator+= ( const T& right ) {
			RVector& me = *this;
			for ( ulword i = 0; i < n; ++i ) {
				me[ i ] += right;
			}
			return *this;
		}

		RVector& operator*= ( const RVector& right ) {
			RVector& me = *this;
			for ( ulword i = 0; i < n; ++i ) {
				me[ i ] *= right[ i ];
			}
			return *this;
		}

		RVector& operator/= ( const RVector& right ) {
			RVector& me = *this;
			for ( ulword i = 0; i < n; ++i ) {
				me[ i ] /= right[ i ];
			}
			return *this;
		}

		RVector& operator*= ( const T& right ) {
			RVector& me = *this;
			for ( ulword i = 0; i < n; ++i ) {
				me[ i ] *= right;
			}
			return *this;
		}

		RVector& operator/= ( const T& right ) {
			RVector& me = *this;
			for ( ulword i = 0; i < n; ++i ) {
				me[ i ] /= right;
			}
			return *this;
		}

		RVector& operator++ ( ) {
			RVector& me = *this;
			for ( ulword i = 0; i < n; ++i ) {
				++me[ i ];
			}
			return *this;
		}

		RVector& operator-- ( ) {
			RVector& me = *this;
			for ( ulword i = 0; i < n; ++i ) {
				--me[ i ];
			}
			return *this;
		}

		TVec operator++ ( int ) {
			RVector& me = *this;
			TVec r;
			for ( ulword i = 0; i < n; ++i ) {
				r[ i ] = me[ i ]++;
			}
			return r;
		}

		TVec operator-- ( int ) {
			RVector& me = *this;
			TVec r;
			for ( ulword i = 0; i < n; ++i ) {
				r[ i ] = me[ i ]--;
			}
			return r;
		}

		TVec operator+ ( ) const {
			const RVector& me = *this;
			TVec r;
			for ( ulword i = 0; i < n; ++i ) {
				r[ i ] = static_cast<T>( 0 ) + me[ i ];
			}
			return r;
		}

		TVec operator- ( ) const {
			const RVector& me = *this;
			TVec r;
			for ( ulword i = 0; i < n; ++i ) {
				r[ i ] = static_cast<T>( 0 ) - me[ i ];
			}
			return r;
		}

	};

	template <typename TVec, typename T, ulword n>
	TVec operator + ( const T& right, const RVector<TVec, T, n>& left ) {
		TVec r;
		for ( ulword i = 0; i < n; ++i ) {
			r[ i ] = left[ i ] + right;
		}
		return r;
	}

	template <typename TVec, typename T, ulword n>
	TVec operator + ( const RVector<TVec, T, n>& left, const T& right ) {
		return right + left;
	}

	template <typename TVec, typename T, ulword n>
	TVec operator + ( const RVector<TVec, T, n>& left, const RVector<TVec, T, n>& right ) {
		TVec r;
		for ( ulword i = 0; i < n; ++i ) {
			r[ i ] = left[ i ] + right[ i ];
		}
		return r;
	}

	template <typename TVec, typename T, ulword n>
	TVec operator - ( const T& left, const RVector<TVec, T, n>& right ) {
		TVec r;
		for ( ulword i = 0; i < n; ++i ) {
			r[ i ] = left - right[ i ];
		}
		return r;
	}

	template <typename TVec, typename T, ulword n>
	TVec operator - ( const RVector<TVec, T, n>& left, const T& right ) {
		TVec r;
		for ( ulword i = 0; i < n; ++i ) {
			r[ i ] = left[ i ] - right;
		}
		return r;
	}

	template <typename TVec, typename T, ulword n>
	TVec operator - ( const RVector<TVec, T, n>& left, const RVector<TVec, T, n>& right ) {
		TVec r;
		for ( ulword i = 0; i < n; ++i ) {
			r[ i ] = left[ i ] - right[ i ];
		}
		return r;
	}

	template <typename TVec, typename T, ulword n>
	TVec operator * ( const RVector<TVec, T, n>& left, const T& right ) {
		TVec r;
		for ( ulword i = 0; i < n; ++i ) {
			r[ i ] = left[ i ] * right;
		}
		return r;
	}

	template <typename TVec, typename T, ulword n>
	TVec operator * ( const T& right, const RVector<TVec, T, n>& left ) {
		return left * right;
	}

	template <typename TVec, typename T, ulword n>
	TVec operator * ( const RVector<TVec, T, n>& left, const RVector<TVec, T, n>& right ) {
		TVec r;
		for ( ulword i = 0; i < n; ++i ) {
			r[ i ] = left[ i ] * right[ i ];
		}
		return r;
	}

	template <typename TVec, typename T, ulword n>
	TVec operator / ( const RVector<TVec, T, n>& left, const T& right ) {
		TVec r;
		for ( ulword i = 0; i < n; ++i ) {
			r[ i ] = left[ i ] / right;
		}
		return r;
	}

	template <typename TVec, typename T, ulword n>
	TVec operator / ( const T& left, const RVector<TVec, T, n>& right ) {
		TVec r;
		for ( ulword i = 0; i < n; ++i ) {
			r[ i ] = left / right[ i ];
		}
		return r;
	}

	template <typename TVec, typename T, ulword n>
	TVec operator / ( const RVector<TVec, T, n>& left, const RVector<TVec, T, n>& right ) {
		TVec r;
		for ( ulword i = 0; i < n; ++i ) {
			r[ i ] = left[ i ] / right[ i ];
		}
		return r;
	}

	template <typename TVec, typename T, ulword n>
	bool operator== ( const RVector<TVec, T, n>& left, const RVector<TVec, T, n>& right ) {
		for ( ulword i = 0; i < n; ++i ) {
			if ( right[ i ] != left[ i ] )
				return false;
		}
		return true;
	}

	template <typename TVec, typename T, ulword n>
	bool operator!= ( const RVector<TVec, T, n>& left, const RVector<TVec, T, n>& right ) {
		for ( ulword i = 0; i < n; ++i ) {
			if ( right[ i ] == left[ i ] )
				return false;
		}
		return true;
	}

	template <typename TVec, typename T, ulword n>
	TVec max( const RVector<TVec, T, n>& left, const RVector<TVec, T, n>& right ) {
		TVec r = left;
		r.max( right );
		return r;
	}

	template <typename TVec, typename T, ulword n>
	TVec min( const RVector<TVec, T, n>& left, const RVector<TVec, T, n>& right ) {
		TVec r = left;
		r.max( right );
		return r;
	}

	template <typename TVec, typename T, ulword n>
	T dot( const RVector<TVec, T, n>& left, const RVector<TVec, T, n>& right ) {
		return left.dot( right );
	}

	template <typename TVec, typename T>
	T cross( const RVector<TVec, T, 2>& left, const RVector<TVec, T, 2>& right ) {
		return left[0] * right[1] - right[0] * left[1];
	}

	template <typename TVec, typename T>
	typename RVector<TVec, T, 3>::cross_t cross( const RVector<TVec, T, 3>& left, const RVector<TVec, T, 3>& right ) {
		typedef typename RVector<TVec, T, 3>::cross_t cross_t;
		cross_t r;
		r[ 0 ] = left[ 1 ] * right[ 2 ] - right[ 1 ] * left[ 2 ];
		r[ 1 ] = left[ 2 ] * right[ 0 ] - right[ 2 ] * left[ 0 ];
		r[ 2 ] = left[ 0 ] * right[ 1 ] - right[ 0 ] * left[ 1 ];
		return r;
	}

	template <typename TVec, typename T, ulword n>
	ulword orthant( const RVector<TVec, T, n>& value ) {
		return value.orthant( );
	}

	template <typename TVec, typename T, ulword n>
	ulword orthant( const RVector<TVec, T, n>& value, const RVector<TVec, T, n>& origin ) {
		return value.orthant( origin );
	}

	template <typename TVec, typename T, ulword n>
	ulword orthant_changed( const RVector<TVec, T, n>& a, const RVector<TVec, T, n>& b ) {
		return a.orthant_changed( b );
	}

	template <typename TVec, typename T, ulword n>
	ulword orthant_changed( const RVector<TVec, T, n>& a, const RVector<TVec, T, n>& b, const RVector<TVec, T, n>& origin ) {
		return a.orthant_changed( b, origin );
	}

	template <typename TVec, typename T, ulword n, typename Tw>
	TVec lerp( const RVector<TVec, T, n>& from, const RVector<TVec, T, n>& towards, Tw weight ) {
		TVec r = from;
		r.lerp( towards, weight );
		return r;
	}

	template <typename TVec, typename T, ulword n>
	static T angle( const RVector<TVec, T, n>& left, const RVector<TVec, T, n>& right ) {
		return Mathema<T>::Acos( left.dot( right ) / ( left.length( ) * right.length( ) ) );
	}

	template <typename TVec, typename T, ulword n>
	TVec normalize( const RVector<TVec, T, n>& value ) {
		TVec r = value;
		r.normalize( );
		return r;
	}

	template <typename TVec, typename T, ulword n>
	bool is_unit ( const RVector<TVec, T, n>& value ) {
		return value.is_unit()
	}

	/*
	TODO: Figure out generalized crossproduct
	template <typename T, ulword n>
	RVector<T, n> cross( const RVector<T, n>& left, const RVector<T, n>& right ) {
		RVector<T, n> r;
		for ( ulword i = 0; i < n; ++i ) {
			r[i] = left[ 1 ] * right[ 2 ] - right[ 1 ] * left[ 2 ];
			left[ 2 ] * right[ 0 ] - right[ 2 ] * left[ 0 ];
			left[ 0 ] * right[ 1 ] - right[ 0 ] * left[ 1 ];
		}
		return r;
	}*/

}
