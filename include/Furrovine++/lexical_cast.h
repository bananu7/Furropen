#pragma once

#include <Furrovine++/lexical_caster.h>

namespace Furrovine {

	template <typename T>
	String lexical_cast( const T& value ) {
		to_lexical_caster<T> caster{};
		return caster( value );
	}

	template <typename T>
	T lexical_cast ( const String& value ) {
		from_lexical_caster<T> caster{};
		return caster( value );
	}

	template <typename T>
	T lexical_cast( String&& value ) {
		from_lexical_caster<T> caster{};
		return caster( value );
	}

}
