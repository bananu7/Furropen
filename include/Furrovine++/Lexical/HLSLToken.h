#pragma once

#include <Furrovine++/Enums.h>

namespace Furrovine { namespace Lexical {
	
	enum class HLSLToken {
		Invalid,
		TechniqueBlock,
		PassBlock,
		VertexShaderStatement,
		GeometryShaderStatement,
		DomainShaderStatement,
		HullShaderStatement,
		PixelShaderStatement,
		ComputeShaderStatement,
		Compile,
		OpenCurlyBrace,
		CloseCurlyBrace,
		OpenParenthesis,
		CloseParenthesis,
		Set,
		EndStatement,
		NewLine,
		Identifier,
		Define,
		PragmaStatement,
		PackMatrix,
		RowMajor,
		ColumnMajor
	};

	enummathoperators( HLSLToken );
	
}}
 