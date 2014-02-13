#pragma once

#include <Furrovine++/PrimitiveTypes.h>
#include <Furrovine++/Graphics/ShaderVariableType.h>
#include <Furrovine++/Graphics/ShaderVariablePrimitive.h>
#include <Furrovine++/Strings.h>

namespace Furrovine { namespace Graphics {

	struct ShaderVariableTypeDescription {
		ShaderVariableType type;          // Variable class (e.g. object, matrix, etc.)
		ShaderVariablePrimitive primitive;           // Variable type (e.g. float, sampler, etc.)
		uint32 rows;           // Number of rows (for matrices, 1 for other numeric, 0 if not applicable)
		uint32 columns;        // Number of columns (for vectors & matrices, 1 for other numeric, 0 if not applicable)
		uint32 elements;       // Number of elements (0 if not an array)
		uint32 members;        // Number of members (0 if not a structure)
		uint32 offset;         // Offset from the start of structure (0 if not a structure member)
		String name;           // Name of type, can be NULL
	};

}}