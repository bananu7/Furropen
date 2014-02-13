#pragma once

#include <Furrovine++/PrimitiveTypes.h>

namespace Furrovine { namespace Audio {

	struct LinearPredictiveCoding {

		furrovineapi static void DecodeResidual( int* residual, int* samples, int32 n, int32 order, int* coefficients, int32 shift );

		furrovineapi static void DecodeResidualLong( int* residual, int* samples, int32 n, int32 order, int* coefficients, int32 shift );
	};

}}
