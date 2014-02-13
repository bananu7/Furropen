#pragma once

#include <type_traits>

namespace Furrovine {
	template <std::size_t I> 
	struct placeholder { 
		
	};
}

namespace std {
	template <size_t I>
	struct is_placeholder<Furrovine::placeholder<I>> : std::integral_constant<size_t, I> { 
		
	};
}