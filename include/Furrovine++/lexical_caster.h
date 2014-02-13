#pragma once

#include <Furrovine++/std_defines.h>
#include <sstream>
#include <Furrovine++/Strings.h>

namespace Furrovine {

	template <typename T>
	struct to_lexical_caster {

		String operator() ( const T& value ) {
			std::ostringstream oss;
			if ( oss << value )
				return String( make_buffer_view( oss.str( ) ) );
			else
				throw std::runtime_error( "Unable to lexical_cast" );
		}

	};

	template <typename TTo>
	struct from_lexical_caster {

		TTo operator() ( String&& value ) {
			return operator()<String&&>( std::move( value ) );
		}

		TTo operator() ( const String& value ) {
			return operator()<const String&>( value );
		}

		template <typename T>
		TTo operator() ( T&& value ) {
			std::istringstream iss( value.Storage( ) );
			T val;
			if ( iss >> value )
				return value;
			else
				throw std::runtime_error( "Unable to lexical_cast" );
		}

	};

}