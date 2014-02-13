#pragma once

#include <Furrovine++/numeric_integer_def.h>
#include <Furrovine++/null.h>
#include <Furrovine++/Export.h>
#include <functional>

namespace Furrovine { namespace Graphics {

	struct graphics_handle {
		union {
			void* dx;
			uint32 gl;
		};

		furrovineapi graphics_handle( );
		furrovineapi graphics_handle( void* dx );
		furrovineapi graphics_handle( uint32 gl );
		furrovineapi graphics_handle& operator=( void* dx );
		furrovineapi graphics_handle& operator=( uint32 gl );

		furrovineapi explicit operator bool( ) const;

		furrovineapi operator void* ( );
		furrovineapi operator uint32 ( );
	};

	furrovineapi bool operator== ( std::nullptr_t, const graphics_handle& left );
	furrovineapi bool operator== ( const graphics_handle& left, std::nullptr_t );
	furrovineapi bool operator== ( const graphics_handle& left, const graphics_handle& right );
	furrovineapi bool operator!= ( std::nullptr_t, const graphics_handle& left );
	furrovineapi bool operator!= ( const graphics_handle& left, std::nullptr_t );
	furrovineapi bool operator!= ( const graphics_handle& left, const graphics_handle& right );

}}

namespace std {

	template <>
	struct hash<Furrovine::Graphics::graphics_handle> {
		furrovineapi size_t operator() ( const Furrovine::Graphics::graphics_handle& hashee ) const;
	};

}