#pragma once

namespace Furrovine { namespace Graphics {

	enum class ResourceMapping {
		Read = 1,
		ReadWrite,
		Write,
		WriteAndDiscard,
		WriteAndDiscardNoOverwrite,
	};

}}
