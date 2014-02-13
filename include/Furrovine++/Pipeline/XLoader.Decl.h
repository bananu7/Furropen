#ifndef FURROVINEXLOADER_DECL_H
#define FURROVINEXLOADER_DECL_H

#include <Furrovine++/Pipeline/XALoader.h>
#include <Furrovine++/Pipeline/XBLoader.h>

namespace Furrovine { namespace Pipeline {

	class XLoader {
	public:

		furrovineapi Graphics::ModelDescription Load( IO::Stream& stream );

	};

}}

#endif // FURROVINEXLOADER_DECL_H