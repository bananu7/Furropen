#pragma once

#include <Furrovine++/Enums.h>

namespace Furrovine {

	enum class Comparison {
		Never = 1,
		Less,
		Equal,
		LessEqual,
		Greater,
		NotEqual,
		GreaterEqual,
		Always
	};

	enum class ComparisonFlags {
		None = 0,
		Never = 1 << (unsigned)Comparison::Never,
		Less = 1 << (unsigned)Comparison::Less,
		Equal = 1 << (unsigned)Comparison::Equal,
		LessEqual = 1 << (unsigned)Comparison::LessEqual,
		Greater = 1 << (unsigned)Comparison::Greater,
		NotEqual = 1 << (unsigned)Comparison::NotEqual,
		GreaterEqual = 1 << (unsigned)Comparison::GreaterEqual,
		Always = 1 << (unsigned)Comparison::Always
	};
	

	enumflagoperators( ComparisonFlags );
}
