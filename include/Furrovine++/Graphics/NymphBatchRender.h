#pragma once

#include <Furrovine++/Declarations.h>
#include <Furrovine++/Graphics/Declarations.Graphics.h>
#include <Furrovine++/null.h>

namespace Furrovine { namespace Graphics {

	struct NymphBatchRender {
	public:
		Texture2D* Texture0;
		uint32 VertexStart;
		uint32 VertexCount;
		uint32 IndexStart;
		uint32 IndexCount;
		bool Outlineable;

		furrovineapi NymphBatchRender( Texture2D* texture = null );

	};

}}
