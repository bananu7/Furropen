#pragma once

#include <Furrovine++/TException.h>

namespace Furrovine {

	typedef TException<std::exception> Exception;

	template <typename T, typename... Tn>
	void ThrowException( Tn&&... argn ) {
		throw T( std::forward<Tn>( argn )... );
	}

}
