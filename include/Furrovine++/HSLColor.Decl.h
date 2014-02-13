#pragma once

#include <Furrovine++/FloatColor.h>

namespace Furrovine {

	struct HSLColor {
	public:
		float hue;
		float saturation;
		float luminosity;

		furrovineapi static const float Scale;

		furrovineapi HSLColor ();

		furrovineapi float Hue ();

		furrovineapi void Hue (float value);

		furrovineapi float Saturation ();

		furrovineapi void Saturation (float value);

		furrovineapi float Luminosity ();

		furrovineapi void Luminosity (float value);

		furrovineapi void FromColor (const FloatColor& color);

		furrovineapi FloatColor ToColor ();
	};

}
 