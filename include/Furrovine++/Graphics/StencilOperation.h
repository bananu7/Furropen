#pragma once

namespace Furrovine { namespace Graphics {
	
	enum class StencilOperation {
		Keep = 1,
		Zero,
		Replace,
		IncrementClamp,
		DecrementClamp,
		Invert,
		Increment,
		Decrement,
	};
	
}}
