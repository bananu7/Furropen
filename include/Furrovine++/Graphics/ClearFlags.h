#pragma once

namespace Furrovine { namespace Graphics {
	
	enum class ClearFlags {
		None = 0x0,
		Depth = 0x01,
		Stencil = 0x02,
		Color = 0x04,
		DepthStencil = Depth | Stencil,
		DepthStencilColor = Depth | Stencil | Color
	};
	
	enumflagoperators( ClearFlags );

}}
