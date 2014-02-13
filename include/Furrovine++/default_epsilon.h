#pragma once

#include <Furrovine++/Export.h>

namespace Furrovine {

	template <typename T> 
	struct default_epsilon;

	template <>
	struct default_epsilon<float> {
		furrovineapi static const float Epsilon;
	};

	template <>
	struct default_epsilon<double> {
		furrovineapi static const double Epsilon;
	};
}
