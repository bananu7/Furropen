#ifndef FURROVINEBMPLOADER_DECL_H
#define FURROVINEBMPLOADER_DECL_H

#include <Furrovine++/Strings.h>
#include <Furrovine++/Graphics/Image2D.h>

namespace Furrovine { namespace Pipeline {

	class BMPLoader {
	public:

		bool IgnoreHeader;
		int ColorMapCount, ContainerWidth, ContainerHeight;


		furrovineapi BMPLoader ( bool ignoreheader = false, int colormapcount = 0, int containerwidth = 0, int containerheight = 0 );

		furrovineapi Graphics::Image2D Load ( const String& path );
		furrovineapi Graphics::Image2D Load ( IO::Stream& stream );
		furrovineapi Graphics::Image2D Load ( IO::ByteReader& reader );
		furrovineapi Graphics::Image2D operator() ( const String& path );
		furrovineapi Graphics::Image2D operator() ( IO::Stream& stream );
		furrovineapi Graphics::Image2D operator() ( IO::ByteReader& reader );

	};

}}

#endif // FURROVINEBMPLOADER_DECL_H