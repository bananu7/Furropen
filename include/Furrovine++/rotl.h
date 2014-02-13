#pragma once

#include <Furrovine++/Platform.OS.h>
#include <Furrovine++/inline.h>
#include <Furrovine++/PrimitiveTypes.h>
#ifdef FURROVINEWIN
#include <stdlib.h>
#endif // WIN

namespace Furrovine {

#ifdef FURROVINEWIN

	inlinealways uint ROTL32 ( uint x, char r ) {
		return _rotl(x, r);
	}

	inlinealways uint64 ROTL64 ( uint64 x, char r ) {
		return _rotl64(x, r);
	}

#elif FURROVINEAPPLE

	inlinealways uint rotl32 ( uint x, char r ) {
		return (x << r) | (x >> (32 - r));
	}

	inlinealways uint64 rotl64 ( uint64 x, char r ) {
		return (x << r) | (x >> (64 - r));
	}

	inlinealways uint ROTL32 ( uint x, char r ) {
		return rotl32(x, r);
	}

	inlinealways uint64 ROTL64 ( uint64 x, char r ) {
		return rotl64(x, r);
	}

#elif FURROVINELINUX

	inlinealways uint rotl32 ( uint x, char r ) {
		return (x << r) | (x >> (32 - r));
	}

	inlinealways uint64 rotl64 ( uint64 x, char r ) {
		return (x << r) | (x >> (64 - r));
	}

	inlinealways uint ROTL32 ( uint x, char r ) {
		return rotl32(x, r);
	}

	inlinealways uint64 ROTL64 ( uint64 x, char r ) {
		return rotl64(x, r);
	}

#endif // WIN || APPLE || LINUX 

}
