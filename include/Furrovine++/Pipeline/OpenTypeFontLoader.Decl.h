#pragma once

#include <Furrovine++/Declarations.h>
#include <Furrovine++/Text/Declarations.Text.h>
#include <Furrovine++/FurrovineApi.h>
#include <Furrovine++/Text/Font.h>

namespace Furrovine { namespace Pipeline {

	class OpenTypeFontLoader {
	private:
		Text::TextResources* textcache;

	public:

		furrovineapi OpenTypeFontLoader( Text::TextResources& cache );

		furrovineapi Text::Font Load ( IO::Stream& reader );
		furrovineapi Text::Font Load ( IO::ByteReader& reader );

	}; 

}}
