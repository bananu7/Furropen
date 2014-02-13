#ifndef FURROVINEINTERPOLATION_H
#define FURROVINEINTERPOLATION_H

#include <Furrovine++/InterpolationStyle.h>

namespace Furrovine {

	struct Interpolation {
	public:
		template <typename T>
		static double Adjust ( InterpolationStyle style, T time ) {
			T value;
			Adjust( style, time, value );
			return value;
		}

		template <typename T>
		static void Adjust ( InterpolationStyle style, T time, T& value ) {
			switch ( style ) {
			case InterpolationStyle::Linear:
				value = time;
				break;
			case InterpolationStyle::Quadratic:
				value = time * time;
				break;
			case InterpolationStyle::Cubic:
				value = time * time * time;
				break;
			case InterpolationStyle::Smooth:
				value = time * time * ( T(3) - ( T(2) * time ) );
				break;
			case InterpolationStyle::Smoother:
				value = time * time * time * ( time * ( ( time * T(6) ) - T(15) ) + T(10) );
				break;
			case InterpolationStyle::Sine:
				value = Math.Sin( time * Mathema<T>::Pi );
				break;
			case InterpolationStyle::SmoothHill:
				bool downhill = time >= T(0.5);
				if ( downhill )
					time -= T(0.5);

				time *= T(2.0);

				if ( downhill )
					time = T(1.0) - time;

				value = time * time * ( T(3) - ( T(2) * time ) );
				break;
			default:
				value = time;
				break;
			}
		}
	};

}

#endif // FURROVINEINTERPOLATION_H