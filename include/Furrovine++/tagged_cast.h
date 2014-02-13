#pragma once

#include <Furrovine++/tagged_value.h>

namespace Furrovine {

	template < class > 
	struct sfinae_false : std::false_type { };

	template <typename tag_to, typename tag_from, typename T>
	struct tagged_caster {
		tagged_value<T, tag_to> operator() ( const tagged_value<T, tag_from>& castee ) {
			static_assert( sfinae_false<T>, "There is no conversion for these tagged types" );
		}
	};

	template <typename tag, typename T>
	struct tagged_caster<tag, tag, T> {
		tagged_value<T, tag> operator() ( const tagged_value<T, tag>& castee ) { return castee; }
	};

	template <typename tag_to, typename tag_from, typename T>
	tagged_value<T, tag_to> tagged_cast ( const tagged_value<T, tag_from>& castee ) {
		return tagged_caster<tag_to, tag_from, T>()( castee );
	}

	template <typename tag, typename T>
	tagged_value<T, tag> tagged_cast ( const tagged_value<T, tag>& castee ) {
		return tagged_caster<tag, tag, T>()( castee );
	}

	template <typename tag_to, typename tag_from, typename T>
	tagged_value<T, tag_to> tagged_cast ( const T& castee ) {
		return tagged_caster<tag_to, tag_from, T>()( castee );
	}

	template <typename tag, typename T>
	tagged_value<T, tag> tagged_cast ( const T& castee ) {
		return tagged_caster<tag, tag, T>()( castee );
	}

}
