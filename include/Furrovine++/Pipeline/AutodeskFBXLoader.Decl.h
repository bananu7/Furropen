#ifndef FURROVINEAUTODESKFBXLOADER_DECL_H
#define FURROVINEAUTODESKFBXLOADER_DECL_H

#include <Furrovine++/Graphics/ModelDescription.h>

namespace Furrovine { namespace Pipeline {

	struct AutodeskFBXLoader {
	private:
		const IO::FileSystem* filesystem;

	public:

		furrovineapi AutodeskFBXLoader ( const IO::FileSystem* filesystem = null );

		furrovineapi Graphics::ModelDescription Load ( const String& path );
		furrovineapi Graphics::ModelDescription Load ( IO::Stream& stream );
		furrovineapi Graphics::ModelDescription operator() ( IO::Stream& stream );
		furrovineapi Graphics::ModelDescription operator() ( const String& path );

	};

}}


#endif // FURROVINEAUTODESKFBXLOADER_DECL_H