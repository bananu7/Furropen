#pragma once

#include <Furrovine++/Enums.h>

namespace Furrovine { namespace Graphics {
	
	enum class BindFlags {
		None = 0,
		VertexBuffer = 0x01,
		IndexBuffer = 0x02,
		UniformConstantBuffer = 0x04,
		ShaderResource = 0x08,
		TransformStreamOutput = 0x10,
		RenderBuffer = 0x20,
		DepthStencil = 0x40
	};

	enumflagoperators( BindFlags );

}}
