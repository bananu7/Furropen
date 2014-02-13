#pragma once

#include <Furrovine++/Exception.h>

namespace Furrovine {

	class ServiceNotFoundException : public Exception {

	public:
		template <typename... Tn>
		ServiceNotFoundException( Tn&&... argn ) : Exception( std::forward<Tn>( argn )... )  {

		}
	};

}
