#pragma once

#include <Furrovine++/handle.h>
#include <Furrovine++/Graphics/graphics_handle.h>
#include <Furrovine++/Graphics/GraphicsResource.h>
#include <Furrovine++/Graphics/VertexDeclaration.h>

namespace Furrovine { namespace Graphics {

	class InputLayout : public GraphicsResource {
	private:
		struct deleter {
			furrovineapi void operator() ( graphics_handle p );
		};

		VertexDeclaration declaration;
		handle<graphics_handle, deleter>  layout;

	public:

		furrovineapi InputLayout( GraphicsDevice& graphicsdevice, const VertexDeclaration& vertexdeclaration, const buffer_view<void>& bytecode );

		furrovineapi InputLayout( InputLayout&& layout );
		furrovineapi InputLayout& operator=( InputLayout&& layout );

		furrovineapi const VertexDeclaration& Declaration( ) const;

		furrovineapi graphics_handle Resource( ) const;

	};

}}
