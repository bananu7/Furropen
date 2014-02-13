#include <Furrovine++/std_defines.h>
#include <Furrovine++/pointer_typedef_enable_if.h>
#include <memory>

namespace Furrovine {

	struct release_deleter {
		template <typename T> 
		void operator() ( T* ptr ) const;
	};

	struct destroy_deleter {
		template <typename T> 
		void operator() ( T* ptr ) const;
	};

	struct destroyvoice_deleter {
		template <typename T> 
		void operator() ( T* ptr ) const;
	};

	struct no_delete {
		template <typename T> 
		void operator() ( T&& ptr ) const;
	};

	template <typename T>
	struct array_delete {
		typedef T* pointer;

		void operator() ( pointer ptr ) const;
	};

	template <typename T, typename TDx = std::default_delete<T>>
	struct optional_delete {
		typedef typename get_pointer_type<T*, TDx>::type pointer;
		bool usedeleter;
		TDx deleter;

		optional_delete ( bool calldelete = true, TDx&& deleter = TDx() );

		void operator() ( pointer ptr ) const;
	};

	template <typename TDx>
	struct optional_deleter {
		bool usedeleter;
		TDx deleter;

		optional_deleter ( bool calldelete = true, TDx&& deleter = TDx() );

		template<typename T>
		void operator() ( T&& ptr ) const;
	};

}
 
