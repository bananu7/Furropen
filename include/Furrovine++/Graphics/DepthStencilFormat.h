#pragma once

namespace Furrovine { namespace Graphics {
	
	enum class DepthStencilFormat {
		None = 0,
		Depth16NoStencil,
		Depth24Stencil8,
		Depth32Stencil8,
	};

	static bool IsValid ( DepthStencilFormat format ) {
		switch ( format ) {
		case DepthStencilFormat::Depth16NoStencil:
		case DepthStencilFormat::Depth24Stencil8:
		case DepthStencilFormat::Depth32Stencil8:
			return true;
		default:
			return false;
		}
		return false;
	}

	static bool HasStencil ( DepthStencilFormat format ) {
		switch (format) {
		case DepthStencilFormat::Depth24Stencil8:
		case DepthStencilFormat::Depth32Stencil8:
			return true;
		case DepthStencilFormat::Depth16NoStencil:
		default:
			return false;
		}
		return false;
	}
	
}}
