#pragma once

#include <Furrovine++/Graphics/graphics_handle.h>
#include <Furrovine++/Graphics/VertexDeclaration.h>

namespace Furrovine { namespace Graphics {

	struct ShaderDeclaration {
	protected:
		VertexDeclaration input, output;

	public:

		furrovineapi ShaderDeclaration( );
		furrovineapi ShaderDeclaration( graphics_handle reflection );

		furrovineapi ShaderDeclaration( ShaderDeclaration&& mov );
		furrovineapi ShaderDeclaration& operator=( ShaderDeclaration&& mov );

		furrovineapi const VertexDeclaration& Input () const;

		furrovineapi const VertexDeclaration& Output () const;

		furrovineapi bool InputCompatible ( const VertexDeclaration& declaration ) const;

		furrovineapi void EnsureInputCompatible ( const VertexDeclaration& declaration ) const;

		furrovineapi bool OutputCompatible ( const VertexDeclaration& declaration ) const;

		furrovineapi void EnsureOutputCompatible ( const VertexDeclaration& declaration ) const;

		furrovineapi bool Before ( const ShaderDeclaration& declaration ) const;

		furrovineapi void EnsureBefore ( const ShaderDeclaration& declaration ) const;

		furrovineapi bool After ( const ShaderDeclaration& declaration ) const;

		furrovineapi void EnsureAfter ( const ShaderDeclaration& declaration ) const;

		furrovineapi bool InputCompatible ( const VertexDeclaration& declaration, bool& fudged ) const;

		furrovineapi void EnsureInputCompatible ( const VertexDeclaration& declaration, bool& fudged ) const;

		furrovineapi bool OutputCompatible ( const VertexDeclaration& declaration, bool& fudged ) const;

		furrovineapi void EnsureOutputCompatible ( const VertexDeclaration& declaration, bool& fudged ) const;

		furrovineapi bool Before ( const ShaderDeclaration& declaration, bool& fudged ) const;

		furrovineapi void EnsureBefore ( const ShaderDeclaration& declaration, bool& fudged ) const;

		furrovineapi bool After ( const ShaderDeclaration& declaration, bool& fudged ) const;

		furrovineapi void EnsureAfter ( const ShaderDeclaration& declaration, bool& fudged ) const;

	};

}}
