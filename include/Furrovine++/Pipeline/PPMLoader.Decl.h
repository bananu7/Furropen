#ifndef FURROVINEPPMLOADER_DECL_H
#define FURROVINEPPMLOADER_DECL_H

#include <Furrovine++/Graphics/Image2D.h>

namespace Furrovine { namespace Pipeline {

	class PPMLoader {
	public:

		furrovineapi Graphics::Image2D Load ( IO::Stream& stream );
		furrovineapi Graphics::Image2D Load ( IO::ByteReader& reader );
		furrovineapi Graphics::Image2D operator()( IO::Stream& stream );
		furrovineapi Graphics::Image2D operator()( IO::ByteReader& reader );

	};

}}

#endif // FURROVINEPPMLOADER_DECL_H