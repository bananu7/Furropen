#pragma once

#include <Furrovine++/Graphics/ModelDescription.h>

namespace Furrovine { namespace Pipeline {

	class XBLoader {
	public:

		furrovineapi Graphics::ModelDescription Load ( IO::Stream& stream );

		furrovineapi Graphics::ModelDescription Load ( IO::TextReader& reader );

	};

}}
