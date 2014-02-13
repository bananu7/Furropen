#ifndef FURROVINETAGGED_UNIT_CASTS_H
#define FURROVINETAGGED_UNIT_CASTS_H

#include <Furrovine++/tags.h>
#include <Furrovine++/TaggedValue.h>
#include <Furrovine++/tagged_cast.h>

namespace Furrovine {

	template <typename T>
	struct tagged_caster<radians_tag, degrees_tag, T> {

		tagged_value<T, radians_tag> operator() ( const tagged_value<T, degrees_tag>& castee ) {
			return castee * 0.0174532925;
		}

	};
	
	template <typename T>
	struct tagged_caster<degrees_tag, radians_tag, T> {

		tagged_value<T, degrees_tag> operator() ( const tagged_value<T, radians_tag>& castee ) {
			return castee * 57.2957795;
		}

	};

}

#endif // FURROVINETAGGED_UNIT_CASTS_H 