#pragma once

#include <Furrovine++/FurrovineApi.h>
#include <Furrovine++/ptr.h>
#include <Furrovine++/Strings.h>
#include <Furrovine++/Graphics/Declarations.Graphics.h>
#include <Furrovine++/Graphics/Model.h>

namespace Furrovine { namespace Pipeline {

	struct ModelLoader {
	private:
		const IO::FileSystem* filesystem;
		Graphics::GraphicsDevice& graphicsdevice;

	public:
		furrovineapi ModelLoader ( Graphics::GraphicsDevice& graphicsdevice, const IO::FileSystem* filesystem = null );
		
		furrovineapi Graphics::Model Load ( Graphics::ModelDescription& modeldescription );
		furrovineapi Graphics::Model operator () ( Graphics::ModelDescription& modeldescription );

		furrovineapi Graphics::Model Load ( const String& path );
		furrovineapi Graphics::Model operator () ( const String& path );

		furrovineapi Graphics::Model Load ( IO::Stream& stream );
		furrovineapi Graphics::Model operator () ( IO::Stream& stream );

	};

}}
