#ifndef FURROVINEDEFAULT_GET_H
#define FURROVINEDEFAULT_GET_H

namespace Furrovine {

	template <typename T>
	struct default_get {
		T operator () ( T& current ) {
			return current;
		}
	};

}

#endif // FURROVINEDEFAULT_GET_H 