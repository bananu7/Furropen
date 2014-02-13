#pragma once

#include <Furrovine++/PrimitiveTypes.h>
#include <Furrovine++/Strings.h>
#include <Furrovine++/Graphics/ShaderCompilationFlags.h>

namespace Furrovine { namespace Graphics {

	struct ShaderReflectionDescription {
		String creator;
		ShaderCompilationFlags flags;
		uint32 version;
		uint32 constantbuffers;
		uint32 boundresources;
		uint32 inputparameters;
		uint32 outputparameters;
	};

}}
