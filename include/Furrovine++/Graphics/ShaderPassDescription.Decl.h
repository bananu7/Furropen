#pragma once

#include <Furrovine++/Strings.h>
#include <Furrovine++/Graphics/ShaderSource.h>

namespace Furrovine { namespace Graphics {

	struct ShaderPassDescription {
	public:
		String PassName;
		ShaderSource VertexSource;
		ShaderSource HullSource;
		ShaderSource DomainSource;
		ShaderSource GeometrySource;
		ShaderSource PixelSource;

		furrovineapi ShaderPassDescription( );

		furrovineapi ShaderPassDescription( ShaderSource vertex, ShaderSource pixel );

		furrovineapi ShaderPassDescription( ShaderSource vertex,
			ShaderSource geometry, ShaderSource hull,
			ShaderSource domain, ShaderSource pixel );

		furrovineapi ShaderPassDescription( ShaderSource vertex,
			ShaderSource geometry,
			ShaderSource pixel );

		furrovineapi ShaderPassDescription( const ShaderSource& compute );

		furrovineapi ShaderSource& operator[] ( ShaderStage method );

	};

}}
