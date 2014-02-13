#pragma once

namespace Furrovine {

	// No-op; handle will invoke default destructor upon exist. 
	// You should override this
	template <typename T>
	struct default_handle_deleter : public default_get_null<T> {
		void operator () ( T& handle ) {
		}
	};

}
