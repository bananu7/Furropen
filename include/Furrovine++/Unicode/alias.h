#pragma once

#include <Furrovine++/Unicode/alias_t.h>
#include <Furrovine++/buffer_view.h>

namespace Furrovine { namespace Unicode {

	struct alias {
	public:
		buffer_view<const char> name;
		alias_t type;

		template <std::size_t n>
		alias( const char( &array )[ n ], alias_t alias_type ) : name( array ), type( alias_type ) {

		}
	};

}}