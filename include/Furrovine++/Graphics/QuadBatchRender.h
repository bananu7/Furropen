#pragma once

#include <Furrovine++/Declarations.h>
#include <Furrovine++/Graphics/Declarations.Graphics.h>
#include <Furrovine++/null.h>

namespace Furrovine { namespace Graphics {

	struct QuadBatchRender {
	public:
		Texture2D* Texture0;
		uint32 VertexStart;
		uint32 VertexCount;
		
		furrovineapi QuadBatchRender( Texture2D* texture = null );

	};

}}
