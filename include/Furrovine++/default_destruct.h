#ifndef FURROVINEDEFAULT_DESTRUCT_H
#define FURROVINEDEFAULT_DESTRUCT_H

namespace Furrovine {
	
	template <typename T> 
	struct default_destruct {
		void operator() ( T* item ) {
			item->~T( );
		}
	};
	
}

#endif // FURROVINEDEFAULT_DESTRUCT_H 