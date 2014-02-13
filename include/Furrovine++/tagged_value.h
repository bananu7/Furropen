#pragma once

#include <Furrovine++/std_defines.h>
#include <utility>

namespace Furrovine {

	template <typename value_type, typename tag_type>
	struct tagged_value {
		typedef value_type T;
		typedef tag_type TTag;

		template<typename ...Args>
		tagged_value(Args&& ...args) : element(std::forward<Args>(args)...) { }

		operator const T& () const { return element; }
		operator T& () { return element; }

		tagged_value& operator= ( tagged_value&& value ) {
			element = std::move( value.val );
			return *this;
		}

		tagged_value& operator= ( const tagged_value& value ) {
			element = value.val;
			return *this;
		}

		T element;
	};

}
