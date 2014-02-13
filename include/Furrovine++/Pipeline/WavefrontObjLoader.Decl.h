#pragma once

#include <Furrovine++/Pipeline/WavefrontMtlLoader.h>
#include <Furrovine++/Graphics/WindingOrder.h>
#include <Furrovine++/Graphics/Model.h>
#include <Furrovine++/Graphics/VertexPositionTextureNormal.h>
#include <Furrovine++/Graphics/ModelDescription.Decl.h>

namespace Furrovine { namespace Pipeline {

	class WavefrontObjLoader {
	public:
		furrovineapi WavefrontObjLoader ( );

		furrovineapi Graphics::ModelDescription operator() ( const String& path );
		furrovineapi Graphics::ModelDescription operator() ( IO::Stream& stream );
		furrovineapi Graphics::ModelDescription operator() ( IO::TextReader& stream );
		furrovineapi Graphics::ModelDescription Load ( const String& path );
		furrovineapi Graphics::ModelDescription Load ( IO::Stream& stream );
		furrovineapi Graphics::ModelDescription Load ( IO::TextReader& stream );

	};

}}
