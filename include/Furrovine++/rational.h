#pragma once

namespace Furrovine {

	template <typename TInteger>
	struct rational {

		static const rational NaN;

		TInteger numerator;
		TInteger denominator;

		bool isNaN( ) const {
			return numerator == NaN.numerator && denominator == NaN.denominator;
		}

	};

	template <typename TInteger>
	const rational<TInteger> rational<TInteger>::NaN = { 0, 0 };
}