
#include <Furrovine++/RVector4.h>
#include <Furrovine++/color_limits.h>

namespace Furrovine {

	template <typename T>
	struct RRgba : public RVector4<T> {
		
		template <typename Tc>
		RRgba& operator=( const RRgba<Tc>& value ) {
			r = color_normalize<T>( value.r );
			g = color_normalize<T>( value.g );
			b = color_normalize<T>( value.b );
			a = color_normalize<T>( value.a );
			return *this;
		}
	};

	template <typename T, typename T0>
	void color_normalize( const RRgba<T0>& value, RRgba<T>& normalized ) {
		normalized.r = color_normalize<T>( value.r );
		normalized.g = color_normalize<T>( value.g );
		normalized.b = color_normalize<T>( value.b );
		normalized.a = color_normalize<T>( value.a );
	}

	template <typename T, typename T0>
	RRgba<T> normalize( const RRgba<T0>& value ) {
		RRgba<T> normalized;
		color_normalize( value, normalized );
		return normalized;
	}

	template <typename T>
	RRgba<T> clamp( const RRgba<T>& pixel ) {
		RRgba<T> clampedpixel;
		std::transform( pixel.data( ), pixel.data_end( ),
			clampedpixel.data( ),
			op::color_clamp( ) );
		return clampedpixel;
	}

}