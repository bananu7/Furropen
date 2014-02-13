#ifndef FURROVINEREFLECT_H
#define FURROVINEREFLECT_H

namespace Furrovine { namespace Introspection {

	template <typename T>
	struct reflect {
		static_assert( false, "This type does not have reflection information. Please override the reflection type and provide reflection information." );
	};

}}

#endif // FURROVINEREFLECT_H 