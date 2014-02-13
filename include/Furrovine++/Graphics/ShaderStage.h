#pragma once

#include <Furrovine++/Enums.h>
#include <Furrovine++/Strings.h>
#include <Furrovine++/lexical_cast.h>
#include <Furrovine++/Graphics/Constants.h>

namespace Furrovine { namespace Graphics {
	
	enum class ShaderStage {
		Vertex = 0x00,
		Hull = 0x01,
		Domain = 0x02,
		Geometry = 0x03,
		Pixel = 0x04,
		Compute = 0x05,
		Unknown = 0x06,
	};

	enummathoperators( ShaderStage );
	
	enum class ShaderStageFlags {
		None = 0x00,
		Vertex = 0x01,
		Hull = 0x02,
		Domain = 0x04,
		Geometry = 0x08,
		Pixel = 0x10,
		Compute = 0x20,
		All = Vertex | Geometry | Hull | Domain | Pixel | Compute,
	};

	enumflagoperators( ShaderStageFlags );

	class ShaderStages {
	public:
		furrovineapi static const String Names[ detail::PipelineStages + 1 ];

	};

	inline furrovineapi ulword ToIndex( ShaderStage value );

	inline furrovineapi ShaderStage ToShaderStage( ulword value );

	inline furrovineapi ShaderStageFlags ToShaderStageFlag( ShaderStage value );
	
}}

namespace Furrovine {

	template <>
	inline furrovineapi String lexical_cast<Graphics::ShaderStage> ( const Graphics::ShaderStage& methodology );

}
 