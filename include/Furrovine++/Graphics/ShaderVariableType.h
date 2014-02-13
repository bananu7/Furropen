#pragma once

namespace Furrovine { namespace Graphics {

	enum class ShaderVariableType {
		Scalar,
		Vector,
		MatrixRows,
		MatrixColums,
		Object,
		Struct,
		InterfaceClass,
		InterfacePointer,
	};

}}