#pragma once

#include <Furrovine++/handle.h>
#include <Furrovine++/Export.h>
#include <Furrovine++/Text/FontDescription.h>
#include <Furrovine++/Text/TextResource.h>

namespace Furrovine { namespace Text {

	class Font : TextResource {
	private:
		struct font_deleter {
			furrovineapi void operator()( void* p );
		};
		FontDescription fontdesc;
		handle<void*, font_deleter> fontresource;

	public:

		furrovineapi Font( TextResources& textcache, FontDescription description );

		furrovineapi void* FontResource( ) const;
	};

}}
 