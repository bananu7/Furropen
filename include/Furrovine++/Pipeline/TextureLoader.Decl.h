#pragma once

#include <Furrovine++/ptr.h>
#include <Furrovine++/Strings.h>
#include <Furrovine++/Graphics/Image2D.h>
#include <Furrovine++/Graphics/Texture2D.h>

namespace Furrovine { namespace Pipeline {

	struct TextureLoader {
	private:
		Graphics::GraphicsDevice& device;

	public:
		furrovineapi TextureLoader ( Graphics::GraphicsDevice& graphicsdevice );

		furrovineapi Graphics::Texture2D Load ( const String& path );
		furrovineapi Graphics::Texture2D operator () ( const String& path );

		furrovineapi Graphics::Texture2D Load ( IO::Stream& stream );
		furrovineapi Graphics::Texture2D operator () ( IO::Stream& stream );
		
		furrovineapi Graphics::Texture2D Load( const std::vector<Graphics::Image2D>& image );
		furrovineapi Graphics::Texture2D operator () ( const std::vector<Graphics::Image2D>& image );
	};

}}
