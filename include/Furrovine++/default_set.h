#ifndef FURROVINEDEFAULT_SET_H
#define FURROVINEDEFAULT_SET_H

#include <utility>

namespace Furrovine {

	template <typename T>
	struct default_set {

		void operator () ( T& current, const T& val ) {
			current = val;
		}

		void operator () ( T& current, T&& val ) {
			current = std::move( val );
		}

	};



}

#endif // FURROVINEDEFAULT_SET_H 