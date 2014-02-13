#pragma once

#include <Furrovine++/PrimitiveTypes.h>
#include <Furrovine++/Strings.h>

namespace Furrovine { namespace Graphics {

	struct AdapterDescription {
		String description;
		uint vendorid;
		uint deviceid;
		uint subsystemid;
		uint revision;
		ulword dedicatedvideomemory;
		ulword dedicatedsystemmemory;
		ulword sharedsystemmemory;
		uint32 adapterluidlow;
		uint32 adapterluidhigh;
	};

}}