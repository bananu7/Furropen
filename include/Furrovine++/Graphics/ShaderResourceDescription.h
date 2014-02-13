#pragma once

#include <Furrovine++/Strings.h>
#include <Furrovine++/Graphics/ShaderResourceFlags.h>
#include <Furrovine++/Graphics/ShaderResourceReturnType.h>
#include <Furrovine++/Graphics/ShaderResourceType.h>
#include <Furrovine++/Graphics/ShaderResourceViewDimension.h>

namespace Furrovine { namespace Graphics {

	struct ShaderResourceDescription {
		String name; // Name of the resource
		ShaderResourceType type; // Type of resource (e.g. texture, cbuffer, etc.)
		uint32 bindpoint;// Starting bind point
		uint32 bindcount;// wNumber of contiguous bind points (for arrays)
		ShaderResourceFlags flags; // Input binding flags
		ShaderResourceReturnType returntype; // Return type (if texture)
		ShaderResourceViewDimension dimension;// Dimension (if texture)
		uint32 samples; // Number of samples (0 if not MS texture)
	};

}}