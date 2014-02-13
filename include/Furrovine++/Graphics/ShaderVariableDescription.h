#pragma once

#include <Furrovine++/PrimitiveTypes.h>
#include <Furrovine++/Strings.h>
#include <Furrovine++/Graphics/ShaderVariableFlags.h>

namespace Furrovine { namespace Graphics {

	struct ShaderVariableDescription {
		String name;           // Name of the variable
		uint32 startoffset;    // Offset in constant buffer's backing store
		uint32 size;           // Size of variable (in bytes)
		ShaderVariableFlags flags;         // Variable flags
		void* defaultvalue;   // Raw pointer to default value
		uint32 starttexture;   // First texture index (or -1 if no textures used)
		uint32 texturesize;    // Number of texture slots possibly used.
		uint32 startsampler;   // First sampler index (or -1 if no textures used)
		uint32 samplersize;    // Number of sampler slots possibly used.
	};

}}