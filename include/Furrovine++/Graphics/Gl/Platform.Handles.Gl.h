#pragma once

#include <Furrovine++/Platform.Graphics.h>
#include <Furrovine++/Graphics/Declarations.Graphics.h>
#include <Furrovine++/Graphics/graphics_handle.h>

namespace Furrovine { namespace Graphics { namespace Gl {

#ifdef FURROVINEOPENGL

	struct ptrptr_cast {

		furrovineapi static GLuint to( graphics_handle a );

		furrovineapi static graphics_handle from( GLuint a );

	};

	template <typename TPtr>
	ptrptr_type<TPtr, GLuint, ptrptr_cast> ptrptr( TPtr& p ) { return ptrptr_type<TPtr, GLuint, ptrptr_cast>( p ); }
	
	namespace detail {
		namespace detail {
			template <typename T>
			GLuint native_handle( T&, graphics_handle target ) {
				return target.gl;
			}
		}

		furrovineapi GLuint native_handle( GpuBuffer& target );

		furrovineapi GLuint native_handle( GpuMultiBuffer& target, ulword n = 0 );

		furrovineapi GLuint native_handle( ShaderResourceView& target );
	}

	template <typename T, typename... Tn>
	inline GLuint native_handle( T& target, Tn&&... argn ) {
		return detail::native_handle( target, std::forward<Tn>( argn )... );
	}

	template <typename T, typename... Tn>
	inline GLuint native_handle( T* target, Tn&&... argn ) {
		typedef decltype( detail::native_handle( *target, std::forward<Tn>( argn )... ) ) TR;
		return detail::native_handle<TR>( target, std::forward<Tn>( argn )... );
	}

	template <typename T, typename... Tn>
	inline GLuint native_handle( graphics_handle target, Tn&&... argn ) {
		return detail::native_handle( null_ref<T>::value, target, std::forward<Tn>( argn )... );
	}

#endif // endif

}}}