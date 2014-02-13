#pragma once

#include <Furrovine++/Export.h>
#include <Furrovine++/Text/Declarations.Text.h>

namespace Furrovine { namespace Text {

	class TextResource {
	protected:
		TextResources* textcache;

	public:
		furrovineapi TextResource( );

		furrovineapi TextResource( TextResources* textcache );

		furrovineapi TextResource( TextResources& textcache );

		furrovineapi TextResource( TextResource&& mov );

		furrovineapi TextResource& operator=( TextResource&& mov );

		furrovineapi bool HasText( ) const;

		furrovineapi TextResources& Text( );

		furrovineapi const TextResources& Text( ) const;
	};

}}