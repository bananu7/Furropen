#pragma once

#include <Furrovine++/Mathema.h>
#include <Furrovine++/Hashers.h>
#include <Furrovine++/Strings.h>

namespace Furrovine {

	struct Double {
	
		furrovineapi static const double MaxValue;
		furrovineapi static const double MinValue;
		furrovineapi static const double InverseInt8Max;
		furrovineapi static const double InverseUInt8Max;
		furrovineapi static const double InverseInt16Max;
		furrovineapi static const double InverseUInt16Max;
		furrovineapi static const double InverseInt24Max;
		furrovineapi static const double InverseUInt24Max;
		furrovineapi static const double InverseInt32Max;
		furrovineapi static const double InverseUInt32Max;
		furrovineapi static const double InverseInt64Max;
		furrovineapi static const double InverseUInt64Max;

		furrovineapi static bool AlmostZero ( double value, double tolerance = DBL_EPSILON * 100 );

		furrovineapi static bool AlmostEquals ( double left, double right, double tolerance = DBL_EPSILON * 100 );

		furrovineapi static double Decimals ( double value );

		furrovineapi static double InvDecimals ( double value );

		furrovineapi static ulword HashCode ( double hashee );

		furrovineapi static bool TryParse ( const String& string, double& value );

	};

}
