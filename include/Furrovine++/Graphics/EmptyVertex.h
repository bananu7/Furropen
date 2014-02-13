#pragma once

#include <Furrovine++/numeric_integer_def.h>
#include <Furrovine++/Export.h>

namespace Furrovine { namespace Graphics {

	struct VertexDeclaration;

	struct EmptyVertex {
	public:
		furrovineapi static const ulword Stride = 0;
		furrovineapi static const VertexDeclaration& Declaration( );


	};

}}
