#pragma once

#include <Furrovine++/Strings.h>
#include <Furrovine++/Graphics/ShaderBufferType.h>
#include <Furrovine++/Graphics/ShaderBufferFlags.h>

namespace Furrovine { namespace Graphics {

	struct ShaderBufferDescription {
		String name; // Name of the constant buffer
		ShaderBufferType type; // Indicates type of buffer content
		uint32 variables;// Number of member variables
		uint32 size; // Size of CB (in bytes)
		ShaderBufferFlags flags; // Buffer description flags
	};

}}