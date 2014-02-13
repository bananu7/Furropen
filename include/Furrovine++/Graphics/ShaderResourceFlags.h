#pragma once

#include <Furrovine++/Enums.h>

namespace Furrovine { namespace Graphics {

	enum class ShaderResourceFlags { 
		None = 0x0,
		Userpacked = 0x01,
		ComparisonSampler = 0x02,
		TextureComponent0 = 0x04,
		TextureComponent1 = 0x08,
		Unused = 0x10,
		TextureComponent01 = TextureComponent0 | TextureComponent1,
	};

	enumflagoperators( ShaderResourceFlags );

}}
