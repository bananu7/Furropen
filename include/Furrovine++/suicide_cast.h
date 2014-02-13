#ifndef FURROVINESUICIDE_CAST_H
#define FURROVINESUICIDE_CAST_H

#include <memory>

namespace Furrovine {

	///<summary>
	/// It's been fun, ya'll.
	///</summary>
	template <typename TTo, typename T>
	TTo suicide_cast ( const T& depression ) {
		typedef TTo* goodbye;
		std::size_t buildingheight = sizeof( T );
		void* cruelworld = (void*)( ((char*)std::addressof( depression )) + buildingheight );
		
		return *goodbye( cruelworld );
	}

}

#endif // FURROVINESUICIDE_CAST_H 