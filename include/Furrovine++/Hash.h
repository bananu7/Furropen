#pragma once

#include <Furrovine++/PrimitiveTypes.h>
#include <Furrovine++/Hashers.h>

namespace Furrovine {
	
	template <typename T, typename S = ulword> 
	struct MurmurHash;

	template <typename T> 
	struct MurmurHash<T, uint32> {
		static ulword HashCode (const T& hashee) {
			ulword hash;
			Hashers::MurmurHash32( &hashee, sizeof( T ), Hashers::HashSeed32, &hash );
			return hash;
		}

		ulword operator () (const T& hashee) const {
			ulword hash;
			Hashers::MurmurHash32( &hashee, sizeof( T ), Hashers::HashSeed32, &hash );
			return hash;
		}
	};

	template <typename T> 
	struct MurmurHash<T, uint64> {
		static ulword HashCode (const T& hashee) {
			ulword hash;
			Hashers::MurmurHash64( &hashee, sizeof( T ), Hashers::HashSeed64, &hash );
			return hash;
		}

		ulword operator () (const T& hashee) const {
			ulword hash;
			Hashers::MurmurHash64( &hashee, sizeof( T ), Hashers::HashSeed64, &hash );
			return hash;
		}
	};

}
